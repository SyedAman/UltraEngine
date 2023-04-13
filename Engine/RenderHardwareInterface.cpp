#include "RenderHardwareInterface.h"

#include <stdexcept>

void* RenderHardwareInterface::CreateInstance()
{
    void* instance = m_GraphicsAPI->CreateInstance();
    if (instance == nullptr)
    {
        throw std::runtime_error("Failed to create graphics api instance!");
    }
    
    return instance;
}



