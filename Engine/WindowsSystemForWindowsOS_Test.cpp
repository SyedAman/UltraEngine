#include <functional>
#include <gmock/gmock-function-mocker.h>

#include "Windows.h"
#include "WindowsSystemForWindowOS.h"
#include "gtest/gtest.h"


TEST(WindowSystem, StartWindowProcess)
{
    WindowSystemForWindowsOS WindowSystem;
    HWND WindowHandle = WindowSystem.StartWindowProcess(0, 0, 500, 500);

    EXPECT_TRUE(WindowHandle != NULL);
    DestroyWindow(WindowHandle);
}

TEST(WindowSystem, DisplayWindow)
{
    WindowSystemForWindowsOS WindowSystem;
    HWND WindowHandle = WindowSystem.StartWindowProcess(0, 0, 500, 500);

    WindowSystem.DisplayWindow(WindowHandle);

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
    HWND WindowHandle = WindowSystem.StartWindowProcess(x, y, width, height);

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
    HWND WindowHandle = WindowSystem.StartWindowProcess(0, 0, 500, 500);
    WindowSystem.DisplayWindow(WindowHandle);

    bool testMessageProcessed = false;
    std::function<void()> customBehavior = [&testMessageProcessed] {
        testMessageProcessed = true;
    };
    SetCustomBehaviorForWindow(WindowHandle, customBehavior);

    PostMessage(WindowHandle, WM_TEST_MESSAGE, 0, 0);

    WindowSystem.RunMessageLoop(1);

    EXPECT_TRUE(testMessageProcessed);

    DestroyWindow(WindowHandle);
}