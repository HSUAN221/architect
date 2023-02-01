// Copyright (c)
// 當多個 Class 都需要接收同一種資料的變化時，就適合使用 Observer Pattern
#ifndef SRC_ARCHITECT_OBSERVER_HPP_
#define SRC_ARCHITECT_OBSERVER_HPP_
namespace architect {

class ObserverInterface {
 public:
    virtual ~ObserverInterface() {}
    virtual void update(const std::string& message_from_subject) = 0;
};

class SubjectInterface {
    using observer_ptr = std::shared_ptr<ObserverInterface>;

 public:
    virtual ~SubjectInterface() {}
    virtual void attach(const observer_ptr& observer) = 0;
    virtual void detach(const observer_ptr& observer) = 0;
 private:
    virtual void notify() = 0;
};


// ------------------------------- //
//             Subject             //
// ------------------------------- //
class Subject : public SubjectInterface {
    using observer_ptr = std::shared_ptr<ObserverInterface>;

 private:
  std::list<observer_ptr> list_observer_;
  std::string message_;

 public:
    virtual ~Subject() {
        std::cout << "Goodbye, I was the Subject.\n";
    }

    void attach(const observer_ptr& observer) override {
        list_observer_.push_back(observer);
    }

    void detach(const observer_ptr& observer) override {
        list_observer_.remove(observer);
    }

    void createMessage(std::string message = "Empty") {
        message_ = message;
        notify();
    }

 private:
    void notify() {
        std::cout << "There are " << list_observer_.size()
        << " observers in the list." << std::endl;

        for (auto& iter : list_observer_) {
            iter->update(message_);
        }
    }
};

// ------------------------------- //
//            Observer             //
// ------------------------------- //
class Observer : public ObserverInterface, public std::enable_shared_from_this<Observer> {
    using subject_ptr = std::shared_ptr<SubjectInterface>;

 private:
    std::string message_from_subject_;
    subject_ptr subject_;
    static int static_number_;
    int number_;

 public:
    Observer() {}

    virtual ~Observer() {
        std::cout << "Goodbye, I was the Observer \"" << this->number_ << "\".\n";
    }

    void addMeToTheList(const subject_ptr& subject) {
        subject_ = subject;
        std::cout << "Hi, I'm the Observer \"" << ++Observer::static_number_ << "\".\n";
        number_ = Observer::static_number_;
        subject_->attach(shared_from_this());
    }

    void update(const std::string& message_from_subject) {
        message_from_subject_ = message_from_subject;
        std::cout << "Observer \"" << number_
        << "\": a new message is available --> " << message_from_subject_ << "\n";
    }

    void removeMeFromTheList() {
        assert(subject_);
        subject_->detach(shared_from_this());
        std::cout << "Observer \"" << number_ << "\" removed from the list.\n";
    }
};
int Observer::static_number_ = 0;
}  // namespace architect
#endif  // SRC_ARCHITECT_OBSERVER_HPP_
