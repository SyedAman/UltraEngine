#include "Engine.h"
#include "Windows.h"
#include "gtest/gtest.h"

TEST(WindowCreationTest, WindowProperties)
{
    // When I call the function to create a window.
    HWND WindowHandle = StartWindowProcessAndGetHandle();

    // Then it should return a valid window handle.
    EXPECT_TRUE(WindowHandle != NULL);
    DestroyWindow(WindowHandle);
}

TEST(DisplayWindowTest, WindowVisibleAfterDisplayWindowCalled)
{
    // Given a created window process and its handle
    HWND WindowHandle = StartWindowProcessAndGetHandle();

    // When I call DisplayWindow() with the window handle
    DisplayWindow(WindowHandle);

    // The window should be visible
    EXPECT_TRUE(IsWindowVisible(WindowHandle));
    DestroyWindow(WindowHandle);
}