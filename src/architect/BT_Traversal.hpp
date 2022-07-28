// Copyright (c) 2022 LucaWei
#ifndef SRC_ARCHITECT_BT_TRAVERSAL_HPP_
#define SRC_ARCHITECT_BT_TRAVERSAL_HPP_

#include <architect/definitions.hpp>
namespace architect {
class binary_tree;
class tree_node {
using node_ptr_type = std::shared_ptr<tree_node>;

 public:
    tree_node()
    : left_(nullptr), right_(nullptr), parent_(nullptr), data_("") {}
    ~tree_node() {}

    string_type getData() {
        return data_;
    }

    bool setLeft(node_ptr_type node_ptr) {
        left_ = node_ptr;
        return true;
    }

    bool setRight(node_ptr_type node_ptr) {
        right_ = node_ptr;
        return true;
    }

    bool setParent(node_ptr_type node_ptr) {
        parent_ = node_ptr;
        return true;
    }

    explicit tree_node(string_type data)
    : left_(nullptr), right_(nullptr), parent_(nullptr) {
        data_ = data;
    }

    friend class binary_tree;

 private:
    std::shared_ptr<tree_node> left_;
    std::shared_ptr<tree_node> right_;
    std::shared_ptr<tree_node> parent_;
    string_type  data_;
};

class binary_tree {
    using node_ptr_type = std::shared_ptr<tree_node>;

 public:
    binary_tree() : root_(nullptr) {}

    explicit binary_tree(node_ptr_type node)
    : root_(node) {}

    bool preorder(node_ptr_type current) {
        if (current) {
            std::cout << current->data_ << std::endl;
            preorder(current->left_);
            preorder(current->right_);
        }
        return true;
    }

    bool inorder(node_ptr_type current) {
        if (current) {
            inorder(current->left_);
            std::cout << current->data_ << std::endl;
            inorder(current->right_);
        }
        return true;
    }
    bool postorder(node_ptr_type current) {
        if (current) {
            postorder(current->left_);
            postorder(current->right_);
            std::cout << current->data_ << std::endl;
        }
        return true;
    }
    bool levelorder() {
        std::queue<node_ptr_type> q;
    }


 private:
    std::shared_ptr<tree_node> root_;
};



}  // namespace architect

#endif  // SRC_ARCHITECT_BT_TRAVERSAL_HPP_
