#include <gtest/gtest.h>
#include "nothing.h"

//expected failed
TEST( avocado, melon)
{
    auto watermelon = Thing{};
    ASSERT_ANY_THROW(watermelon.function());
}

//expected Ok
TEST( pomelo, strawberry)
{
    auto berry = Thing{};
    EXPECT_EQ(10,berry.add(4,6));
}