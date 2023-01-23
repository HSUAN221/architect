// Copyright (c) 2022 LucaWei
#include <architect/architect.hpp>

namespace backend {
class IOException : public std::exception {
 public:
    const char* what() const noexcept override {
        return "IO Error";
    }
};
}


int main(int argc, char **argv) {
    std::vector<int> v = {1, 2, 3};
    /// input region
    try {
        // std::cout << v.at(3) << "\n";
        throw backend::IOException();
        // throw std::invalid_argument("Division by zero condition!");
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
        architect::LoggerA::getInstance().info(e.what());
        architect::LoggerB::info(e.what());
        architect::LoggerB::show(e.what());
    }
    return 0;
}
