#include "../headers/matrix.h"

/**
 * Constructeur privé
 *
 * @param nbRows Nombre de lignes
 * @param nbCols Nombre de colonnes
 */
template<typename TYPE_ELEM>
Matrix<TYPE_ELEM>::Matrix(const size_t nbRows, const size_t nbCols) {
    this->nbCols = nbCols;
    this->nbRows = nbRows;

    content = (TYPE_ELEM **) std::malloc(nbRows * sizeof(TYPE_ELEM*));
    // Exemple : [*ptr0, *ptr1, *ptr2...]

    for (int r=0; r<nbRows; r++) {
        content[r] = (TYPE_ELEM *) std::malloc(nbCols * sizeof(TYPE_ELEM));
        // Pour chaque ligne : [elem0, elem1, elem2...]
    }
}

/**
 * Construit une matrice de zéros
 * @param nbRows
 * @param nbCols
 * @return
 */
template<typename TYPE_ELEM>
void Matrix<TYPE_ELEM>::zeros() {
    for (int row=0; row<nbRows; row++) {
        for (int col=0; col<nbRows; col++) {
            content[row][col] = 0;
        }
    }
}

/**
 * Setter
 *
 * @param row Ligne
 * @param col Colonne
 * @param value Valeur
 */
template<typename TYPE_ELEM>
void Matrix<TYPE_ELEM>::set(int row, int col, TYPE_ELEM value) {
    if (row >= 0 && row < nbRows && col >= 0 && col < nbCols) {
        content[row][col] = value;
    }
    else {
        throw std::out_of_range("Index out of range");
    }
}

/**
 * Getter
 *
 * @param row Ligne
 * @param col Colonne
 *
 * @return Matrix[row, col]
 */
template<typename TYPE_ELEM>
TYPE_ELEM Matrix<TYPE_ELEM>::get(int row, int col) const {
    if (row >= 0 && row < nbRows && col >= 0 && col < nbCols) {
        return content[row][col];
    }
    else {
        throw std::out_of_range("Index out of range");
    }
}

/**
 * Affiche la matrice
 */
template<typename TYPE_ELEM>
void Matrix<TYPE_ELEM>::display() const {
    for (int row=0; row<nbRows; row++) {
        for (int col=0; col<nbCols; col++) {
            std::cout << (content[row][col]) << ' ';
        }

        std::cout << std::endl;
    }
}

template<typename TYPE_ELEM>
Matrix<TYPE_ELEM>::~Matrix() {
    for (int row=0; row<nbRows; row++) {
        std::free(content[row]);
    }

    std::free(content);

    std::free(this);
}
