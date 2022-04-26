#include "../Vector.hpp"
#include "../Matrix.hpp"

template<class T>
T lerp(T u, T v, double t) {
    u.scl(1 - t);
    v.scl(t);
    u.add(v);
    return u;
}

int main(void) {
    ft::Vector<double> res = lerp< ft::Vector<double> >({0.}, {1.}, 0.);
    std::cout   << "lerp(0., 1., 0.) = \n" << res << std::endl;
    res = lerp< ft::Vector<double> >({0.}, {1.}, 1.);
    std::cout   << "lerp(0., 1., 1.) = \n" << res << std::endl;
    res = lerp< ft::Vector<double> >({0.}, {1.}, 0.5);
    std::cout   << "lerp(0., 1., 0.5) = \n" << res << std::endl;
    res = lerp< ft::Vector<double> >({21.}, {42.}, 0.3);
    std::cout   << "lerp(21., 42., 0.3) = \n" << res << std::endl;
    res = lerp< ft::Vector<double> >(
            {2., 1.},
            {4., 2.},
            0.3
        );
    std::cout   << "lerp([2., 1.], [4., 2.], 0.3) =\n"
                << res << std::endl;
    ft::Matrix<double> res1;
    res1 = lerp< ft::Matrix<double> >(
            {{2., 1.}, {3., 4.}},
            {{20., 10.}, {30., 40.}},
            0.5
        );
    std::cout   << "lerp([[2., 1.], [3., 4.]], [[20., 10.], [30., 40.]]) =\n"
                << res1;
}
