#include "../Vector.hpp"
#include "../Matrix.hpp"

template<class V, typename K>
V   linear_combination(V *u, K *coefs, size_t size) {
    V res(u[0].size(), 0);
    for (size_t i = 0; i < u[0].size(); i++) {
        for (typename V::size_type j = 0; j < size; j++)
            res[i] += u[j][i] * coefs[j];
    }
    return res;
}

int main() {
    Vector<float> e1 = {1, 0, 0};
    Vector<float> e2 = {0, 1, 0};
    Vector<float> e3 = {0, 0, 1};
    Vector<float> vect_list[] = {e1, e2, e3};
    float           coef1[] = {10., -2., 0.5};
    std::cout   << "e1 =\n" << e1 << std::endl
                << "e2 =\n" << e2  << std::endl
                << "e3 =\n" << e3 << std::endl
                << "coef1 = [10.  -2.  0.5]" << std::endl << std::endl;
    Vector<float> res = linear_combination< Vector<float>, float >(vect_list, coef1, 3);
    std::cout << "linear_combination([e1, e2, e3], coef1) =\n" << res;

    std::cout << "----\n\n";
    Vector<float> v1 = {1., 2., 3.};
    Vector<float> v2 = {0., 10., -100.};
    Vector<float> vect_list2[] = {v1, v2};
    float           coef2[] = {10., -2};
    std::cout   << "v1 =\n" << v1 << std::endl
                << "v2 =\n" << v2  << std::endl
                << "coef2 = [10.  -2]" << std::endl << std::endl;
    Vector<float> res2 = linear_combination< Vector<float>, float >(vect_list2, coef2, 2);
    std::cout << "linear_combination([v1, v2], coef2) =\n" << res2;


}
