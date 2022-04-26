#include "../Vector.hpp"
#include "../Matrix.hpp"

int main() {
    std::cout << "--- multiply a matrix by a vector ---\n";
    ft::Matrix<double> u = {{1., 0.}, {0., 1.}};
    ft::Vector<double> v = {4., 2.};
    std::cout << u.mul_vec(v) << std::endl;

    u = {{2., 0.}, {0., 2.}};
    std::cout << u.mul_vec(v) << std::endl;

    u = {{2., -2.}, {-2., 2.}};
    std::cout << u.mul_vec(v) << std::endl;

    std::cout << "--- multiply a matrix by a matrix ---\n";
    u = {{1., 0.}, {0., 1.}};
    ft::Matrix<double> w = {{1., 0.}, {0., 1.}};
    std::cout << u.mul_mat(w) << std::endl;

    w = {{2., 1.}, {4., 2.}};
    std::cout << u.mul_mat(w) << std::endl;

    u = {{3., -5.}, {6., 8.}};
    std::cout << u.mul_mat(w) << std::endl;
}
