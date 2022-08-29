// Copyright (c) 2022 LucaWei
#include <architect/architect.hpp>

void showInfo(const std::shared_ptr<architect::Spaghetti>& spaghetti) {
    std::cout << "<" << spaghetti->getName() << ">" << std::endl;
    std::cout << spaghetti->getPrice() << std::endl;
    std::cout << spaghetti->getRecipe() << std::endl;
    std::cout << std::endl;
}

int main(int argc, char **argv) {
    auto normalSpaghetti = std::make_shared<architect::NormalSpaghetti>();
    showInfo(normalSpaghetti);

    auto HamSpaghetti = std::make_shared<architect::HamDecorator>(normalSpaghetti);
    showInfo(HamSpaghetti);

    auto EggHamSpaghetti = std::make_shared<architect::EggDecorator>(HamSpaghetti);
    showInfo(EggHamSpaghetti);
    return 0;
}
