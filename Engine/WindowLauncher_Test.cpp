#include "WindowLauncher.h"

#include <Windows.h>
#include <gmock/gmock-function-mocker.h>

#include "IPlatformWindowSystem.h"
#include "WindowSystemForWindowOS.h"


TEST(WindowLauncher, StartsWindowDisplaysThenRunsMessageLoopAndCanBeClosed)
{
    class MockWindowSystemForCustomOS : public IPlatformWindowSystem
    {
    public:
        MOCK_METHOD(WindowHandle, StartWindowProcess, (int, int, int, int), (override));
        MOCK_METHOD(void, DisplayWindow, (), (override));
        MOCK_METHOD(size_t, RunMessageLoop, (size_t), (override));
        MOCK_METHOD(void, CloseWindow, (), (override));
        MOCK_METHOD(WindowHandle, GetWindowHandle, (), (override));
    };
    
    MockWindowSystemForCustomOS mockWindowSystem;

    EXPECT_CALL(mockWindowSystem, StartWindowProcess(0, 0, 500, 500))
        .Times(1)
        .WillOnce(testing::Return(reinterpret_cast<WindowHandle>(1)));

    EXPECT_CALL(mockWindowSystem, DisplayWindow())
        .Times(1);

    EXPECT_CALL(mockWindowSystem, RunMessageLoop(testing::_))
        .Times(1);

    WindowLauncher MyWindowLauncher(mockWindowSystem);
    MyWindowLauncher.LaunchWindow();
}

TEST(WindowLauncher, IntegrationTest_LaunchWindowWithWindowsOS)
{
    WindowSystemForWindowsOS windowSystem;
    WindowLauncher windowsOSWindowLauncher(windowSystem);

    std::thread windowThread([&]() { windowsOSWindowLauncher.LaunchWindow(); });
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    
    HWND windowHandle = reinterpret_cast<HWND>(windowSystem.GetWindowHandle());
    EXPECT_TRUE(IsWindowVisible(windowHandle));

    windowSystem.CloseWindow();
    windowThread.join();
}