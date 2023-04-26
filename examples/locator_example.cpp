// Copyright (c) 2022 LucaWei
#include <architect/architect.hpp>

class MathServiceInterface {};

class MathService : public MathServiceInterface {
 public:
    int state;

    float add(const float& a, const float& b) { return a + b; }
    float subtract(const float& a, const float& b) { return a - b; }
    float multiply(const float& a, const float& b) { return a * b; }
    float divide(const float& a, const float& b) { return a / b; }
};

class MyMathService : public MathServiceInterface {
 public:
    int state;

    float add(const float& a, const float& b) { return (a + b) * 2; }
    float subtract(const float& a, const float& b) { return a - b; }
    float multiply(const float& a, const float& b) { return a * b; }
    float divide(const float& a, const float& b) { return a / b; }
};

class MyMathPackage : public MathServiceInterface {
 public:
    int state;
    double val;

    explicit MyMathPackage(double val) : val(val) {}
};

class Solver {
 private:
    const architect::ServiceLocator& locator_;

 public:
    explicit Solver(const architect::ServiceLocator& locator)
    : locator_(locator) {}

    std::shared_ptr<MyMathPackage> mathPackage() {
        // locator_.resolve<MyMathPackage>()->val = 4156.123;
        return locator_.resolve<MyMathPackage>();
    }

    void showVar() {
        auto math_pkg = locator_.resolve<MyMathPackage>();
        std::cout << "<inside solver object> " << math_pkg->val << " " << math_pkg->state << std::endl;
    }
};

int main(int argc, char **argv) {
    /// 建立服務定位者
    architect::ServiceLocator locator;

    /// 服務定位者註冊 MathService 物件，並使用其物件。
    locator.registerInstance<MathService>();
    auto math_service = locator.resolve<MathService>();
    std::cout << math_service->add(10, 23) << std::endl;

    /// 服務定位者註冊 MyMathService 物件，並使用其物件。
    locator.registerInstance<MyMathService>();
    auto my_math_service = locator.resolve<MyMathService>();
    std::cout << my_math_service->add(10, 23) << std::endl;

    /// 服務定位者註冊 MyMathPackage 物件，然後初始化內部變數。
    architect::ServiceLocator solver_locator;
    solver_locator.registerInstance<MyMathPackage>(new MyMathPackage(5.2));
    auto math_pkg = solver_locator.resolve<MyMathPackage>();
    math_pkg->state = 2;

    /// 注入其相依於 Solver 物件，並從 solver 物件拿出 pkg。
    auto solver = std::make_shared<Solver>(solver_locator);
    auto pkg_from_solver = solver->mathPackage();
    std::cout << "<outside solver object> " << pkg_from_solver->val << " " << pkg_from_solver->state << std::endl;

    /// solver 內使用 pkg
    solver->showVar();

    return 0;
}
