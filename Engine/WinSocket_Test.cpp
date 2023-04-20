// Copyright Syed Aman. All Rights Reserved.
#include "WinSocket.h"

#include <gtest/gtest.h>

#include "Server.h"


TEST(WinSocket, ShouldCreateValidSocket)
{
    WinSocket winSocket;
    Server server(&winSocket);
    ASSERT_TRUE(server.CreateSocket());

    const int socketDescriptor = winSocket.GetSocketDescriptor();
    ASSERT_NE(socketDescriptor, winSocket.INVALID_SOCKET_DESCRIPTOR);
}
