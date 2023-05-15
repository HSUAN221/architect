// Copyright (c) 2022 LucaWei
#include <architect/architect.hpp>

namespace backend {
class IOException : public std::exception {
 public:
    const char* what() const noexcept override {
        return "IO Error";
    }
};
}

template<typename T>
class Add {
 public:
    T operator()(const T& a, const T& b) {
        return a + b;
    }
};

template<typename T>
class Multiplies {
 public:
    T operator()(const T& a, const T& b) {
        return a * b;
    }
};


template<typename T, typename Functor = Add<T>>
T useFunc(Functor f, const T& a, const T& b) {
    return f(a, b);
}



class Multply {
 public:
    int operator()(const int& a, const int& b) {
        return a * b;
    }
};

template<typename T, typename Functor = Add<T>>
class Element {
 private:
    Functor f_;
    T a_, b_;

 public:
    Element(const T& a, const T& b)
    : a_(a), b_(b) {}

    T operator()() {
        return f_(a_, b_);
    }
};



int main(int argc, char **argv) {
    std::cout << "<1> " << useFunc(Multiplies<int>(), 5, 6) << std::endl;
    std::cout << "<2> " << useFunc(Add<int>(), 5, 6) << std::endl;
    std::cout << "<3> " << Element<int, Multply>(2, 6)() << std::endl;


    std::vector<int> v = {1, 2, 3};
    /// input region
    try {
        // std::cout << v.at(3) << "\n";
        throw backend::IOException();
        // throw std::invalid_argument("Division by zero condition!");
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
        architect::LoggerA::getInstance().info(e.what());
        architect::LoggerB::info(e.what());
        architect::LoggerB::show(e.what());
    }

    return 0;
}
