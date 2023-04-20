#include "Queue.h"

#include <gtest/gtest.h>

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
TEST(Queue, EnqueueMultipleItems) {
    // Test that enqueueing multiple items adds them to the queue in the correct order
}

TEST(Queue, DequeueMultipleItems) {
    // Test that dequeueing multiple items removes them from the queue in the correct order
}

TEST(Queue, Clear) {
    // Test that the Clear method correctly empties the queue and updates its size
}

TEST(Queue, CopyConstructor) {
    // Test that the copy constructor creates a new queue with the same elements and order as the original
}

TEST(Queue, AssignmentOperator) {
    // Test that the assignment operator correctly copies the elements and order of one queue to another
}

TEST(Queue, MoveConstructor) {
    // Test that the move constructor transfers ownership of the elements from one queue to another
}

TEST(Queue, MoveAssignmentOperator) {
    // Test that the move assignment operator transfers ownership of the elements from one queue to another
}
