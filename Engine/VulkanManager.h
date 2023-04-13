#pragma once
#include <vulkan/vulkan_core.h>


class IVulkanAPI;

class VulkanManager
{
    IVulkanAPI* VulkanWrapper;

public:
    VulkanManager(IVulkanAPI* VulkanWrapper) : VulkanWrapper(VulkanWrapper) {}
    
    VkPhysicalDevice SelectPhysicalDevice();
};
