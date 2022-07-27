// Copyright (c) 2022 LucaWei
#ifndef SRC_ARCHITECT_BINARY_TREE_HPP_
#define SRC_ARCHITECT_BINARY_TREE_HPP_

#include <architect/definitions.hpp>
namespace architect {

class binary_tree {

    class tree_node {
     public:
        tree_node()
        : left_(nullptr), right_(nullptr), parent_(nullptr), data_('x') {}

        explicit tree_node(char data)
        : left_(nullptr), right_(nullptr), parent_(nullptr) {
            data_ = data;
        }

        friend class binary_tree;

     private:
        std::shared_ptr<tree_node> left_;
        std::shared_ptr<tree_node> right_;
        std::shared_ptr<tree_node> parent_;
        char  data_;
    };

 public:
    binary_tree()
    : root(nullptr) {}

    explicit binary_tree(const char* str) {
        std::stringstream ss;
        ss << str;
        root = std::make_shared<tree_node>();
    }

 private:
    std::shared_ptr<tree_node> root;
};

}  // namespace architect

#endif  // SRC_ARCHITECT_BINARY_TREE_HPP_
