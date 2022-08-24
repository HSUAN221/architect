// Copyright (c)
#ifndef SRC_ARCHITECT_EXPRESSION_TEMPLATES_HPP_
#define SRC_ARCHITECT_EXPRESSION_TEMPLATES_HPP_
namespace architect {

template <typename T>
class vector {
 private:
    std::vector<T> elems_;

 public:
    using value_type = T;
    explicit vector(size_t n) : elems_(n) {}

    vector(std::initializer_list<T> init) : elems_(init) {}

    T operator[](size_t i) const {
        return elems_[i];
    }

    T& operator[](size_t i) {
        return elems_[i];
    }

    size_t size() const {
        return elems_.size();
    }

    template <typename E>
    vector<T> operator= (const E& expression) {
        for (size_t i = 0; i != expression.size(); ++i) {
            elems_[i] = expression[i];
        }
    }
};

template <typename E1, typename E2>
class VectorSum {
    using value_type = typename E2::value_type;
 private:
    const E1& u_;
    const E2& v_;

 public:
    VectorSum(const E1& u, const E2& v) : u_(u), v_(v) {
        if (u_.size() != v_.size()) {
            throw std::invalid_argument("different size!!");
        }
    }

    value_type operator[](size_t i) const { return u_[i] + v_[i]; }

    size_t size() const { return v_.size(); }
};

template <typename E1, typename E2>
VectorSum<E1, E2> operator+ (const E1& u, const E2& v) {
    return VectorSum<E1, E2>(u, v);
}


}  // namespace architect
#endif  // SRC_ARCHITECT_EXPRESSION_TEMPLATES_HPP_
