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
    

HWND StartWindowProcessAndGetHandle()
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
        0, 0, 500, 500,
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
    
}