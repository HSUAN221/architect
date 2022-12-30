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

        // for (int i = 0; i < rows_; ++i) {
        //     for (int j = 0; j < cols_; ++j) {
        //         if (i > 10 && i < 20 && j > 10 && j < 20) {
        //             domain[i][j] = 1;
        //         } else if (i > 30 && i < 50 && j > 30 && j < 50) {
        //             domain[i][j] = 1;
        //         } else if (i > 30 && i < 50 && j > 60 && j < 50) {
        //             domain[i][j] = 1;
        //         } else {
        //             domain[i][j] = 0;
        //         }
        //     }
        // }

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



class Timer {
 public:
    void start() {
        t_start = std::chrono::high_resolution_clock::now();
    }

    void stop() {
        t_stop = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> d = t_stop - t_start;
        total = d.count();
    }

    double elapsedTime() { return total;}

    static double resolution() {
        auto tmp = std::chrono::high_resolution_clock::period();
        return static_cast<double>(tmp.num) / tmp.den;
    }

 private:
    std::chrono::high_resolution_clock::time_point t_start, t_stop;
    double total = 0;
};

}  // namespace architect
#endif  // SRC_ARCHITECT_UTILITY_HPP_
