#include <gtest/gtest.h>
#include "../include/splay_tree.h" 

TEST(SplayTreeTest, InsertAndFind) {
    SplayTree<int> splayTree;

    splayTree.insert(5);
    splayTree.insert(3);
    splayTree.insert(7);

    EXPECT_TRUE(splayTree.find(5));
    EXPECT_TRUE(splayTree.find(3));
    EXPECT_TRUE(splayTree.find(7));

    EXPECT_FALSE(splayTree.find(1));
    EXPECT_FALSE(splayTree.find(10));
}


TEST(SplayTreeTest, DeleteMaxAndMin) {
    SplayTree<int> splayTree;

    splayTree.insert(5);
    splayTree.insert(3);
    splayTree.insert(7);

    splayTree.delete_max();
    EXPECT_EQ(splayTree.size(), 2);
    EXPECT_EQ(splayTree.get_maximum(), 5);

    splayTree.delete_min();
    EXPECT_EQ(splayTree.size(), 1);
    EXPECT_EQ(splayTree.get_minimum(), 5);
}

TEST(SplayTreeTest, DeleteNonexistent) {
    SplayTree<int> splayTree;

    splayTree.insert(5);
    splayTree.insert(3);
    splayTree.insert(7);

    EXPECT_FALSE(splayTree.find(10));

    splayTree.delete_max(); 
    EXPECT_EQ(splayTree.size(), 2);
    
    splayTree.delete_min(); 
    EXPECT_EQ(splayTree.size(), 1);
}


TEST(SplayTreeTest, SizeAndEmpty) {
    SplayTree<int> splayTree;

    EXPECT_EQ(splayTree.size(), 0);
    EXPECT_TRUE(splayTree.empty());

    splayTree.insert(5);

    EXPECT_EQ(splayTree.size(), 1);
    EXPECT_FALSE(splayTree.empty());
}
