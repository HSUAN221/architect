// Copyright (c) 2022 LucaWei
#include <architect/architect.hpp>
class PhaseSolverInterface {
 public:
    virtual void before() = 0;
    virtual void run() = 0;
    virtual void after() = 0;
};

class VofSolver : public PhaseSolverInterface {
 public:
    VofSolver() = default;
    virtual ~VofSolver() = default;

    void before() override {
        std::cout
          << __func__
          << std::endl;
    }

    void run() override {
        std::cout
          << __func__
          << std::endl;
    }

    void after() override {
        std::cout
          << __func__
          << std::endl;
    }
};

class Logger : public aop::AspectInterface {
 public:
    Logger() = default;
    virtual ~Logger() = default;

    template<typename... Args>
    void before(Args&&... args) {
        std::cout
          << "[logger before]"
          << std::endl;
    }

    template<typename... Args>
    void after(Args&&... args) {
        std::cout
          << "[logger after]"
          << std::endl;
    }
};

class MemoryChecker : public aop::AspectInterface {
 public:
    MemoryChecker() = default;
    virtual ~MemoryChecker() = default;

    template<typename... Args>
    void before(Args&&... args) {
        std::cout
          << "[MemoryChecker before]"
          << std::endl;
    }

    template<typename... Args>
    void after(Args&&... args) {
        std::cout
          << "[MemoryChecker after]"
          << std::endl;
    }
};

class VofSolverProxy : public PhaseSolverInterface {
 private:
    std::shared_ptr<VofSolver> vof_solver_{nullptr};

 public:
    explicit VofSolverProxy(std::shared_ptr<VofSolver>&& vof_solver)
    : vof_solver_(vof_solver) {
    }

    virtual ~VofSolverProxy() = default;

    VofSolverProxy() = delete;

    void before() override {
        aop::Invoke<Logger, MemoryChecker>(
          Logger(),
          MemoryChecker(),
          &VofSolver::before,
          vof_solver_);
    }

    void run() override {
        aop::Invoke<Logger>(
          Logger(),
          &VofSolver::run,
          vof_solver_);
    }

    void after() override {
        aop::Invoke<Logger>(
          Logger(),
          &VofSolver::after,
          vof_solver_);
    }
};


int main(int argc, char **argv) {
    auto vof_solver_proxy =
      std::make_shared<VofSolverProxy>(
      std::make_shared<VofSolver>());
    vof_solver_proxy->before();
    vof_solver_proxy->run();
    vof_solver_proxy->run();
    return 0;
}
