#pragma once
#include <functional>
#include <Windows.h>

LRESULT CALLBACK OnReceivedMessageToWindow(
    HWND HandleToWindowReceivingTheMessage,
    UINT TypeOfMessageSentToTheWindowMouseClickKeyPressPaintDestroy,
    WPARAM AdditionalMessageInformation,
    LPARAM AdditionalMessageInformation2
);

HWND StartWindowProcessAndGetHandle(int X, int Y, int Width, int Height);

void DisplayWindow(HWND WindowHandle);

void SetCustomBehaviorForWindow(HWND windowHandle, std::function<void()>& customBehavior);

inline void RunMessageLoop(size_t MaxIterations = SIZE_MAX)
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