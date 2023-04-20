// Copyright (c) 2022 LucaWei
#include <architect/architect.hpp>
class MathService {
 public:
    int state;

    float add(const float& a, const float& b) { return a + b; }
    float subtract(const float& a, const float& b) { return a - b; }
    float multiply(const float& a, const float& b) { return a * b; }
    float divide(const float& a, const float& b) { return a / b; }
};

int main(int argc, char **argv) {
    architect::ServiceLocator locator;
    locator.registerInstance<MathService>(new MathService());
    auto math_service = locator.resolve<MathService>();
    std::cout << math_service->add(10, 23) << std::endl;
    return 0;
}
