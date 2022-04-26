#ifndef FUNCTION_HPP
# define FUNCTION_HPP

# include <vector>

template<class V, typename K>
V   linear_combination(std::vector<V> u, std::vector<K> coefs) {
    V res(u[0].size(), 0);
    for (size_t i = 0; i < u[0].size(); i++) {
        for (typename V::size_type j = 0; j < u.size(); j++)
            res[i] += u[j][i] * coefs[j];
    }
    return res;
}

template<class T>
T lerp(T u, T v, double t) {
    u.scl(1 - t);
    v.scl(t);
    u.add(v);
    return u;
}

template<typename T>
T   angle_cos(ft::Vector<T> &u, ft::Vector<T> &v) {
    return u.dot(v) / (u.norm() * v.norm());
}

template<typename T>
ft::Vector<T>   cross_product(ft::Vector<T> &u, ft::Vector<T> &v) {
    return {
        u[1] * v[2] - u[2] * v[1],
        u[2] * v[0] - u[0] * v[2],
        u[0] * v[1] - u[1] * v[0]
    };
}

#endif
