// Copyright (c)
// 中介者模式缺點，中介者物件會演化成上帝對象
// 中介者模式在 C++ 代碼中最常用於幫助程序 GUI 組件之間的通信。
// 在 MVC 模式中， 控制器是中介者的同義詞。
#ifndef SRC_ARCHITECT_MEDIATOR_HPP_
#define SRC_ARCHITECT_MEDIATOR_HPP_
namespace architect {
class BaseComponent;

class BaseMediator {
 public:
    virtual void notify(BaseComponent* sender, std::string event) const = 0;
    virtual ~BaseMediator() {
        std::cout << ">> BaseMediator destructor" << std::endl;
    }
};

class BaseComponent {
 protected:
    BaseMediator* mediator_;

 public:
    explicit BaseComponent(BaseMediator* mediator = nullptr)
    : mediator_(mediator) {}

    void setMediator(BaseMediator* mediator) {
        mediator_ = mediator;
    }

    virtual ~BaseComponent() {
        // delete mediator_;
        std::cout << ">> BaseComponent destructor" << std::endl;
    }

    virtual void send(const std::string& message) = 0;
    virtual void recv(const std::string& message) = 0;
};



class Renter : public BaseComponent {
    using base = BaseComponent;

 private:
    void recv(const std::string& message) {
        std::cout << "Renter get message: " << message << std::endl;
    }

 public:
    Renter() = default;

    virtual ~Renter() {
        std::cout << ">> Renter destructor" << std::endl;
    }

    void send(const std::string& message) {
        mediator_->notify(this, message);
    }
};

class Landlord : public BaseComponent {
    using base = BaseComponent;

 private:
    void recv(const std::string& message) {
        std::cout << "Landlord get message: " << message << std::endl;
    }

 public:
    Landlord() = default;

    virtual ~Landlord() {
        std::cout << ">> Landlord destructor" << std::endl;
    }

    void send(const std::string& message) {
        mediator_->notify(this, message);
    }

};

class HouseMediator : public BaseMediator {
 private:
    BaseComponent* renter_;
    BaseComponent* landlord_;

 public:
    HouseMediator() = default;

    virtual ~HouseMediator() {
        delete renter_;
        delete landlord_;
        std::cout << ">> HouseMediator destructor" << std::endl;
    }

    void setRenter(BaseComponent* renter) {
        renter_ = renter;
        renter_->setMediator(this);
    }

    void setLandlord(BaseComponent* landlord) {
        landlord_ = landlord;
        landlord_->setMediator(this);
    }

    virtual void notify(BaseComponent* sender, std::string event) const {
        if (sender == renter_) {
            landlord_->recv(event);
        } else {
            renter_->recv(event);
        }
    }
};


class TestA {
 public:
    ~TestA() {
        std::cout << ">> TestA destructor" << std::endl;
    }
};

class TestB {
 public:
    std::shared_ptr<TestA> A_;
    explicit TestB(const std::shared_ptr<TestA>& A)
    : A_(A) {}

    ~TestB() {
        std::cout << ">> TestB destructor" << std::endl;
    }
};

}  // namespace architect
#endif  // SRC_ARCHITECT_MEDIATOR_HPP_
