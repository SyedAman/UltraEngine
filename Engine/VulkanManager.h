#pragma once
#include <vulkan/vulkan_core.h>


class IVulkanWrapper;

class VulkanManager
{
    IVulkanWrapper* VulkanWrapper;

public:
    VulkanManager(IVulkanWrapper* VulkanWrapper) : VulkanWrapper(VulkanWrapper) {}
    
    VkPhysicalDevice SelectPhysicalDevice()
    {
        return VkPhysicalDevice();
    }
};
