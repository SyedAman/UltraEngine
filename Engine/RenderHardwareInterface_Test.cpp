#include "RenderHardwareInterface.h"

#include <gtest/gtest.h>


TEST(RenderHardwareInterface, CreateVulkanInstanceReturnsNewVulkanInstance) {
    VkInstance instance = CreateVulkanInstance();
}

