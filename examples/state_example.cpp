// Copyright (c) 2023 LucaWei
#include <architect/architect.hpp>

int main(int argc, char **argv) {
    auto context = std::make_shared<architect::Context>(new architect::StateA);
    context->request();
    context->changeState(new architect::StateB);
    context->request();
    return 0;
}
