#include "../src/armstrong_numbers.h"
#include "gtest/gtest.h"
#include <stdlib.h>

TEST(Armstrong, 0) { EXPECT_TRUE(is_armstrong_number(0)); }
TEST(Armstrong, 5) { EXPECT_TRUE(is_armstrong_number(5)); }
TEST(Armstrong, 6) { EXPECT_TRUE(is_armstrong_number(6)); }
TEST(Armstrong, 10) { EXPECT_FALSE(is_armstrong_number(10)); }
TEST(Armstrong, 9926315) { EXPECT_TRUE(is_armstrong_number(9926315)); }
TEST(Armstrong, 9926314) { EXPECT_FALSE(is_armstrong_number(9926314)); }
