#ifndef MATRIX_HPP
# define MATRIX_HPP

# include "Vector.hpp"
# include <utility>

template < class T = double>
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

        Matrix(size_type m, size_type n, const value_type &val) :  _column(n), _row(m){
            this->_begin = new vector[this->_row];
            for (size_type i = 0; i < this->_row; i++)
                this->_begin[i] = vector(this->_column, 0);
        }
        
        Matrix(const Matrix& x) : _column(x._column), _row(x._row)  {
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

        // 				~ Operators ~
        vector&		operator[] (size_type n) { return this->_begin[n]; }
        const vector&	operator[] (size_type n) const { return this->_begin[n]; }
        
        void            add(const Matrix &x) {
            for (size_type i = 0; i < this->_row; i++)
                this->_begin[i].add(x[i]);
        }

        void            sub(const Matrix &x) {
            for (size_type i = 0; i < this->_row; i++)
                this->_begin[i].sub(x[i]);
        }

        void            scl(const value_type &a) {
            for (size_type i = 0; i < this->_row; i++)
                this->_begin[i].scl(a);
        }

        vector          mul_vec(const vector &vect) {
            vector v(vect.size(), 0);
            for (size_type i = 0; i < this->_row; i++) {
                for (size_type j = 0; j < this->_column; j++) {
                    v[i] += vect[j] * this->_begin[i][j];
                }
            }
            return v;
        }

        Matrix          mul_mat(const Matrix &mat) {
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

        Matrix          &row_arrange(Matrix &mat) {
            Matrix tmp;
            for (size_type k = 0; k < this->_row && k < this->_column ; k++) {
                if (!mat[k][k]) {
                    for (size_type i = k; i < this->_row; i++) {
                        if (mat[i][k]) {
                            tmp = mat;
                            mat[k] = mat[i];
                            mat[i] = tmp[k];
                        }
                    }
                }
            }
            return mat;
        }

        void            substract_row(Matrix &mat, const vector &row, const value_type rank) {
            if (row[rank] != 1)
                return ;
            vector tmp;
            for (size_type i = 0; i < this->_row; i++) {
                if (i != rank) {
                    tmp = row;
                    tmp.scl(mat[i][rank]);
                    mat[i].sub(tmp);
                }
            }
        }

        Matrix          row_echelon(void) {
            std::cout << "---- start ----\n";
            std::cout << *this << "--" << std::endl;
            if (this->_row <= 1)
                return *this;

            Matrix res = *this;
            Matrix tmp;
            size_type j;
            /* arrange to try to get out 0 from the diag */
            this->row_arrange(res);
            for (size_type k = 0; k < this->_row && k < this->_column ; k++) {
                if (res[k][k]) {
                    /* set diag elements = 1 */
                    res[k].scl(1 / res[k][k]);
                    /* set column k elem = 0 */ 
                    this->substract_row(res, res[k], k);
                }
            }
            for (size_type k = this->_row - 1; k > 0; k--)
                this->substract_row(res, res[k], k);
            /* case if no 1 on a colum */

            std::cout << "---- end ----\n";
            return res;
        }

    private:
        vector			*_begin;
        size_type 		_row;
        size_type 		_column;
};

template<typename T>
std::ostream& operator << (std::ostream& os, const Matrix<T> &mat) {
    os << "[";
    for (typename Matrix<T>::size_type i = 0; i < mat.shape().first; i++) {
        os << "[";
        for (typename Matrix<T>::size_type j = 0; j < mat.shape().second; j++) {

            if (j != 0)
                os << "\t";
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

#endif
