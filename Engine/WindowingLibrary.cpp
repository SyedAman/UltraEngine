#include <functional>
#include <Windows.h>


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

// Can pass a custom callback function to override the default behavior
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

void SetCustomBehaviorForWindow(HWND windowHandle, std::function<void()>& customBehavior)
{
    SetWindowLongPtr(windowHandle, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(&customBehavior));
}