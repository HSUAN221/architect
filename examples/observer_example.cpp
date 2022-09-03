// Copyright (c) 2022 LucaWei
#include <architect/architect.hpp>

int main(int argc, char **argv) {
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

    return 0;
}
