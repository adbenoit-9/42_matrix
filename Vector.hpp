#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <iomanip>

template < class T = float>
class Vector
{
    public:
        typedef	T                                   value_type;
        typedef	T&                                  reference;
        typedef	const T&                            const_reference;
        typedef	T*                                  pointer;
        typedef	const T*                            const_pointer;
        typedef	ptrdiff_t                           difference_type;
        typedef	size_t                              size_type;
        typedef std::initializer_list<value_type>   list_type;

        Vector()  : _size(0) {
            this->_begin = new value_type[0];
        }
        
        Vector(list_type init) : _size(init.size()){
            this->_begin = new value_type[this->_size];
            size_type i = 0;
            for (typename list_type::const_iterator it = init.begin(); it < init.end(); it++) {
                this->_begin[i] = *it;
                ++i;
            }
        }

        Vector(size_type n, const value_type& val = value_type()) : _size(n) {
            this->_begin = new value_type[n];
            for (size_type i = 0; i < n; i++)
                this->_begin[i] = val;		
        }
        
        Vector(const Vector& x) : _size(x._size) {
            this->_begin = new value_type[x._size];
            for (size_type i = 0; i < this->_size; i++)
                    this->_begin[i] = x._begin[i];
        }
        
        ~Vector() {
            delete[] this->_begin;
        }

        Vector& operator= (const Vector& x)
        {		
            if (this == &x)
                return *this;

            delete[] this->_begin;
            this->_begin = new value_type[x._size];
            this->_size = x._size;
            for (size_type i = 0; i < this->_size; i++)
                this->_begin[i] = x._begin[i];

            return *this;
        }

        Vector& operator= (std::initializer_list<value_type> init)
        {
            delete[] this->_begin;
            this->_size = init.size();
            this->_begin = new value_type[this->_size];
            size_type i = 0;
            for (typename std::initializer_list<value_type>::const_iterator it = init.begin(); it < init.end(); it++) {
                this->_begin[i] = *it;
                ++i;
            }
            return *this;
        }
        
        size_type	size() const {
            return this->_size;
        }
        
        void        push_back(const value_type &val) {
            pointer tmp = new value_type[this->_size + 1];
            for (size_type i = 0; i < this->_size; i++)
                tmp[i] = this->_begin[i];
            tmp[this->_size] = val;
            ++_size;
            delete[] this->_begin;
            this->_begin = tmp;
        }

        // 				~ Operators ~
        reference		operator[] (size_type n) { return this->_begin[n]; }
        const_reference	operator[] (size_type n) const { return this->_begin[n]; }

        void            add(const Vector &x) {
            for (size_type i = 0; i < this->_size; i++)
                this->_begin[i] += x[i];
        }

        void            sub(const Vector &x) {
            for (size_type i = 0; i < this->_size; i++)
                this->_begin[i] -= x[i];
        }

        void            scl(const value_type &a) {
            for (size_type i = 0; i < this->_size; i++)
                this->_begin[i] *= a;
        }
        
        
    private:
        pointer			_begin;
        size_type 		_size;
};

template<typename T>
std::ostream& operator << (std::ostream& os, const Vector<T> &vect) {
    for (typename Vector<T>::size_type i = 0; i < vect.size(); i++)
        os << "[" << std::setprecision(3) << vect[i] << "]" << std::endl;
    return os;
}

#endif