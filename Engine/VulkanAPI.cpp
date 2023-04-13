#include "VulkanAPI.h"

#include <vector>


VkApplicationInfo VulkanAPI::FillOutApplicationInfo()
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

VkInstanceCreateInfo VulkanAPI::CreateInstanceCreateInfo(VkApplicationInfo appInfo)
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

void* VulkanAPI::CreateInstance()
{
    VkApplicationInfo appInfo = FillOutApplicationInfo();
    VkInstanceCreateInfo createInfo = CreateInstanceCreateInfo(appInfo);

    VkInstance instance;
    VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);

    if (result != VK_SUCCESS)
    {
        return nullptr;
    }

    return static_cast<void*>(instance);
}
