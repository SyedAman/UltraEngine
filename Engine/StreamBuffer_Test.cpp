// Copyright Syed Aman. All rights reserved.
#include "StreamBuffer.h"

#include "TestingFramework.h"

TEST(StreamBuffer, ShouldCreateEmptyStreamBuffer)
{
    const StreamBuffer streamBuffer;
    constexpr size_t expected = 0;
    const size_t actual = streamBuffer.Length();
    EXPECT_EQ(actual, expected);
}

TEST(StreamBuffer, ShouldWriteToStreamBuffer) {}
TEST(StreamBuffer, ShouldReadDataFromStreamBuffer) {}
TEST(StreamBuffer, ShouldReadDataInChunks) {}
TEST(StreamBuffer, ShouldReturnZeroWhenNoDataAvailable) {}
