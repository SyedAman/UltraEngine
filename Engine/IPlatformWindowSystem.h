#pragma once
#include <functional>

using WindowHandle = void*;

class IPlatformWindowSystem
{
public:
    virtual ~IPlatformWindowSystem() = default;
    virtual WindowHandle StartWindowProcessNew(int x, int y, int width, int height) = 0;
    virtual void DisplayWindowNew(WindowHandle windowHandle) = 0;
    virtual void RunMessageLoop(size_t MaxIterations = SIZE_MAX) = 0;
    virtual void CloseWindow() = 0;
};
