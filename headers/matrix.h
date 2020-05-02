#ifndef TESTCLION_MATRIX_H
#define TESTCLION_MATRIX_H

#include <iostream>
#include <vector>

template<typename TYPE_ELEM>
class Matrix {
public:
    template<TYPE_ELEM> Matrix(size_t nbRows, size_t nbCols);
    ~Matrix();

    void set(int row, int col, TYPE_ELEM value);
    TYPE_ELEM get(int row, int col) const;

    void zeros();

    void display() const;

    class Access {
    public:
        Matrix& parent;
        int row, col;

        Access(Matrix& parent, int row, int col) {
            this->parent = parent;
            this->row = row;
            this->col = col;
        }

        operator TYPE_ELEM() {
            std::cout << "reading\n";
            return parent.content[row][col];
        }

        TYPE_ELEM& operator=(const TYPE_ELEM& other) {
            std::cout << "writing\n";
            return parent.content[row][col] = other;
        }
    };

    Access operator()(int row, int col) {
        return Access(*this, row, col);
    }

private:
    size_t nbRows{};
    size_t nbCols{};
    TYPE_ELEM **content;
};

#endif
