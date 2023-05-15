// Copyright (c) 2022 LucaWei
#include <architect/architect.hpp>

using architect::ServiceLocator;
using architect::KernelLocator;
using architect::ProcessBase;
using architect::SolverBuilderBase;
using architect::KernelSolver;
using architect::MeshRepo;



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
 public:
    Problem(KernelLocator& kernel, const ServiceLocator& locator)
    : base::ProcessBase(kernel, locator) {}

    void run() override {
        const auto& kernel_solver = kernel_.resolve<KernelSolver>();
        const auto& mesh_repo = locator_.resolve<MeshRepo>();
        const auto& dispenser_para_repo = locator_.resolve<DispenserParaRepo>();

        std::cout << "\n * define IC BCs" << std::endl;
        std::cout << "<<\n";
        std::cout << "DispenserParaRepo->type = " <<
        dispenser_para_repo->type << std::endl;
        kernel_solver->api();
        mesh_repo->api();
        std::cout << ">>\n";
    }
};

class NumericalPara : public ProcessBase {
    using base = ProcessBase;
 public:
    NumericalPara(KernelLocator& kernel, const ServiceLocator& locator)
    : base::ProcessBase(kernel, locator) {}

    void run() override {
        const auto& kernel_solver = kernel_.resolve<KernelSolver>();
        const auto& mesh_repo = locator_.resolve<MeshRepo>();
        const auto& dispenser_para_repo = locator_.resolve<DispenserParaRepo>();

        dispenser_para_repo->type = 100;
        std::cout << "\n * define numerical parameters" << std::endl;
        std::cout << "<<\n";
        std::cout << "DispenserParaRepo->type = " <<
        dispenser_para_repo->type << std::endl;
        kernel_solver->api();
        mesh_repo->api();
        std::cout << ">>\n";
    }
};

class Run : public ProcessBase {
    using base = ProcessBase;
 public:
    Run(KernelLocator& kernel, const ServiceLocator& locator)
    : base::ProcessBase(kernel, locator) {}

    void run() override {
        const auto& kernel_solver = kernel_.resolve<KernelSolver>();
        const auto& mesh_repo = locator_.resolve<MeshRepo>();
        const auto& dispenser_para_repo = locator_.resolve<DispenserParaRepo>();

        std::cout << "\n * define the flow solver algorithm" << std::endl;
        std::cout << "<<\n";
        std::cout << "DispenserParaRepo->type = " <<
        dispenser_para_repo->type << std::endl;
        kernel_solver->api();
        mesh_repo->api();
        std::cout << ">>\n";
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
    KernelLocator solver_kernel;
    solver_kernel.registerInstance(new KernelSolver());
    solver_kernel.registerInstance(new MeshRepo());

    // 建立計算物件
    UnderfillSolver uf_solver;

    // 建立計算流程 (可以自由定義) & 註冊計算流程 (註冊代表之後計算要用的)
    uf_solver.registerInstance(new Problem(solver_kernel, underfill_locator));
    uf_solver.registerInstance(new NumericalPara(solver_kernel, underfill_locator));
    uf_solver.registerInstance(new Run(solver_kernel, underfill_locator));


    // 執行計算流程
    uf_solver.run();
    return 0;
}
