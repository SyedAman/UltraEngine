// Copyright Syed Aman. All Rights Reserved.
#pragma once

class IPlatformWindowSystem;


class WindowLauncher
{
    IPlatformWindowSystem& PlatformWindowSystem;
    
public:
    WindowLauncher(IPlatformWindowSystem& InPlatformWindowSystem) : PlatformWindowSystem(InPlatformWindowSystem) {}

    void LaunchWindow();
};

