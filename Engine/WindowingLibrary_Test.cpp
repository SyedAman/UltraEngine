#include "WindowingLibrary.h"
#include "Windows.h"
#include "gtest/gtest.h"

TEST(WindowCreationTest, ShouldCreateWindowWithValidHandle)
{
    HWND WindowHandle = StartWindowProcessAndGetHandle();

    EXPECT_TRUE(WindowHandle != NULL);
    DestroyWindow(WindowHandle);
}

TEST(DisplayWindow, ShouldMakeWindowVisibleAfterDisplayWindowCalled)
{
    HWND WindowHandle = StartWindowProcessAndGetHandle();

    DisplayWindow(WindowHandle);

    EXPECT_TRUE(IsWindowVisible(WindowHandle));
    DestroyWindow(WindowHandle);
}