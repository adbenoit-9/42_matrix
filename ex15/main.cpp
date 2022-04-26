#include "Complex.hpp"
#include "functions.hpp"

void    test_vector() {
    std::cout << "------ VECTOR ------" << std::endl;
    ft::Vector<ft::Complex> u = {ft::Complex(9., 21.), ft::Complex(-2., -1.)};
    std::cout << "u = " << std::endl << u << std::endl;

    ft::Vector<ft::Complex> v = {ft::Complex(1.6, 2.), ft::Complex(2., 1.)};
    std::cout << "v = " << std::endl << v << "---\n" << std::endl;

    std::cout << "u.add(v) = \n";
    u.add(v);
    std::cout << u << std::endl;
   u = {ft::Complex(9., 21.), ft::Complex(-2., -1.)};

    std::cout << "u.sub(v) = \n";
    u.sub(v);
    std::cout << u << std::endl;
    u = {ft::Complex(9., 21.), ft::Complex(-2., -1.)};

    std::cout << "u.scl(2.) = \n";
    u.scl(2.);
    std::cout << u << std::endl;

    std::cout << std::endl;
}

void    test_matrix() {
    std::cout << "------ MATRIX ------" << std::endl;
    ft::Matrix<ft::Complex> m1 = {
        {ft::Complex(1., 2.), ft::Complex(2., -1.)},
        {ft::Complex(-2., 3.), ft::Complex(0., -1.)}
    };
    std::cout << "m1 = " << std::endl << m1 << std::endl;

    ft::Matrix<ft::Complex> m2 = {
        {ft::Complex(4., 1.), ft::Complex(8, -1)},
        {ft::Complex(-2., 4.), ft::Complex(4., 0.)}
    };
    std::cout << "m2 = " << std::endl << m2 << "---\n" << std::endl;
    
    std::cout << "m1.add(m2) = \n";
    m1.add(m2);
    std::cout << m1 << std::endl;
    m1 = {
        {ft::Complex(1., 2.), ft::Complex(2., -1.)},
        {ft::Complex(-2., 3.), ft::Complex(0., -1.)}
    };

    std::cout << "m1.sub(m2) = \n";
    m1.sub(m2);
    std::cout << m1 << std::endl;
    m1 = {
        {ft::Complex(1., 2.), ft::Complex(2., -1.)},
        {ft::Complex(-2., 3.), ft::Complex(0., -1.)}
    };

    std::cout << "m1.scl(2.) = \n";
    m1.scl(2.);
    std::cout << m1 << std::endl;
}

void test_lc(void) {
    std::cout << "------ linear_combination ------" << std::endl;
    ft::Vector<ft::Complex> v1 = {1, ft::Complex(2., 4.), 0};
    ft::Vector<ft::Complex> v2 = {ft::Complex(1., 4.), ft::Complex(2., -4.), 0};
    ft::Vector<ft::Complex> v3 = {ft::Complex(-3., 6.), 0, ft::Complex(-1., 4.)};
    std::cout   << "v1 =\n" << v1 << std::endl
                << "v2 =\n" << v2  << std::endl
                << "v3 =\n" << v3 << std::endl;
    ft::Vector<ft::Complex> res = linear_combination< ft::Vector<ft::Complex>, double >({v1, v2, v3}, {10., -2., 0.5});
    std::cout << "linear_combination =\n" << res << std::endl;
}

void test_lerp(void) {
    std::cout << "------ lerp ------" << std::endl;
    std::cout << lerp< ft::Vector<ft::Complex> >(
        {ft::Complex(2., 21.), ft::Complex(-2., -1.)},
        {ft::Complex(9., -8.), ft::Complex(0., 2.)},
        0.3
        ) << std::endl;
}

