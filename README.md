# UltraEngine

Work in progress game engine made using Vulkan, specifically made for creating a RTS game. But (hopefully) made modular enough to create other games.

## Stack

* Vulkan
* Windows API (cross-platform support is way off in the roadmap)

I tried to avoid using math libraries and SDKs (e.g. glfw, boost, STL) wherever possible and rolled out my custom solutions.

## Automation

Poor experiences with Unreal Engine not being tested made me double down on automation for this engine. This should allow for heavy refactoring without worrying about breaking things.

* Google Test (gtest, gmock)

## Source

It is all in the `Engine` directory

## Getting Started

```sh
$ mkdir build
$ cd build
$ cmake ..
$ cmake --build .
```

### Known Problems

If you delete a file, it will not trigger a build reconfiguration and it will complain that it can't find
the specific file. This is a limitation due to recursively adding source files via CMake. The alternative
is to manually add the file name for every file in the CMake file, but a project of this size will get
tedious very fast. So if you run into this issue, you will have delete `build/*` and rebuild with cmake.

## Best Practices, Patterns, Designs

I want to keep the code base consistant

* Gang of Four OOP designs
* Clean Code (uncle bob)
* Test Driven Development
