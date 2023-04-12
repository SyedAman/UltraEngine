#pragma once

#include "IVulkanAPI.h"


class VulkanWrapper : public IVulkanAPI
{
public:
    VkResult CreateInstance(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkInstance* pInstance) override
    {
        return vkCreateInstance(pCreateInfo, pAllocator, pInstance);
    }
};
