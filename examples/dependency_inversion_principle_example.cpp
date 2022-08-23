// Copyright (c) 2022 LucaWei
#include <architect/architect.hpp>

int main(int argc, char **argv) {
    std::shared_ptr<architect::Button> ibutton = std::make_shared<architect::Button>();
    std::shared_ptr<architect::Lamp> f32mulf32x = std::make_shared<architect::Lamp>();
    ibutton->turnOn(f32mulf32x);

    // CRPT
    std::cout << "-----------CRPT-----------" << std::endl;
    std::unique_ptr<architect::Player> Luca = std::make_unique<architect::Player>();
    std::unique_ptr<architect::Door> door_of_truth = std::make_unique<architect::Door>();
    std::unique_ptr<architect::Table> Luca_table = std::make_unique<architect::Table>();
    door_of_truth->setName("door_of_truth");
    Luca_table->setName("Luca's table");
    Luca->interactWith(*Luca_table);
    Luca->destroy(*Luca_table);
    Luca->interactWith(*door_of_truth);
    Luca->destroy(*door_of_truth);

    return 0;
}
