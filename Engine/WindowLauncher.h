#pragma once

class IPlatformSpecificWindowSystem;


class WindowLauncher
{
    IPlatformSpecificWindowSystem& PlatformSpecificWindowSystem;
    
public:
    WindowLauncher(IPlatformSpecificWindowSystem& platformSpecificWindowSystem) : PlatformSpecificWindowSystem(platformSpecificWindowSystem) {}

    void LaunchWindow();
};

