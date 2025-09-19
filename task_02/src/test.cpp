#include <gtest/gtest.h>
#include "getMax.hpp"

TEST(Test, Simple) {
  int arr[] = {1,2,3,4,5};
  // int* arr = new int[5];
  ASSERT_EQ(GetMax(arr, 5), 5);
}