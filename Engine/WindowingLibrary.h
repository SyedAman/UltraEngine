#pragma once
#include <Windows.h>

LRESULT CALLBACK OnReceivedMessageToWindow(
    HWND HandleToWindowReceivingTheMessage,
    UINT TypeOfMessageSentToTheWindowMouseClickKeyPressPaintDestroy,
    WPARAM AdditionalMessageInformation,
    LPARAM AdditionalMessageInformation2
);

HWND StartWindowProcessAndGetHandle();

void DisplayWindow(HWND WindowHandle);