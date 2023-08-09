#ifndef SRC_ARCHITECT_AOP_HPP_
#define SRC_ARCHITECT_AOP_HPP_
#include <functional>
#include <map>
namespace aop {
class NonCopyable {
 public:
    NonCopyable() = default;

    ~NonCopyable() = default;

    NonCopyable(const NonCopyable &) = delete;

    NonCopyable &operator=(const NonCopyable &) = delete;
};


class AspectInterface {
 public:
    AspectInterface() = default;

    ~AspectInterface() = default;

    template<typename... Args>
    void before(Args&&... args) {}

    template<typename... Args>
    void after(Args&&... args) {}
};

template<typename F, typename... AP>
class Aspects : public NonCopyable {
 private:
    F func_;
    std::tuple<AP...> aps_;

 public:
    Aspects(F&& func, AP&&... aps)
    : func_(std::forward<F>(func)),
    aps_(std::make_tuple(std::forward<AP>(aps)...)) {}

    ~Aspects() = default;

    template<std::size_t I = 0, typename... Args>
    typename std::enable_if<I == sizeof...(AP)>::type
    Invoke(Args&&... args) {
        func_(std::forward<Args>(args)...);
    }

    template<std::size_t I = 0, typename... Args>
    typename std::enable_if<I < sizeof...(AP)>::type
    Invoke(Args&&... args) {
#ifndef NDEBUG
        static_assert(std::is_base_of<AspectInterface,
          typename std::decay<decltype(std::get<I>(aps_))>::type>::value,
          "Aspect object must derives from BaseAspect.\n");
#endif
        std::get<I>(aps_).before(std::forward<Args>(args)...);
        Invoke<I + 1>(std::forward<Args>(args)...);
        std::get<I>(aps_).after(std::forward<Args>(args)...);
    }
};


/// for user
template <typename... AP, typename F, typename... Args>
typename std::enable_if<!std::is_member_function_pointer<F>::value>::type
Invoke(AP&&... aps, F&& func, Args&&... args) {
    Aspects<F, AP...>(
      std::forward<F>(func),
      std::forward<AP>(aps)...).Invoke(std::forward<Args>(args)...);
}

template <typename... AP, typename F, typename TP, typename... Args>
typename std::enable_if<std::is_member_function_pointer<F>::value>::type
Invoke(AP &&... aps, F &&func, TP *target, Args &&... args) {
    auto bind = [&](Args &&... args) -> void {
        (target->*std::forward<F>(func))(std::forward<Args>(args)...);
    };

    Invoke<AP...>(std::forward<AP>(aps)..., bind, std::forward<Args>(args)...);
}

template <typename... AP, typename F, typename TP, typename... Args>
typename std::enable_if<std::is_member_function_pointer<F>::value>::type
Invoke(AP &&... aps, F &&func, std::shared_ptr<TP> target, Args &&... args) {
    auto bind = [&](Args &&... args) -> void {
        ((target.get())->*std::forward<F>(func))(std::forward<Args>(args)...);
    };

    Invoke<AP...>(std::forward<AP>(aps)..., bind, std::forward<Args>(args)...);
}

} // end of namespace aop

#endif // SRC_ARCHITECT_AOP_HPP_
