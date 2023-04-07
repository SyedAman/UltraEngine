#include <gtest/gtest.h>

#include "Engine.h"

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();

    HWND WindowHandle = StartWindowProcessAndGetHandle();
    DisplayWindow(WindowHandle);

    return 0;
}
