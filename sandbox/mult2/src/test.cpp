#include <gtest/gtest.h>
#include "mult2.hpp"

TEST(Mult2, Simple) {
    int arr1[]={1,2,3,4,5};
    int arr2[]={2,4,6,8,10};
    Mult2(arr1, sizeof(arr1)/4);
    ASSERT_EQ(*arr1, *arr2);
}
