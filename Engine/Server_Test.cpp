// Copyright Syed Aman. All rights reserved.
#include "Server.h"

#include <gmock/gmock-function-mocker.h>
#include <gmock/gmock-spec-builders.h>
#include <gtest/gtest.h>

#include "ISocket.h"


class MockSocket : public ISocket
{
public:
    MOCK_METHOD(bool, Create, (), (override));
    MOCK_METHOD(int, GetSocketDescriptor, (), (override));
};

TEST(DedicatedServer, ShouldInstantiateDedicatedServer)
{
    MockSocket mockSocket;
    Server server(&mockSocket);
    EXPECT_NE(nullptr, &server);
}

TEST(DedicatedServer, ShouldCreateValidSocket)
{
    MockSocket mockSocket;
    Server server(&mockSocket);
    
    ON_CALL(mockSocket, Create())
        .WillByDefault(testing::Return(true));
    ON_CALL(mockSocket, GetSocketDescriptor())
        .WillByDefault(testing::Return(100));
    
    EXPECT_TRUE(server.CreateSocket());
    const int socketDescriptor = mockSocket.GetSocketDescriptor();
    EXPECT_NE(socketDescriptor, mockSocket.INVALID_SOCKET_DESCRIPTOR);
}