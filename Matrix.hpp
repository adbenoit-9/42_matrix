#ifndef MATRIX_HPP
# define MATRIX_HPP

# include "Vector.hpp"
# include <utility>

template < class T = float>
class Matrix
{
    public:
        typedef	T                                   value_type;
        typedef Vector<T>                           vector;
        typedef	T&                                  reference;
        typedef	const T&                            const_reference;
        typedef	T*                                  pointer;
        typedef	const T*                            const_pointer;
        typedef	ptrdiff_t                           difference_type;
        typedef	size_t                              size_type;
        typedef std::initializer_list<value_type>   list_type;
        typedef std::initializer_list<list_type>    tab_type;

        Matrix() : _row(0), _column(0) {
            this->_begin = new vector[0];
        }
        
        Matrix(const Matrix& x) : _column(x._column), _row(x._row)  {
            this->_begin = new vector[x._row];
            for (size_type i = 0; i < this->_row; i++)
                    this->_begin[i] = x._begin[i];
        }

        Matrix(tab_type init) : _column(init.size()), _row((init.begin())->size()) {
            this->_begin = new vector[this->_row];
            size_type i = 0;
            for (typename tab_type::const_iterator it = init.begin(); it < init.end(); it++) {
                this->_begin[i] = *it;
                ++i;
            }
        }

        ~Matrix() {
            delete[] this->_begin;
        }

        Matrix& operator= (const Matrix& x)
        {		
            if (this == &x)
                return *this;
            delete[] this->_begin;
            this->_begin = new vector[x._row];
            this->_column = x._column;
            this->_row = x._row;
            for (size_type i = 0; i < this->_row; i++)
                    this->_begin[i] = x._begin[i];
            return *this;
        }

        Matrix& operator= (tab_type init)
        {		
            delete[] this->_begin;
            this->_row = (init.begin())->size();
            this->_column = init.size();
            this->_begin = new vector[this->_row];
            size_type i = 0;
            for (typename tab_type::const_iterator it = init.begin(); it < init.end(); it++) {
                this->_begin[i] = *it;
                ++i;
            }
            return *this;
        }
        
        size_type	size() const {
            return this->_column * this->_row;
        }

        std::pair<size_type, size_type>	shape() const {
            return std::make_pair(this->_row, this->_column);
        }

        void        zeros(size_type m, size_type n) {
            this->_row = m;
            this->_column = n;
            delete[] this->_begin;
            this->_begin = new vector[n];
            for (size_type i = 0; i < n; i++)
                this->_begin[i].zeros(m);
        }

        void        insert_column(const vector& v) {
            this->_row = v.size();
            vector *tmp = new vector[this->_column + 1];
            for (size_type i = 0; i < this->_column; i++)
                tmp[i] = this->_begin[i];
            tmp[this->_column] = v;
            ++this->_column;
            delete[] this->_begin;
            this->_begin = tmp;
        }

        // 				~ Operators ~
        vector&		operator[] (size_type n) { return this->_begin[n]; }
        const vector&	operator[] (size_type n) const { return this->_begin[n]; }
        
        void            add(const Matrix &x) {
            for (size_type i = 0; i < this->_column; i++)
                this->_begin[i].add(x[i]);
        }

        void            sub(const Matrix &x) {
            for (size_type i = 0; i < this->_column; i++)
                this->_begin[i].sub(x[i]);
        }

        void            scl(const value_type &a) {
            for (size_type i = 0; i < this->_column; i++)
                this->_begin[i].scl(a);
        }

    private:
        vector			*_begin;
        size_type 		_column;
        size_type 		_row;
};

template<typename T>
std::ostream& operator << (std::ostream& os, const Matrix<T> &mat) {
    os << "[";
    for (typename Matrix<T>::size_type i = 0; i < mat.shape().first; i++) {
        os << "[";
        for (typename Matrix<T>::size_type j = 0; j < mat.shape().second; j++) {

            if (j != 0)
                os << "\t";
            os << mat[j][i];
        }
        if (i != mat.shape().first - 1)
            os << "]" << std::endl;
        else
            os << "]";
    }
    os << "]" << std::endl;
    return os;
}

#endif
