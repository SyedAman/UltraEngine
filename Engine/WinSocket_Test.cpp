#include "WinSocket.h"

#include <gtest/gtest.h>

#include "DedicatedServer.h"


TEST(WinSocket, ShouldCreateValidSocket)
{
    WinSocket winSocket;
    DedicatedServer server(&winSocket);
    ASSERT_TRUE(server.CreateSocket());

    const int socketDescriptor = winSocket.GetSocketDescriptor();
    ASSERT_NE(socketDescriptor, winSocket.INVALID_SOCKET_DESCRIPTOR);
}
