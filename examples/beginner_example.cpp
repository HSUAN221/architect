#include <architect/architect.hpp>

int main(int argc, char **argv) {
    architect::beginner bg(5);
    auto result{bg.getValue()};
    std::cout << result << std::endl;
    return 0;
}