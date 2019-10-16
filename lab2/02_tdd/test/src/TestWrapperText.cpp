//
// Created by student on 14.10.2019.
//
#include "TestIncludes.h"
#include "TextWrapper.h"

TEST( TextWrapper, HasColumsGetter) {

    auto wrapper = TextWrapper{};
    EXPECT_EQ(10, wrapper.columns());
}

TEST( TextWrapper, OneColumn)
{
    auto wrapper2 = TextWrapper{};
    EXPECT_EQ("a\nb",wrapper2.wrap("a b"));
}

TEST( TextWrapper, OneColumn3characters )
{
    auto wrapper3 = TextWrapper{};
    EXPECT_EQ("a\nb\nc", wrapper3.wrap("a b c"));
}

TEST(TextWrapper, TwoColumns)
{
    auto wrapper4 = TextWrapper{};
    EXPECT_EQ("ab\ncd", wrapper4.wrapInColumns("a b c d", 2));
}
