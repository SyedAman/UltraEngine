#pragma once
#include "IPlatformWindowSystem.h"
#include "WindowsAPIWrapper.h"


class IWindowsAPI;

class WindowSystemForWindowsOS : public IPlatformWindowSystem
{
    HWND WindowHandle = NULL;
    IWindowsAPI& WindowsAPI;

public:
    WindowSystemForWindowsOS() : WindowsAPI(WindowsAPIWrapper::Instance()) {}
    WindowSystemForWindowsOS(IWindowsAPI& WindowsAPI) : WindowsAPI(WindowsAPI) {}
    
    ::WindowHandle StartWindowProcess(int X, int Y, int Width, int Height) override;
    void CloseWindow() override { PostMessage(WindowHandle, WM_CLOSE, 0, 0); }
    void DisplayWindow() override;
    FORCEINLINE size_t RunMessageLoop(size_t MaxIterations = SIZE_MAX) override
    {
        MSG Message;
        size_t Iterations = 0;
        while (Iterations < MaxIterations && WindowsAPI.GetMessage(&Message))
        {
            ++Iterations;
            
            if (Message.message == WM_QUIT || Message.message == WM_CLOSE)
            {
                return Iterations;
            }

            TranslateMessage(&Message);
            DispatchMessage(&Message);
        }
        
        return Iterations;
    }

    HWND GetWindowHandle();
};

LRESULT CALLBACK OnReceivedMessageToWindow(
    HWND HandleToWindowReceivingTheMessage,
    UINT TypeOfMessageSentToTheWindowMouseClickKeyPressPaintDestroy,
    WPARAM AdditionalMessageInformation,
    LPARAM AdditionalMessageInformation2
);

void SetCustomBehaviorForWindow(HWND windowHandle, std::function<void()>& customBehavior);

