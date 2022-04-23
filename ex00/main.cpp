#include "Vector.hpp"
#include "Matrix.hpp"

void    test_vector() {
    std::cout << "------ VECTOR ------" << std::endl;
    Vector<float> u;
    u.push_back(2.);
    u.push_back(3.);
    std::cout << "u = " << std::endl << u << std::endl;

    Vector<float> v;
    v.push_back(5.);
    v.push_back(7.);
    std::cout << "v = " << std::endl << v << "---\n" << std::endl;

    std::cout << "u.add(v) = \n";
    u.add(v);
    std::cout << u << std::endl;
    u.sub(v);

    std::cout << "u.sub(v) = \n";
    u.sub(v);
    std::cout << u << std::endl;
    u.add(v);

    std::cout << "u.scl(2.) = \n";
    u.scl(2.);
    std::cout << u << std::endl;

    std::cout << std::endl;
}

void    test_matrix() {
    std::cout << "------ MATRIX ------" << std::endl;
    Vector<float> u1;
    u1.push_back(1.);
    u1.push_back(3.);

    Vector<float> u2;
    u2.push_back(2.);
    u2.push_back(4.);

    Matrix<float> m1;
    m1.insert_column(u1);
    m1.insert_column(u2);
    std::cout << "m1 = " << std::endl << m1 << std::endl;


    Vector<float> v1;
    v1.push_back(7.);
    v1.push_back(-2.);

    Vector<float> v2;
    v2.push_back(4.);
    v2.push_back(2.);


    Matrix<float> m2;
    m2.insert_column(v1);
    m2.insert_column(v2);
    std::cout << "m2 = " << std::endl << m2 << "---\n" << std::endl;
    
    std::cout << "m1.add(m2) = \n";
    m1.add(m2);
    std::cout << m1 << std::endl;
    m1.sub(m2);

    std::cout << "m1.sub(m2) = \n";
    m1.sub(m2);
    std::cout << m1 << std::endl;
    m1.add(m2);

    std::cout << "m1.scl(2.) = \n";
    m1.scl(2.);
    std::cout << m1 << std::endl;
}

int main () {
    test_vector();
    test_matrix();
}
