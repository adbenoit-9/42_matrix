#include "../Vector.hpp"
#include "../Matrix.hpp"

int main() {
    ft::Matrix<double> u = {
        {1., -1.},
        {-1., 1.}
    };
    std::cout << u.determinant() << std::endl;

    u = {
        {2., 0., 0.},
        {0., 2., 0.},
        {0., 0., 2.}
    };
    std::cout << u.determinant() << std::endl;

    u = {
        {8., 5., -2.},
        {4., 7., 20.},
        {7., 6., 1.}
    };
    std::cout << u.determinant() << std::endl;

    u = {
        {8., 5., -2., 4.},
        {4., 2.5, 20., 4.},
        {8., 5., 1., 4.},
        {28., -4., 17., 1.}
    };
    std::cout << u.determinant() << std::endl;
}
