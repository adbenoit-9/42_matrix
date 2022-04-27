#ifndef MATRIX_HPP
# define MATRIX_HPP

# include "Vector.hpp"
# include <utility>
# include <initializer_list>

namespace ft{
template < class T = double>
class Matrix
{
    public:
        typedef	T                                   value_type;
        typedef ft::Vector<T>                           vector;
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

        Matrix(size_type m, size_type n, const value_type &val) :  _row(m), _column(n) {
            this->_begin = new vector[this->_row];
            for (size_type i = 0; i < this->_row; i++)
                this->_begin[i] = vector(this->_column, val);
        }
        
        Matrix(const Matrix& x) :  _row(x._row), _column(x._column) {
            this->_begin = new vector[x._row];
            for (size_type i = 0; i < this->_row; i++)
                    this->_begin[i] = x._begin[i];
        }

        Matrix(const tab_type init) : _row(init.size()), _column((init.begin())->size()) {
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

        Matrix& operator= (const tab_type init)
        {		
            delete[] this->_begin;
            this->_row = init.size();
            this->_column = (init.begin())->size();
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

        bool        square() const {
            return (this->_column == this->_row);
        }

        void        insert_row(const vector& v) {
            this->_row = v.size();
            vector *tmp = new vector[this->_row + 1];
            for (size_type i = 0; i < this->_row; i++)
                tmp[i] = this->_begin[i];
            tmp[this->_row] = v;
            ++this->_row;
            delete[] this->_begin;
            this->_begin = tmp;
        }

        void        remove_row(const size_type& k) {
            vector *tmp = new vector[this->_row - 1];
            for (size_type i = 0, j = 0; i < this->_row; i++) {
                if (i != k) {
                    tmp[j] = this->_begin[i];
                    ++j;
                }
            }
            --this->_row;
            delete[] this->_begin;
            this->_begin = tmp;
        }

        void        remove_col(const size_type& k) {
            vector *tmp = new vector[this->_row];
            for (size_type i = 0; i < this->_row; i++) {
                tmp[i] = vector(this->_column - 1, 0);
                for (size_type j = 0, m = 0; j < this->_column; j++) {
                    if (j != k) {
                        tmp[i][m] = this->_begin[i][j];
                        ++m;
                    }
                }
            }
            --this->_column;
            delete[] this->_begin;
            this->_begin = tmp;
        }

        // 				~ Operators ~
        vector&		operator[] (size_type n) { return this->_begin[n]; }
        const vector&	operator[] (size_type n) const { return this->_begin[n]; }
        
        void            add(const Matrix &x) {
            if (this->_row != x._row || this->_column != x._column)
                throw sizeError();
            for (size_type i = 0; i < this->_row; i++)
                this->_begin[i].add(x[i]);
        }

        void            sub(const Matrix &x) {
            if (this->_row != x._row || this->_column != x._column)
                throw sizeError();
            for (size_type i = 0; i < this->_row; i++)
                this->_begin[i].sub(x[i]);
        }

        void            scl(const value_type &a) {
            for (size_type i = 0; i < this->_row; i++)
                this->_begin[i].scl(a);
        }

        vector          mul_vec(const vector &vect) {
            if (this->_column != vect.size())
                throw sizeError();
            vector v(vect.size(), 0);
            for (size_type i = 0; i < this->_row; i++) {
                for (size_type j = 0; j < this->_column; j++) {
                    v[i] += vect[j] * this->_begin[i][j];
                }
            }
            return v;
        }

        Matrix          mul_mat(const Matrix &mat) {
            if (this->_column != mat._row)
                throw sizeError();
            Matrix res(mat._column, mat._row, 0);
            for (size_type i = 0; i < this->_row; i++) {
                for (size_type j = 0; j < mat._column; j++) {
                    for (size_type k = 0; k < this->_column; k++) {
                        res[i][j] += this->_begin[i][k] * mat[k][j];
                    }
                }
            }
            return res;
        }

        value_type      trace(void) {
            value_type tr = 0;
            for (size_type i = 0; i < this->_row; i++)
                tr += this->_begin[i][i];
            return tr;
        }

        Matrix          transpose(void) {
            Matrix tp(this->_column, this->_row, 0);
            for (size_type i = 0; i < this->_row; i++)
                for (size_type j = 0; j < this->_column; j++)
                    tp[j][i] = this->_begin[i][j];
            return tp;
        }

    private:
        Matrix          &row_arrange(Matrix &mat) {
            Matrix tmp;
            for (size_type k = 0; k < this->_row && k < this->_column ; k++) {
                if (mat[k][k] == 0) {
                    for (size_type i = k; i < this->_row; i++) {
                        if (mat[i][k] != 0) {
                            tmp = mat;
                            mat[k] = mat[i];
                            mat[i] = tmp[k];
                        }
                    }
                }
            }
            return mat;
        }

        void            substract_pivot(Matrix &mat, const vector &pivot, const size_type rank) {
            if (pivot[rank] != 1)
                return ;
            vector tmp;
            for (size_type i = 0; i < this->_row; i++) {
                if (&mat[i] != &pivot && mat[i][rank] != 0) {
                    tmp = pivot;
                    tmp.scl(mat[i][rank]);
                    mat[i].sub(tmp);
                }
            }
        }

    public:
        Matrix          row_echelon(void) {
            if (this->_row <= 1)
                return *this;

            Matrix res = *this;
            Matrix tmp;
            for (size_type k = 0; k < this->_row; k++) {
                for (size_type j = k; j < this->_column; j++) {
                    if (res[k][j] != 0) {
                        res[k].scl(1 / res[k][j]);
                        this->substract_pivot(res, res[k], j);
                        break ;
                    }
                }
            }
            this->row_arrange(res);
            return res;
        }

        value_type  determinant(void) {
            if (!this->square())
                throw sizeError();
            if (this->size() == 4)
                return this->_begin[0][0] * this->_begin[1][1] - this->_begin[0][1] * this->_begin[1][0];
            Matrix a;
            value_type det = 0;
            for (size_type i = 0; i < this->_row; i++) {
                    a = *this;
                    a.remove_row(i);
                    a.remove_col(0);
                    det += this->_begin[i][0] * ft::pow(-1, i) * a.determinant();
                }
            return det;
        }

        Matrix      comatrix(void) {
            Matrix a;
            Matrix com(this->_row, this->_column, 0);
            for (size_type i = 0; i < this->_row; i++) {
                for (size_type j = 0; j < this->_column; j++) {
                    a = *this;
                    for (size_type k = 0; k < this->_row; k++) {
                        if (k != i)
                            a[k][j] = 0;
                        else
                            a[k][j] = 1;
                    }
                    com[i][j] = a.determinant();
                }
            }
            return com;
        }

        Matrix      inverse(void) {
            value_type det = this->determinant();
            if (det == 0)
                return {};
            Matrix com = this->comatrix();
            Matrix tp = com.transpose();
            tp.scl(1 / det);
            return tp;
        }

        size_type   rank(void) {
            size_type r = 0;
            Matrix a = this->row_echelon();
            for (size_type i = 0; i < this->_row; i++) {
                for (size_type j = 0; j < this->_column; j++) {
                    if (a[i][j] != 0) {
                        ++r;
                        break ;
                    }
                }
            }
            return r;
        }

        class sizeError : virtual public std::exception {
			public:
				virtual const char*	what() const throw() {
                    return "Size error";
                };
		};

    private:
        vector			*_begin;
        size_type 		_row;
        size_type 		_column;
};

template<typename T>
std::ostream& operator << (std::ostream& os, const ft::Matrix<T> &mat) {
    os << "[";
    for (typename ft::Matrix<T>::size_type i = 0; i < mat.shape().first; i++) {
        os << "[";
        for (typename ft::Matrix<T>::size_type j = 0; j < mat.shape().second; j++) {

            if (j != 0)
                os << ", ";
            os << mat[i][j];
        }
        if (i != mat.shape().first - 1)
            os << "]" << std::endl;
        else
            os << "]";
    }
    os << "]" << std::endl;
    return os;
}
}

#endif
