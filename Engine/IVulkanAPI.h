#pragma once
#include <vulkan/vulkan_core.h>

class IVulkanAPI
{
public:
    // TODO: Add unit tests for this destructor.
    virtual ~IVulkanAPI() = default;

    virtual VkResult CreateInstance(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkInstance* pInstance) = 0;
};