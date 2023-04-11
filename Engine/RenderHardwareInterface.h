#pragma once

#include "VulkanWrapper.h"


class IRenderHardwareInterface
{
public:
    virtual ~IRenderHardwareInterface() = default;
    virtual VkInstance CreateVulkanInstance() = 0;
};

class RenderHardwareInterface : public IRenderHardwareInterface
{
    VkApplicationInfo FillOutApplicationInfo();
    VkInstanceCreateInfo CreateInstanceCreateInfo(VkApplicationInfo appInfo);

    IVulkanWrapper* m_VulkanWrapper;

public:
    RenderHardwareInterface(IVulkanWrapper* vulkanWrapper) : m_VulkanWrapper(vulkanWrapper) {}

    VkInstance CreateVulkanInstance() override;
};
