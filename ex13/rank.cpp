#include "../Vector.hpp"
#include "../Matrix.hpp"

int main(void) {
    ft::Matrix<double> u;
    u = {
        {1., 0., 0.},
        {0., 1., 0.},
        {0., 0., 1.}
    };
    std::cout << u.rank() << std::endl;

    u = {
        {1., 2., 0., 0.},
        {2., 4., 0., 0.},
        {-1., 2., 1., 1.}
    };
    std::cout << u.rank() << std::endl;

    u = {
        {8., 5., -2.},
        {4., 7., 20.},
        {7., 6., 1.},
        {21., 18., 7.}
    };
    std::cout << u.rank() << std::endl;
}
