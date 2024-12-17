#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "BaseTree.h"

template <typename T>
class BinaryTree : public BaseTree<T> {
    using typename BaseTree<T>::Node;
    using BaseTree<T>::root;

public:
    void insert(const T& key) override {
        insert(root, key);
    }

    bool search(const T& key) const override {
        return search(root.get(), key);
    }

    void remove(const T& key) override {
        // Binary tree without balancing doesn't implement removal in this example.
        throw std::logic_error("Remove operation is not implemented for BinaryTree.");
    }

private:
    void insert(std::unique_ptr<Node>& node, const T& key) {
        if (!node) {
            node = std::make_unique<Node>(key);
        } else if (!node->left) {
            insert(node->left, key);
        } else {
            insert(node->right, key);
        }
    }

    bool search(const Node* node, const T& key) const {
        if (!node) return false;
        if (node->key == key) return true;
        return search(node->left.get(), key) || search(node->right.get(), key);
    }
};

#endif // BINARYTREE_H