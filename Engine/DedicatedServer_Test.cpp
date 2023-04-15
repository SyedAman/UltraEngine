#include "DedicatedServer.h"

#include <gtest/gtest.h>

#include "ISocket.h"


class MySocket : public ISocket {};

TEST(DedicatedServer, ShouldInstantiateDedicatedServer)
{
    MySocket mySocket;
    DedicatedServer server(&mySocket);
    EXPECT_NE(nullptr, &server);
}