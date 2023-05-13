// Copyright (c)
#ifndef SRC_ARCHITECT_SOLVER_KERNEL_HPP_
#define SRC_ARCHITECT_SOLVER_KERNEL_HPP_
#include <architect/solver_kernel.hpp>
namespace architect {
class KernelSolver{
 public:
    KernelSolver() = default;

    void api() {
        std::cout << "Hi, I'm KernelSolver." << std::endl;
    }
};
class MeshRepo{
 public:
    MeshRepo() = default;

    void api() {
        std::cout << "Hi, I'm MeshRepo." << std::endl;
    }
};

}  // namespace architect
#endif  // SRC_ARCHITECT_SOLVER_KERNEL_HPP_
