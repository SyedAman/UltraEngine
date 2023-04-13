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
