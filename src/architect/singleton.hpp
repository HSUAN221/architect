// Copyright (c)
#ifndef SRC_ARCHITECT_SINGLETON_HPP_
#define SRC_ARCHITECT_SINGLETON_HPP_
namespace architect {

class LoggerA {
 private:
    LoggerA() = default;

 public:
    static LoggerA& getInstance() {
        static LoggerA logger;
        return logger;
    }

    void info(std::string message) {
        std::cout << "LOG: " << message << std::endl;
    }
};

class LoggerB {
 public:
    static void info(std::string message) {
        std::cout << "LOG(static function): " << message << std::endl;
    }

    static void show(std::string message) {
        std::cout << message << std::endl;
    }
};

}  // namespace architect
#endif  // SRC_ARCHITECT_SINGLETON_HPP_
