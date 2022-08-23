// Copyright (c)
#ifndef SRC_ARCHITECT_FACTORY_HPP_
#define SRC_ARCHITECT_FACTORY_HPP_
namespace architect {

// ------------------------------- //
//             Weapon              //
// ------------------------------- //
namespace backend {
template <typename weapon_type>
class Weapon {
 public:
    void display() {
        static_cast<weapon_type*>(this)->display();
    }

    void set() {
        static_cast<weapon_type*>(this)->set();
    }
};
}  // namespace backend

class Bow : backend::Weapon<Bow> {
 private:
    double atk_;
    double range_;
 public:
    Bow() = default;
    ~Bow() = default;

    void display() {
        std::cout
        << " atk= " << atk_
        << " range= " << range_
        << std::endl;
    }

    void set() {
        atk_ = 10.0;
        range_ = 1000.0;
    }
};

// ------------------------------- //
//             Clothes             //
// ------------------------------- //
namespace backend {
template <typename clothes_type>
class Clothes {
 public:
    void display() {
        static_cast<clothes_type*>(this)->display();
    }

    void set() {
        static_cast<clothes_type*>(this)->set();
    }
};
}  // namespace backend

class Leather : backend::Clothes<Leather> {
 private:
    double def_;
 public:
    Leather() = default;
    ~Leather() = default;

    void display() {
        std::cout
        << " def= " << def_
        << std::endl;
    }

    void set() {
        def_ = 8.0;
    }
};

// ------------------------------- //
//          Equip Factory          //
// ------------------------------- //
namespace backend {
template <typename equip_type>
class EquipFactory {
 public:
    void productWeapon() {
        static_cast<equip_type*>(this)->productWeapon();
    }
    void productArmor() {
        static_cast<equip_type*>(this)->productArmor();
    }
};
}  // namespace backend


class ArcherEquipFactory : backend::EquipFactory<ArcherEquipFactory> {
 private:
    std::shared_ptr<Bow> bow_;
    std::shared_ptr<Leather> leather_;
 public:
    ArcherEquipFactory() = default;
    ~ArcherEquipFactory() = default;

    const std::shared_ptr<Bow>& productWeapon() {
        bow_ = std::make_shared<Bow>();
        bow_->set();
        return bow_;
    }

    const std::shared_ptr<Leather>& productArmor() {
        leather_ = std::make_shared<Leather>();
        leather_->set();
        return leather_;
    }
};


// ------------------------------- //
//           Adventurer            //
// ------------------------------- //
namespace backend {
template<typename Adventurer_type>
class Adventurer {
 public:
    void getType() {
        static_cast<Adventurer_type*>(this)->getType();
    }

    void setWeapon() {
        static_cast<Adventurer_type*>(this)->setWeapon();
    }

    void setClothes() {
        static_cast<Adventurer_type*>(this)->setClothes();
    }

    void display() {
        static_cast<Adventurer_type*>(this)->display();
    }

    template <typename strategy_type>
    void attack(FightStrategy<strategy_type>&& attack_strategy) {
        static_cast<Adventurer_type*>(this)->attack();
    }
};
}  // namespace backend

class Archer : public backend::Adventurer<Archer> {
 private:
    std::shared_ptr<Bow> bow_{nullptr};
    std::shared_ptr<Leather> leather_{nullptr};

 public:
    Archer() = default;
    ~Archer() = default;

    void getType() {
        std::cout << "Hi I am an Archer!!" << std::endl;
    }

    void setWeapon(const std::shared_ptr<Bow>& bow) {
        bow_ = bow;
    }

    void setClothes(const std::shared_ptr<Leather>& leather) {
        leather_ = leather;
    }

    void display() {
        if (bow_) {
            std::cout << "<Bow>" << std::endl;
            bow_->display();
        } else {
            std::cout << "no Bow" << std::endl;
        }

        if (leather_) {
            std::cout << "<leather>" << std::endl;
            leather_->display();
        } else {
            std::cout << "no leather" << std::endl;
        }
    }

    template <typename strategy_type>
    void attack(backend::FightStrategy<strategy_type>&& attack_strategy) {
        attack_strategy.execute();
    }
};

// ------------------------------- //
//       Adventurer Factory        //
// ------------------------------- //
namespace backend {
template<typename Camp>
class TrainingCamp {
 public:
    void trainAdventurer() {
        static_cast<Camp*>(this)->trainAdventurer();
    }
};
}  // namespace backend

class ArcherTrainingCamp : public backend::TrainingCamp<ArcherTrainingCamp> {
 private:
    std::shared_ptr<Archer> adventurer_;
 public:
    ArcherTrainingCamp() = default;
    ~ArcherTrainingCamp() = default;

    const std::shared_ptr<Archer>& trainAdventurer() {
        std::cout << "Training an Archer!!" << std::endl;
        adventurer_ = std::make_shared<Archer>();
        const auto& archer_equip_factory = std::make_shared<ArcherEquipFactory>();
        adventurer_->setWeapon(archer_equip_factory->productWeapon());
        adventurer_->setClothes(archer_equip_factory->productArmor());
        return adventurer_;
    }
};

template <typename A>
class TrainCamp1 {
 private:
    std::shared_ptr<A> adventurer_;
 public:
    const std::shared_ptr<A>& trainAdventurer() {
        adventurer_ = std::make_shared<A>();
        const auto& archer_equip_factory = std::make_shared<ArcherEquipFactory>();
        adventurer_->setWeapon(archer_equip_factory->productWeapon());
        adventurer_->setClothes(archer_equip_factory->productArmor());
        return adventurer_;
    }
};



}  // namespace architect
#endif  // SRC_ARCHITECT_FACTORY_HPP_
