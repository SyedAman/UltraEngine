#include "RenderHardwareInterface.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "IVulkanAPI.h"
#include "VulkanAPI.h"


TEST(RenderHardwareInterface, CreateVulkanInstanceReturnsNewVulkanInstance)
{
    RenderHardwareInterface rhi(new VulkanAPI());
    VkInstance instance = rhi.CreateInstance();
    ASSERT_TRUE(instance != VK_NULL_HANDLE);
}


class MockVulkanWrapper : public IVulkanAPI
{
public:
    MOCK_METHOD(VkResult, CreateInstance, (const VkInstanceCreateInfo*, const VkAllocationCallbacks*,
    VkInstance*), (override));
};

class MockSomeOtherGraphicsAPIWrapper : public IGraphicsAPI
{
public:
    MOCK_METHOD(void*, CreateInstance, (), (override));
};

class RenderHardwareInterfaceParameterizedTest : public testing::TestWithParam<std::tuple<VkResult, IGraphicsAPI*>> {};
TEST_P(RenderHardwareInterfaceParameterizedTest, CreateInstanceThrowsExceptionOnOutOfHostMemory)
{
    IGraphicsAPI* mockGraphicsAPI = std::get<1>(GetParam());
    RenderHardwareInterface rhi(&mockGraphicsAPI);

    ON_CALL(*static_cast<MockVulkanWrapper*>(mockGraphicsAPI), CreateInstance)
        .WillByDefault(testing::Return(std::get<0>(GetParam())));

    ASSERT_THROW(rhi.CreateInstance(), std::runtime_error);
}
INSTANTIATE_TEST_SUITE_P(
    RenderHardwareInterfaceErrorCodes,
    RenderHardwareInterfaceParameterizedTest,
    testing::Combine(
        testing::Values(
            VK_ERROR_OUT_OF_HOST_MEMORY,
            VK_ERROR_OUT_OF_DEVICE_MEMORY,
            VK_ERROR_INITIALIZATION_FAILED
        ),
        testing::Values(
            static_cast<IGraphicsAPI*>(new MockVulkanWrapper()),
            static_cast<IGraphicsAPI*>(new MockSomeOtherGraphicsAPIWrapper())
        )
    )
);
