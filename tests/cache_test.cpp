#include <gtest/gtest.h>

#include "../include/cache2.h"

#include <string>

TEST(LRUCacheTest, BasicOperations) {

    LRUCache<int, std::string> cache(3);

    cache.put(1, "One");
    cache.put(2, "Two");
    cache.put(3, "Three");

    EXPECT_EQ(cache.get(1), "One");
    EXPECT_EQ(cache.get(2), "Two");
    EXPECT_EQ(cache.get(3), "Three");

  
    cache.put(4, "Four");

    EXPECT_THROW(cache.get(1), std::out_of_range); 
    EXPECT_EQ(cache.get(2), "Two");
    EXPECT_EQ(cache.get(3), "Three");
    EXPECT_EQ(cache.get(4), "Four");
}

TEST(LRUCacheTest, UpdateExistingKey) {
    LRUCache<std::string, int> cache(3);

    cache.put("one", 1);
    cache.put("two", 2);
    cache.put("three", 3);

    EXPECT_EQ(cache.get("one"), 1);
    EXPECT_EQ(cache.get("two"), 2);
    EXPECT_EQ(cache.get("three"), 3);


    cache.put("two", 22);

    EXPECT_EQ(cache.get("one"), 1);
    EXPECT_EQ(cache.get("two"), 22);
    EXPECT_EQ(cache.get("three"), 3);
}

TEST(LRUCacheTest, NonexistentKey) {
    LRUCache<int, double> cache(2);

    EXPECT_THROW(cache.get(1), std::out_of_range);

    cache.put(1, 3.14);
    EXPECT_EQ(cache.get(1), 3.14);
}