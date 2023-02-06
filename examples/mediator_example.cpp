// Copyright (c) 2022 LucaWei
#include <architect/architect.hpp>


int main(int argc, char **argv) {
    auto house_mediator = std::make_shared<architect::HouseMediator>();
    auto renter = new architect::Renter;
    auto landlord = new architect::Landlord;
    house_mediator->setRenter(renter);
    house_mediator->setLandlord(landlord);
    renter->send("i am r");

    // shared_ptr 循環依賴鏈
    auto A = std::make_shared<architect::TestA>();
    auto B = std::make_shared<architect::TestB>(A);
    return 0;
}
