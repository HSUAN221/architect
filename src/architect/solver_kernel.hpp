// Copyright (c)
#ifndef SRC_ARCHITECT_SOLVER_KERNEL_HPP_
#define SRC_ARCHITECT_SOLVER_KERNEL_HPP_
namespace architect {
class KernelSolver{
 private:
    int type_ = 0;

 public:
    KernelSolver() = default;

    int& type() {
        return type_;
    }

    void api() {
        std::cout << "Hi, I'm KernelSolver. type = " << type_  << std::endl;
    }
};
class MeshRepo{
 public:
    MeshRepo() = default;

    void api() {
        std::cout << "Hi, I'm MeshRepo." << std::endl;
    }
};

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

}  // namespace architect
#endif  // SRC_ARCHITECT_SOLVER_KERNEL_HPP_
