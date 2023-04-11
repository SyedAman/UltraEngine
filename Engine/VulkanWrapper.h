#pragma once

#include <vulkan/vulkan_core.h>


class IVulkanWrapper
{
public:
    virtual ~IVulkanWrapper() = default;

    virtual VkResult CreateInstance(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkInstance* pInstance) = 0;
};


class VulkanWrapper : public IVulkanWrapper
{
public:
    VkResult CreateInstance(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkInstance* pInstance) override
    {
        return vkCreateInstance(pCreateInfo, pAllocator, pInstance);
    }
};