// Copyright (c) 2022 LucaWei
#include <architect/architect.hpp>

int main(int argc, char **argv) {
    architect::vector<double> v0 = {23.4, 12.5, 144.56, 90.56};
    architect::vector<double> v1 = {67.12, 34.8, 90.34, 89.30};
    architect::vector<double> v2 = {34.90, 111.9, 45.12, 90.5};
    architect::vector<double> v3 = {34.90, 111.9, 45.12, 90.5};

    auto vec = v0 + v1 + v2 + v3;
    std::cout << vec[0] << std::endl;

    auto vec1 = v0 * v1 * v2 * v3;
    std::cout << vec1[0] << std::endl;

    return 0;
}
