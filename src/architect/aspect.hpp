// Copyright (c)
#ifndef SRC_ARCHITECT_ASPECT_HPP_
#define SRC_ARCHITECT_ASPECT_HPP_
namespace architect {
template <typename F, typename... Args>
class Aspect {
 private:
    F func_;

 public:
    explicit Aspect(F&& func)
    : func_(func) {
    }

    Aspect() = default;
    Aspect(const Aspect&) = delete;
    Aspect& operator = (const Aspect&) = delete;
};
}  // namespace architect
#endif  // SRC_ARCHITECT_ASPECT_HPP_
