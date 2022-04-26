#ifndef FUNCTION_HPP
# define FUNCTION_HPP

# include <vector>

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

template<class T>
T lerp(T u, T v, double t) {
    u.scl(1 - t);
    v.scl(t);
    u.add(v);
    return u;
}

template<typename T>
T   angle_cos(ft::Vector<T> &u, ft::Vector<T> &v) {
    double d = u.norm() * v.norm();
    if (d == 0)
        return 0;
    return u.dot(v) / d;
}

template<typename T>
ft::Vector<T>   cross_product(ft::Vector<T> &u, ft::Vector<T> &v) {
    if (u.size() != 3 || v.size() != 3)
        throw typename ft::Vector<T>::sizeError();
    return {
        u[1] * v[2] - u[2] * v[1],
        u[2] * v[0] - u[0] * v[2],
        u[0] * v[1] - u[1] * v[0]
    };
}

#endif
