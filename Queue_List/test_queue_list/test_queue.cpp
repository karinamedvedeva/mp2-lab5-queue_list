#include "gtest.h"

#include "../Queue_List/Queue_List.h"

TEST(Queue, can_create_queue)
{
	ASSERT_NO_THROW(TQueue <int>q);
}

TEST(Queue, can_create_copied_queue)
{
	TQueue<int> q;

	ASSERT_NO_THROW(TQueue<int> q1(q));
}

TEST(Queue, copied_queue_is_equal_to_source_one)
{
	TQueue <int> q1, q2;
	
	EXPECT_EQ(q1, q2);
}

TEST(Queue, can_assign_queue_to_itself)
{
	TQueue <int> q;
	
	ASSERT_NO_THROW(q = q);
}

TEST(Queue, can_assign_queues)
{
	TQueue <int> q1, q2;
	q1.Push(1);
	q1.Push(2);
	q2.Push(3);
	ASSERT_NO_THROW(q1 = q2);
	EXPECT_EQ(q1.Pop(), q2.Pop());
}

TEST(Queue, compare_queue_with_itself_return_true)
{
	TQueue <int>q;
	
	EXPECT_EQ(1, q == q);
}

TEST(Queue, compare_equal_queues_return_true)
{
	TQueue <int> q1;
	q1.Push(1);
	q1.Push(2);
	q1.Push(3);
	TQueue <int> q2;
	q2.Push(1);
	q2.Push(2);
	q2.Push(3);
	EXPECT_EQ(1, q1 == q2);
}

TEST(Queue, different_queues_are_not_equal)
{
	TQueue <int> q1, q2;
	q1.Push(1);
	q1.Push(2);
	q1.Push(3);
	q2.Push(1);
	q2.Push(7);
	q2.Push(5);
	EXPECT_EQ(1, q1 != q2);
}

TEST(Queue, can_put_element)
{
	TQueue<int> q;
	ASSERT_NO_THROW(q.Push(15));
}

TEST(Queue, can_put_out_of_not_empty_queue)
{
	TQueue<int>q;
	q.Push(2);
	ASSERT_NO_THROW(q.Pop());
}

TEST(Queue, cant_put_out_of_empty_queue)
{
	TQueue<int>q;
	ASSERT_ANY_THROW(q.Pop());
}

TEST(Queue, empty_queue_return_true)
{
	TQueue <int> q;
	EXPECT_EQ(1, q.Empty());
}

TEST(Queue, can_check_that_queue_is_empty)
{
	TQueue <int> q;
	ASSERT_NO_THROW(q.Empty());
}

TEST(Queue, can_put_in_not_full_queue)
{
	TQueue<int>q;
	q.Push(1);
	ASSERT_NO_THROW(q.Push(2));
}

TEST(Queue, can_get_the_head)
{
	TQueue<int>q;
	q.Push(1);
	ASSERT_NO_THROW(q.GetHead());
}

TEST(Queue, cant_get_the_head_of_empty_queue)
{
	TQueue<int>q;
	ASSERT_ANY_THROW(q.GetHead());
}


