// Copyright (c) 2022 LucaWei
#include <architect/architect.hpp>


int main(int argc, char **argv) {
    architect::MergeSortTest merge_sort_test;
    auto merge_is_passed = merge_sort_test.runMergeTest();
    if (merge_is_passed)
        std::cout << "is same" << std::endl;
    else
        std::cout << "isn't same" << std::endl;

    architect::MergeSort merge_sort;
    auto arr_is_sorted = merge_sort.run({99, 7, 100, 4, 5, 2});
    // for (const auto& i : arr_is_sorted)
    //     std::cout << i << std::endl;

    architect::QuickSortTest quick_sort_test;
    auto partition_is_passed = quick_sort_test.runPartitionTest();
    return 0;
}
