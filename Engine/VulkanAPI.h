// Copyright Syed Aman. All Rights Reserved.
/**
 * A wrapper for the Vulkan SDK.
 */

#pragma once
#include "IVulkanAPI.h"

class VulkanAPI : public IVulkanAPI
{
    VkApplicationInfo FillOutApplicationInfo();
    VkInstanceCreateInfo CreateInstanceCreateInfo(VkApplicationInfo appInfo);

public:
    void* CreateInstance() override;

    VkPhysicalDevice SelectPhysicalDevice();
};
