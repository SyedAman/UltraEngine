// Copyright Syed Aman. All Rights Reserved.

#include <gtest/gtest.h>
#include "Queue.h"
#include "String.h"

TEST(Queue, CreatesEmptyQueue)
{
    constexpr Queue<int> queue;
    ASSERT_TRUE(queue.IsEmpty());
    ASSERT_EQ(0, queue.Size());
}

TEST(Queue, Template)
{
    Queue<int> queue1;
    Queue<String> queue2;
    Queue<Queue<int>> queue3;

    ASSERT_TRUE(queue1.IsEmpty());
    ASSERT_TRUE(queue2.IsEmpty());
    ASSERT_TRUE(queue3.IsEmpty());
}

TEST(Queue, Enqueue)
{
    Queue<int> queue;
    queue.Enqueue(1);
    ASSERT_FALSE(queue.IsEmpty());
    const size_t size = queue.Size();
    ASSERT_EQ(1, size);

    queue.Enqueue(2);
    ASSERT_FALSE(queue.IsEmpty());
    ASSERT_EQ(2, queue.Size());
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
