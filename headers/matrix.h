#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

/**
 * Classe Matrice
 */
template<typename TYPE_ELEM>
class Matrix {
public:
    /**
     * Construit une matrice de zéros
     *
     * @param nbRows Nombre de lignes
     * @param nbCols Nombre de colonnes
     *
     * @return Matrice construite
     */
    static Matrix<TYPE_ELEM> zeros(const int nbRows, const int nbCols);

    /**
     * Matrice identité, carrée
     *
     * @param size Nombre de lignes (== nombre de colonnes)
     * @return
     */
    static Matrix<TYPE_ELEM> identity(const int size);

    /**
     * Destructeur
     */
    ~Matrix();

    /**
     * Getter
     *
     * @param row Ligne
     * @param col Colonne
     *
     * @return Matrix[row, col]
     */
    TYPE_ELEM get(const int row, const int col) const;

    /**
     * Setter
     *
     * @param row Ligne
     * @param col Colonne
     * @param value Valeur
     */
    TYPE_ELEM & set(const int row, const int col, const TYPE_ELEM value);

    /**
     * Matrice carrée ou non
     *
     * @return Carrée
     */
    bool isSquare() const;

    /**
     * Affiche la matrice
     */
    void display() const;

    Matrix<TYPE_ELEM> copy() const;

    Matrix<TYPE_ELEM> add(const Matrix<TYPE_ELEM> other);

    /**
     * Gestion des accès pour la surcharge de l'opérateur <code>()</code>
     */
    class Access {
    public:
        Access(Matrix<TYPE_ELEM> & parent, int row, int col) : parent(parent) {
            this->row = row;
            this->col = col;
        }

        /**
         * Surcharge du getter de l'opérateur <code>()</code><br>
         * Exemple : <code>std::cout << m(1, 1) << std::endl;</code>
         *
         * @return Valeur en [row, col]
         */
        operator TYPE_ELEM() const {
            return parent.get(row, col);
        }

        /**
         * Surcharge du setter de l'opérateur <code>()</code><br>
         * Exemple : <code>m(1, 1) = 5;</code>
         *
         * @param other Autre valeur
         *
         * @return Adresse de l'opérateur ?
         */
        TYPE_ELEM & operator=(const TYPE_ELEM & other) {
            return parent.set(row, col, other);
        }

    private:
        /**
         * Matrice parente
         */
        Matrix<TYPE_ELEM> & parent;

        /**
         * Ligne
         */
        int row;

        /**
         * Colonne
         */
        int col;
    };

    /**
     * Surcharge de l'opérateur <code>()</code> <br>
     * Exemple : <code>m(1, 1) = 5;</code>
     *
     * @param row Ligne
     * @param col Colonne
     *
     * @return Access
     */
    Access operator()(int row, int col) {
        return Access(*this, row, col);
    }

    /*
    Matrix<TYPE_ELEM> & operator+=(Matrix<TYPE_ELEM> other) {
        return add(other);
    }

    Matrix<TYPE_ELEM> operator+(Matrix<TYPE_ELEM> other) {
        return (this->copy()).add(other);
    }
     */

private:
    /**
     * Constructeur
     *
     * @param nbRows Nombre de lignes
     * @param nbCols Nombre de colonnes
     */
    Matrix(const int nbRows, const int nbCols);

    /**
     * Nombre de lignes
     */
    size_t nbRows{};

    /**
     * Nombre de colonnes
     */
    size_t nbCols{};

    /**
     * Contenu, tableau à 2 dimensions
     */
    TYPE_ELEM **content;
};

#endif
