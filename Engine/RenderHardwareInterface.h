#pragma once

#include "IRenderHardwareInterface.h"
#include "VulkanWrapper.h"


class RenderHardwareInterface : public IRenderHardwareInterface
{
    IVulkanAPI* m_VulkanWrapper;

    VkApplicationInfo FillOutApplicationInfo();
    VkInstanceCreateInfo CreateInstanceCreateInfo(VkApplicationInfo appInfo);

public:
    RenderHardwareInterface(IVulkanAPI* VulkanWrapper) : m_VulkanWrapper(VulkanWrapper) {}

    VkInstance CreateVulkanInstance() override;
};
