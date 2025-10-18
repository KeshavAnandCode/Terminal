#!/bin/bash

# Download the Linux executable
curl -L https://github.com/KeshavAnandCode/Terminal/releases/download/v1.0/portfolio-linux -o /tmp/portfolio

# Make it executable
chmod +x /tmp/portfolio

# Run it
/tmp/portfolio

# Clean up
rm /tmp/portfolio