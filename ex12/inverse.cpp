#include "../Vector.hpp"
#include "../Matrix.hpp"

int main() {
    ft::Matrix<double> u;
    u = {
        {1., 0., 0.},
        {0., 1., 0.},
        {0., 0., 1.}
    };
    std::cout << u.inverse() << std::endl;

    u = {
        {2., 0., 0.},
        {0., 2., 0.},
        {0., 0., 2.}
    };
    std::cout << u.inverse() << std::endl;

    u = {
        {8., 5., -2.},
        {4., 7., 20.},
        {7., 6., 1.}
    };
    std::cout << u.inverse() << std::endl;
}
