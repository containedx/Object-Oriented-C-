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

TEST( TextWrapper, ManyColums)
{
    auto wrapper5 = TextWrapper{};
    EXPECT_EQ("ab\ncd\nef\ngh\nij", wrapper5.wrapInColumns("abcd ef ghij",2));
}

TEST( TextWrapper, ManyColumsX)
{
    auto wrapper6 = TextWrapper{};
    EXPECT_EQ("abcd\nefgh\nij", wrapper6.wrapInColumns("abcd ef ghij",4));
}

TEST( TextWrapper, realwrapping )
{
    auto wrapper7 = TextWrapper{};
    EXPECT_EQ("jakis dlugi tekst\njakis dlugi tekst\njakis dlugi tekst", wrapper7.realtextwrapper("jakis dlugi tekst jakis dlugi tekst jakis dlugi tekst", 20));
}

TEST( TextWrapper, longtext)
{
    auto wrapper8 = TextWrapper{};
    EXPECT_EQ("Lorem ipsum dolor sit amet, consectetur adipiscing\nelit. Suspendisse ut quam libero. Curabitur eu\npellentesque turpis. Vivamus rhoncus porttitor\norci, eu blandit urna malesuada non. Nulla eget\nsagittis augue, nec commodo arcu. Ut malesuada\nefficitur felis id feugiat. Cras nec consectetur\ndui, eu consectetur nisi. Ut pharetra elementum\nposuere. Mauris suscipit feugiat urna. Etiam\nvitae tellus non odio rutrum porttitor. Praesent\ncommodo aliquet dolor molestie viverra. Nulla\nsollicitudin eu velit sed sagittis. Ut gravida\nfeugiat leo, eget rutrum elit luctus eget. Nullam\nvel enim consectetur, sollicitudin justo dictum,\nullamcorper enim. Phasellus eget mi mauris.\nPraesent ac mauris ut lorem porttitor gravida id\neget mauris. ",
            wrapper8.realtextwrapper("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Suspendisse ut quam libero. Curabitur eu pellentesque turpis. Vivamus rhoncus porttitor orci, eu blandit urna malesuada non. Nulla eget sagittis augue, nec commodo arcu. Ut malesuada efficitur felis id feugiat. Cras nec consectetur dui, eu consectetur nisi. Ut pharetra elementum posuere. Mauris suscipit feugiat urna. Etiam vitae tellus non odio rutrum porttitor. Praesent commodo aliquet dolor molestie viverra. Nulla sollicitudin eu velit sed sagittis. Ut gravida feugiat leo, eget rutrum elit luctus eget. Nullam vel enim consectetur, sollicitudin justo dictum, ullamcorper enim. Phasellus eget mi mauris. Praesent ac mauris ut lorem porttitor gravida id eget mauris. ", 50));
}