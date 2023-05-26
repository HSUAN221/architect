// Copyright (c)
// Backdoor Control Sysyem
#ifndef SRC_ARCHITECT_FEATURE_CONTROL_HPP_
#define SRC_ARCHITECT_FEATURE_CONTROL_HPP_
#include <memory>
#include <map>
namespace architect {
struct FeatureProperties {
    enum class FeatureType {
        Backdoor,
        Frontdoor,
        Disable
    };

    FeatureType type;
    std::string cmp_file_path;
    std::string cmx_file_path;
};

class FeatureBase {
 private:
    bool is_on_ = false;
    std::string status_ = "Disable";

    void setStatus(FeatureProperties::FeatureType type) {
        if (type == FeatureProperties::FeatureType::Backdoor) {
            status_ = "Backdoor";
        } else if (type == FeatureProperties::FeatureType::Frontdoor) {
            status_ = "Frontdoor";
        } else if (type == FeatureProperties::FeatureType::Disable) {
            status_ = "Disable";
        } else {
            throw std::runtime_error("unknown status");
        }
    }

    void setFlag(bool flag) {
        is_on_ = flag;
    }

 protected:
    virtual void readCmpFile(const std::string& cmp_file_path) {
        std::cout << "default read cmp file function" << std::endl;
    }

    virtual void readCmxFile(const std::string& cmx_file_path) {
        std::cout << "default read cmx file function" << std::endl;
    }


 public:
    FeatureBase() = default;

    virtual  ~FeatureBase() = default;

    void initialize(const FeatureProperties& properties) {
        setStatus(properties.type);
        if (status() == "Backdoor") {
            readCmpFile(properties.cmp_file_path);
            setFlag(true);
        } else if (status() == "Frontdoor") {
            readCmxFile(properties.cmx_file_path);
            setFlag(true);
        }
    }

    const bool& isOn() const {
        return is_on_;
    }

    const std::string& status() const {
        return status_;
    }
};


class FeatureRepository {
 private:
    std::map<std::string, std::shared_ptr<FeatureBase>> features_;

    bool isInMap(const char* feature_name) {
        if (features_.find(feature_name) != features_.end())
            return true;
        else
            return false;
    }

 public:
    FeatureRepository() = default;

    virtual ~FeatureRepository() {
        clear();
    }

    void setFeature(const char* feature_name, std::shared_ptr<FeatureBase> feature) {
        if (!feature)
            throw std::runtime_error("feature is null");

        if (!isInMap(feature_name))
            features_.insert(std::make_pair(feature_name, feature));
        else
            throw std::runtime_error("feature already exists");
    }

    std::shared_ptr<FeatureBase> getFeature(const char* feature_name) {
        if (isInMap(feature_name))
            return features_[feature_name];
        else
            throw std::runtime_error("no feature");
    }

    void removeFeature(const char* feature_name) {
        if (isInMap(feature_name))
            features_.erase(feature_name);
        else
            throw std::runtime_error("no feature");
    }

    void info() {
        if (features_.empty()) {
            std::cout << "FeatureRepository: no features" << std::endl;
            return;
        }

        std::cout << "\n[FeatureRepository]";
        for (auto& feature : features_) {
            std::string flag = feature.second->isOn() ? "on" : "off";
            std::cout
            << std::boolalpha
            << "\nfeature name: " << feature.first << "\n"
            << "flag: " << flag  << "\n"
            << "type: " << feature.second->status()
            << std::endl;
        }
        std::cout << "[/FeatureRepository]\n" << std::endl;
    }

    void clear() {
        features_.clear();
    }
};

}  // namespace architect
#endif  // SRC_ARCHITECT_FEATURE_CONTROL_HPP_
