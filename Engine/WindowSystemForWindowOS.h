#pragma once
#include "IPlatformWindowSystem.h"


class WindowSystemForWindowsOS : public IPlatformWindowSystem
{
    HWND WindowHandle = NULL;

public:
    ::WindowHandle StartWindowProcess(int X, int Y, int Width, int Height) override;
    void CloseWindow() override { PostMessage(WindowHandle, WM_CLOSE, 0, 0); }
    void DisplayWindow() override;
    FORCEINLINE void RunMessageLoop(size_t MaxIterations = SIZE_MAX) override
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
};

LRESULT CALLBACK OnReceivedMessageToWindow(
    HWND HandleToWindowReceivingTheMessage,
    UINT TypeOfMessageSentToTheWindowMouseClickKeyPressPaintDestroy,
    WPARAM AdditionalMessageInformation,
    LPARAM AdditionalMessageInformation2
);

void SetCustomBehaviorForWindow(HWND windowHandle, std::function<void()>& customBehavior);

