#include <gtest/gtest.h>
#include "reverse.hpp"

// Положительные числа
int arr1[]={1,2,3,4,5};
int arr3[]={1,2,3,4};

TEST(Reverse, OddPlusCount) {
    int arr2[]={5,4,3,2,1};
    Reverse(arr1, sizeof(arr1)/4);
    ASSERT_EQ(*arr2, *arr1);
}
TEST(Reverse, EvenPlusCount) {
    int arr4[]={4,3,2,1};
    Reverse(arr3, sizeof(arr3)/4);
    ASSERT_EQ(*arr4, *arr3);
}

// Отрицательные числа
int arr5[]={-1,-2,-3,-4,-5};
int arr7[]={-1,-2,-3,-4};

TEST(Reverse, OddMinusCount) {
    int arr6[]={-5,-4,-3,-2,-1};
    Reverse(arr5, sizeof(arr5)/4);
    ASSERT_EQ(*arr6, *arr5);
}
TEST(Reverse, EvenMinusCount) {
    int arr8[]={-4,-3,-2,-1};
    Reverse(arr7, sizeof(arr7)/4);
    ASSERT_EQ(*arr8, *arr7);
}