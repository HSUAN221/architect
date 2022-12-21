// Copyright (c)
#ifndef SRC_ARCHITECT_UTILITY_HPP_
#define SRC_ARCHITECT_UTILITY_HPP_
namespace architect {
class DomainBuilder {
 private:
    int rows_ = 0, cols_ = 0;

 public:
    DomainBuilder() = delete;

    DomainBuilder(int rows, int cols)
    : rows_(rows), cols_(cols) {}

    ~DomainBuilder() = default;

    void build() {
        std::vector<std::vector<int>> domain;
        domain.resize(rows_, std::vector<int>(cols_, 0));
        std::uniform_int_distribution<> distrib(0, 1);
        for (int i = 0; i < rows_; ++i) {
            for (int j = 0; j < cols_; ++j) {
                size_t c = distrib(architect::generator);
                domain[i][j] = c;
            }
        }

        std::ofstream domain_file("data/domain.txt");
        for (int i = 0; i < rows_; ++i) {
            for (int j = 0; j < cols_; ++j) {
                domain_file << domain[i][j] << " ";
            }
            domain_file << std::endl;
        }
    }

    std::vector<std::vector<int>> parse() {
        std::ifstream file("data/domain.txt");
        std::vector<std::vector<int>> domain;
            domain.resize(rows_, std::vector<int>(cols_, 0));
        for (int i = 0; i < rows_; ++i) {
            for (int j = 0; j < cols_; ++j) {
                int temp = 0;
                file >> temp;
                domain[i][j] = temp;
            }
        }
        return domain;
    }
};

}  // namespace architect
#endif  // SRC_ARCHITECT_UTILITY_HPP_
