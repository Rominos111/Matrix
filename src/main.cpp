#include "../headers/main.h"

/**
 * Main
 *
 * @return Code d'erreur
 */
int main() {
    Matrix<int> m1 = Matrix<int>::identity(10);
    Matrix<int> m2 = Matrix<int>::identity(10);

    m1.add(&m2);

    m1.display();

    // Matrix<int> m3 = m1 + m2;

    // m3.display();

    return 0;
}