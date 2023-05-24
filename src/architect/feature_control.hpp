// Copyright (c)
// Backdoor Control Sysyem
#ifndef SRC_ARCHITECT_FEATURE_CONTROL_HPP_
#define SRC_ARCHITECT_FEATURE_CONTROL_HPP_
#include <memory>
#include <map>
namespace architect {



class BaseFeature {
 private:
    bool is_on_ = false;
    std::string status_ = "Disable";

    enum class Type {
        Backdoor,
        Frontdoor,
        Disable
    };

    void setStatus(Type type) {
        if (type == Type::Backdoor) {
            status_ = "Backdoor";
        } else if (type == Type::Frontdoor) {
            status_ = "Frontdoor";
        } else if (type == Type::Disable) {
            status_ = "Disable";
        } else {
            throw std::runtime_error("unknown status");
        }
    }

    void setFlag(bool falg) {
        is_on_ = falg;
    }

 public:
    BaseFeature() = default;

    virtual  ~BaseFeature() = default;

    virtual void readCmpFile(const std::string& cmp_file_name) {
        std::cout << "default read cmp file function" << std::endl;
    }

    virtual void readCmxFile(const std::string& cmx_file_name) {
        std::cout << "default read cmx file function" << std::endl;
    }

    const bool& isOn() const {
        return is_on_;
    }

    const std::string& status() const {
        return status_;
    }

    friend class ReadCmpCommand;
    friend class ReadCmxCommand;
};


class BaseCommand {
 protected:
    std::shared_ptr<BaseFeature> feature_;

    explicit BaseCommand(std::shared_ptr<BaseFeature> feature)
    : feature_(feature) {}

 private:
    BaseCommand() = delete;


 public:
    virtual void exeute() = 0;

    std::shared_ptr<BaseFeature> feature() {
        return feature_;
    }

    std::shared_ptr<const BaseFeature> feature() const {
        return feature_;
    }
};

class ReadCmpCommand : public BaseCommand {
 private:
    std::string cmp_file_name_;

 public:
    explicit ReadCmpCommand(std::shared_ptr<BaseFeature> feature, const std::string& cmp_file_name)
    : BaseCommand(feature), cmp_file_name_(cmp_file_name) {}

    void exeute() override {
        feature()->setFlag(true);
        feature()->setStatus(BaseFeature::Type::Backdoor);
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
        feature()->setFlag(true);
        feature()->setStatus(BaseFeature::Type::Frontdoor);
        feature()->readCmxFile(cmx_file_name_);
    }
};



class FeatureInvoker {
 private:
    using CommandType = std::shared_ptr<BaseCommand>;
    using FeatureType = std::shared_ptr<BaseFeature>;
    using ConstFeatureType = std::shared_ptr<const BaseFeature>;
    std::map<std::string, CommandType> commands_;

 public:

    FeatureInvoker() = default;

    virtual ~FeatureInvoker() = default;

    void setCommand(const char* feature_name, std::shared_ptr<BaseCommand> command) {
        if (!command)
            throw std::runtime_error("command is null");

        if (commands_.find(feature_name) == commands_.end())
            commands_.insert(std::make_pair(feature_name, command));
        else
            throw std::runtime_error("command already exists");
    }

    void invoke() {
        for (auto& command : commands_) {
            if (command.second) {
                command.second->exeute();
            } else {
                throw std::runtime_error("no command");
            }
        }
    }

    FeatureType getFeature(const char* feature_name) {
        if (commands_.find(feature_name) != commands_.end())
            return commands_[feature_name]->feature();
        else
            throw std::runtime_error("no feature");
    }

    void info() {
        for (auto& command : commands_) {
            auto feature = command.second->feature();
            std::string flag = feature->isOn() ? "on" : "off";
            std::cout
            << std::boolalpha
            << "feature name: " << command.first << "\n"
            << "flag: " << flag  << "\n"
            << "source: " << feature->status()  << "\n"
            << std::endl;
        }
    }
};


}  // namespace architect
#endif  // SRC_ARCHITECT_FEATURE_CONTROL_HPP_
