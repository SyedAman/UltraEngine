#pragma once

class IGraphicsAPI
{
public:
    virtual void* CreateInstance() = 0;
};