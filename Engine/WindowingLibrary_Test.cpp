#include "WindowingLibrary.h"

#include <functional>
#include <gmock/gmock-function-mocker.h>

#include "Windows.h"
#include "gtest/gtest.h"

TEST(WindowSystem, StartWindowProcess)
{
    WindowSystemForWindowsOS WindowSystem;
    HWND WindowHandle = WindowSystem.StartWindowProcessX(0, 0, 500, 500);

    EXPECT_TRUE(WindowHandle != NULL);
    DestroyWindow(WindowHandle);
}

TEST(WindowSystem, DisplayWindow)
{
    WindowSystemForWindowsOS WindowSystem;
    HWND WindowHandle = WindowSystem.StartWindowProcessX(0, 0, 500, 500);

    WindowSystem.DisplayWindowX(WindowHandle);

    EXPECT_TRUE(IsWindowVisible(WindowHandle));
    DestroyWindow(WindowHandle);
}

TEST(WindowSystem, ShouldCreateWindowWithCorrectSizeAndPosition)
{
    int x = 100;
    int y = 100;
    int width = 800;
    int height = 600;

    WindowSystemForWindowsOS WindowSystem;
    HWND WindowHandle = WindowSystem.StartWindowProcessX(x, y, width, height);

    RECT WindowRect;
    GetWindowRect(WindowHandle, &WindowRect);

    EXPECT_EQ(WindowRect.left, x);
    EXPECT_EQ(WindowRect.top, y);
    EXPECT_EQ(WindowRect.right - WindowRect.left, width);
    EXPECT_EQ(WindowRect.bottom - WindowRect.top, height);

    DestroyWindow(WindowHandle);
}

#define WM_TEST_MESSAGE (WM_USER + 1)

TEST(WindowSystem, MessageLoop)
{
    WindowSystemForWindowsOS WindowSystem;
    HWND WindowHandle = WindowSystem.StartWindowProcessX(0, 0, 500, 500);
    WindowSystem.DisplayWindowX(WindowHandle);

    bool testMessageProcessed = false;
    std::function<void()> customBehavior = [&testMessageProcessed] {
        testMessageProcessed = true;
    };
    SetCustomBehaviorForWindow(WindowHandle, customBehavior);

    PostMessage(WindowHandle, WM_TEST_MESSAGE, 0, 0);

    WindowSystem.RunMessageLoopX(1);

    EXPECT_TRUE(testMessageProcessed);

    DestroyWindow(WindowHandle);
}

class MockWindowSystemForCustomOS : public IPlatformSpecificWindowSystem
{
public:
    MOCK_METHOD(HWND, StartWindowProcessX, (int, int, int, int), (override));
    MOCK_METHOD(void, DisplayWindowX, (HWND), (override));
    MOCK_METHOD(void, RunMessageLoopX, (size_t), (override));
    MOCK_METHOD(void, CloseWindowX, (), (override));
};

TEST(WindowSystem, LaunchWindow_CallsStartWindowProcessWithCorrectParameters)
{
    MockWindowSystemForCustomOS mockWindowSystem;
    EXPECT_CALL(mockWindowSystem, StartWindowProcessX(0, 0, 500, 500))
        .Times(1)
        .WillOnce(testing::Return(reinterpret_cast<HWND>(1)));

    EXPECT_CALL(mockWindowSystem, DisplayWindowX(testing::_))
        .Times(1);

    EXPECT_CALL(mockWindowSystem, RunMessageLoopX(testing::_))
        .Times(1);

    std::thread exitThread([&]()
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        mockWindowSystem.CloseWindowX();
    });
    
    WindowLauncher MyWindowLauncher(mockWindowSystem);
    MyWindowLauncher.LaunchWindow();

    exitThread.join();
}