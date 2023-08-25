#include <Eigen/Dense>

// solve discrete time_Algebraic Riccati equation (DARE) using the structured doubling algorithm
// Ref: http://dx.doi.org/10.1080/00207170410001714988
void dare(const Eigen::MatrixXd &Ad,
                            const Eigen::MatrixXd &Bd, const Eigen::MatrixXd &Q,
                            const Eigen::MatrixXd &R, Eigen::MatrixXd &P,
                            const double &tolerance = 1.E-3,
                            const int iter_max = 1000,
                            const bool &verbose = false);