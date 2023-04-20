// Copyright Syed Aman. All Rights Reserved.
#include <gmock/gmock-function-mocker.h>

#include "VulkanAPI.h"
#include "RenderHardwareInterface.h"


class MockVulkanWrapper : public IGraphicsAPI
{
public:
    MOCK_METHOD(void*, CreateInstance, (), (override));
};

TEST(VulkanAPI, CreateNewInstanceReturnsNewVulkanInstance)
{
    VulkanAPI vulkanAPI;
    VkInstance instance = reinterpret_cast<VkInstance>(vulkanAPI.CreateInstance());
    ASSERT_TRUE(instance != VK_NULL_HANDLE);
}

class VulkanAPIParameterizedTest : public testing::TestWithParam<VkResult> {};
TEST_P(VulkanAPIParameterizedTest, CreateInstanceThrowsExceptionOnOutOfHostMemory)
{
    MockVulkanWrapper mockVulkanAPI;
    RenderHardwareInterface rhi(&mockVulkanAPI);

    ON_CALL(mockVulkanAPI, CreateInstance)
        .WillByDefault(testing::Invoke([result = GetParam()]() -> void* {
            if (result != VK_SUCCESS) {
                return nullptr;
            }
            return reinterpret_cast<void*>(1);
        }));

    ASSERT_THROW(rhi.CreateInstance(), std::runtime_error);
}
INSTANTIATE_TEST_SUITE_P(
    VulkanAPIErrorCodes,
    VulkanAPIParameterizedTest,
    testing::Values(
        VK_ERROR_OUT_OF_HOST_MEMORY,
        VK_ERROR_OUT_OF_DEVICE_MEMORY,
        VK_ERROR_INITIALIZATION_FAILED
    )
);

TEST(VulkanAPI, ShouldReturnAValidPhysicalDevice)
{
    VulkanAPI vulkanAPI;

    VkPhysicalDevice PhysicalDevice = vulkanAPI.SelectPhysicalDevice();
    EXPECT_NE(PhysicalDevice, VK_NULL_HANDLE);
}

// TODO: ShouldThrowAnErrorIfThereAreNoDevices
// TODO: ShouldFindDiscreteGPU
