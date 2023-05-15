// Copyright (c)
#ifndef SRC_ARCHITECT_SOLVER_COMPONENT_HPP_
#define SRC_ARCHITECT_SOLVER_COMPONENT_HPP_
#include <architect/solver_kernel.hpp>
#include <architect/locator.hpp>
namespace architect {
class ProcessBase {
 protected:
    KernelLocator kernel_;
    ServiceLocator locator_;

 public:
    ProcessBase(KernelLocator& kernel, const ServiceLocator& locator)
    : kernel_(kernel), locator_(locator) {}

    virtual void run() {
        std::cout << "default process" << std::endl;
    }
};
}  // namespace architect
#endif  // SRC_ARCHITECT_SOLVER_COMPONENT_HPP_
