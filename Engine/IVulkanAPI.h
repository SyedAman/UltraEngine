#pragma once
#include <vulkan/vulkan_core.h>

#include "IGraphicsAPI.h"

class IVulkanAPI : public IGraphicsAPI
{
public:
    // TODO: Add unit tests for this destructor.
    virtual ~IVulkanAPI() = default;

    virtual VkApplicationInfo FillOutApplicationInfo() = 0;
    virtual VkInstanceCreateInfo CreateInstanceCreateInfo(VkApplicationInfo appInfo) = 0;
};
