#include <gmock/gmock-function-mocker.h>

#include "RenderHardwareInterface.h"
#include "IVulkanAPI.h"


class MockGraphicsAPI : public IVulkanAPI
{
public:
    MOCK_METHOD(void*, CreateInstance, (), (override));
};

TEST(RenderHardwareInterface, CreateInstanceReturnsNewInstance)
{
    MockGraphicsAPI mockGraphicsAPI;
    ON_CALL(mockGraphicsAPI, CreateInstance)
        .WillByDefault(testing::Return(reinterpret_cast<void*>(1)));
    
    RenderHardwareInterface rhi(&mockGraphicsAPI);
    void* instance = rhi.CreateInstance();
    ASSERT_TRUE(instance != nullptr);
}


TEST(RenderHardwareInterface, CreateInstanceThrowsExceptionWhenInstanceIsntValid)
{
    MockGraphicsAPI mockGraphicsAPI;
    ON_CALL(mockGraphicsAPI, CreateInstance)
        .WillByDefault(testing::Return(nullptr));
    
    RenderHardwareInterface rhi(&mockGraphicsAPI);
    ASSERT_THROW(rhi.CreateInstance(), std::runtime_error);
}