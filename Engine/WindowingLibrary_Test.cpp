#include "WindowingLibrary.h"

#include <functional>

#include "Windows.h"
#include "gtest/gtest.h"

TEST(WindowCreationTest, ShouldCreateWindowWithValidHandle)
{
    HWND WindowHandle = StartWindowProcessAndGetHandle(0, 0, 500, 500);

    EXPECT_TRUE(WindowHandle != NULL);
    DestroyWindow(WindowHandle);
}

TEST(DisplayWindow, ShouldMakeWindowVisibleAfterDisplayWindowCalled)
{
    HWND WindowHandle = StartWindowProcessAndGetHandle(0, 0, 500, 500);

    DisplayWindow(WindowHandle);

    EXPECT_TRUE(IsWindowVisible(WindowHandle));
    DestroyWindow(WindowHandle);
}

TEST(WindowCreationTest, ShouldCreateWindowWithCorrectSizeAndPosition)
{
    int x = 100;
    int y = 100;
    int width = 800;
    int height = 600;

    HWND WindowHandle = StartWindowProcessAndGetHandle(x, y, width, height);

    RECT WindowRect;
    GetWindowRect(WindowHandle, &WindowRect);

    EXPECT_EQ(WindowRect.left, x);
    EXPECT_EQ(WindowRect.top, y);
    EXPECT_EQ(WindowRect.right - WindowRect.left, width);
    EXPECT_EQ(WindowRect.bottom - WindowRect.top, height);

    DestroyWindow(WindowHandle);
}

#define WM_TEST_MESSAGE (WM_USER + 1)

TEST(MessageLoop, ShouldProcessCustomMessages)
{
    HWND WindowHandle = StartWindowProcessAndGetHandle(0, 0, 500, 500);
    DisplayWindow(WindowHandle);

    bool testMessageProcessed = false;

    // Define the custom behavior as a lambda function
    std::function<void()> customBehavior = [&testMessageProcessed] {
        testMessageProcessed = true;
    };

    // Set the custom behavior for the window
    SetCustomBehaviorForWindow(WindowHandle, customBehavior);

    // Send the custom test message to the window
    PostMessage(WindowHandle, WM_TEST_MESSAGE, 0, 0);

    // Run the message loop
    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);

        // Break the loop if the test message has been processed
        if (testMessageProcessed) {
            break;
        }
    }

    // Check if the test message has been processed
    EXPECT_TRUE(testMessageProcessed);

    DestroyWindow(WindowHandle);
}
