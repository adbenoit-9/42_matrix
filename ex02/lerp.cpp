#include "../Vector.hpp"
#include "../Matrix.hpp"

template<class T>
T lerp(T u, T v, float t) {
    u.scl(1 - t);
    v.scl(t);
    u.add(v);
    return u;
}

int main() {
    Vector<float> res = lerp< Vector<float> >({0.}, {1.}, 0.);
    std::cout   << "lerp(0., 1., 0.) = \n" << res << std::endl;
    res = lerp< Vector<float> >({0.}, {1.}, 1.);
    std::cout   << "lerp(0., 1., 1.) = \n" << res << std::endl;
    res = lerp< Vector<float> >({0.}, {1.}, 0.5);
    std::cout   << "lerp(0., 1., 0.5) = \n" << res << std::endl;
    res = lerp< Vector<float> >({21.}, {42.}, 0.3);
    std::cout   << "lerp(21., 42., 0.3) = \n" << res << std::endl;
    res = lerp< Vector<float> >(
            {2., 1.},
            {4., 2.},
            0.3
        );
    std::cout   << "lerp([2., 1.], [4., 2.], 0.3) =\n"
                << res << std::endl;
    Matrix<float> res1;
    res1 = lerp< Matrix<float> >(
            {{2., 3.}, {1., 4.}},
            {{20., 30.}, {10., 40.}},
            0.5
        );
    std::cout   << "lerp([[2., 1.], [3., 4.]], [[20., 10.], [30., 40.]]) =\n"
                << res1;
}