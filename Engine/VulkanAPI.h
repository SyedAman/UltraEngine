#pragma once

#include "IVulkanAPI.h"


class VulkanAPI : public IVulkanAPI
{
public:
    void* CreateInstance() override;
    
    VkApplicationInfo FillOutApplicationInfo() override;
    VkInstanceCreateInfo CreateInstanceCreateInfo(VkApplicationInfo appInfo) override;
};

