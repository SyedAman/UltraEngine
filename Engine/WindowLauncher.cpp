#include "WindowLauncher.h"

#include <Windows.h>

#include "IPlatformWindowSystem.h"


void WindowLauncher::LaunchWindow()
{
    PlatformWindowSystem.StartWindowProcessNew(0, 0, 500, 500);
    PlatformWindowSystem.DisplayWindowNew();
    PlatformWindowSystem.RunMessageLoop();
}

