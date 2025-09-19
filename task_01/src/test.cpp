#include <gtest/gtest.h>
#include "getMedian.hpp"

TEST(Test, Three_different_numbers) {
    ASSERT_EQ(GetMedian(1, 2, 3), 2);
    ASSERT_EQ(GetMedian(1, 3, 2), 2);
    ASSERT_EQ(GetMedian(2, 1, 3), 2);
    ASSERT_EQ(GetMedian(2, 3, 1), 2);
    ASSERT_EQ(GetMedian(3, 1, 2), 2);
    ASSERT_EQ(GetMedian(3, 2, 1), 2);
}

TEST(Test, Three_repetings_numbers) {
    ASSERT_EQ(GetMedian(0, 0, 0), 0);
    ASSERT_EQ(GetMedian(100, 100, 100), 100);
}

TEST(Test, Negative_numbers) {
    ASSERT_EQ(GetMedian(-1, -2, -3), -2);
    ASSERT_EQ(GetMedian(-1, -3, -2), -2);
    ASSERT_EQ(GetMedian(-2, -1, -3), -2);
    ASSERT_EQ(GetMedian(-2, -3, -1), -2);
    ASSERT_EQ(GetMedian(-3, -1, -2), -2);
    ASSERT_EQ(GetMedian(-3, -2, -1), -2);
}