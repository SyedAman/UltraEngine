#pragma once


class IRenderHardwareInterface
{
public:
    virtual ~IRenderHardwareInterface() = default;
    virtual void* CreateInstance() = 0;
};
