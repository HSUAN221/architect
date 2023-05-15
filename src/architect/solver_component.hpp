// Copyright (c)
#ifndef SRC_ARCHITECT_SOLVER_COMPONENT_HPP_
#define SRC_ARCHITECT_SOLVER_COMPONENT_HPP_
#include <architect/solver_kernel.hpp>
#include <architect/locator.hpp>
namespace architect {
class KernelRepo {
 private:
    KernelSolver kernel_solver_;
    MeshRepo mesh_repo_;

 public:
    KernelRepo(KernelSolver& kernel_solver, MeshRepo& mesh_repo)
    : kernel_solver_(kernel_solver), mesh_repo_(mesh_repo) {}

    virtual ~KernelRepo() = default;

    const KernelSolver& kernel_Solver() const {
        return kernel_solver_;
    }

    KernelSolver& kernel_solver() {
        return kernel_solver_;
    }

    const MeshRepo& mesh_repo() const {
        return mesh_repo_;
    }

    MeshRepo& mesh_repo() {
        return mesh_repo_;
    }
};

class ProcessBase {
 protected:
    KernelRepo kernel_;
    ServiceLocator locator_;

 public:
    ProcessBase(KernelRepo& kernel, const ServiceLocator& locator)
    : kernel_(kernel), locator_(locator) {}

    virtual ~ProcessBase() = default;

    virtual void run() {
        std::cout << "default process" << std::endl;
    }
};

}  // namespace architect
#endif  // SRC_ARCHITECT_SOLVER_COMPONENT_HPP_
