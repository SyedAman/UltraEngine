# UltraEngine

Game engine made using Vulkan, specifically made for creating a RTS game. But (hopefully) made modular enough to create other games.

## Stack

* Vulkan
* Windows API

I tried to avoid using math libraries and SDKs (e.g. glfw, boost, STL) wherever possible and rolled out my custom solutions.

## Automation

Poor experiences with Unreal Engine not being tested made me double down on automation for this engine. This should allow for heavy refactoring without worrying about breaking things.

* Google Test (gtest, gmock)

## Source

It is all in the `Engine` directory

## Getting Started

1. `mkdir build`
2. `cmake ..`
3. `cmake --build .`
