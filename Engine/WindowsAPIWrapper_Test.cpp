// I know it's ridiculous that I am testing the Windows API wrapper, but there is some custom behavior that I added
// to the wrapper that I want to test, so technically I am not testing the Windows API.

#include "WindowsAPIWrapper.h"
#include <gtest/gtest.h>

BOOL WINAPI MockGetMessage(LPMSG Message, HWND WindowHandle, UINT MessageFilterMin, UINT MessageFilterMax)
{
    Message->message = WM_USER + 1;
    return TRUE;
}

class TestWindowsAPIWrapperWithFunctionHooking : public WindowsAPIWrapper
{
public:
    TestWindowsAPIWrapperWithFunctionHooking()
    {
        GetMessagePtr = MockGetMessage;
    }
};

TEST(WindowsAPIWrapper, GetMessageShouldUpdateEventMessage)
{
    // Given a simulated native windows api GetMessage (function hooked/intercepted) call which updates a passed in MSG struct with a new message 
    TestWindowsAPIWrapperWithFunctionHooking testWindowsAPIWrapper;

    // When I call the wrapper's GetMessage method, which has some additional custom behavior
    EventMessage eventMessage;
    testWindowsAPIWrapper.GetMessageWrapper(&eventMessage);

    // Then the wrapper's GetMessage method should update the passed in EventMessage struct with the new message,
    EXPECT_EQ(eventMessage.message, WM_USER + 1);
}