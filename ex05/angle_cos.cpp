#include "../Vector.hpp"
#include "../Matrix.hpp"

template<typename T>
T   angle_cos(ft::Vector<T> &u, ft::Vector<T> &v) {
    return u.dot(v) / (u.norm() * v.norm());
}

int main() {
    ft::Vector<double> u = {1., 0.};
    ft::Vector<double> v = {1., 0.};
    std::cout   << "angle_cos({1., 0.}, {1., 0.}) =\n"
                << angle_cos<double>(u, v) << std::endl
                << std::endl;

    u = {1., 0.};
    v = {0., 1.};
    std::cout   << "angle_cos({1., 0.}, {0., 1.}) =\n"
                << angle_cos<double>(u, v) << std::endl
                << std::endl;

    u = {-1., 1.};
    v = {1., -1.};
    std::cout   << "angle_cos({-1., 1.}, {1., -1.}) =\n"
                << angle_cos<double>(u, v) << std::endl
                << std::endl;

    u = {2., 1.};
    v = {4., 2.};
    std::cout   << "angle_cos({2., 1.}, {4., 2.}) =\n"
                << angle_cos<double>(u, v) << std::endl
                << std::endl;

    u = {1., 2., 3.};
    v = {4., 5., 6.};
    std::cout   << "angle_cos({1., 2., 3.}, {4., 5., 6.}) =\n"
                << angle_cos<double>(u, v) << std::endl;
}
