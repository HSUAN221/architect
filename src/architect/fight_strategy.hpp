// Copyright (c)
#ifndef SRC_ARCHITECT_FIGHT_STRATEGY_HPP_
#define SRC_ARCHITECT_FIGHT_STRATEGY_HPP_
namespace architect {

namespace backend {
template <typename strategy_type>
class FightStrategy {
 public:
    void execute() {
        static_cast<strategy_type*>(this)->execute();
    }
};
}  // namespace backend


class NormalAttack : public backend::FightStrategy<NormalAttack> {
 public:
    NormalAttack() = default;
    ~NormalAttack() = default;

    void execute() {
        std::cout << "Normal Attack" <<std::endl;
    }
};

class UseSkill : public backend::FightStrategy<UseSkill> {
 public:
    UseSkill() = default;
    ~UseSkill() = default;

    void execute() {
        std::cout << "Use Skill" <<std::endl;
    }
};


}  // namespace architect
#endif  // SRC_ARCHITECT_FIGHT_STRATEGY_HPP_
