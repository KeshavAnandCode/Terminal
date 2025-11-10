#!/bin/bash

#macos

cd ~/Downloads/Code/Terminal
rm -rf macbuild
mkdir macbuild
cd macbuild
cmake -DCMAKE_OSX_ARCHITECTURES="arm64;x86_64" ..
make



#Linux

cd ~/Downloads/Code/Terminal
rm -rf linuxbuild
mkdir linuxbuild
cd linuxbuild

docker run --rm -v "$(pwd)/..":/src -w /src gcc:latest bash -c "
apt-get update && apt-get install -y cmake make
mkdir -p build && cd build
cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_EXE_LINKER_FLAGS='-static' ..
make
cd ..
mv build linuxbuild/
"

#Linux Test

cd ~/Downloads/Code/Terminal

docker run --rm -v "$(pwd)/linuxbuild":/build -w /build --platform linux/amd64 ubuntu:22.04 bash -c "
apt-get update && apt-get install -y libstdc++6
./build/portfolio
"

#Windows:

cd ~/Downloads/Code/Terminal
rm -rf winbuild
mkdir winbuild

# Download Dockcross helper
docker run --rm dockcross/windows-static-x64 > ./winbuild/dockcross-windows
chmod +x ./winbuild/dockcross-windows

# Build Windows binary inside winbuild
# Note: we mount the repo root (current folder) as /work
./winbuild/dockcross-windows bash -c "
mkdir -p /work/winbuild/build
cd /work/winbuild/build
cmake -DCMAKE_BUILD_TYPE=Release -S /work -B .
make
cp portfolio.exe /work/winbuild/
"

#Windows Test (requires Wine)

cd ~/Downloads/Code/Terminal

docker run --rm -v "$(pwd)/winbuild":/winbuild -w /winbuild --platform linux/amd64 \
  scottyhardy/docker-wine:latest wine64 build/portfolio.exe

