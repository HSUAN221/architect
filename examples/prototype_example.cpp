// Copyright (c) 2022 LucaWei
#include <architect/architect.hpp>

void createProducts(architect::MDXProductRepo* mdx_product_repo) {
    mdx_product_repo->append(new architect::ProductA());
    mdx_product_repo->append(new architect::ProductB());
}

void registerProducts(architect::ProductFactory* product_factory, architect::MDXProductRepo* product_repo) {
    product_factory->registerProducts(product_repo);
}

void runProduct(architect::Product* solver) {
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
