#pragma once

class IPlatformWindowSystem;


class WindowLauncher
{
    IPlatformWindowSystem& PlatformWindowSystem;
    
public:
    WindowLauncher(IPlatformWindowSystem& InPlatformWindowSystem) : PlatformWindowSystem(InPlatformWindowSystem) {}

    void LaunchWindow();
};

