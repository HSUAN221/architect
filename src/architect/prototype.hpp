// Copyright (c) 2023 LucaWei
// 有些物件若以標準的方式建立實例，或者是設定至某個狀態需要複雜的運算及昂貴的資源，
// 則您可以考慮直接以某個物件作為原型，在需要個別該物件時，複製原型並傳回。

/////////////////////////////////////////////////////////////////////////////////
// #include "product_a.h"
// #include "product_b.h"
// #include "product_c.h"
// #include "product_factory.h"
// Product* ProductFactory(int id)
// {
//     Product* product;
//     switch(id)
//     {
//         case PRODUCT_A_ID:
//             product = new ProductA;
//             break;
//         case PRODUCT_B_ID:
//             product = new ProductB;
//             break;
//         case PRODUCT_C_ID:
//             product = new ProductC;
//             break;
//         default:
//             product = 0;
//     }
//     return product;
// }
// 這樣的作法只要每次增加新產品，就要來這邊修改 switch case 並且要
// include 正確的 header file，而這樣的作法明顯違反 OCP (Open-Closed Principle)。
// 程式碼就是我們的小孩，我們不能讓管理中心製造的各種神秘編碼污染小孩的 DNA。
// 解決辦法就是建立一道防火牆，需要認識編碼的只有該物件本身，
// 並且不使用 switch case id 產生物件，而由物件自己施展影分身之術


#ifndef SRC_ARCHITECT_PROTOTYPE_HPP_
#define SRC_ARCHITECT_PROTOTYPE_HPP_
namespace architect {
class Product {
 public:
    Product() = default;
    virtual ~Product() = default;
    virtual Product* clone() const = 0;
    virtual std::string id() const noexcept = 0;
};

class ProductRepoInterface {
 public:
    ProductRepoInterface() = default;
    virtual ~ProductRepoInterface() = default;
    virtual void append(Product*) = 0;
    virtual size_t size() const noexcept = 0;
    virtual std::vector<Product*> getProductFamily() const noexcept = 0;
};

class ProductA : public Product {
 private:
    std::string product_id_ = "product-A";
 public:
    ProductA() = default;
    virtual ~ProductA() = default;

    // 補充說明: covariance
    // https://blog.csdn.net/ithiker/article/details/109013385
    // https://shininglionking.blogspot.com/2017/10/c-covariance-contravariance.html
    // https://www.lwithers.me.uk/articles/covariant.html
    ProductA* clone() const override {
        return new ProductA;
    }

    std::string id() const noexcept override {
        return product_id_;
    }
};

class ProductB : public Product {
 private:
    std::string product_id_ = "product-B";
 public:
    ProductB() = default;
    virtual ~ProductB() = default;

    ProductB* clone() const override {
        return new ProductB;
    }

    std::string id() const noexcept override {
        return product_id_;
    }
};


// 動態的寫法
class ProductFactory {
 private:
    std::unordered_map<std::string, Product*> products_;

 public:
    ProductFactory() = default;
    virtual ~ProductFactory() = default;

    void registerProducts(ProductRepoInterface* product_repo) {
        auto products = product_repo->getProductFamily();
        for (auto product : products) {
            if (products_.count(product->id()))
                continue;
            products_[product->id()] = product;
        }
    }

    Product* create(std::string product_id) {
        if (products_.find(product_id) != products_.end()) {
            return products_.find(product_id)->second->clone();
        } else {
            return nullptr;
        }
    }
};



class MDXProductRepo : public ProductRepoInterface {
 private:
    std::vector<Product*> products_;

 public:
    MDXProductRepo() = default;
    virtual ~MDXProductRepo() = default;

    void append(Product* p) {
        products_.push_back(p);
    }

    size_t size() const noexcept {
        return products_.size();
    }

    std::vector<Product*> getProductFamily() const noexcept {
        return products_;
    }
};


}  // namespace architect
#endif  // SRC_ARCHITECT_PROTOTYPE_HPP_
