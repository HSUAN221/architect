// Copyright (c) 2022 LucaWei
#include <architect/architect.hpp>

int main(int argc, char **argv) {
    std::shared_ptr<Button> ibutton = std::make_shared<Button>();
    std::shared_ptr<lamp> f32mulf32x = std::make_shared<lamp>();
    ibutton->turnOn(f32mulf32x);

    // CRPT
    std::cout << "-----------CRPT-----------" << std::endl;
    std::unique_ptr<player> Luca = std::make_unique<player>();
    std::unique_ptr<Door> door_of_truth = std::make_unique<Door>();
    std::unique_ptr<Table> Luca_table = std::make_unique<Table>();
    door_of_truth->setName("door_of_truth");
    Luca_table->setName("Luca's table");
    Luca->interactWith(*Luca_table);
    Luca->destroy(*Luca_table);
    Luca->interactWith(*door_of_truth);
    Luca->destroy(*door_of_truth);

    return 0;
}
