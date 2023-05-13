// Copyright (c)
#ifndef SRC_ARCHITECT_SOLVER_BUILDER_HPP_
#define SRC_ARCHITECT_SOLVER_BUILDER_HPP_
#include <architect/solver_component.hpp>
namespace architect {

class SolverBuilderBase {
 protected:
    std::unordered_map<size_t, std::shared_ptr<void>> instances_;

 public:
    SolverBuilderBase() = default;

    virtual ~SolverBuilderBase() {
        clear();
    }

    void clear() {
        instances_.clear();
    }

    template<typename T>
    void registerInstance(T* instance = new T()) {
        const size_t hash_key = typeid(T).hash_code();
        if (instances_.find(hash_key) == instances_.end())
            instances_.emplace(hash_key, std::shared_ptr<void>(instance));
    }

    template<typename T>
    std::shared_ptr<T> resolve() const {
        const size_t hash_key = typeid(T).hash_code();
        auto pos = instances_.find(hash_key);
        if (pos != instances_.end())
            return std::static_pointer_cast<T>(pos->second);
        return nullptr;
    }

    virtual void run() = 0;
};

}  // namespace architect
#endif  // SRC_ARCHITECT_SOLVER_BUILDER_HPP_
