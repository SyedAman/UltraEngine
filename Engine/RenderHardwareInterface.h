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
    IVulkanAPI* m_VulkanWrapper;

    VkApplicationInfo FillOutApplicationInfo();
    VkInstanceCreateInfo CreateInstanceCreateInfo(VkApplicationInfo appInfo);

public:
    RenderHardwareInterface(IVulkanAPI* VulkanWrapper) : m_VulkanWrapper(VulkanWrapper) {}

    VkInstance CreateVulkanInstance() override;
};
