// Copyright (c)
#ifndef SRC_ARCHITECT_ADAPTER_HPP_
#define SRC_ARCHITECT_ADAPTER_HPP_
namespace architect {
/**
 * The Target defines the domain-specific interface used by the client code.
 */
class Target {
 public:
    Target() = default;
    virtual ~Target() = default;

    virtual std::string request() const {
        return "Target: The default target's behavior.";
    }
};


/**
 * The Adaptee contains some useful behavior, but its interface is incompatible
 * with the existing client code. The Adaptee needs some adaptation before the
 * client code can use it.
 */
class Adaptee {
 public:
    Adaptee() = default;
    virtual ~Adaptee() = default;

    std::string SpecificRequest() const {
        return "roivaheb laicepS";
    }
};

class Adapter : public Target {
 private:
    std::shared_ptr<Adaptee> adaptee_;
 public:
    Adapter() = default;
    virtual ~Adapter() = default;
    explicit Adapter(const std::shared_ptr<Adaptee>& adaptee)
    : adaptee_(adaptee) {}

    std::string request() const override {
        assert(adaptee_);
        std::string to_reserve = adaptee_->SpecificRequest();
        std::reverse(to_reserve.begin(), to_reserve.end());
        return to_reserve;
    }
};

class MultiAdapter : public Target, public Adaptee {
 public:
    MultiAdapter() = default;
    virtual ~MultiAdapter() = default;

    std::string request() const override {
        std::string to_reserve = SpecificRequest();
        std::reverse(to_reserve.begin(), to_reserve.end());
        return to_reserve;
    }
};

}  // namespace architect
#endif  // SRC_ARCHITECT_ADAPTER_HPP_
