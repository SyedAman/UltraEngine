#include <gmock/gmock-function-mocker.h>

#include "IVulkanAPI.h"
#include "RenderHardwareInterface.h"


class MockVulkanWrapper : public IVulkanAPI
{
public:
    MOCK_METHOD(void*, CreateInstance, (), (override));

    MOCK_METHOD(VkApplicationInfo, FillOutApplicationInfo, (), (override));
    MOCK_METHOD(VkInstanceCreateInfo, CreateInstanceCreateInfo, (VkApplicationInfo), (override));
};

class RenderHardwareInterfaceParameterizedTest : public testing::TestWithParam<VkResult> {};
TEST_P(RenderHardwareInterfaceParameterizedTest, CreateInstanceThrowsExceptionOnOutOfHostMemory)
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
    RenderHardwareInterfaceErrorCodes,
    RenderHardwareInterfaceParameterizedTest,
    testing::Values(
        VK_ERROR_OUT_OF_HOST_MEMORY,
        VK_ERROR_OUT_OF_DEVICE_MEMORY,
        VK_ERROR_INITIALIZATION_FAILED
    )
);