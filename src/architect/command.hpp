// Copyright (c)
// Backdoor Control Sysyem
#ifndef SRC_ARCHITECT_COMMAND_HPP_
#define SRC_ARCHITECT_COMMAND_HPP_
#include <memory>
namespace architect {
class BaseFeature {
 public:
    virtual void readCmpFile(const std::string& cmp_file_name) {
        std::cout << "default read cmp file function" << std::endl;
    }

    virtual void readCmxFile(const std::string& cmx_file_name) {
        std::cout << "default read cmx file function" << std::endl;
    }
};

class BaseCommand {
 protected:
    std::shared_ptr<BaseFeature> feature_;

    explicit BaseCommand(std::shared_ptr<BaseFeature> feature)
    : feature_(feature) {}

    std::shared_ptr<BaseFeature> feature() {
        return feature_;
    }

    std::shared_ptr<const BaseFeature> feature() const {
        return feature_;
    }

 private:
    BaseCommand() = delete;

 public:
    virtual void exeute() = 0;
};

class ReadCmpCommand : public BaseCommand {
 private:
    std::string cmp_file_name_;

 public:
    explicit ReadCmpCommand(std::shared_ptr<BaseFeature> feature, const std::string& cmp_file_name)
    : BaseCommand(feature), cmp_file_name_(cmp_file_name) {}

    void exeute() override {
        feature()->readCmpFile(cmp_file_name_);
    }
};


class ReadCmxCommand : public BaseCommand {
 private:
    std::string cmx_file_name_;

 public:
    explicit ReadCmxCommand(std::shared_ptr<BaseFeature> feature, const std::string& cmx_file_name)
    : BaseCommand(feature), cmx_file_name_(cmx_file_name) {}

    void exeute() override {
        feature()->readCmxFile(cmx_file_name_);
    }
};



class Invoker {
 private:
    std::shared_ptr<BaseCommand> command_;

 public:
    Invoker() = default;

    void setCommand(std::shared_ptr<BaseCommand> command) {
        command_ = command;
    }

    void invoke() {
        if (command_) {
            command_->exeute();
        } else {
            throw std::runtime_error("no command");
        }
    }
};
}  // namespace architect
#endif  // SRC_ARCHITECT_COMMAND_HPP_
