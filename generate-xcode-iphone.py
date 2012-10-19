#!/usr/bin/python
import os
import sys

# Change working directory to the one containing this script
os.chdir(os.path.split(sys.argv[0])[0])

# Create build subfolder and chdir into it
if not os.path.isdir("build"):
    os.mkdir("build")
os.chdir("build")

# Run cmake with the correct arguments
os.system("cmake -DCMAKE_TOOLCHAIN_FILE=../iOS.cmake -GXcode ..")
