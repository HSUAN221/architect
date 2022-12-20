// Copyright (c)
#ifndef SRC_ARCHITECT_DISJOINT_SET_HPP_
#define SRC_ARCHITECT_DISJOINT_SET_HPP_
namespace architect {
class DisjointSet {
 private:
    class Element {
     public:
        size_t parent = 0;
        size_t rank = 0;

        Element() = default;

        ~Element() = default;

        Element(size_t p, size_t r)
        : parent(p), rank(r) {}
    };

    std::unordered_map<size_t, Element> element_list_;

 public:
    DisjointSet() = default;

    ~DisjointSet() = default;

    void makeSet(size_t v) {
        element_list_.insert(std::pair<size_t, Element>(v, Element(v, 0)));
    }

    size_t findSet(size_t v) {
        /// Debug mode
        bool is_find_v = element_list_.find(v) != element_list_.end();
        if (!is_find_v)
            throw std::invalid_argument(std::to_string(v) + " isn't exist");

        if (v == element_list_[v].parent)
            return v;
        return element_list_[v].parent = findSet(element_list_[v].parent);
    }

    void connect(size_t x, size_t y) {
        /// Debug mode
        bool is_find_x = element_list_.find(x) != element_list_.end();
        bool is_find_y = element_list_.find(y) != element_list_.end();
        if (!is_find_x && !is_find_y)
            throw std::invalid_argument(std::to_string(x)
            + std::to_string(y) + " isn't exist");

        auto root_x = findSet(x);
        auto root_y = findSet(y);
        auto& root_x_parent = element_list_[root_x].parent;
        auto& root_y_parent = element_list_[root_y].parent;
        auto& root_X_rank = element_list_[root_x].rank;
        auto& root_y_rank = element_list_[root_y].rank;

        if (root_x != root_y) {
            if (root_X_rank > root_y_rank) {
                root_y_parent = root_x;
            } else if (root_X_rank < root_y_rank) {
                root_x_parent = root_y;
            } else {
                root_y_parent = root_x;
                root_X_rank++;
            }
        }
    }
};

class DisjointSetFixSize {
 private:
    std::vector<size_t> parent_;
    std::vector<size_t> rank_;

 public:
    DisjointSetFixSize() = delete;

    explicit DisjointSetFixSize(size_t n = 0)
    : parent_(n), rank_(n, 0) {
        for (size_t i = 0; i < n; ++i)
            parent_[i] = i;
    }

    void makeSet(size_t v) {
        parent_[v] = v;
        rank_[v] = 0;
    }

    size_t findSet(size_t v) {
        if (v == parent_[v])
            return v;
        return parent_[v] = findSet(parent_[v]);
    }

    void connect(size_t x, size_t y) {
        auto root_x = findSet(x);
        auto root_y = findSet(y);
        if (root_x != root_y) {
            if (rank_[root_x] > rank_[root_y]) {
                parent_[root_y] = root_x;
            } else if (rank_[root_x] < rank_[root_y]) {
                parent_[root_x] = root_y;
            } else {
                parent_[root_y] = root_x;
                rank_[root_x]++;
            }
        }
    }

    ~DisjointSetFixSize() = default;
};

}  // namespace architect
#endif  // SRC_ARCHITECT_DISJOINT_SET_HPP_
