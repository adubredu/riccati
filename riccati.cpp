#include <iostream>
#include "riccati.h"

void dare(const Eigen::MatrixXd &A,
                            const Eigen::MatrixXd &B, const Eigen::MatrixXd &Q,
                            const Eigen::MatrixXd &R, Eigen::MatrixXd &P,
                            const double &tolerance,
                            const int iter_max,
                            const bool &verbose) {
    P = Q;
    Eigen::MatrixXd G = B * R.inverse() * B.transpose();
    Eigen::MatrixXd Ak = A;
    Eigen::MatrixXd Ak_next;
    Eigen::MatrixXd P_next;
    Eigen::MatrixXd G_next;
    int m = A.rows();
    int n = A.cols();
    double diff;
    if (verbose) {
        std::cout << "Iter " << "      " << " Error " <<  std::endl;
        std::cout << "-----------------" << std::endl << std::endl;
    }
    for (int i=0; i < iter_max; ++i) {
        Ak_next = Ak * (Eigen::MatrixXd::Identity(m, n) + G * P).inverse()*Ak;
        G_next = G + Ak*(Eigen::MatrixXd::Identity(m, n) + G * P).inverse()*G*Ak.transpose();
        P_next = P + Ak.transpose()*P*(Eigen::MatrixXd::Identity(m, n) + G * P).inverse()*Ak;

        diff = fabs((P_next - P).maxCoeff());
        P = P_next;
        Ak = Ak_next;
        G = G_next;
        if (verbose) {
            std::cout << i << "         " << diff << std::endl;
        }
        if (diff < tolerance) {
        return;
        }
    }
}