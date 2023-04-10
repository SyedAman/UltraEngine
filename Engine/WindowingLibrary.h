#pragma once
#include <Windows.h>

LRESULT CALLBACK OnReceivedMessageToWindow(
    HWND HandleToWindowReceivingTheMessage,
    UINT TypeOfMessageSentToTheWindowMouseClickKeyPressPaintDestroy,
    WPARAM AdditionalMessageInformation,
    LPARAM AdditionalMessageInformation2
);

HWND StartWindowProcessAndGetHandle(int X, int Y, int Width, int Height);

void DisplayWindow(HWND WindowHandle);
