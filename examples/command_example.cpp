// Copyright (c) 2023 LucaWei
#include <architect/architect.hpp>
using architect::ReadCmpCommand;

// 建立後門功能囉~
//=======================================================//
class EbgFeature
: public architect::BaseFeature {
 private:
    int test_para_ = 0;

 public:
    EbgFeature() {}

    void readCmpFile(const std::string& cmp_file_name) override {
        std::cout << "EbgFeature: readCmpFile" << std::endl;
        std::cout << "Here, it's the " << cmp_file_name << std::endl;
        test_para_ = 100;
    }

};
//=======================================================//

int main(int argc, char **argv) {
    architect::Invoker back_door;
    auto ebg_feature = std::make_shared<EbgFeature>();
    back_door.setCommand(std::make_shared<ReadCmpCommand>(ebg_feature, "cmp_file_name"));
    back_door.invoke();

    return 0;
}
