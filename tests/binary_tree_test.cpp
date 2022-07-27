// Copyright (c) 2022 LucaWei
#include <gtest/gtest.h>
#include <omp.h>
#include <architect/architect.hpp>


class binary_tree_test: public testing::Test {
 protected:
    static void SetUpTestCase() {
#ifdef _OPENMP
        std::cout << _OPENMP << std::endl;
        #pragma omp parallel
            #pragma omp single
        std::cout << "num_threads= " << omp_get_num_threads() << std::endl;
#endif
    }

    static void TearDownTestCase() {
    }
};




int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
