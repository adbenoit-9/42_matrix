#ifndef UTILS_HPP
# define UTILS_HPP

namespace ft {
    template<class T>
    T   pow(const T& x, int n) {
        if (n == 0)
            return 1;
        T res = 1;
        for(int i = 0; i < n; i++)
            res *= x;
        return res;
    }

    template<class T>
    T   abs(const T& x) {
        if (x < 0)
            return -x;
        return x;
    }
}

#endif
