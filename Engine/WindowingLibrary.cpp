#include "WindowingLibrary.h"

#include <functional>
#include <Windows.h>


HWND WindowSystemForWindowsOS::StartWindowProcessX(int x, int y, int width, int height)
{
    WindowHandle = StartWindowProcess(x, y, width, height);
    return WindowHandle;
}

void WindowSystemForWindowsOS::DisplayWindowX(HWND windowHandle)
{
    DisplayWindow(windowHandle);
}

void WindowSystemForWindowsOS::RunMessageLoopX()
{
    RunMessageLoop();
}

void WindowLauncher::LaunchWindow()
{
    HWND WindowHandle = PlatformSpecificWindowSystem.StartWindowProcessX(0, 0, 500, 500);
    PlatformSpecificWindowSystem.DisplayWindowX(WindowHandle);
    PlatformSpecificWindowSystem.RunMessageLoopX();
}

LRESULT CALLBACK OnReceivedMessageToWindow(
    HWND HandleToWindowReceivingTheMessage,
    UINT TypeOfMessageSentToTheWindowMouseClickKeyPressPaintDestroy,
    WPARAM AdditionalMessageInformation,
    LPARAM AdditionalMessageInformation2
)
{
    auto customBehavior = reinterpret_cast<std::function<void()>*>(GetWindowLongPtr(HandleToWindowReceivingTheMessage, GWLP_USERDATA));
    if (customBehavior) {
        (*customBehavior)();
    }

    return DefWindowProc(HandleToWindowReceivingTheMessage, TypeOfMessageSentToTheWindowMouseClickKeyPressPaintDestroy, AdditionalMessageInformation, AdditionalMessageInformation2);
}

HWND StartWindowProcess(const int X, const int Y, const int Width, const int Height)
{
    const HINSTANCE ExecutableInstanceThatOwnsTheWindow = GetModuleHandle(NULL);

    WNDCLASS WindowBehaviorsAndAttributes = { };
    WindowBehaviorsAndAttributes.lpfnWndProc = OnReceivedMessageToWindow;
    WindowBehaviorsAndAttributes.hInstance = ExecutableInstanceThatOwnsTheWindow;
    WindowBehaviorsAndAttributes.lpszClassName = "DummyWindowClass";

    RegisterClass(&WindowBehaviorsAndAttributes);
    
    HWND WindowHandle = NULL;
    WindowHandle = CreateWindowEx(
        0,
        "DummyWindowClass",
        "DummyWindow",
        WS_OVERLAPPEDWINDOW,
        X, Y, Width, Height,
        NULL,
        NULL,
        ExecutableInstanceThatOwnsTheWindow,
        NULL
    );

    return WindowHandle;
}


void DisplayWindow(HWND WindowHandle)
{
    ShowWindow(WindowHandle, SW_SHOW);
    UpdateWindow(WindowHandle);
}

void SetCustomBehaviorForWindow(HWND windowHandle, std::function<void()>& customBehavior)
{
    SetWindowLongPtr(windowHandle, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(&customBehavior));
}
