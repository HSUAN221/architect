// Copyright (c) 2022 LucaWei
#include <architect/architect.hpp>

int main(int argc, char **argv) {
    using architect::ArcherEquipFactory;
    const auto& archer_equip_factory = std::make_shared<ArcherEquipFactory>();
    const auto& archer_weapon = archer_equip_factory->productWeapon();
    archer_weapon->display();
    const auto& archer_armor = archer_equip_factory->productArmor();
    archer_armor->display();

    std::cout << "  <method1>" << std::endl;
    using architect::ArcherTrainingCamp;
    const auto& archer_training_camp = std::make_shared<ArcherTrainingCamp>();
    const auto& memberA = archer_training_camp->trainAdventurer();
    memberA->getType();
    memberA->display();
    memberA->attack(architect::NormalAttack());
    memberA->attack(architect::UseSkill());

    std::cout << "  <method2>" << std::endl;
    using architect::TrainCamp1;
    const auto& archer_training_camp1 = std::make_shared<TrainCamp1<architect::Archer>>();
    const auto& memberB = archer_training_camp1->trainAdventurer();
    memberB->getType();
    memberB->display();
    memberB->attack(architect::NormalAttack());
    memberB->attack(architect::UseSkill());

    return 0;
}
