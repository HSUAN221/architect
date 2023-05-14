// Copyright (c) 2022 LucaWei
#include <architect/architect.hpp>

using architect::ServiceLocator;
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
 private:
    KernelSolver solver_;
    MeshRepo mesh_repo_;
    ServiceLocator locator_;

 public:
    Problem(KernelSolver& solver, MeshRepo& mesh_repo,
    const ServiceLocator& locator)
    : solver_(solver), mesh_repo_(mesh_repo), locator_(locator) {}

    void run() override {
        std::cout << "\n * define IC BCs" << std::endl;
        std::cout << "<<\n";
        std::cout << "DispenserParaRepo->type = " <<
        locator_.resolve<DispenserParaRepo>()->type << std::endl;
        solver_.api();
        mesh_repo_.api();
        std::cout << ">>\n";
    }
};

class NumericalPara : public ProcessBase {
 private:
    KernelSolver solver_;
    MeshRepo mesh_repo_;
    ServiceLocator locator_;

 public:
    NumericalPara(KernelSolver& solver, MeshRepo& mesh_repo,
    const ServiceLocator& locator)
    : solver_(solver), mesh_repo_(mesh_repo), locator_(locator) {}

    void run() override {
        locator_.resolve<DispenserParaRepo>()->type = 100;
        std::cout << "\n * define numerical parameters" << std::endl;
        std::cout << "<<\n";
        std::cout << "DispenserParaRepo->type = " <<
        locator_.resolve<DispenserParaRepo>()->type << std::endl;
        solver_.api();
        mesh_repo_.api();
        std::cout << ">>\n";
    }
};

class Run : public ProcessBase {
 private:
    KernelSolver solver_;
    MeshRepo mesh_repo_;
    ServiceLocator locator_;

 public:
    Run(KernelSolver& solver, MeshRepo& mesh_repo,
    const ServiceLocator& locator)
    : solver_(solver), mesh_repo_(mesh_repo), locator_(locator) {}

    void run() override {
        std::cout << "\n * define the flow solver algorithm" << std::endl;
        std::cout << "<<\n";
        std::cout << "DispenserParaRepo->type = " <<
        locator_.resolve<DispenserParaRepo>()->type << std::endl;
        solver_.api();
        mesh_repo_.api();
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
    KernelSolver solver;
    MeshRepo mesh_repo;

    // 建立計算物件
    UnderfillSolver uf_solver;

    // 建立計算流程 (可以自由定義) & 註冊計算流程 (註冊代表之後計算要用的)
    uf_solver.registerInstance(new Problem(solver, mesh_repo, underfill_locator));
    uf_solver.registerInstance(new NumericalPara(solver, mesh_repo, underfill_locator));
    uf_solver.registerInstance(new Run(solver, mesh_repo, underfill_locator));


    // 執行計算流程
    uf_solver.run();
    return 0;
}
