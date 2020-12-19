#include "listarray.h"

#include "../gtest/gtest.h"

TEST(TListArray, eq1)
{
	TListArray<int> A(3);
	TListArray<int> B(4);
	ASSERT_ANY_THROW(A = B);
}

TEST(TListArray, eq2)
{
	TListArray<int> A(3);
	TListArray<int> B(13);
	B.InsLast(10);
	B.InsLast(11);
	B.InsLast(13);
	B.InsLast(10);
	A = B;
	ASSERT_EQ(A.GetCount(), B.GetCount());
}

TEST(TListArray, eq3)
{
	TListArray<int> A(3);
	TListArray<int> B(13);
	B.InsLast(10);
	B.InsLast(11);
	B.InsLast(13);
	B.InsLast(10);
	A = B;
	ASSERT_EQ(A.GetLast, B.GetLast);
}

TEST(TListArray, eq4)
{
	TListArray<int> A(3);
	TListArray<int> B(13);
	B.InsLast(10);
	B.InsLast(11);
	B.InsLast(13);
	B.InsLast(10);
	A = B;
	ASSERT_EQ(A.GetFirst, B.GetFirst);
}

TEST(TListArray, can_create_array_list)
{
	ASSERT_NO_THROW(TListArray<int> A(3));
}

TEST(TListArray, can_get_count)
{
	TListArray<int> A(3);
	EXPECT_EQ(0, A.GetCount());
}

TEST(TListArray, can_ins_first)
{
	TListArray<int> A(3);
	ASSERT_NO_THROW(A.InsFirst(1));
	ASSERT_NO_THROW(A.InsFirst(2));

	EXPECT_EQ(2, A.GetFirst());
	EXPECT_EQ(1, A.GetLast());
}

TEST(TListArray, can_ins_last)
{
	TListArray<int> A(3);
	ASSERT_NO_THROW(A.InsLast(1));
	ASSERT_NO_THROW(A.InsLast(2));

	EXPECT_EQ(1, A.GetFirst());
	EXPECT_EQ(2, A.GetLast());
}

TEST(TListArray, can_copy_array_list)
{
	TListArray<int> A(3);
	A.InsLast(2);
	A.InsFirst(1);
	A.InsFirst(0);

	TListArray<int> B(A);
	EXPECT_EQ(0, B.GetFirst());
	EXPECT_EQ(2, B.GetLast());
}

TEST(TListArray, can_delete_first)
{
	TListArray<int> A(3);
	A.InsLast(2);
	A.InsFirst(1);
	A.InsFirst(0);

	ASSERT_NO_THROW(A.DellFirst());
	EXPECT_EQ(2, A.GetCount());
	EXPECT_EQ(1, A.GetFirst());
	EXPECT_EQ(2, A.GetLast());
}

TEST(TListArray, can_delete_last)
{
	TListArray<int> A(3);
	A.InsLast(2);
	A.InsFirst(1);
	A.InsFirst(0);

	ASSERT_NO_THROW(A.DellLast());
	EXPECT_EQ(2, A.GetCount());
	EXPECT_EQ(0, A.GetFirst());
	EXPECT_EQ(1, A.GetLast());
}

TEST(TListArray, use_operator_equal)
{
	TListArray<int> A(3);
	A.InsLast(2);
	A.InsFirst(1);
	A.InsFirst(0);

	TListArray<int> B = A;
	EXPECT_EQ(A.GetCount(), B.GetCount());
	EXPECT_EQ(A.GetFirst(), B.GetFirst());
	EXPECT_EQ(A.GetLast(), B.GetLast());
	B.DellLast();
	A.DellLast();
	EXPECT_EQ(A.GetLast(), B.GetLast());
}

TEST(TListArray, can_not_add_in_full_list)
{
	TListArray<int> A(3);
	A.InsLast(2);
	A.InsFirst(1);
	A.InsFirst(0);

	ASSERT_ANY_THROW(A.InsFirst(2));
	ASSERT_ANY_THROW(A.InsLast(2));
}

TEST(TListArray, can_not_del_from_empty_list)
{
	TListArray<int> A(3);

	ASSERT_ANY_THROW(A.DellFirst());
	ASSERT_ANY_THROW(A.DellLast());
}
