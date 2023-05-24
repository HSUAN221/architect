// Copyright (c) 2023 LucaWei
#include <architect/architect.hpp>
using architect::ReadCmpCommand;
using architect::ReadCmxCommand;

// 建立後門功能囉~
//=======================================================//
class EbgFeature
: public architect::BaseFeature {
 private:
    int test_para_ = 0;

 public:
    EbgFeature() {}

    void readCmpFile(const std::string& cmp_file_name) override {
        std::cout << "\nEbgFeature: readCmpFile" << std::endl;
        std::cout << "Here, it's the " << cmp_file_name << std::endl;
        test_para_ = 100;
    }

};

class ICFeature
: public architect::BaseFeature {
 private:
    int test_para_ = 0;

 public:
    ICFeature() {}

    void readCmpFile(const std::string& cmp_file_name) override {
        std::cout << "\nICFeature: readCmpFile" << std::endl;
        std::cout << "Here, it's the " << cmp_file_name << std::endl;
        test_para_ = 123;
    }

};
//=======================================================//

int main(int argc, char **argv) {

    auto ebg_feature_2 = std::make_shared<EbgFeature>();
    auto ic_feature_3 = std::make_shared<ICFeature>();

    architect::FeatureInvoker invoker;
    invoker.setCommand("ebg_feature_2", std::make_shared<ReadCmpCommand>(ebg_feature_2, "cmp_file_name"));
    invoker.setCommand("ic_feature_3", std::make_shared<ReadCmxCommand>(ic_feature_3, "cmx_file_name"));

    // In solver
    // ========================================================== //
    invoker.invoke();
    invoker.info();
    auto ebg = invoker.getFeature("ebg_feature_2");
    std::cout << std::boolalpha << ebg->isOn() << std::endl;
    std::cout << ebg->status() << std::endl;
    // ========================================================== //

    return 0;
}
