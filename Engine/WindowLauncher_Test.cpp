#include "WindowLauncher.h"

#include <Windows.h>
#include <gmock/gmock-function-mocker.h>

#include "IPlatformWindowSystem.h"


TEST(WindowSystem, StartsWindowDisplaysThenRunsMessageLoopAndCanBeClosed)
{
    class MockWindowSystemForCustomOS : public IPlatformWindowSystem
    {
    public:
        MOCK_METHOD(WindowHandle, StartWindowProcessNew, (int, int, int, int), (override));
        MOCK_METHOD(void, DisplayWindowNew, (), (override));
        MOCK_METHOD(void, RunMessageLoop, (size_t), (override));
        MOCK_METHOD(void, CloseWindow, (), (override));
    };
    
    MockWindowSystemForCustomOS mockWindowSystem;

    EXPECT_CALL(mockWindowSystem, StartWindowProcessNew(0, 0, 500, 500))
        .Times(1)
        .WillOnce(testing::Return(reinterpret_cast<WindowHandle>(1)));

    EXPECT_CALL(mockWindowSystem, DisplayWindowNew())
        .Times(1);

    EXPECT_CALL(mockWindowSystem, RunMessageLoop(testing::_))
        .Times(1);

    WindowLauncher MyWindowLauncher(mockWindowSystem);
    MyWindowLauncher.LaunchWindow();
}