﻿// Copyright Syed Aman. All Rights Reserved.
#include "WindowsOSWindowSystem.h"

#include <functional>
#include <gmock/gmock-function-mocker.h>

#include "TestingUtilities_Test.h"
#include "gtest/gtest.h"


TEST(WindowSystem, StartWindowProcess)
{
    WindowsOSWindowSystem WindowSystem;
    WindowHandle WindowHandle = WindowSystem.StartWindowProcess(0, 0, 500, 500);

    EXPECT_TRUE(WindowHandle != nullptr);
    DestroyWindow(reinterpret_cast<HWND>(WindowHandle));
}

TEST(WindowSystem, DisplayWindow)
{
    WindowsOSWindowSystem WindowSystem;
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

    WindowsOSWindowSystem WindowSystem;
    WindowHandle WindowHandle = WindowSystem.StartWindowProcess(x, y, width, height);

    RECT WindowRect;
    GetWindowRect(reinterpret_cast<HWND>(WindowHandle), &WindowRect);

    EXPECT_EQ(WindowRect.left, x);
    EXPECT_EQ(WindowRect.top, y);
    EXPECT_EQ(WindowRect.right - WindowRect.left, width);
    EXPECT_EQ(WindowRect.bottom - WindowRect.top, height);

    DestroyWindow(reinterpret_cast<HWND>(WindowHandle));
}

TEST(WindowSystem, MessageLoopShouldProcessMessages)
{
    #define WM_TEST_MESSAGE (WM_USER + 1)
    
    WindowsOSWindowSystem WindowSystem;
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

    #undef WM_TEST_MESSAGE
}

class WindowSystemParameterizedTest : public testing::TestWithParam<UINT> {};
TEST_P(WindowSystemParameterizedTest, RunMessageLoopShouldExitOnWM_QUITAndWM_CLOSEAndReturnNumberOfIterations)
{
    MockWindowsAPIWrapper mockWindowsAPI;
    WindowsOSWindowSystem windowSystem(mockWindowsAPI);

    ON_CALL(mockWindowsAPI, GetEventMessage)
        .WillByDefault([](EventMessage* LoopMessage) {
            LoopMessage->message = GetParam();
            return true;
        });

    const size_t maxIterations = 10;
    const size_t actualIterations = windowSystem.RunMessageLoop(maxIterations);

    EXPECT_EQ(actualIterations, 1);
}
INSTANTIATE_TEST_SUITE_P(
    WindowSystem,
    WindowSystemParameterizedTest,
    testing::Values(WM_QUIT, WM_CLOSE)
);
