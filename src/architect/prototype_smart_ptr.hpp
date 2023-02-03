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


#ifndef SRC_ARCHITECT_PROTOTYPE_SMART_PTR_HPP_
#define SRC_ARCHITECT_PROTOTYPE_SMART_PTR_HPP_
namespace architect::other {
class Product {
 private:
    virtual Product* cloneImplementation() const {
        return new Product(*this);
    }

 public:
    Product() = default;
    virtual ~Product() = default;
    virtual std::shared_ptr<Product> clone() const {
        return std::shared_ptr<Product>(cloneImplementation());
    }
    virtual std::string id() const noexcept {
        return "Default Product";
    }
};

class ProductRepoInterface {
 public:
    ProductRepoInterface() = default;
    virtual ~ProductRepoInterface() = default;
    virtual void append(Product*) = 0;
    virtual size_t size() const noexcept = 0;
    virtual std::vector<Product*> getProductFamily() const noexcept = 0;
};


// 需要一些額外的機制來使智能指針行為協變
class ProductA : public Product {
 private:
    std::string product_id_ = "product-A";

    ProductA* cloneImplementation() const override {
        return new ProductA(*this);
    }

 public:
    ProductA() = default;
    virtual ~ProductA() = default;

    std::shared_ptr<ProductA> Clone() const {
        return std::shared_ptr<ProductA>(cloneImplementation());
    }

    std::string id() const noexcept override {
        return product_id_;
    }
};

class ProductB : public Product {
 private:
    std::string product_id_ = "product-B";

    ProductB* cloneImplementation() const override {
        return new ProductB(*this);
    }

 public:
    ProductB() = default;
    virtual ~ProductB() = default;

    std::shared_ptr<ProductB> Clone() const {
        return std::shared_ptr<ProductB>(cloneImplementation());
    }

    std::string id() const noexcept override {
        return product_id_;
    }
};


// 動態的寫法
// class ProductFactory {
//  private:
//     std::unordered_map<std::string, Product*> products_;

//  public:
//     ProductFactory() = default;
//     virtual ~ProductFactory() = default;

//     void registerProducts(ProductRepoInterface* product_repo) {
//         auto products = product_repo->getProductFamily();
//         for (auto product : products) {
//             if (products_.count(product->id()))
//                 continue;
//             products_[product->id()] = product;
//         }
//     }

//     Product* create(std::string product_id) {
//         if (products_.find(product_id) != products_.end()) {
//             return products_.find(product_id)->second->clone();
//         } else {
//             return nullptr;
//         }
//     }
// };



// class MDXProductRepo : public ProductRepoInterface {
//  private:
//     std::vector<Product*> products_;

//  public:
//     MDXProductRepo() = default;
//     virtual ~MDXProductRepo() = default;

//     void append(Product* p) {
//         products_.push_back(p);
//     }

//     size_t size() const noexcept {
//         return products_.size();
//     }

//     std::vector<Product*> getProductFamily() const noexcept {
//         return products_;
//     }
// };


}  // namespace architect::other
#endif  // SRC_ARCHITECT_PROTOTYPE_SMART_PTR_HPP_
