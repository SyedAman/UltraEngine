# UltraEngine

Game engine made using Vulkan, specifically made for creating a RTS game. But (hopefully) made modular enough to create other games.

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

## Best Practices, Patterns, Designs

I want to keep the code base consistant

* Gang of Four OOP designs
* Clean Code (uncle bob)
* Test Driven Development