#include "list.h"

#include "../gtest/gtest.h"

TEST(TListArray, can_create_steck_with_positive_length)
{
  ASSERT_NO_THROW(TListArray<int> bf(3));
}

