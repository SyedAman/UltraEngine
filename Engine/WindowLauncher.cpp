// Copyright Syed Aman. All Rights Reserved.
#include "WindowLauncher.h"

#include <Windows.h>

#include "IPlatformWindowSystem.h"


void WindowLauncher::LaunchWindow()
{
    PlatformWindowSystem.StartWindowProcess(0, 0, 500, 500);
    PlatformWindowSystem.DisplayWindow();
    PlatformWindowSystem.RunMessageLoop();
}
