#include "../Vector.hpp"
#include "../Matrix.hpp"

int main() {
    Matrix<double> u = {
        {1., 2., 3.},
        {4., 5., 6.},
        {7., 8., 9.},
    };
    std::cout << "u =\n" << u << std::endl;
    std::cout << "uT =\n" << u.transpose() << std::endl;
    std::cout << "-------\n\n";

   u = {
        {-1., 3., 9.},
        {0., -5., 8.},
    };
    std::cout << "u =\n" << u << std::endl;
    std::cout << "uT =\n" << u.transpose() << std::endl;
}
