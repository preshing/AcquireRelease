cmake_minimum_required (VERSION 2.8.8)
set(CMAKE_CONFIGURATION_TYPES "Release")

set(CMAKE_XCODE_EFFECTIVE_PLATFORMS "-iphoneos;-iphonesimulator")

project (AcquireRelease)
set(MACOSX_BUNDLE_GUI_IDENTIFIER "com.mycompany.\${PRODUCT_NAME:identifier}")
file(GLOB SOURCES *.cpp)
add_executable(AcquireRelease MACOSX_BUNDLE ${SOURCES})

set_target_properties(AcquireRelease PROPERTIES XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY "iPhone Developer")
set_target_properties(AcquireRelease PROPERTIES XCODE_ATTRIBUTE_GCC_OPTIMIZATION_LEVEL "s")
set_target_properties(AcquireRelease PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "c++0x")
set_target_properties(AcquireRelease PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
