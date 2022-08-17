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

    explicit binary_tree(const std::vector<string_type>& str) {
        root_ = std::make_shared<tree_node>();
        root_->data_ = str[0];
        LevelorderConstruct(str);
    }

    bool LevelorderConstruct(const std::vector<string_type>& str) {
        node_ptr_type current = root_;
        std::queue<node_ptr_type> q;
        string_type data{"x"};

        for (const auto& iter : str) {
            if (iter[0] >= 65 && iter[0] <= 90) {
                node_ptr_type new_node = std::make_shared<tree_node>(iter);
                new_node->parent_ = current;
                current->left_ = new_node;
                q.push(new_node);
            }

            if (iter[0] >= 65 && iter[0] <= 90) {
                node_ptr_type new_node = std::make_shared<tree_node>(iter);
                new_node->parent_ = current;
                current->right_ = new_node;
                q.push(new_node);
            }

            current = q.front();
        }
        return true;
    }

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

    node_ptr_type InorderSuccessor(node_ptr_type current) {
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
            current = InorderSuccessor(current);
        }
        return true;
    }

    node_ptr_type mostright(node_ptr_type current) {
        while (current->right_) {
            current = current->right_;
        }
        return current;
    }

    node_ptr_type InorderPredecessor(node_ptr_type current) {
        if (current->left_) {
            return mostright(current->left_);
        }

        node_ptr_type predecessor = current->parent_;
        while (predecessor && current == predecessor->left_) {
            current = predecessor;
            predecessor = predecessor->parent_;
        }
        return predecessor;
    }

    bool inorder_reverse(node_ptr_type root) {
        node_ptr_type current{ mostright(root)};

        while (current) {
            std::cout << current->data_ << " ";
            current = InorderPredecessor(current);
        }
        return true;
    }


 private:
    std::shared_ptr<tree_node> root_;
};



}  // namespace architect

#endif  // SRC_ARCHITECT_BT_TRAVERSAL_HPP_
