// Copyright (c) 2022 LucaWei
#include <architect/definitions.hpp>
#include <architect/solver_kernel.hpp>
#include <architect/solver_builder.hpp>
using architect::ServiceLocator;
using architect::ProcessBase;
using architect::SolverBuilderBase;
using architect::KernelSolver;
using architect::MeshRepo;
using architect::KernelRepo;



// 特殊製程的元件庫，數據包
//-------------------------------------------------------------------------------------------------//
struct DispenserParaRepo {
    int type = 0;
};
//-------------------------------------------------------------------------------------------------//

// 自由定義每個計算階段
//-------------------------------------------------------------------------------------------------//
class Problem : public ProcessBase {
    using base = ProcessBase;

 private:
    std::shared_ptr<KernelRepo> kernel_;

 public:
    Problem(const std::shared_ptr<KernelRepo>& kernel, const ServiceLocator& locator)
    : kernel_(kernel), base(locator) {}

    void run() override {
        const auto& dispenser_para_repo = locator_.resolve<DispenserParaRepo>();
        auto kernel_solver = kernel_->kernel_solver();
        auto mesh_repo = kernel_->mesh_repo();

        std::cout << "\n * define IC BCs" << std::endl;
        std::cout << "<<\n";
        std::cout << "DispenserParaRepo->type = " <<
        dispenser_para_repo->type << std::endl;
        kernel_solver.api();
        mesh_repo.api();
        std::cout << ">>\n";
    }
};

class NumericalPara : public ProcessBase {
    using base = ProcessBase;

 private:
    std::shared_ptr<KernelRepo> kernel_;

 public:
    NumericalPara(const std::shared_ptr<KernelRepo>& kernel, const ServiceLocator& locator)
    : kernel_(kernel), base(locator) {}

    void run() override {
        const auto& dispenser_para_repo = locator_.resolve<DispenserParaRepo>();
        auto kernel_solver = kernel_->kernel_solver();
        auto mesh_repo = kernel_->mesh_repo();

        dispenser_para_repo->type = 100;
        std::cout << "\n * define numerical parameters" << std::endl;
        std::cout << "<<\n";
        std::cout << "DispenserParaRepo->type = " <<
        dispenser_para_repo->type << std::endl;
        kernel_solver.api();
        mesh_repo.api();
        std::cout << ">>\n";
    }
};

class TimeIterator : public ProcessBase {
    using base = ProcessBase;

 private:
    std::shared_ptr<KernelRepo> kernel_;

 public:
    TimeIterator(const std::shared_ptr<KernelRepo>& kernel, const ServiceLocator& locator)
    : kernel_(kernel), base(locator) {}

    void run() override {
        std::cout << "\n * define the time iterator" << std::endl;
        const auto& dispenser_para_repo = locator_.resolve<DispenserParaRepo>();
        std::cout << dispenser_para_repo->type << std::endl;
        auto& kernel_solver = kernel_->kernel_solver();
        kernel_solver.api();
    }
};

class Run : public ProcessBase {
    using base = ProcessBase;

 protected:
    void registerSubprocesses() override {
        base::registerInstance(new TimeIterator(kernel_, locator_));
    }

 private:
    std::shared_ptr<KernelRepo> kernel_;

 public:
    Run(const std::shared_ptr<KernelRepo>& kernel, const ServiceLocator& locator)
    : kernel_(kernel), base(locator) {}

    void run() override {
        registerSubprocesses();
        locator_.resolve<DispenserParaRepo>()->type = 52;
        const auto& dispenser_para_repo = locator_.resolve<DispenserParaRepo>();
        auto& kernel_solver = kernel_->kernel_solver();
        auto& mesh_repo = kernel_->mesh_repo();
        kernel_solver.type() = 56;
        dispenser_para_repo->type = 89;
        std::cout << "\n * define the flow solver algorithm" << std::endl;
        std::cout << "<<\n";
        std::cout << "DispenserParaRepo->type = " <<
        dispenser_para_repo->type << std::endl;
        kernel_solver.api();
        mesh_repo.api();
        std::cout << ">>\n";
        base::resolve<TimeIterator>()->run();
    }
};

//-------------------------------------------------------------------------------------------------//


// 對定義好的計算流程做排程
//-------------------------------------------------------------------------------------------------//
class UnderfillSolver : public SolverBuilderBase {
    using base = SolverBuilderBase;
 public:
    UnderfillSolver() = default;

    void run() override {
        base::resolve<Problem>()->run();
        base::resolve<NumericalPara>()->run();
        base::resolve<Run>()->run();
    }

    virtual ~UnderfillSolver() = default;
};
//-------------------------------------------------------------------------------------------------//


int main(int argc, char **argv) {
    // 建立計算資源
    ServiceLocator underfill_locator;
    underfill_locator.registerInstance(new DispenserParaRepo());
    underfill_locator.resolve<DispenserParaRepo>()->type = 5;

    // 建立核心計算資源
    KernelSolver kernel_solver;
    MeshRepo mesh_repo;

    // 打包核心計算資源
    auto kernel = std::make_shared<KernelRepo>(kernel_solver, mesh_repo);

    // 建立計算物件
    UnderfillSolver uf_solver;

    // 建立計算流程 (可以自由定義) & 註冊計算流程 (註冊代表之後計算要用的)
    uf_solver.registerInstance(new Problem(kernel, underfill_locator));
    uf_solver.registerInstance(new NumericalPara(kernel, underfill_locator));
    uf_solver.registerInstance(new Run(kernel, underfill_locator));

    // 執行計算流程
    uf_solver.run();

    // 清理資源
    uf_solver.clear();
    return 0;
}
