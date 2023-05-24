// Copyright (c) 2023 LucaWei
#include <architect/architect.hpp>
using architect::ReadCmpCommand;

// 建立後門功能囉~
//=======================================================//
class EbgFeature
: public architect::BaseFeature {
 private:
    int test_para_ = 0;
    std::string cmp_file_name_;

 public:
    explicit EbgFeature(const std::string& cmp_file_name)
    : cmp_file_name_(cmp_file_name) {}

    void readCmpFile() override {
        std::cout << "EbgFeature: readCmpFile" << std::endl;
        std::cout << "Here, it's the " << cmp_file_name_ << std::endl;
        test_para_ = 100;
    }

};
//=======================================================//

int main(int argc, char **argv) {
    architect::Invoker back_door;
    back_door.setCommand(std::make_shared<ReadCmpCommand>(
        std::make_shared<EbgFeature>("cmp_file_name")));
    back_door.invoke();
    return 0;
}
