#include "pch.h"
#include "../base/Stack.h"

TEST(Stack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(Stack<int> st(5));
}

TEST(Stack, throws_when_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(Stack<int> st(-5));
}

TEST(Stack, cant_create_stack_with_zero_length)
{
	ASSERT_ANY_THROW(Stack<int> st(0));
}


TEST(Stack, cant_create_too_large_stack)
{
	ASSERT_ANY_THROW(Stack<int> st(MaxStackSize + 1));
}

TEST(Stack, cant_push_if_stack_full)
{
	Stack<int> st(2);
	st.push(1);
	st.push(2);
	ASSERT_ANY_THROW(st.push(4));
}

TEST(Stack, cant_pop_if_stack_empty)
{
	Stack<int> st(2);
	ASSERT_ANY_THROW(st.Pop());
}

TEST(Stack, can_push_and_pop_element)
{
	Stack<int> st(5);
	st.push(4);
	st.push(5);
	EXPECT_EQ(5, st.Pop());
	//EXPECT_EQ(4, st.top());
}

TEST(Stack, function_full_is_correct)
{
	Stack<int> st(2);
	st.push(4);
	st.push(4);
	ASSERT_TRUE(st.isFull());
}

TEST(Stack, function_empty_is_correct)
{
	Stack<int> st(2);
	ASSERT_TRUE(st.isEmpty());
}