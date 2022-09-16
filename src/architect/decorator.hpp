// Copyright (c)
#ifndef SRC_ARCHITECT_DECORATOR_HPP_
#define SRC_ARCHITECT_DECORATOR_HPP_
namespace architect {
class Spaghetti {
 public:
    virtual float getPrice() = 0;

    virtual std::string getName() = 0;

    virtual std::string getRecipe() = 0;
};

class NormalSpaghetti : public Spaghetti {
 public:
    NormalSpaghetti() {}

    float getPrice() override {
        return 100.0;
    }

    std::string getName() override {
        return "Spaghetti";
    }

    std::string getRecipe() override {
        return "Spaghetti";
    }
};

class CondimentDecorator : public Spaghetti {};

class HamDecorator : public CondimentDecorator {
 private:
    std::string name_{"Ham"};
    std::shared_ptr<Spaghetti> spaghetti_{nullptr};

 public:
    explicit HamDecorator(const std::shared_ptr<Spaghetti>& spaghetti)
    : spaghetti_(spaghetti) {}

    float getPrice() override {
        return spaghetti_->getPrice() + 38.0;
    }

    std::string getName() override {
        return name_ + " " + spaghetti_->getName();
    }

    std::string getRecipe() override {
        return spaghetti_->getRecipe() + ", " + name_;
    }
};

class EggDecorator : public CondimentDecorator {
 private:
    std::string name_{"Egg"};
    std::shared_ptr<Spaghetti> spaghetti_{nullptr};

 public:
    explicit EggDecorator(const std::shared_ptr<Spaghetti>& spaghetti)
    : spaghetti_(spaghetti) {}

    float getPrice() override {
        return spaghetti_->getPrice() + 12.0;
    }

    std::string getName() override {
        return name_ + " " + spaghetti_->getName();
    }

    std::string getRecipe() override {
        return spaghetti_->getRecipe() + ", " + name_;
    }
};



class person {
 public:
    void addAge() {
        age_++;
    }

    void showAge() {
        std::cout << age_ << std::endl;
    }

    static int age_;
};

int person::age_ = 10;

class Jack : public person {
 public:
    void addAge() {
        age_++;
    }

    void showAge() {
        std::cout << age_ << std::endl;
    }
};


}  // namespace architect
#endif  // SRC_ARCHITECT_DECORATOR_HPP_
