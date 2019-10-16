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
