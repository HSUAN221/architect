// Copyright (c)
#ifndef SRC_ARCHITECT_DEPENDENCY_INVERSION_PRINCIPLE_HPP_
#define SRC_ARCHITECT_DEPENDENCY_INVERSION_PRINCIPLE_HPP_
namespace architect {

class SwitchDevice {
 private:
    virtual bool turnOn() = 0;
    virtual bool turnOff() = 0;
 public:
    SwitchDevice() = default;
    virtual ~SwitchDevice() = default;
    friend class Button;
};

class Lamp : public SwitchDevice {
 public:
    Lamp() {}
    ~Lamp() = default;
    bool turnOn() override {
        std::cout << "Lamp turn on" << std::endl;
        return true;
    }

    bool turnOff() override {
        std::cout << "Lamp turn off" << std::endl;
        return true;
    }
};

class Button {
 public:
    Button() = default;
    ~Button() = default;
    bool turnOn(const std::shared_ptr<SwitchDevice>& obj) {
        if (obj) {
            return obj->turnOn();
        }
        return false;
    }
};

// CRPT
template<typename specific_object>
class IteractiveObject1 {
 public:
    void interact() {
        std::cout << "interact" << std::endl;
        static_cast<specific_object*>(this)->interact();
    }

    void destroy() {
        std::cout << "destroy" << std::endl;
        static_cast<specific_object*>(this)->destroy();
    }
};

class Door : public IteractiveObject1<Door> {
 private:
    bool open_{false};
    std::string name_;

 public:
    Door() = default;
    ~Door() = default;

    void setName(std::string door_name) {
        name_ = door_name;
    }

    void interact() {
        open_ = !open_;
        if (open_) {
            std::cout << name_ + " is open!!" << std::endl;
        } else {
            std::cout << name_ + " is close!!" << std::endl;
        }
    }

    void destroy() {
        std::cout << name_ + " is destroy!!" << std::endl;
    }
};

class Table : public IteractiveObject1<Table> {
 private:
    std::string name_;

 public:
    Table() = default;
    ~Table() = default;

    void setName(std::string table_name) {
        name_ = table_name;
    }

    void interact() {
            std::cout << name_ + " is moved!!" << std::endl;
    }

    void destroy() {
        std::cout << name_ + " is destroy!!" << std::endl;
    }
};

class Player {
 public:
    template<typename specific_object>
    void interactWith(IteractiveObject1<specific_object>& object) {
        object.interact();
    }

    template<typename specific_object>
    void destroy(IteractiveObject1<specific_object>& object) {
        object.destroy();
    }
};

}  // namespace architect
#endif  // SRC_ARCHITECT_DEPENDENCY_INVERSION_PRINCIPLE_HPP_
