#include "RenderHardwareInterface.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "VulkanWrapper.h"


TEST(RenderHardwareInterface, CreateVulkanInstanceReturnsNewVulkanInstance)
{
    RenderHardwareInterface rhi(new VulkanWrapper());
    VkInstance instance = rhi.CreateVulkanInstance();
    ASSERT_TRUE(instance != VK_NULL_HANDLE);
}

class MockVulkanWrapper : public IVulkanAPI
{
public:
    MOCK_METHOD(VkResult, CreateInstance, (const VkInstanceCreateInfo*, const VkAllocationCallbacks*,
    VkInstance*), (override));
};

class RenderHardwareInterfaceParameterizedTest : public testing::TestWithParam<VkResult> {};
TEST_P(RenderHardwareInterfaceParameterizedTest, CreateVulkanInstanceThrowsExceptionOnOutOfHostMemory)
{
    
    MockVulkanWrapper mockVulkanWrapper;
    RenderHardwareInterface rhi(&mockVulkanWrapper);

    ON_CALL(mockVulkanWrapper, CreateInstance)
        .WillByDefault(testing::Return(GetParam()));

    ASSERT_THROW(rhi.CreateVulkanInstance(), std::runtime_error);
}
INSTANTIATE_TEST_SUITE_P(
    RenderHardwareInterfaceErrorCodes,
    RenderHardwareInterfaceParameterizedTest,
    testing::Values(
        VK_ERROR_OUT_OF_HOST_MEMORY,
        VK_ERROR_OUT_OF_DEVICE_MEMORY,
        VK_ERROR_INITIALIZATION_FAILED
    )
);
