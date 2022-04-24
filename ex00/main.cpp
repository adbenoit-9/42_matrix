#include "../Vector.hpp"
#include "../Matrix.hpp"

void    test_vector() {
    std::cout << "------ VECTOR ------" << std::endl;
    Vector<double> u = {2., 3.};
    std::cout << "u = " << std::endl << u << std::endl;

    Vector<double> v = {5., 7.};
    std::cout << "v = " << std::endl << v << "---\n" << std::endl;

    std::cout << "u.add(v) = \n";
    u.add(v);
    std::cout << u << std::endl;
    u = {2., 3.};

    std::cout << "u.sub(v) = \n";
    u.sub(v);
    std::cout << u << std::endl;
    v = {5., 7.};

    std::cout << "u.scl(2.) = \n";
    u.scl(2.);
    std::cout << u << std::endl;

    std::cout << std::endl;
}

void    test_matrix() {
    std::cout << "------ MATRIX ------" << std::endl;
    Matrix<double> m1 = {{1., 2.}, {3., 4.}};
    std::cout << "m1 = " << std::endl << m1 << std::endl;

    Matrix<double> m2 = {{7., 4.}, {-2., 2.}};
    std::cout << "m2 = " << std::endl << m2 << "---\n" << std::endl;
    
    std::cout << "m1.add(m2) = \n";
    m1.add(m2);
    std::cout << m1 << std::endl;
    m1 = {{1., 2.}, {3., 4.}};

    std::cout << "m1.sub(m2) = \n";
    m1.sub(m2);
    std::cout << m1 << std::endl;
    m1 = {{1., 2.}, {3., 4.}};

    std::cout << "m1.scl(2.) = \n";
    m1.scl(2.);
    std::cout << m1 << std::endl;
}

int main () {
    test_vector();
    test_matrix();
}
