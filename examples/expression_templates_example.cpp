// Copyright (c) 2022 LucaWei
#include <architect/architect.hpp>

int main(int argc, char **argv) {
    architect::expression::vector<double> v0 = {23.4, 12.5, 144.56, 90.56};
    architect::expression::vector<double> v1 = {67.12, 34.8, 90.34, 89.30};
    architect::expression::vector<double> v2 = {34.90, 111.9, 45.12, 90.5};
    architect::expression::vector<double> v3 = {34.90, 111.9, 45.12, 90.5};

    auto vec = v0 + v1 + v2;
    std::cout << vec[0] << std::endl;
    std::cout << vec[1] << std::endl;
    std::cout << vec[2] << std::endl;
    std::cout << vec[3] << std::endl;
    return 0;
}
