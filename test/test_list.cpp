#include "list.h"

#include "../gtest/gtest.h"

TEST(TList, can_create_steck_with_positive_length)
{
  ASSERT_NO_THROW(TList<int> bf(3));
}

