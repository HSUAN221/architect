// Copyright (c) 2022 LucaWei
#include <architect/architect.hpp>

// 有可能需要有訪問私有變量的權限
// 不要用在容易增加資料型別的資料結構中

// 覺得可以用在基礎元件的資料結構(萬年不變)
// 像是 sysyem 級別的資料結構不要用，因為容易改變內部資料，
// system 應該放在另外一邊，負責紀錄演算法算完之後的結果
int main(int argc, char **argv) {
    architect::Circle circle(5.2);
    auto area_calculator = std::make_shared<architect::AreaCalculator>();
    circle.accept(area_calculator);
    std::cout << "circle area = "
    << area_calculator->getCircleArea() << std::endl;
    return 0;
}
