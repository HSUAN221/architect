// Copyright (c)
#ifndef SRC_ARCHITECT_LABELING_HPP_
#define SRC_ARCHITECT_LABELING_HPP_
namespace architect {
class Labeling {
 private:
    std::vector<std::vector<int>> domain_;
    std::vector<std::vector<int>> labels_;
    DisjointSet ds_;
    int rows_ = 0, cols_ = 0;
    std::vector<std::pair<int, int>> idx_list_;

    std::vector<int> getNeighborsLabel(int x, int y) {
        std::vector<int> neighbors;
        neighbors.reserve(4);
        if (x > 0)
            neighbors.push_back(labels_[x-1][y]);
        if (y > 0)
            neighbors.push_back(labels_[x][y-1]);
        if (x < rows_ - 1)
            neighbors.push_back(labels_[x+1][y]);
        if (y < cols_ - 1)
            neighbors.push_back(labels_[x][y+1]);
        return neighbors;
    }

 public:
    Labeling() = delete;

    ~Labeling() = default;

    explicit Labeling(const std::vector<std::vector<int>>& domain)
    : domain_(domain) {
        rows_ = domain_.size();
        cols_ = domain_[0].size();
        labels_.resize(rows_, std::vector<int>(cols_, 0));
    }

    std::vector<std::vector<int>> getDomainSet() {
        /// allocate index of 1-elements
        for (int i = 0; i < rows_; ++i) {
            for (int j = 0; j < cols_; ++j) {
                if (domain_[i][j] == 1) {
                    idx_list_.push_back(std::pair<int, int>(i, j));
                }
            }
        }

        /// label all 1-elements
        /// And make set
        int current_label = 1;
        for (const auto& iter : idx_list_) {
            labels_[iter.first][iter.second] = current_label++;
            ds_.makeSet(labels_[iter.first][iter.second]);
        }

        /// find neighbors, if neighbor > 0 -> connect
        for (const auto& iter : idx_list_) {
            const auto& neighbors = getNeighborsLabel(iter.first, iter.second);
            for (const auto& n : neighbors) {
                if (n != 0)
                    ds_.connect(labels_[iter.first][iter.second], n);
            }
        }

        /// group all labels
        for (const auto& iter : idx_list_) {
            labels_[iter.first][iter.second] = ds_.findSet(labels_[iter.first][iter.second]);
        }
        return labels_;
    }

};
}  // namespace architect
#endif  // SRC_ARCHITECT_LABELING_HPP_
