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


