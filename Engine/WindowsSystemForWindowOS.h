#pragma once
#include "IPlatformWindowSystem.h"


class WindowSystemForWindowsOS : public IPlatformWindowSystem
{
    HWND WindowHandle = NULL;

public:
    HWND StartWindowProcess(int x, int y, int width, int height) override;
    void DisplayWindow(HWND windowHandle) override;
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
    void CloseWindow() override { PostMessage(WindowHandle, WM_CLOSE, 0, 0); }
};

LRESULT CALLBACK OnReceivedMessageToWindow(
    HWND HandleToWindowReceivingTheMessage,
    UINT TypeOfMessageSentToTheWindowMouseClickKeyPressPaintDestroy,
    WPARAM AdditionalMessageInformation,
    LPARAM AdditionalMessageInformation2
);

void SetCustomBehaviorForWindow(HWND windowHandle, std::function<void()>& customBehavior);

