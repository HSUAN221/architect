// Copyright (c) 2022 LucaWei
#include <architect/architect.hpp>

class MathServiceInterface {
 public:
    virtual float add(const float& a, const float& b) {
        std::cout << "Hi, I'm default add ^^" << std::endl;
        return 0;
    }
};

class MathService1 : public MathServiceInterface {
 public:
    int state;

    float add(const float& a, const float& b) override { return a + b; }
    float subtract(const float& a, const float& b) { return a - b; }
    float multiply(const float& a, const float& b) { return a * b; }
    float divide(const float& a, const float& b) { return a / b; }
};

class MathService2 : public MathServiceInterface {
 public:
    int state;

    float add(const float& a, const float& b) override { return (a + b) * 2; }
    float subtract(const float& a, const float& b) { return a - b; }
    float multiply(const float& a, const float& b) { return a * b; }
    float divide(const float& a, const float& b) { return a / b; }
};

class MathService3 : public MathServiceInterface {
 public:
    int state;
    double val;

    explicit MathService3(double val) : val(val) {}
    float add(const float& a, const float& b) override { return (a + b) * 200; }
};

class Solver {
 private:
    const architect::ServiceLocator& locator_;

 public:
    explicit Solver(const architect::ServiceLocator& locator)
    : locator_(locator) {}

    std::shared_ptr<MathService3> mathPackage() {
        // locator_.resolve<MyMathPackage>()->val = 4156.123;
        return locator_.resolve<MathService3>();
    }

    void showVar() {
        auto math_pkg = locator_.resolve<MathService3>();
        std::cout << "<inside solver object> " << math_pkg->val << " " << math_pkg->state << std::endl;
    }
};


class Test {
 public:
    int type = 0;

};


int main(int argc, char **argv) {
    /// 建立服務定位者
    architect::ServiceLocator locator;

    /// 服務定位者註冊 MathService1 物件，並使用其物件。
    locator.registerInstance<MathService1>();
    const auto& math_service_1 = locator.resolve<MathService1>();
    std::cout << math_service_1->add(10, 23) << std::endl;

    /// 服務定位者註冊 MathService2 物件，並使用其物件。
    locator.registerInstance<MathService2>();
    const auto& math_service_2 = locator.resolve<MathService2>();
    std::cout << math_service_2->add(10, 23) << std::endl;

    /// 服務定位者註冊 MathService3 物件，然後初始化內部變數。
    architect::ServiceLocator solver_locator;
    solver_locator.registerInstance<MathService3>(new MathService3(5.2));
    const auto& math_service_3 = solver_locator.resolve<MathService3>();
    math_service_3->state = 2;

    /// 注入其相依於 Solver 物件，並從 solver 物件拿出 pkg。
    auto solver = std::make_shared<Solver>(solver_locator);
    auto math_service_3_from_solver = solver->mathPackage();
    std::cout << "<outside solver object> "
    << math_service_3_from_solver->val << " " << math_service_3_from_solver->state << std::endl;
    math_service_3_from_solver->val = 58;
    /// solver 內使用 pkg
    solver->showVar();


    Test test;
    test.type = 55;

    MathService2 math_2;
    architect::ServiceLocator test_locator;
    test_locator.registerInstance(math_2);
    test_locator.registerInstance<Test>(test);
    auto math_2_ptr = locator.resolve<MathService2>();
    auto test_2_ptr = test_locator.resolve<Test>();
    std::cout << "g " << math_2_ptr->add(5, 100) << std::endl;
    std::cout << "g " << test_2_ptr->type << std::endl;
    test_2_ptr->type = 125;

    std::cout << "g2 " << test_2_ptr->type << std::endl;

    return 0;
}
