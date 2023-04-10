#include "RenderHardwareInterface.h"

#include <gtest/gtest.h>
// #include <gmock/gmock.h>


TEST(RenderHardwareInterface, CreateVulkanInstanceReturnsNewVulkanInstance) {
    RenderHardwareInterface rhi;
    VkInstance instance = rhi.CreateVulkanInstance();
    ASSERT_TRUE(instance != VK_NULL_HANDLE);
}

// class MockRenderHardwareInterface : public IRenderHardwareInterface {
// public:
//     MOCK_METHOD(VkInstance, CreateVulkanInstance, (), (override));
// };
//
// TEST(RenderHardwareInterface, ThrowsErrorWhenCreateVulkanInstanceFails) {
//     MockRenderHardwareInterface mockRHI;
//
//     // Set the expectation for the CreateVulkanInstance method
//     EXPECT_CALL(mockRHI, CreateVulkanInstance())
//         .Times(1)
//         .WillOnce(::testing::Throw(std::runtime_error("Failed to create Vulkan instance.")));
//
//     ASSERT_THROW(mockRHI.CreateVulkanInstance(), std::runtime_error);
// }