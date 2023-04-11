#pragma once
#include <functional>
#include <Windows.h>


class IPlatformWindowSystem
{
public:
    virtual ~IPlatformWindowSystem() = default;
    virtual HWND StartWindowProcess(int x, int y, int width, int height) = 0;
    virtual void DisplayWindow(HWND windowHandle) = 0;
    virtual void RunMessageLoop(size_t MaxIterations = SIZE_MAX) = 0;
    virtual void CloseWindow() = 0;
};
