// Copyright (c) 2022 LucaWei
#include <architect/architect.hpp>

struct Widget1 {
    std::string hello() { return "widget1"; }
};

struct Widget2 {
    std::string hello() { return "widget2"; }
};

struct Widget3 {
    // Widget3 objects share their components. This is now documented in the interface here...
    Widget3(const std::shared_ptr<Widget1>& widget1, const std::shared_ptr<Widget2>& widget2)
    : _widget1(widget1) , _widget2(widget2) {}

    void doSomething() {
        std::cout << "<doSomething> " << _widget1->hello()
        << " " << _widget1.get() << std::endl;
        std::cout << "<doSomething> " << _widget2->hello()
        << " " << _widget2.get() << std::endl;
    }
 private:
    std::shared_ptr<Widget1> _widget1;
    std::shared_ptr<Widget2> _widget2;
};

auto main() -> int {
    using architect::Subject;
    using architect::Observer;
    const auto& subject = std::make_shared<Subject>();

    const auto& observer1 = std::make_shared<Observer>();
    observer1->setSubject(subject);

    const auto& observer2 = std::make_shared<Observer>();
    observer2->setSubject(subject);

    std::cout << "  ---Use createMessage---" << std::endl;
    subject->createMessage("YES Amy");

    observer2->removeMeFromTheList();

    std::cout << "  ---Use createMessage---" << std::endl;
    subject->createMessage("YES Luca");

    observer1->removeMeFromTheList();


    /// Here, test that moving an unique_ptr to shared_ptr parameter of constructor
    auto w1a = std::make_unique<Widget1>();
    auto w2a = std::make_unique<Widget2>();
    std::cout << "<before constructor> " << w1a.get() << " " << w2a.get() << std::endl;
    // note the automatic move-conversion from unique_ptr to shared_ptr
    auto w3a = std::make_unique<Widget3>(std::move(w1a), std::move(w2a));
    w3a->doSomething();
    std::cout << "<after constructor> " << w1a.get() << " " << w2a.get() << std::endl;

    // make unique widget3 that uses shared components
    const auto& w1b = std::make_shared<Widget1>();
    const auto& w2b = std::make_shared<Widget2>();
    std::cout << "<before constructor> " << w1b.get() << " " << w2b.get() << std::endl;
    auto w3b = std::make_unique<Widget3>(w1b, w2b);
    w3b->doSomething();
    std::cout << "<after constructor> " << w1b.get() << " " << w2b.get() << std::endl;

    return 0;
}
