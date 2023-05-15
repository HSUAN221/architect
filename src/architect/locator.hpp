// Copyright (c)
#ifndef SRC_ARCHITECT_LOCATOR_HPP_
#define SRC_ARCHITECT_LOCATOR_HPP_
namespace architect {

class LocatorInterface {
 protected:
    std::unordered_map<size_t, std::shared_ptr<void>> instances_;

 public:
    LocatorInterface() = default;

    virtual ~LocatorInterface() = default;
};

class ServiceLocator : public LocatorInterface {
    using base = LocatorInterface;
    using base::instances_;

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
    void registerInstance(T instance) {
        const size_t hash_key = typeid(T).hash_code();
        if (instances_.find(hash_key) == instances_.end()) {
            instances_.emplace(hash_key, std::shared_ptr<void>(new T(instance)));
        }
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

class KernelLocator : public LocatorInterface {
    using base = LocatorInterface;
    using base::instances_;

 public:
    KernelLocator() = default;

    virtual ~KernelLocator() {
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
    void registerInstance(T instance) {
        const size_t hash_key = typeid(T).hash_code();
        if (instances_.find(hash_key) == instances_.end()) {
            instances_.emplace(hash_key, std::shared_ptr<void>(new T(instance)));
        }
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
