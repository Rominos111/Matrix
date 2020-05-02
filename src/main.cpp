#include "../headers/main.h"

/**
 * Main
 *
 * @return Erreur
 */
int main() {
    Matrix<int> m1 = Matrix<int>::identity(10);
    // Matrix<int> m2 = Matrix<int>::identity(4);

    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            m1.set(i, j, i+j);
        }
    }

    m1.display();
    // m2.display();

    // Matrix<int> m3 = m1 + m2;

    // m3.display();

    return 0;
}