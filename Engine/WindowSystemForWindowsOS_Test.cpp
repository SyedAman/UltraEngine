#include <functional>
#include <gmock/gmock-function-mocker.h>

#include "IWindowsAPI.h"
#include "Windows.h"
#include "WindowSystemForWindowOS.h"
#include "gtest/gtest.h"


TEST(WindowSystem, StartWindowProcess)
{
    WindowSystemForWindowsOS WindowSystem;
    WindowHandle WindowHandle = WindowSystem.StartWindowProcess(0, 0, 500, 500);

    EXPECT_TRUE(WindowHandle != nullptr);
    DestroyWindow(reinterpret_cast<HWND>(WindowHandle));
}

TEST(WindowSystem, DisplayWindow)
{
    WindowSystemForWindowsOS WindowSystem;
    WindowHandle WindowHandle = WindowSystem.StartWindowProcess(0, 0, 500, 500);

    WindowSystem.DisplayWindow();

    EXPECT_TRUE(IsWindowVisible(reinterpret_cast<HWND>(WindowHandle)));
    DestroyWindow(reinterpret_cast<HWND>(WindowHandle));
}

TEST(WindowSystem, ShouldCreateWindowWithCorrectSizeAndPosition)
{
    int x = 100;
    int y = 100;
    int width = 800;
    int height = 600;

    WindowSystemForWindowsOS WindowSystem;
    WindowHandle WindowHandle = WindowSystem.StartWindowProcess(x, y, width, height);

    RECT WindowRect;
    GetWindowRect(reinterpret_cast<HWND>(WindowHandle), &WindowRect);

    EXPECT_EQ(WindowRect.left, x);
    EXPECT_EQ(WindowRect.top, y);
    EXPECT_EQ(WindowRect.right - WindowRect.left, width);
    EXPECT_EQ(WindowRect.bottom - WindowRect.top, height);

    DestroyWindow(reinterpret_cast<HWND>(WindowHandle));
}

// TODO: See if this can be moved inside the unit test.
#define WM_TEST_MESSAGE (WM_USER + 1)

TEST(WindowSystem, MessageLoopShouldProcessMessages)
{
    WindowSystemForWindowsOS WindowSystem;
    WindowHandle WindowHandle = WindowSystem.StartWindowProcess(0, 0, 500, 500);
    WindowSystem.DisplayWindow();

    bool testMessageProcessed = false;
    std::function<void()> customBehavior = [&testMessageProcessed] {
        testMessageProcessed = true;
    };
    SetCustomBehaviorForWindow(reinterpret_cast<HWND>(WindowHandle), customBehavior);

    PostMessage(reinterpret_cast<HWND>(WindowHandle), WM_TEST_MESSAGE, 0, 0);

    WindowSystem.RunMessageLoop(1);

    EXPECT_TRUE(testMessageProcessed);

    DestroyWindow(reinterpret_cast<HWND>(WindowHandle));
}

#undef WM_TEST_MESSAGE

class WindowSystemParameterizedTest : public testing::TestWithParam<UINT> {};
TEST_P(WindowSystemParameterizedTest, RunMessageLoopShouldExitOnWM_QUITAndWM_CLOSEAndReturnNumberOfIterations)
{
    class MockWindowsAPIWrapper : public IWindowsAPI
    {
    public:
        MOCK_METHOD(BOOL, GetMessage, (LPMSG LoopMessage), (override));
    };
    
    MockWindowsAPIWrapper mockWindowsAPI;
    WindowSystemForWindowsOS windowSystem(mockWindowsAPI);

    ON_CALL(mockWindowsAPI, GetMessage)
        .WillByDefault([](LPMSG LoopMessage) {
            LoopMessage->message = GetParam();
            return TRUE;
        });

    size_t maxIterations = 10;
    size_t actualIterations = windowSystem.RunMessageLoop(maxIterations);

    EXPECT_EQ(actualIterations, 1);
}
INSTANTIATE_TEST_SUITE_P(
    WindowSystem,
    WindowSystemParameterizedTest,
    testing::Values(WM_QUIT, WM_CLOSE)
);
