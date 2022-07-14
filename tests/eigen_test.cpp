// Copyright (c)
#include <gtest/gtest.h>
#include <omp.h>
#include <architect/architect.hpp>


class Eigen_test: public testing::Test {
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

TEST_F(Eigen_test, matrix) {
    Eigen::MatrixXd m(2, 2);
    m(0, 0) = 3;
    m(1, 0) = 2.5;
    m(0, 1) = -1;
    m(1, 1) = m(1, 0) + m(0, 1);
    std::cout << "Here is the matrix m:\n" << m << std::endl;
    Eigen::VectorXd v(2);
    v(0) = 4;
    v(1) = v(0) - 1;
    std::cout << "Here is the vector v:\n" << v << std::endl;
}




int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
