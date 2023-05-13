// Copyright (c)
#ifndef SRC_ARCHITECT_SOLVER_COMPONENT_HPP_
#define SRC_ARCHITECT_SOLVER_COMPONENT_HPP_
#include <architect/solver_kernel.hpp>
namespace architect {
class ProcessBase {
 public:
    virtual void run() {
        std::cout << "default process" << std::endl;
    }
};
}  // namespace architect
#endif  // SRC_ARCHITECT_SOLVER_COMPONENT_HPP_
