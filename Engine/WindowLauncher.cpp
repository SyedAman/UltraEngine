#include "WindowLauncher.h"

#include <Windows.h>

#include "IPlatformSpecificWindowSystem.h"


void WindowLauncher::LaunchWindow()
{
    HWND WindowHandle = PlatformSpecificWindowSystem.StartWindowProcess(0, 0, 500, 500);
    PlatformSpecificWindowSystem.DisplayWindow(WindowHandle);
    PlatformSpecificWindowSystem.RunMessageLoop();
}

