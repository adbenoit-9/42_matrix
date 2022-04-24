#include "../Vector.hpp"
#include "../Matrix.hpp"

int main() {
    Vector<double> u = {0., 0.};
    Vector<double> v = {1., 1.};
    std::cout << u.dot(v) << std::endl;

    u = {1., 1.};
    v = {1., 1.};
    std::cout << u.dot(v) << std::endl;

    u = {-1., 6.};
    v = {3., 2.};
    std::cout << u.dot(v) << std::endl;
}
