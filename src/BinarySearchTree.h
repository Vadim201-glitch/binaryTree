#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "BaseTree.h"

template <typename T>
class BinarySearchTree : public BaseTree<T> {
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
        root = remove(std::move(root), key);
    }

private:
    void insert(std::unique_ptr<Node>& node, const T& key) {
        if (!node) {
            node = std::make_unique<Node>(key);
        } else if (key < node->key) {
            insert(node->left, key);
        } else if (key > node->key) {
            insert(node->right, key);
        }
    }

    bool search(const Node* node, const T& key) const {
        if (!node) return false;
        if (node->key == key) return true;
        return (key < node->key) ? search(node->left.get(), key) : search(node->right.get(), key);
    }

    std::unique_ptr<Node> remove(std::unique_ptr<Node> node, const T& key) {
        if (!node) return nullptr;

        if (key < node->key) {
            node->left = remove(std::move(node->left), key);
        } else if (key > node->key) {
            node->right = remove(std::move(node->right), key);
        } else {
            if (!node->left) return std::move(node->right);
            if (!node->right) return std::move(node->left);

            Node* successor = findMin(node->right.get());
            node->key = successor->key;
            node->right = remove(std::move(node->right), successor->key);
        }
        return node;
    }

    Node* findMin(Node* node) const {
        while (node->left) {
            node = node->left.get();
        }
        return node;
    }
};

#endif // BINARYSEARCHTREE_H