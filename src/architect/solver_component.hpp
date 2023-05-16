// Copyright (c)
#ifndef SRC_ARCHITECT_SOLVER_COMPONENT_HPP_
#define SRC_ARCHITECT_SOLVER_COMPONENT_HPP_
#include <architect/solver_kernel.hpp>
#include <architect/locator.hpp>
namespace architect {
class ProcessBase {
 private:
    std::unordered_map<size_t, std::shared_ptr<void>> instances_;

 protected:
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
    explicit ProcessBase(const ServiceLocator& locator)
    : locator_(locator) {}

    virtual ~ProcessBase() = default;

    virtual void run() {
        std::cout << "default process" << std::endl;
    }
};

}  // namespace architect
#endif  // SRC_ARCHITECT_SOLVER_COMPONENT_HPP_
