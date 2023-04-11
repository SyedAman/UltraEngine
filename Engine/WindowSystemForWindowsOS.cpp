﻿#include <Windows.h>

#include "WindowSystemForWindowOS.h"


WindowHandle WindowSystemForWindowsOS::StartWindowProcessNew(int X, int Y, int Width, int Height)
{
    const HINSTANCE ExecutableInstanceThatOwnsTheWindow = GetModuleHandle(NULL);

    WNDCLASS WindowBehaviorsAndAttributes = { };
    WindowBehaviorsAndAttributes.lpfnWndProc = OnReceivedMessageToWindow;
    WindowBehaviorsAndAttributes.hInstance = ExecutableInstanceThatOwnsTheWindow;
    WindowBehaviorsAndAttributes.lpszClassName = "DummyWindowClass";

    RegisterClass(&WindowBehaviorsAndAttributes);
    
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

    return reinterpret_cast<::WindowHandle>(WindowHandle);
}

// TODO: Remove the parameter since we don't need it.
void WindowSystemForWindowsOS::DisplayWindowNew(::WindowHandle windowHandle)
{
    ShowWindow(WindowHandle, SW_SHOW);
    UpdateWindow(WindowHandle);
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

void SetCustomBehaviorForWindow(HWND windowHandle, std::function<void()>& customBehavior)
{
    SetWindowLongPtr(windowHandle, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(&customBehavior));
}
