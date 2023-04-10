#include <Windows.h>

LRESULT CALLBACK OnReceivedMessageToWindow(
        HWND HandleToWindowReceivingTheMessage,
        UINT TypeOfMessageSentToTheWindowMouseClickKeyPressPaintDestroy,
        WPARAM AdditionalMessageInformation,
        LPARAM AdditionalMessageInformation2
    )
{
    return DefWindowProc(HandleToWindowReceivingTheMessage, TypeOfMessageSentToTheWindowMouseClickKeyPressPaintDestroy, AdditionalMessageInformation, AdditionalMessageInformation2);
}
    

HWND StartWindowProcessAndGetHandle(const int X, const int Y, const int Width, const int Height)
{
    const HINSTANCE ExecutableInstanceThatOwnsTheWindow = GetModuleHandle(NULL);

    WNDCLASS WindowBehaviorsAndAttributes = { };
    WindowBehaviorsAndAttributes.lpfnWndProc = OnReceivedMessageToWindow;
    WindowBehaviorsAndAttributes.hInstance = ExecutableInstanceThatOwnsTheWindow;
    WindowBehaviorsAndAttributes.lpszClassName = L"DummyWindowClass";

    RegisterClass(&WindowBehaviorsAndAttributes);
    
    HWND WindowHandle = NULL;
    WindowHandle = CreateWindowEx(
        0,
        L"DummyWindowClass",
        L"DummyWindow",
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