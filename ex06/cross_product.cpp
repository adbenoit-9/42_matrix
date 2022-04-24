#include "../Vector.hpp"
#include "../Matrix.hpp"

template<typename T>
Vector<T>   cross_product(Vector<T> &u, Vector<T> &v) {
    return {
        u[1] * v[2] - u[2] * v[1],
        u[2] * v[0] - u[0] * v[2],
        u[0] * v[1] - u[1] * v[0]
    };
}

int main() {
    Vector<double> u = {0., 0., 1.};
    Vector<double> v = {1., 0., 0.};
    std::cout   << "cross_product({0., 0., 1.}, {1., 0., 0.}) =\n"
                << cross_product<double>(u, v) << std::endl
                << std::endl;

    u = {1., 2., 3.};
    v = {4., 5., 6.};
    std::cout   << "cross_product({1., 2., 3.}, {4., 5., 6.}) =\n"
                << cross_product<double>(u, v) << std::endl
                << std::endl;

    u = {4., 2., -3.};
    v = {-2., -5., 16.};
    std::cout   << "cross_product({4., 2., -3.}, {-2., -5., 16.}) =\n"
                << cross_product<double>(u, v) << std::endl
                << std::endl;
}
