#include <gtest/gtest.h>
#include "../include/set.h"

TEST(ISetTest, Size) {
    ISet<int> set;

    set.insert(5);
    set.insert(2);
    set.insert(7);

    ASSERT_EQ(set.size(), 3);
}


TEST(ISetTest, EmptySet) {
    ISet<int> set;

    ASSERT_EQ(set.size(), 0);
    ASSERT_FALSE(set.contains(5));
    ASSERT_FALSE(set.contains(2));
    ASSERT_FALSE(set.contains(7));
}

TEST(ISetTest, EmplaceWithArgs) {
    ISet<std::string> set;

    set.emplace("hello");
    set.emplace("world");

    ASSERT_TRUE(set.contains("hello"));
    ASSERT_TRUE(set.contains("world"));
    ASSERT_FALSE(set.contains("test"));
}

TEST(ISetTest, InsertAndContains) {
    ISet<int> set;

    set.insert(5);
    set.insert(2);
    set.insert(7);

    ASSERT_EQ(set.size(), 3);
    ASSERT_TRUE(set.contains(5));
    ASSERT_TRUE(set.contains(2));
    ASSERT_TRUE(set.contains(7));
    ASSERT_FALSE(set.contains(10));
}

TEST(ISetTest, EmplaceMultiple) {
    ISet<std::pair<int, std::string>> set;

    set.emplace(1, "one");
    set.emplace(2, "two");
    set.emplace(3, "three");

    ASSERT_EQ(set.size(), 3);
    ASSERT_TRUE(set.contains(std::make_pair(1, "one")));
    ASSERT_TRUE(set.contains(std::make_pair(2, "two")));
    ASSERT_TRUE(set.contains(std::make_pair(3, "three")));
    ASSERT_FALSE(set.contains(std::make_pair(4, "four")));
}


