#pragma once
#include "IPlatformWindowSystem.h"
// TODO: Fix direct dependency on concrete Windows API Wrapper.
#include "WindowsOS.h"
#include <functional>


class IOperatingSystem;

class WindowsOSWindowSystem : public IPlatformWindowSystem
{
    HWND WindowHandle = NULL;
    IOperatingSystem& WindowsAPI;

public:
    WindowsOSWindowSystem() : WindowsAPI(WindowsOS::Instance()) {}
    WindowsOSWindowSystem(IOperatingSystem& OperatingSystem) : WindowsAPI(OperatingSystem) {}
    
    ::WindowHandle StartWindowProcess(int X, int Y, int Width, int Height) override;
    void CloseWindow() override;
    void DisplayWindow() override;
    FORCEINLINE size_t RunMessageLoop(size_t MaxIterations = SIZE_MAX) override
    {
        MSG Message;
        EventMessage eventMessage;

        size_t Iterations = 0;
        while (Iterations < MaxIterations && WindowsAPI.GetEventMessage(&eventMessage))
        {
            ++Iterations;

            Message.message = eventMessage.message;
            
            if (Message.message == WM_QUIT || Message.message == WM_CLOSE)
            {
                return Iterations;
            }

            TranslateMessage(&Message);
            DispatchMessage(&Message);
        }
        
        return Iterations;
    }

    ::WindowHandle GetWindowHandle() override;
};

LRESULT CALLBACK OnReceivedMessageToWindow(
    HWND HandleToWindowReceivingTheMessage,
    UINT TypeOfMessageSentToTheWindowMouseClickKeyPressPaintDestroy,
    WPARAM AdditionalMessageInformation,
    LPARAM AdditionalMessageInformation2
);

void SetCustomBehaviorForWindow(HWND windowHandle, std::function<void()>& customBehavior);

