#include <stdint.h>
#include <math.h>

#include <gtest/gtest.h>
#include "math.hpp"
#include "status.hpp"

// Demonstrate some basic assertions.
TEST(MathTestGroup, BasicAssertions)
{
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

TEST(MathTestGroup, muldivInt)
{
   unsigned int a = 1;
   unsigned int b = 1;
   unsigned int c = 1;
   auto res = math::muldiv(a, b, c);
   EXPECT_EQ(res.value(), 1);
}

TEST(MathTestGroup, muldivIntMore)
{
   auto res = math::muldiv(-20, 10, 2);
   ASSERT_EQ(res.value(), -100);
}

TEST(MathTestGroup, muldivIntStatus)
{
   unsigned int a = UINT32_MAX;
   unsigned int b = 2;
   unsigned int c = 1;
   auto res = math::muldiv(a, b, c);
   ASSERT_EQ(res.status(), math::StatusCode::INVALID_ARGUMENT);
}