// Copyright Syed Aman. All Rights Reserved.
#include "WinSocket.h"

#include "TestingFramework.h"

#include "Server.h"


TEST(WinSocket, ShouldCreateValidSocket)
{
    WinSocket winSocket;
    Server server(&winSocket);
    EXPECT_TRUE(server.CreateSocket());

    const int socketDescriptor = winSocket.GetSocketDescriptor();
    EXPECT_NE(socketDescriptor, winSocket.INVALID_SOCKET_DESCRIPTOR);
}
