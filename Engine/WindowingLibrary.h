#pragma once
#include <functional>
#include <Windows.h>


class IPlatformSpecificWindowSystem
{
public:
    virtual ~IPlatformSpecificWindowSystem() = default;
    virtual HWND StartWindowProcessX(int x, int y, int width, int height) = 0;
    virtual void DisplayWindowX(HWND windowHandle) = 0;
    virtual void RunMessageLoopX(int MaxIterations = SIZE_MAX) = 0;
    virtual void CloseWindowX() = 0;
};

class WindowSystemForWindowsOS : public IPlatformSpecificWindowSystem
{
    HWND WindowHandle = NULL;

public:
    HWND StartWindowProcessX(int x, int y, int width, int height) override;
    void DisplayWindowX(HWND windowHandle) override;
    void RunMessageLoopX(int MaxIterations = SIZE_MAX) override;
    void CloseWindowX() override { PostMessage(WindowHandle, WM_CLOSE, 0, 0); }
};

class WindowLauncher
{
    IPlatformSpecificWindowSystem& PlatformSpecificWindowSystem;
    
public:
    WindowLauncher(IPlatformSpecificWindowSystem& platformSpecificWindowSystem) : PlatformSpecificWindowSystem(platformSpecificWindowSystem) {}

    void LaunchWindow();
};


LRESULT CALLBACK OnReceivedMessageToWindow(
    HWND HandleToWindowReceivingTheMessage,
    UINT TypeOfMessageSentToTheWindowMouseClickKeyPressPaintDestroy,
    WPARAM AdditionalMessageInformation,
    LPARAM AdditionalMessageInformation2
);

HWND StartWindowProcess(int X, int Y, int Width, int Height);

void DisplayWindow(HWND WindowHandle);

void SetCustomBehaviorForWindow(HWND windowHandle, std::function<void()>& customBehavior);

FORCEINLINE void RunMessageLoop(size_t MaxIterations = SIZE_MAX)
{
    MSG Message;
    size_t Iterations = 0;
    while (Iterations < MaxIterations && GetMessage(&Message, NULL, 0, 0))
    {
        TranslateMessage(&Message);
        DispatchMessage(&Message);
        ++Iterations;
    }
}
