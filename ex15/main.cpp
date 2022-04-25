#include "Complex.hpp"

void    test_vector() {
    std::cout << "------ VECTOR ------" << std::endl;
    Vector<Complex> u = {Complex(9., 21.), Complex(-2., -1.)};
    std::cout << "u = " << std::endl << u << std::endl;

    Vector<Complex> v = {Complex(1.6, 2.), Complex(2., 1.)};
    std::cout << "v = " << std::endl << v << "---\n" << std::endl;

    std::cout << "u.add(v) = \n";
    u.add(v);
    std::cout << u << std::endl;
   u = {Complex(9., 21.), Complex(-2., -1.)};

    std::cout << "u.sub(v) = \n";
    u.sub(v);
    std::cout << u << std::endl;
    u = {Complex(9., 21.), Complex(-2., -1.)};

    std::cout << "u.scl(2.) = \n";
    u.scl(2.);
    std::cout << u << std::endl;

    std::cout << std::endl;
}

void    test_matrix() {
    std::cout << "------ MATRIX ------" << std::endl;
    Matrix<Complex> m1 = {
        {Complex(1., 2.), Complex(2., -1.)},
        {Complex(-2., 3.), Complex(0., -1.)}
    };
    std::cout << "m1 = " << std::endl << m1 << std::endl;

    Matrix<Complex> m2 = {
        {Complex(4., 1.), Complex(8, -1)},
        {Complex(-2., 4.), Complex(4., 0.)}
    };
    std::cout << "m2 = " << std::endl << m2 << "---\n" << std::endl;
    
    std::cout << "m1.add(m2) = \n";
    m1.add(m2);
    std::cout << m1 << std::endl;
    m1 = {
        {Complex(1., 2.), Complex(2., -1.)},
        {Complex(-2., 3.), Complex(0., -1.)}
    };

    std::cout << "m1.sub(m2) = \n";
    m1.sub(m2);
    std::cout << m1 << std::endl;
    m1 = {
        {Complex(1., 2.), Complex(2., -1.)},
        {Complex(-2., 3.), Complex(0., -1.)}
    };

    std::cout << "m1.scl(2.) = \n";
    m1.scl(2.);
    std::cout << m1 << std::endl;
}

void test_lc(void) {
    std::cout << "------ linear_combination ------" << std::endl;
    Vector<Complex> v1 = {1, Complex(2., 4.), 0};
    Vector<Complex> v2 = {Complex(1., 4.), Complex(2., -4.), 0};
    Vector<Complex> v3 = {Complex(-3., 6.), 0, Complex(-1., 4.)};
    std::cout   << "v1 =\n" << v1 << std::endl
                << "v2 =\n" << v2  << std::endl
                << "v3 =\n" << v3 << std::endl;
    Vector<Complex> res = linear_combination< Vector<Complex>, double >({v1, v2, v3}, {10., -2., 0.5});
    std::cout << "linear_combination =\n" << res << std::endl;
}

void test_lerp(void) {
    std::cout << "------ lerp ------" << std::endl;
    std::cout << lerp< Vector<Complex> >(
        {Complex(2., 21.), Complex(-2., -1.)},
        {Complex(9., -8.), Complex(0., 2.)},
        0.3
        ) << std::endl;
}

void    test_dot(void) {
    std::cout << "------ dot ------" << std::endl;
    Vector<Complex> u = {Complex(2., 21.), Complex(-2., -1.)};
    Vector<Complex> v = {Complex(9., -8.), Complex(0., 2.)};
    std::cout << u.dot(v) << std::endl << std::endl;
}

void    test_norm(void) {
    std::cout << "------ norm ------" << std::endl;
    Vector<Complex> u = {
        Complex(2., 21.),
        Complex(-2., -1.),
        Complex(4., 3.)};
    std::cout   << "u =\n" << u << std::endl
                << "norm_1 = " << u.norm_1() << std::endl
                << "norm = " << u.norm() << std::endl
                << "norm_inf = " << u.norm_inf() << std::endl
                << std::endl;
}

void    test_cos(void) {
    std::cout << "------ angle_cos ------" << std::endl;
    Vector<Complex> u = {Complex(2., 21.), Complex(-2., -1.)};
    Vector<Complex> v = {Complex(9., -8.), Complex(0., 2.)};
    std::cout   << "angle_cos =\n"
                << angle_cos<Complex>(u, v) << std::endl
                << std::endl;
}

void    test_cp(void) {
    std::cout << "------ cross_product ------" << std::endl;
    Vector<Complex> u = {Complex(2., 21.), Complex(-2., -1.), Complex(-1.5, 3.)};
    Vector<Complex> v = {Complex(9., -8.), Complex(0., 2.), Complex(1., -1.)};
    std::cout   << "u =\n" << u << std::endl
                << "v =\n" << v << std::endl
                << "cross_product =\n"
                << cross_product<Complex>(u, v) << std::endl
                << std::endl;
}

void    test_mul(void) {
    std::cout << "--- multiply a matrix by a vector ---\n";

    Matrix<Complex> u = {
        {Complex(9., -8.), Complex(0., 2.)},
        {Complex(1., 8.), Complex(3., 2.)}
    };
    Vector<Complex> v = {Complex(2., 21.), Complex(-2., -1.)};
    std::cout << u.mul_vec(v) << std::endl;

    std::cout << "--- multiply a matrix by a matrix ---\n";
    u = {
        {Complex(9., -8.), Complex(0., 2.)},
        {Complex(1., 8.), Complex(3., 2.)}
    };
    Matrix<Complex> w = {
        {Complex(1., -4.), Complex(-1., 2.)},
        {Complex(1., 3.), Complex(4., 2.)}
    };
    std::cout << u.mul_mat(w) << std::endl;
}

void    test_trace(void) {
    std::cout << "------ trace ------" << std::endl;
    Matrix<Complex> u = {
        {Complex(9., -8.), Complex(0., 2.)},
        {Complex(1., 8.), Complex(3., 2.)}
    };
    std::cout << u.trace() << std::endl << std::endl;
}

void test_transpose(void) {
    std::cout << "------ transpose ------" << std::endl;
    Matrix<Complex> u = {
        {Complex(0., -15.), Complex(3., 12.)},
        {Complex(19., -8.), Complex(14., 2.)},
        {Complex(10., 8.), Complex(31., 2.)}
    };
    std::cout << "u =\n" << u << std::endl;
    std::cout << "uT =\n" << u.transpose() << std::endl;
}


int main () {
    test_vector();
    test_matrix();
    test_lc();
    test_lerp();
    test_dot();
    test_norm();
    test_cos();
    test_cp();
    test_mul();
    test_trace();
    test_transpose();
    Matrix<Complex> u = {
        {Complex(0., -1.), Complex(3., 12.), Complex(3., 2.)},
        {Complex(9., -8.), Complex(4., 2.), Complex(0., 1.)},
        {Complex(10., 8.), Complex(1., 2.), Complex(1., 1.)}
    };
    std::cout   << "------ matrice =\n" << u << std::endl
                << "------ row_echelon ------" << std::endl
                << u.row_echelon() << std::endl
                << "------ determinant ------" << std::endl
                << u.determinant() << std::endl << std::endl
                << "------ inverse ------" << std::endl
                << u.inverse() << std::endl << std::endl
                << "------ rank ------" << std::endl
                << u.rank() << std::endl << std::endl;
}
