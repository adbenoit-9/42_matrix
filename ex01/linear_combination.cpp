#include "../Vector.hpp"
#include "../Matrix.hpp"
#include <vector>

template<class V, typename K>
V   linear_combination(std::vector<V> u, std::vector<K> coefs) {
    V res(u[0].size(), 0);
    for (size_t i = 0; i < u[0].size(); i++) {
        for (typename V::size_type j = 0; j < u.size(); j++)
            res[i] += u[j][i] * coefs[j];
    }
    return res;
}

int main() {
    Vector<double> e1 = {1, 0, 0};
    Vector<double> e2 = {0, 1, 0};
    Vector<double> e3 = {0, 0, 1};
    std::cout   << "e1 =\n" << e1 << std::endl
                << "e2 =\n" << e2  << std::endl
                << "e3 =\n" << e3 << std::endl
                << "coef1 = [10.  -2.  0.5]" << std::endl << std::endl;
    Vector<double> res = linear_combination< Vector<double>, double >({e1, e2, e3}, {10., -2., 0.5});
    std::cout << "linear_combination([e1, e2, e3], coef1) =\n" << res;

    std::cout << "----\n\n";
    Vector<double> v1 = {1., 2., 3.};
    Vector<double> v2 = {0., 10., -100.};
    std::cout   << "v1 =\n" << v1 << std::endl
                << "v2 =\n" << v2  << std::endl
                << "coef2 = [10.  -2]" << std::endl << std::endl;
    Vector<double> res2 = linear_combination< Vector<double>, double >({v1, v2}, {10., -2});
    std::cout << "linear_combination([v1, v2], coef2) =\n" << res2;


}
