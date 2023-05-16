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
 private:
    std::unordered_map<size_t, std::shared_ptr<void>> instances_;

 protected:
    KernelRepo kernel_;
    ServiceLocator locator_;

    template<typename T>
    std::shared_ptr<T> resolve() const {
        static_assert(std::is_base_of<ProcessBase, T>::value,
        "Plz use Base Object(ProcessBase) to define process");
        const size_t hash_key = typeid(T).hash_code();
        auto pos = instances_.find(hash_key);
        if (pos != instances_.end())
            return std::static_pointer_cast<T>(pos->second);
        return nullptr;
    }

    template<typename T>
    void registerInstance(T* instance = new T()) {
        static_assert(std::is_base_of<ProcessBase, T>::value,
        "Plz use Base Object(ProcessBase) to define process");
        const size_t hash_key = typeid(T).hash_code();
        if (instances_.find(hash_key) == instances_.end())
            instances_.emplace(hash_key, std::shared_ptr<void>(instance));
    }

    virtual void registerSubprocesses() {
        std::cout << "Plz register subprocesses" << std::endl;
    }


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
