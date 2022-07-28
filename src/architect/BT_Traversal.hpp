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

    node_ptr_type root() {
        return root_;
    }

    explicit binary_tree(node_ptr_type node)
    : root_(node) {}

    bool preorder_recursive(node_ptr_type current) {
        if (current) {
            std::cout << current->data_ << std::endl;
            preorder_recursive(current->left_);
            preorder_recursive(current->right_);
        }
        return true;
    }

    bool inorder_recursive(node_ptr_type current) {
        if (current) {
            inorder_recursive(current->left_);
            std::cout << current->data_ << std::endl;
            inorder_recursive(current->right_);
        }
        return true;
    }
    bool postorder_recursive(node_ptr_type current) {
        if (current) {
            postorder_recursive(current->left_);
            postorder_recursive(current->right_);
            std::cout << current->data_ << std::endl;
        }
        return true;
    }
    bool levelorder() {
        std::queue<node_ptr_type> q;
        q.push(this->root_);

        while (!q.empty()) {
            node_ptr_type current = q.front();
            q.pop();
            std::cout << current->data_ << " ";

            if (current->left_ != nullptr) {
                q.push(current->left_);
            }

            if (current->right_ != nullptr) {
                q.push(current->right_);
            }
        }
        return true;
    }

    node_ptr_type mostleft(node_ptr_type current) {
        while (current->left_ != nullptr) {
            current = current->left_;
        }
        return current;
    }

    node_ptr_type inorderSuccessor(node_ptr_type current) {
        if (current->right_) {
            return mostleft(current->right_);
        }

        node_ptr_type successor = current->parent_;
        while (successor && current == successor->right_) {
            current = successor;
            successor = current->parent_;
        }
        return successor;
    }

    bool inorder(node_ptr_type root) {
        node_ptr_type current{mostleft(root)};

        while (current) {
            std::cout << current->data_ << " ";
            current = inorderSuccessor(current);
        }
        return true;
    }


 private:
    std::shared_ptr<tree_node> root_;
};



}  // namespace architect

#endif  // SRC_ARCHITECT_BT_TRAVERSAL_HPP_
