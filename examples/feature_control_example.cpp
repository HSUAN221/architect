// Copyright (c) 2023 LucaWei
#include <architect/architect.hpp>
using namespace architect;
// 建立後門功能囉~
//=======================================================//
class EbgFeature
: public architect::BaseFeature {
 private:
    int test_para_ = 0;

 public:
    EbgFeature() {}

    void readCmpFile(const std::string& cmp_file_path) override {
        std::cout << "EbgFeature::cmp_file_path: " << cmp_file_path << std::endl;
        test_para_ = 100;
    }

};

class EbgFeature1
: public architect::BaseFeature {
 private:
    int test_para_ = 0;

 public:
    EbgFeature1() {}

    void readCmpFile(const std::string& cmp_file_path) override {
        std::cout << "EbgFeature1::cmp_file_path: " << cmp_file_path << std::endl;
        test_para_ = 100;
    }

};

class EbgFeature2
: public architect::BaseFeature {
 private:
    int test_para_ = 0;

 public:
    EbgFeature2() {}

    void readCmxFile(const std::string& cmx_file_path) override {
        std::cout << "EbgFeature2::cmx_file_path: " << cmx_file_path << std::endl;
        test_para_ = 100;
    }


};
//=======================================================//

int main(int argc, char **argv) {
    FeatureProperties backdoor;
    backdoor.cmx_file_path = "";
    backdoor.cmp_file_path = "path/to/cmp";
    backdoor.type = FeatureProperties::FeatureType::Backdoor;

    FeatureProperties frontdoor;
    frontdoor.cmx_file_path = "path/to/cmx";
    frontdoor.cmp_file_path = "";
    frontdoor.type = FeatureProperties::FeatureType::Frontdoor;


    auto ebg_feature = std::make_shared<EbgFeature>();
    ebg_feature->initialize(backdoor);

    auto ebg_feature1 = std::make_shared<EbgFeature1>();
    ebg_feature1->initialize(backdoor);

    auto ebg_feature2 = std::make_shared<EbgFeature2>();
    ebg_feature2->initialize(frontdoor);



    auto features = std::make_shared<FeatureRepository>();
    features->setFeature("ebg_feature", ebg_feature);
    features->setFeature("ebg_feature1", ebg_feature1);
    features->setFeature("ebg_feature2", ebg_feature2);

    auto ebg2 = features->getFeature("ebg_feature2");
    std::cout << "\n" << std::boolalpha << ebg2->isOn() << std::endl;
    std::cout << ebg2->status() << std::endl;
    features->info();
    return 0;
}
