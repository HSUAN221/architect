// Copyright (c) 2022 LucaWei
#include <architect/architect.hpp>


auto main() -> int {
    std::cout << "=======DisjointSetFixSize======" << std::endl;
    architect::DisjointSetFixSize ds_fix_size(6);
    ds_fix_size.connect(0, 5);
    ds_fix_size.connect(1, 2);
    ds_fix_size.connect(1, 5);
    for (size_t i = 0; i < 6; ++i)
        std::cout << "vertex= " << i << " " << ds_fix_size.findSet(i) << std::endl;

    std::cout << "=======DisjointSet======" << std::endl;
    architect::DisjointSet ds;
    std::vector<size_t> vertrex_list{5, 0, 1, 2, 3};
    for (const auto& v : vertrex_list)
        ds.makeSet(v);

    ds.connect(0, 5);
    ds.connect(1, 2);
    ds.connect(1, 5);
    for (const auto& v : vertrex_list)
        std::cout << "vertex= " << v << " " << ds.findSet(v) << std::endl;
    return 0;
}
