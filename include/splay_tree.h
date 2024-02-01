#ifndef LAB3_1_SPLAY_TREE_H
#define LAB3_1_SPLAY_TREE_H

#include <iostream>
#include <stack>
#include <fstream>

template <typename _Tp>
class SplayTree
{
public:

    using value_type = _Tp;
    using size_type = size_t;
    using reference = _Tp &;
    using const_reference = const _Tp &;

    struct Node
    {

        _Tp data;

        Node *left, *right;

        Node *parent;

        Node(const _Tp &value) : data(value), right(nullptr), left(nullptr), parent(nullptr) {}
    };

private:

    void rotateLeft(Node *x);

    void rotateRight(Node *x);

    void splay(Node *x);

    void clear(Node *vertex);

    void printInOrder(Node *node) const {
        if (node) {
            printInOrder(node->left);
            std::cout << node->data << " ";
            printInOrder(node->right);
        }
    }

    void generateDotFileRecursive(Node* node, std::ofstream& dotFile) const {
        if (node) {
            dotFile << "    " << node->data << ";\n";
            
            if (node->left) {
                dotFile << "    " << node->data << " -> " << node->left->data << ";\n";
                generateDotFileRecursive(node->left, dotFile);
            }
            if (node->right) {
                dotFile << "    " << node->data << " -> " << node->right->data << ";\n";
                generateDotFileRecursive(node->right, dotFile);
            }
        }
    }
    
    Node *root;

    size_type count;

public:

    SplayTree();

    SplayTree(SplayTree<_Tp> &&other) : root(std::move(other.root)), count(std::move(other.count)) {}

    ~SplayTree() {
        clear(root);
    }

    void insert(const _Tp &value);

    bool find(const _Tp &value) const;

    void generateDotFile(const std::string& fileName) const;

    void print() const;

    size_t size() const;

    bool empty() const;

    _Tp get_maximum() const;

    _Tp get_minimum() const;

    void delete_max();

    void delete_min();
};

#include "../tpp_files/splay_tree.tpp"

#endif