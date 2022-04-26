#include "../Vector.hpp"
#include "../Matrix.hpp"

int main() {
    ft::Matrix<double> u = {
        {1., 0., 0.},
        {0., 1., 0.},
        {1., 0., 1.}
    };
    std::cout << u.row_echelon() << std::endl;

    u = {
        {1., 2.},
        {3., 4.}
    };
    std::cout << u.row_echelon() << std::endl;

    u = {
        {1., 2.},
        {2., 4.}
    };
    std::cout << u.row_echelon() << std::endl;

    u = {
        {8., 5., -2., 4., 28.},
        {4., 2.5, 20., 4., -4.},
        {8., 5., 1., 4., 17.},
    };
    std::cout << u.row_echelon() << std::endl;
}
