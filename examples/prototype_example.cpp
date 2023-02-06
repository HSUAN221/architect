// Copyright (c) 2023 LucaWei
#include <architect/architect.hpp>

// 如果有增加新產品的實作，這裡改動即可。這裡也可以包成物件
void createProducts(const std::shared_ptr<architect::ProductRepoInterface>& mdx_product_repo) {
    mdx_product_repo->append(new architect::ProductA());
    mdx_product_repo->append(new architect::ProductB());
    // delete ptr by MDXProductRepo
}


void runProduct(const architect::ProductInterface* const solver) {
    std::cout << "run the " << solver->id() << std::endl;
}


int main(int argc, char **argv) {
    // 由 MDXProductRepo 來管理 mdx 產品的生命週期
    auto mdx_product_repo = std::make_shared<architect::MDXProductRepo>();
    // 由 ProductFactory 來負責生產 mdx 產品。但是不管理產品的生命週期
    auto product_factory = std::make_shared<architect::ProductFactory>();
    // MDXProductRepo 配置產品的記憶體
    createProducts(mdx_product_repo);
    // 把 MDXProductRepo 裡面的產品註冊進 ProductFactory 。跟 ProductFactory 說要生產
    // MDXProductRepo 裡面的產品
    product_factory->registerProducts(mdx_product_repo);
    // ProductFactory 生產 product-A 。 並執行
    runProduct(product_factory->create("product-A"));
    // ProductFactory 生產 product-B 。 並執行
    runProduct(product_factory->create("product-B"));
    return 0;
}

// output
// run the product-A
// run the product-B
// >> ProductFactory destructor
// >> ProductA destructor
// >> Product destructor
// >> ProductB destructor
// >> Product destructor
// >> MDXProductRepo destructor
// >> ProductRepoInterface destructor
