#include "gtest/gtest.h"
#include<iostream>
#include<string>

std::string::size_type onlyEnds_with(const std::string& str, const std::string& subStr)
{
    std::string::size_type n = str.find(subStr);

    if (n != std::string::npos && str.compare(n, str.size() - n, subStr) == 0)
    {
        return n;
    }

    return std::string::npos;
}

TEST(String, onlyEnds_with)
{
    /*ends_with*/
    EXPECT_EQ(onlyEnds_with("123456", "56"), 4);
    EXPECT_EQ(onlyEnds_with("12563456", "56"), std::string::npos);

    /*not ends_with*/
    EXPECT_EQ(onlyEnds_with("123456", "34"), std::string::npos);
    EXPECT_EQ(onlyEnds_with("123456", "78"), std::string::npos);
}

TEST(String, char2String)
{
    const char* chr = "12345\0hj";
    EXPECT_EQ(strlen(chr), 5);

    std::string str(chr);
    EXPECT_EQ(str.size(), 5);

    std::string str1(chr, 8);
    EXPECT_EQ(str1.size(), 8);
}