void    test_dot(void) {
    std::cout << "------ dot ------" << std::endl;
    ft::Vector<ft::Complex> u = {ft::Complex(2., 21.), ft::Complex(-2., -1.)};
    ft::Vector<ft::Complex> v = {ft::Complex(9., -8.), ft::Complex(0., 2.)};
    std::cout << u.dot(v) << std::endl << std::endl;
}

void    test_norm(void) {
    std::cout << "------ norm ------" << std::endl;
    ft::Vector<ft::Complex> u = {
        ft::Complex(2., 21.),
        ft::Complex(-2., -1.),
        ft::Complex(4., 3.)};
    std::cout   << "u =\n" << u << std::endl
                << "norm_1 = " << u.norm_1() << std::endl
                << "norm = " << u.norm() << std::endl
                << "norm_inf = " << u.norm_inf() << std::endl
                << std::endl;
}

void    test_cos(void) {
    std::cout << "------ angle_cos ------" << std::endl;
    ft::Vector<ft::Complex> u = {ft::Complex(2., 21.), ft::Complex(-2., -1.)};
    ft::Vector<ft::Complex> v = {ft::Complex(9., -8.), ft::Complex(0., 2.)};
    std::cout   << "angle_cos =\n"
                << angle_cos<ft::Complex>(u, v) << std::endl
                << std::endl;
}

void    test_cp(void) {
    std::cout << "------ cross_product ------" << std::endl;
    ft::Vector<ft::Complex> u = {ft::Complex(2., 21.), ft::Complex(-2., -1.), ft::Complex(-1.5, 3.)};
    ft::Vector<ft::Complex> v = {ft::Complex(9., -8.), ft::Complex(0., 2.), ft::Complex(1., -1.)};
    std::cout   << "u =\n" << u << std::endl
                << "v =\n" << v << std::endl
                << "cross_product =\n"
                << cross_product<ft::Complex>(u, v) << std::endl
                << std::endl;
}

void    test_mul(void) {
    std::cout << "--- multiply a matrix by a vector ---\n";

    ft::Matrix<ft::Complex> u = {
        {ft::Complex(9., -8.), ft::Complex(0., 2.)},
        {ft::Complex(1., 8.), ft::Complex(3., 2.)}
    };
    ft::Vector<ft::Complex> v = {ft::Complex(2., 21.), ft::Complex(-2., -1.)};
    std::cout << u.mul_vec(v) << std::endl;

    std::cout << "--- multiply a matrix by a matrix ---\n";
    u = {
        {ft::Complex(9., -8.), ft::Complex(0., 2.)},
        {ft::Complex(1., 8.), ft::Complex(3., 2.)}
    };
    ft::Matrix<ft::Complex> w = {
        {ft::Complex(1., -4.), ft::Complex(-1., 2.)},
        {ft::Complex(1., 3.), ft::Complex(4., 2.)}
    };
    std::cout << u.mul_mat(w) << std::endl;
}

void    test_trace(void) {
    std::cout << "------ trace ------" << std::endl;
    ft::Matrix<ft::Complex> u = {
        {ft::Complex(9., -8.), ft::Complex(0., 2.)},
        {ft::Complex(1., 8.), ft::Complex(3., 2.)}
    };
    std::cout << u.trace() << std::endl << std::endl;
}

void test_transpose(void) {
    std::cout << "------ transpose ------" << std::endl;
    ft::Matrix<ft::Complex> u = {
        {ft::Complex(0., -15.), ft::Complex(3., 12.)},
        {ft::Complex(19., -8.), ft::Complex(14., 2.)},
        {ft::Complex(10., 8.), ft::Complex(31., 2.)}
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
    ft::Matrix<ft::Complex> u = {
        {ft::Complex(0., -1.), ft::Complex(3., 12.), ft::Complex(3., 2.)},
        {ft::Complex(9., -8.), ft::Complex(4., 2.), ft::Complex(0., 1.)},
        {ft::Complex(10., 8.), ft::Complex(1., 2.), ft::Complex(1., 1.)}
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
