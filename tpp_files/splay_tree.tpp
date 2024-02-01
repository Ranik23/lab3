#include "splay_tree.h"
#include <iomanip>

template <typename _Tp>
void SplayTree<_Tp>::rotateLeft(Node *x)
{
    Node *y = x->right;
    x->right = y->left;
    if (y->left)
        y->left->parent = x;
    y->parent = x->parent;
    if (!x->parent)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
}

template <typename _Tp>
void SplayTree<_Tp>::rotateRight(Node *x)
{
    Node *y = x->left;
    x->left = y->right;
    if (y->right)
        y->right->parent = x;
    y->parent = x->parent;
    if (!x->parent)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->right = x;
    x->parent = y;
}

template <typename _Tp>
void SplayTree<_Tp>::splay(Node *x)
{
    while (x->parent) {
        Node *parent = x->parent;
        Node *grandparent = parent->parent;

        if (!grandparent)
        {
            if (x == parent->left)
                rotateRight(parent);
            else
                rotateLeft(parent);
        }
        else if (x == parent->left && parent == grandparent->left)
        {
            rotateRight(grandparent);
            rotateRight(parent);
        }
        else if (x == parent->right && parent == grandparent->right)
        {
            rotateLeft(grandparent);
            rotateLeft(parent);
        }
        else if (x == parent->right && parent == grandparent->left)
        {
            rotateLeft(parent);
            rotateRight(grandparent);
        }
        else
        {
            rotateRight(parent);
            rotateLeft(grandparent);
        }
    }
}

template <typename _Tp>
void SplayTree<_Tp>::clear(Node *vertex) {
    if (vertex == nullptr)
        return;
    clear(vertex->right);
    clear(vertex->left);
    delete vertex;
}

template <typename _Tp>
SplayTree<_Tp>::SplayTree() : root(nullptr), count(0){};

template<typename _Tp>
void SplayTree<_Tp>::generateDotFile(const std::string& fileName) const {
    std::ofstream dotFile(fileName + ".dot");

    if (dotFile.is_open()) {
        dotFile << "digraph splay_tree {\n";
        dotFile << "    node [shape=circle];\n";

        generateDotFileRecursive(root, dotFile);

        dotFile << "}\n";
        dotFile.close();

        std::string command = "dot -Tpng " + fileName + ".dot -o " + fileName + ".png";
        system(command.c_str());

        std::cout << "Tree visualization saved as " << fileName << ".png\n";
    }
    else
    {
        std::cerr << "Unable to open DOT file: " << fileName << std::endl;
    }
}

template <typename _Tp>
void SplayTree<_Tp>::insert(const _Tp &value)
{
    if (root == nullptr)
    {
        root = new Node(value);
        root->parent = nullptr;
    }
    else
    {
        auto v = root;
        Node *p = nullptr;
        while (v != nullptr)
        {
            p = v;
            if (value < v->data)
            {
                v = v->left;
            }
            else
            {
                v = v->right;
            }
        }
        v = new Node(value);
        v->parent = p;
        if (value < p->data)
        {
            p->left = v;
        }
        else
        {
            p->right = v;
        }
        splay(v);
    }

    count += 1;
}

template <typename T>
bool SplayTree<T>::find(const T &value) const {
    
    auto v = root;
    while (v != nullptr)
    {
        if (v->data < value)
        {
            v = v->right;
        }
        else if (v->data > value)
        {
            v = v->left;
        }
        else
        {
            return true;
        }
    }
    return false;
}

template <typename T>
void SplayTree<T>::print() const {
    printInOrder(root);
    std::cout << std::endl;
}

template <typename T>
size_t SplayTree<T>::size() const {
    
    return count;
}

template<typename T>
bool SplayTree<T>::empty() const {
    
    return count == 0;
}

template<typename T>
T SplayTree<T>::get_maximum() const {
    
    auto node = root;

    while (node->right != nullptr)
        node = node->right;

    return node->data;
}

template<typename T>
T SplayTree<T>::get_minimum() const {
    
    auto node = root;

    while (node->left != nullptr)
        node = node->left;

    return node->data;
}

template<typename T>
void SplayTree<T>::delete_max() {
    
    if (root == nullptr)
        {
            return;
        }
        count -= 1;

        if (root->right == nullptr)
        {
            Node *temp = root->left;
            delete root;
            root = temp;
            return;
        }

        Node *parent = nullptr;
        Node *node = root;

        while (node->right != nullptr)
        {
            parent = node;
            node = node->right;
        }

        parent->right = node->left;
        delete node;
}

template<typename T>
void SplayTree<T>::delete_min() {
   
    if (root == nullptr)
        {
            return;
        }

        count -= 1;

        if (root->left == nullptr)
        {
            Node *temp = root->right;
            delete root;
            root = temp;
            return;
        }

        Node *parent = nullptr;
        Node *node = root;

        while (node->left != nullptr)
        {
            parent = node;
            node = node->left;
        }

        parent->left = node->right;
        delete node;
}