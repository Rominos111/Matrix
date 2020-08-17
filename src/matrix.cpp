// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 02/05/2020.

#include "matrix.h"

template<typename TYPE_ELEM>
Matrix<TYPE_ELEM>::Matrix(const int nbRows, const int nbCols) {
    this->nbRows = nbRows;
    this->nbCols = nbCols;

    if (nbRows <= 0) {
        throw std::range_error("Number of rows negative or null");
    }

    if (nbCols <= 0) {
        throw std::range_error("Number of columns negative or null");
    }

    content = (TYPE_ELEM **) std::malloc(nbRows * sizeof(TYPE_ELEM*));
    // Exemple : [*ptr0, *ptr1, *ptr2...]

    for (int r=0; r<nbRows; r++) {
        content[r] = (TYPE_ELEM *) std::malloc(nbCols * sizeof(TYPE_ELEM));
        // Pour chaque ligne : [elem0, elem1, elem2...]
    }
}

template<typename TYPE_ELEM>
Matrix<TYPE_ELEM>::~Matrix() {
    for (int row=0; row<nbRows; row++) {
        delete[] content[row];
    }

    delete[] content;
}

template<typename TYPE_ELEM>
Matrix<TYPE_ELEM> Matrix<TYPE_ELEM>::zeros(int nbRows, int nbCols) {
    Matrix<TYPE_ELEM> m(nbRows, nbCols);

    for (int row=0; row<nbRows; row++) {
        for (int col=0; col<nbRows; col++) {
            m.content[row][col] = 0;
        }
    }

    return m;
}

template<typename TYPE_ELEM>
Matrix<TYPE_ELEM> Matrix<TYPE_ELEM>::identity(const int size) {
    Matrix<TYPE_ELEM> m = Matrix<TYPE_ELEM>::zeros(size, size);

    for (int row=0; row<size; row++) {
        m.content[row][row] = 1;
    }

    return m;
}

template<class TYPE_ELEM>
TYPE_ELEM& Matrix<TYPE_ELEM>::set(const int row, const int col, const TYPE_ELEM value) {
    if (row >= 0 && row < nbRows && col >= 0 && col < nbCols) {
        return content[row][col] = value;
    }
    else {
        throw std::out_of_range("Index out of range");
    }
}

template<class TYPE_ELEM>
TYPE_ELEM Matrix<TYPE_ELEM>::get(const int row, const int col) const {
    if (row >= 0 && row < nbRows && col >= 0 && col < nbCols) {
        return content[row][col];
    }
    else {
        throw std::out_of_range("Index out of range");
    }
}

template<class TYPE_ELEM>
void Matrix<TYPE_ELEM>::display() const {
    for (int row=0; row<nbRows; row++) {
        for (int col=0; col<nbCols; col++) {
            std::cout << (content[row][col]) << ' ';
        }

        std::cout << std::endl;
    }
}

template<typename TYPE_ELEM>
bool Matrix<TYPE_ELEM>::isSquare() const {
    return (nbRows == nbCols);
}

template<typename TYPE_ELEM>
Matrix<TYPE_ELEM> Matrix<TYPE_ELEM>::copy() const {
    Matrix<TYPE_ELEM> other(nbRows, nbCols);

    for (int row=0; row<nbRows; row++) {
        for (int col=0; col<nbCols; col++) {
            other.content[row][col] = content[row][col];
        }
    }

    return other;
}

template<typename TYPE_ELEM>
void Matrix<TYPE_ELEM>::add(const Matrix<TYPE_ELEM> *other) {
    for (int row=0; row<nbRows; row++) {
        for (int col=0; col<nbCols; col++) {
            set(row, col, get(row, col) + other->get(row, col));
        }
    }
}

template<typename TYPE_ELEM>
Matrix<TYPE_ELEM> Matrix<TYPE_ELEM>::add(const Matrix<TYPE_ELEM> *m1, const Matrix<TYPE_ELEM> *m2) {
    if (m1->nbRows != m2->nbRows || m1->nbCols != m2->nbCols) {
        throw std::range_error("Pas les mêmes dimensions");
    }

    Matrix<TYPE_ELEM> m = Matrix<TYPE_ELEM>(m1->nbRows, m1->nbCols);

    for (int i=0; i<m1->nbRows; i++) {
        for (int j=0; j<m1->nbCols; j++) {
            m.set(i, j, m1->get(i, j) + m2->get(i, j));
        }
    }

    return m;
}

// Initialisation des templates pour pouvoir utiliser ce .cpp
template class Matrix<int>;
