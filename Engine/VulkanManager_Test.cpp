#include "VulkanManager.h"

#include <gtest/gtest.h>
#include <vulkan/vulkan_core.h>

#include "VulkanAPI.h"

TEST(VulkanManager, ShouldReturnAValidPhysicalDevice)
{
    VulkanAPI VulkanWrapper;
    VulkanManager MyVulkanManager(&VulkanWrapper);

    VkPhysicalDevice PhysicalDevice = MyVulkanManager.SelectPhysicalDevice();
    EXPECT_NE(PhysicalDevice, VK_NULL_HANDLE);
}

TEST(VulkanManager, ShouldThrowAnErrorIfThereAreNoDevices)
{
    // Mock the get physical devices to return 0
}

TEST(VulkanManager, ShouldFindDiscreteGPU)
{
    
}
