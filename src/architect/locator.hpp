// Copyright (c)
#ifndef SRC_ARCHITECT_LOCATOR_HPP_
#define SRC_ARCHITECT_LOCATOR_HPP_
namespace architect {
class ServiceLocator {
 private:
    std::unordered_map<size_t, std::shared_ptr<void>> instances_;

 public:
    ServiceLocator() = default;

    virtual ~ServiceLocator() {
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
};
}  // namespace architect
#endif  // SRC_ARCHITECT_LOCATOR_HPP_
