#include "WindowLauncher.h"

#include <Windows.h>
#include <gmock/gmock-function-mocker.h>

#include "IPlatformWindowSystem.h"


// TODO: This is an integration test. Figure out what to do with tests like these.
TEST(WindowSystem, StartsWindowDisplaysThenRunsMessageLoopAndCanBeClosed)
{
    class MockWindowSystemForCustomOS : public IPlatformWindowSystem
    {
    public:
        MOCK_METHOD(HWND, StartWindowProcess, (int, int, int, int), (override));
        MOCK_METHOD(void, DisplayWindow, (HWND), (override));
        MOCK_METHOD(void, RunMessageLoop, (size_t), (override));
        MOCK_METHOD(void, CloseWindow, (), (override));
    };
    
    MockWindowSystemForCustomOS mockWindowSystem;
    EXPECT_CALL(mockWindowSystem, StartWindowProcess(0, 0, 500, 500))
        .Times(1)
        .WillOnce(testing::Return(reinterpret_cast<HWND>(1)));

    EXPECT_CALL(mockWindowSystem, DisplayWindow(testing::_))
        .Times(1);

    EXPECT_CALL(mockWindowSystem, RunMessageLoop(testing::_))
        .Times(1);

    std::thread exitThread([&]()
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        mockWindowSystem.CloseWindow();
    });
    
    WindowLauncher MyWindowLauncher(mockWindowSystem);
    MyWindowLauncher.LaunchWindow();

    exitThread.join();

    EXPECT_FALSE(IsWindow(reinterpret_cast<HWND>(1)));
}