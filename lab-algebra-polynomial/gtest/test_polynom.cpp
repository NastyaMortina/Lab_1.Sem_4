#include "pch.h"
#include "../base/Polynom.cpp"

TEST(Polynom, can_create_polynom)
{
	ASSERT_NO_THROW(Polynom polynom);
}
TEST(Polynom, can_create_polynom_with_argument)
{
	Polynom polynom1;
	ASSERT_NO_THROW(Polynom polynom2(polynom1));
}
TEST(Polynom, can_create_polynom_with_monom)
{
	ASSERT_NO_THROW(Polynom polynom("3x4y5z6"));
}
TEST(Polynom, can_calculate_in_point_of_polynom)
{
	Polynom polynom("3x4y5z6-2x5yz3");
	polynom.Convert();
	int result = polynom.CalculateInPoint(1, 1, 1);
	EXPECT_EQ(1, result);
}
TEST(Polynom, can_compare_prefix_of_two_polynom)
{
	Polynom polynom("3x4y5z6-2x5yz3");
	EXPECT_EQ("3x4y5z6-2x5yz3", polynom.GetPrefix());
}
TEST(Polynom, can_addition_of_two_polynom)
{
	Polynom polynom1("3x4y5z6-2x5yz3");
	Polynom polynom2("3x4y5z6+2x5yz3");
	Polynom result;
	polynom1.Convert();
	polynom2.Convert();
	result = polynom1 + polynom2;
	Polynom addition(result);
	EXPECT_EQ("", addition.GetPrefix());
}
TEST(Polynom, can_compare_two_polynom_with_identical_value)
{
	Polynom polynom1("3x4y5z6-2x5yz3");
	Polynom polynom2("3x4y5z6-2x5yz3");
	EXPECT_TRUE(polynom1 == polynom2);
}
TEST(Polynom, can_compare_two_polynom_with_different_value)
{
	Polynom polynom1("3x4y5z6-2x5yz3");
	Polynom polynom2("3x4y5z6+2x5yz3");
	EXPECT_FALSE(polynom1 == polynom2);
}
TEST(Polynom, cant_sort_empty_polynom)
{
	Polynom polynom;
	ASSERT_ANY_THROW(polynom.Sort());
}
TEST(Polynom, cant_addition_with_empty_polynom)
{
	Polynom polynom1("3x4y5z6-2x5yz3");
	Polynom polynom2("");
	ASSERT_ANY_THROW(polynom1 + polynom2);
}
TEST(Polynom, cant_subtraction_with_empty_polynom)
{
	Polynom polynom1("3x4y5z6-2x5yz3");
	Polynom polynom2("");
	ASSERT_ANY_THROW(polynom1 - polynom2);
}
TEST(Polynom, cant_multiplication_with_empty_polynom)
{
	Polynom polynom1("3x4y5z6-2x5yz3");
	Polynom polynom2("");
	ASSERT_ANY_THROW(polynom1 * polynom2);
}