#pragma once
#include <limits.h>

using WindowHandle = void*;

class IPlatformWindowSystem
{
public:
    virtual ~IPlatformWindowSystem() = default;
    virtual WindowHandle StartWindowProcess(int x, int y, int width, int height) = 0;
    virtual void DisplayWindow() = 0;
    virtual size_t RunMessageLoop(size_t MaxIterations = SIZE_MAX) = 0;
    virtual void CloseWindow() = 0;
    virtual WindowHandle GetWindowHandle() = 0;
};
