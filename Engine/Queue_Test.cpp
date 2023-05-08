// Copyright Syed Aman. All Rights Reserved.
#include "TestingFramework.h"
#include "Queue.h"
#include "String.h"

TEST(Queue, CreatesEmptyQueue)
{
    constexpr Queue<int> queue;
    EXPECT_TRUE(queue.IsEmpty());
    EXPECT_EQ(0, queue.Size());
}

TEST(Queue, Template)
{
    Queue<int> queue1;
    Queue<String> queue2;
    Queue<Queue<int>> queue3;

    EXPECT_TRUE(queue1.IsEmpty());
    EXPECT_TRUE(queue2.IsEmpty());
    EXPECT_TRUE(queue3.IsEmpty());
}

TEST(Queue, Enqueue)
{
    Queue<int> queue;
    queue.Enqueue(1);
    EXPECT_FALSE(queue.IsEmpty());
    const size_t size = queue.Size();
    EXPECT_EQ(1, size);

    queue.Enqueue(2);
    EXPECT_FALSE(queue.IsEmpty());
    EXPECT_EQ(2, queue.Size());
}

TEST(Queue, Dequeue) {}
TEST(Queue, Size) {}
TEST(Queue, IsEmpty) {}
TEST(Queue, Peek) {}
TEST(Queue, EnqueueMultipleItemsAddsThemToTheQueueInCorrectOrder) {}
TEST(Queue, DequeueMultipleItemsRemovesThemFromTheQueueInCorrectOrder) {}
TEST(Queue, ClearCorrectlyEmptiesTheQueue) {}
TEST(Queue, CopyConstructorCreatesNewQueueWithSameElementsAndOrder) {}
TEST(Queue, AssignmentOperatorCorrectlyCopiesTheElementsAndOrderOfOneQueueToAnother) {}
TEST(Queue, MoveConstructorTransfersOwnershipOfTheElementsFromOneQueueToAnother) {}
TEST(Queue, MoveAssignmentOperatorTransfersOwnershipOfTheElementsFromOneQueueToAnother) {}
