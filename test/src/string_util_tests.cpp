#include "string_util.h"

#include <gtest/gtest.h>

using namespace testing;

struct StringUtilTests: public Test {};

TEST_F(StringUtilTests, format_s_given_a_string_formatted_result_is_returned)
{
    ASSERT_EQ(util::format_s("Hello, %dth world!", 100), "Hello, 100th world!");
}
