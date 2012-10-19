# AcquireRelease

AcquireRelease is a sample application which complements the blog post, [This Is Why They Call It a Weakly-Ordered CPU](http://preshing.com/20121019/this-is-why-they-call-it-a-weakly-ordered-cpu).

It demonstrates the kind of memory reordering which only happens on weakly-ordered CPUs, assuming no compiler reordering takes place.

## Requirements

[CMake](http://www.cmake.org/cmake/resources/software.html) 2.8.9 or later. It might work using earlier versions of CMake if you edit `CMakeLists.txt`, but I didn't test this. The CMake  executable must be available in your path.

A compiler toolchain which supports C++11 threads and atomics. I tested it using Xcode 4.5.1 on OSX Mountain Lion 10.8.2, and Visual Studio 2012 on Windows 7.

If you're targeting iOS, your device must be running iOS 5.0 or later. You must also have your developer certificate and provisioning profiles already set up. If you're able to build and run sample applications, you should be good to go.

## How to Build and Run on iOS Devices

Run `generate-xcode-iphone.py`.

Open `build/AcquireRelease.xcodeproj`.

Select **AcquireRelease** as the target scheme using the drop-down list available by clicking the **Scheme** box.

Click **Run**.

Notes:

* The Xcode project is generated using a slightly modified version of [this CMake toolchain file](http://code.google.com/p/ios-cmake/). Specifically, I modified it to additionally search for the iOS Developer folder under `/Applications/Xcode.app/Contents/`, which is where it was for me after installing Xcode via the App Store on Mountain Lion.
* When using the resulting generated Xcode project, you won't be able to set source-level breakpoints. Assembly-level breakpoints still work, though.

## How to Build on Other Platforms

Make a `build` subdirectory, run `cmake -G "<generator>" ..` in that subdirectory, then use the resulting solution, project or makefile. To see a list of available generators, run `cmake` by itself. For example, for Visual Studio 2012, I used the following command line:

```
cmake -G "Visual Studio 11" ..
```
