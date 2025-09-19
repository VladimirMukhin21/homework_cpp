#include <gtest/gtest.h>
#include "getMax.hpp"

TEST(Test, Test1) {
  int arr1[] = {1,2,3,4,5};
  ASSERT_EQ(GetMax(arr1, sizeof(arr1)/4), 5);
}

TEST(Test, Test2) {
  int arr2[] = {-1,-2,-3,-4,-5};
  ASSERT_EQ(GetMax(arr2, sizeof(arr2)/4), -1);
}

TEST(Test, Test3) {
  int arr3[] = {9,-3,5,8,-1};
  ASSERT_EQ(GetMax(arr3, sizeof(arr3)/4), 9);
}