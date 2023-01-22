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
    } catch (const backend::IOException& my_exception) {
        std::cout << my_exception.what() << std::endl;
        architect::LoggerA::getInstance().info(my_exception.what());
        architect::LoggerB::info(my_exception.what());
        architect::LoggerB::show(my_exception.what());
    } catch (const std::invalid_argument i) {
        std::cout << i.what() << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
