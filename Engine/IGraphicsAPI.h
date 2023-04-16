#pragma once

class IGraphicsAPI
{
public:
    virtual ~IGraphicsAPI() = default;
    virtual void* CreateInstance() = 0;
};