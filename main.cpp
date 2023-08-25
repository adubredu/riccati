#include <Eigen/Dense>
#include <iostream>
#include <time.h>
#include <vector>
#include "riccati.h"

int main() {
    const uint dim_x = 4;
    const uint dim_u = 1;
    Eigen::MatrixXd A = Eigen::MatrixXd::Zero(dim_x, dim_x);
    Eigen::MatrixXd B = Eigen::MatrixXd::Zero(dim_x, dim_u);
    Eigen::MatrixXd Q = Eigen::MatrixXd::Zero(dim_x, dim_x);
    Eigen::MatrixXd R = Eigen::MatrixXd::Zero(dim_u, dim_u);
    Eigen::MatrixXd P = Eigen::MatrixXd::Zero(dim_x, dim_x);

    A(0, 1) = 1.0;
    A(1, 1) = -15.0;
    A(1, 2) = 10.0;
    A(2, 3) = 1.0;
    A(3, 3) = -15.0;
    B(1, 0) = 10.0;
    B(3, 0) = 1.0;

    Q(0, 0) = 1.0;
    Q(2, 2) = 1.0;
    Q(3, 3) = 2.0;

    R(0, 0) = 1.0;

    double tolerance = 1.E-3;
    bool verbose = true;
    int max_iter = 1000;

    std::cout << "A: " << std::endl << A << std::endl<< std::endl;
    std::cout << "B: " << std::endl << B << std::endl<< std::endl;
    std::cout << "Q: " << std::endl << Q << std::endl<< std::endl;
    std::cout << "R: " << std::endl << R << std::endl<< std::endl;

    clock_t start = clock();
    dare(A, B, Q, R, P, tolerance, max_iter, verbose);
    clock_t end = clock();

    std::cout << "\nElapsed Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << std::endl << std::endl;
    std::cout << "Result: \nP: " << std::endl << P << std::endl;

    return EXIT_SUCCESS;
}