#include "RenderHardwareInterface.h"

#include <stdexcept>
#include <vector>

VkApplicationInfo RenderHardwareInterface::FillOutApplicationInfo()
{
    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Vulkan Test";
    appInfo.pApplicationName = "My Vulkan Engine";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "Custom Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    return appInfo;
}

VkInstanceCreateInfo RenderHardwareInterface::CreateInstanceCreateInfo(VkApplicationInfo appInfo)
{
    // Specify layers and extensions
    std::vector<const char*> enabledLayers;
    std::vector<const char*> enabledExtensions;
    
    VkInstanceCreateInfo createInfo = {};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;
    createInfo.enabledLayerCount = static_cast<uint32_t>(enabledLayers.size());
    createInfo.ppEnabledLayerNames = enabledLayers.data();
    createInfo.enabledExtensionCount = static_cast<uint32_t>(enabledExtensions.size());
    createInfo.ppEnabledExtensionNames = enabledExtensions.data();

    return createInfo;
}

VkInstance RenderHardwareInterface::CreateVulkanInstance()
{
    VkApplicationInfo appInfo = FillOutApplicationInfo();
    VkInstanceCreateInfo createInfo = CreateInstanceCreateInfo(appInfo);
    
    VkInstance instance;

    VkResult Result = m_VulkanWrapper->CreateInstance(&createInfo, nullptr, &instance);
    if (Result != VK_SUCCESS)
    {
        throw std::runtime_error("Failed to create Vulkan instance!");
    }
    
    return instance;
}



