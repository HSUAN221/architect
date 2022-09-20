// Copyright (c) 2022 LucaWei
#include <architect/architect.hpp>
using architect::Target;
using architect::Adaptee;
using architect::Adapter;
using architect::MultiAdapter;
void ClinetCode(const std::shared_ptr<Target>& target) {
    assert(target);
    std::cout << target->request() << std::endl;
}

int main(int argc, char **argv) {
    std::cout << "Client: I can work just fine with the Target objects:" << std::endl;
    std::unique_ptr<Target> target = std::make_unique<Target>();
    ClinetCode(std::move(target));

    std::cout << "\n\n";
    std::unique_ptr<Adaptee> adaptee = std::make_unique<Adaptee>();
    std::cout << "Client: The Adaptee class has a weird interface. See, I don't understand it:\n";
    std::cout << adaptee->SpecificRequest() << std::endl;

    std::cout << "\n\n";
    std::unique_ptr<Adapter> adapter = std::make_unique<Adapter>(std::move(adaptee));
    std::cout << "Client: But I can work with it via the Adapter:" << std::endl;
    ClinetCode(std::move(adapter));

    std::cout << "\n\n";
    std::cout << "Client: But I can work with it via the MultiAdapter:" << std::endl;
    std::unique_ptr<MultiAdapter> multiadapter = std::make_unique<MultiAdapter>();
    std::cout << multiadapter->request() << std::endl;
    return 0;
}
