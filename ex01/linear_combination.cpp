#include "../Vector.hpp"
#include "../Matrix.hpp"
#include <vector>

template<class V, typename K>
V   linear_combination(const std::vector<V> &u, const std::vector<K> &coefs) {
    if (u.size() != coefs.size())
        throw typename V::sizeError();
    if  (u.size() == 0)
        return {};
    size_t size = u[0].size();
    for (size_t i = 1; i < u.size(); i++) {
        if (u[i].size() != size)
            throw typename V::sizeError();
    }
    V res(size, 0);
    for (size_t i = 0; i < size; i++) {
        for (typename V::size_type j = 0; j < u.size(); j++)
            res[i] += u[j][i] * coefs[j];
    }
    return res;
}

int main(void) {
    ft::Vector<double> e1 = {1, 0, 0};
    ft::Vector<double> e2 = {0, 1, 0};
    ft::Vector<double> e3 = {0, 0, 1};
    std::cout   << "e1 =\n" << e1 << std::endl
                << "e2 =\n" << e2  << std::endl
                << "e3 =\n" << e3 << std::endl
                << "coef1 = [10.  -2.  0.5]" << std::endl << std::endl;
    ft::Vector<double> res = linear_combination< ft::Vector<double>, double >({e1, e2, e3}, {10., -2., 0.5});
    std::cout << "linear_combination([e1, e2, e3], coef1) =\n" << res;

    std::cout << "----\n\n";
    ft::Vector<double> v1 = {1., 2., 3.};
    ft::Vector<double> v2 = {0., 10., -100.};
    std::cout   << "v1 =\n" << v1 << std::endl
                << "v2 =\n" << v2  << std::endl
                << "coef2 = [10.  -2]" << std::endl << std::endl;
    ft::Vector<double> res2 = linear_combination< ft::Vector<double>, double >({v1, v2}, {10., -2});
    std::cout << "linear_combination([v1, v2], coef2) =\n" << res2;


}
