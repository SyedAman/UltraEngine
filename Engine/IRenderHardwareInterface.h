// Copyright Syed Aman. All Rights Reserved.
#pragma once

class IRenderHardwareInterface
{
public:
    virtual ~IRenderHardwareInterface() = default;
    virtual void* CreateInstance() = 0;
};
