#include "WindowingLibrary.h"
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
