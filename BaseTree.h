#ifndef BASETREE_H
#define BASETREE_H

#include <memory>
#include <iostream>

template <typename T>
class BaseTree {
protected:
    struct Node {
        T key;
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;

        Node(const T& k) : key(k), left(nullptr), right(nullptr) {}
    };

    std::unique_ptr<Node> root;

public:
    BaseTree() : root(nullptr) {}
    virtual ~BaseTree() = default;

    virtual void insert(const T& key) = 0;
    virtual bool search(const T& key) const = 0;
    virtual void remove(const T& key) = 0;

    void print() const {
        printInOrder(root.get());
    }

protected:
    void printInOrder(const Node* node, int depth = 0) const {
    if (node) {
        printInOrder(node->right.get(), depth + 1); // Print right subtree
        
        // Print current node with indentation based on depth
        std::cout <<"(" << depth << ")" << node->key << " ";

        printInOrder(node->left.get(), depth + 1); // Print left subtree
    }
}

};

#endif // BASETREE_H