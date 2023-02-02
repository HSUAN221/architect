// Copyright (c) 2023 LucaWei
#include <architect/architect.hpp>

// 如果有增加新產品的實作，這裡改動即可。這裡也可以包成物件
void createProducts(architect::MDXProductRepo* const mdx_product_repo) {
    mdx_product_repo->append(new architect::ProductA());
    mdx_product_repo->append(new architect::ProductB());
}

void registerProducts(architect::ProductFactory* const product_factory,
architect::MDXProductRepo* const product_repo) {
    product_factory->registerProducts(product_repo);
}

void runProduct(const architect::Product* const solver) {
    std::cout << "run the " << solver->id() << std::endl;
}


int main(int argc, char **argv) {
    auto mdx_product_repo = new architect::MDXProductRepo();
    auto product_factory = new architect::ProductFactory();
    createProducts(mdx_product_repo);
    registerProducts(product_factory, mdx_product_repo);
    runProduct(product_factory->create("product-A"));
    runProduct(product_factory->create("product-B"));
    return 0;
}
