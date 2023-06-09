// Copyright Syed Aman. All Rights Reserved.
#include "RenderHardwareInterface.h"

#include <stdexcept>

void* RenderHardwareInterface::CreateInstance()
{
    void* instance = GraphicsAPI->CreateInstance();
    if (instance == nullptr)
    {
        throw std::runtime_error("Failed to create graphics api instance!");
    }
    
    return instance;
}

