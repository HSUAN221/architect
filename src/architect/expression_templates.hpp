// Copyright (c)
#ifndef SRC_ARCHITECT_EXPRESSION_TEMPLATES_HPP_
#define SRC_ARCHITECT_EXPRESSION_TEMPLATES_HPP_
namespace architect {
template <typename E>
class VecExpression {
 public:
    double operator[](size_t i) const {
        return static_cast<const E&>(*this)[i];
    }

    size_t size() const {
        return static_cast<const E&>(*this).size();
    }
};

template <typename T>
class vector : public VecExpression<vector<T>> {
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
    vector(const VecExpression<E>& expr)
    : elems_(expr.size()) {
        for (size_t i = 0; i != expr.size(); ++i) {
            elems_[i] = expr[i];
        }
    }
};

template <typename E1, typename E2>
class VectorSum : public VecExpression<VectorSum<E1, E2>> {
    using T = typename E2::value_type;
    const E1& u_;
    const E2& v_;

 public:
    VectorSum(const E1& u, const E2& v) : u_(u), v_(v) {
        if (u_.size() != v_.size()) {
            throw std::invalid_argument("different size!!");
        }
    }

    T operator[](size_t i) const { return u_[i] + v_[i]; }

    size_t size() const { return v_.size(); }
};

template <typename E1, typename E2>
VectorSum<E1, E2> operator+ (const VecExpression<E1>& u, const VecExpression<E2>& v) {
    return VectorSum<E1, E2>(*static_cast<const E1*>(&u), *static_cast<const E2*>(&v));
}

template <typename E1, typename E2>
class VectorMul : public VecExpression<VectorMul<E1, E2>> {
    using T = typename E2::value_type;
    const E1& u_;
    const E2& v_;

 public:
    VectorMul(const E1& u, const E2& v) : u_(u), v_(v) {
        if (u_.size() != v_.size()) {
            throw std::invalid_argument("different size!!");
        }
    }

    T operator[](size_t i) const { return u_[i] * v_[i]; }

    size_t size() const { return v_.size(); }
};

template <typename E1, typename E2>
VectorMul<E1, E2> operator* (const VecExpression<E1>& u, const VecExpression<E2>& v) {
    return VectorMul<E1, E2>(*static_cast<const E1*>(&u), *static_cast<const E2*>(&v));
}

}  // namespace architect
#endif  // SRC_ARCHITECT_EXPRESSION_TEMPLATES_HPP_
