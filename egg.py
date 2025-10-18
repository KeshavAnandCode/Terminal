import cv2
import numpy as np
import math

# === Parameters ===
input_path = "input_image.png"    # replace with your image filename
output_path = "radial_output.png"
canvas_size = 1000                # output size (square)
num_sections = 8                  # 8 radial triangles (45° each)

# === Load and prepare image ===
img = cv2.imread(input_path, cv2.IMREAD_UNCHANGED)
img = cv2.resize(img, (canvas_size, canvas_size))

# Convert to grayscale if needed
if img.ndim == 3:
    img_gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
else:
    img_gray = img.copy()

# === Create mask for one triangular wedge ===
center = (canvas_size // 2, canvas_size // 2)
radius = canvas_size // 2
angle_step = 360 / num_sections
angle1 = -angle_step / 2
angle2 = angle_step / 2

# Create polygon points for wedge
pts = np.array([
    center,
    (int(center[0] + radius * math.cos(math.radians(angle1))),
     int(center[1] + radius * math.sin(math.radians(angle1)))),
    (int(center[0] + radius * math.cos(math.radians(angle2))),
     int(center[1] + radius * math.sin(math.radians(angle2))))
], np.int32)

mask = np.zeros_like(img_gray)
cv2.fillConvexPoly(mask, pts, 255)

# === Extract the wedge from input image ===
wedge = cv2.bitwise_and(img_gray, mask)

# === Prepare output canvas ===
output = np.zeros_like(img_gray)

# === Paste rotated copies of the wedge into all sections ===
for i in range(num_sections):
    angle = i * angle_step
    rot_mat = cv2.getRotationMatrix2D(center, angle, 1.0)
    rotated = cv2.warpAffine(wedge, rot_mat, (canvas_size, canvas_size))
    output = cv2.bitwise_or(output, rotated)

# === Optional: enhance lines for visibility ===
output = cv2.threshold(output, 10, 255, cv2.THRESH_BINARY)[1]

# === Save result ===
cv2.imwrite(output_path, output)

print(f"✅ Radial design saved as {output_path}")
