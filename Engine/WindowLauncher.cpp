#include "WindowLauncher.h"

#include <Windows.h>

#include "IPlatformWindowSystem.h"


void WindowLauncher::LaunchWindow()
{
    HWND WindowHandle = PlatformWindowSystem.StartWindowProcess(0, 0, 500, 500);
    PlatformWindowSystem.DisplayWindow(WindowHandle);
    PlatformWindowSystem.RunMessageLoop();
}

