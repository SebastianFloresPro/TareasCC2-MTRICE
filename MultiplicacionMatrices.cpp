#include <iostream>
using namespace std;

void MultiplicacionMatrices(int (*p)[3][3]) {
    int (*A)[3] = *p;       
    int (*B)[3] = *(p + 1); 
    int (*C)[3] = *(p + 2); 

    int (*filaC)[3] = C;
    while (filaC < C + 3) {
        int *colC = *filaC;
        while (colC < *filaC + 3) {
            *colC = 0;

            // Multiplica la fila de A por la columna de B
            int *a = *(A + (filaC - C)); 
            int *b = *B + (colC - *filaC); 
            int k = 0;
            while (k < 3) {
                *colC += (*a) * (*b);
                a++;
                b += 3;
                k++;
            }
            colC++;
        }
        filaC++;
    }
}

void mostrar(int (*p)[3][3]) {
    int (*mat)[3][3] = p; // Puntero a las matrices
    while (mat < p + 3) {
        int (*fila)[3] = *mat; 
        while (fila < *mat + 3) {
            int *col = *fila; // Puntero a los elementos de la fila
            while (col < *fila + 3) {
                cout << *col << " ";
                col++;
            }
            cout << endl;
            fila++;
        }
        cout << "---" << endl;
        mat++;
    }
}

int main() {
    int m[3][3][3] = {
        {{5,6,7}, {7,8,9}, {2,3,4}},   
        {{3,4,5}, {5,1,7}, {8,9,3}},   
        {{0,0,0}, {0,0,0}, {0,0,0}}    
    };

    MultiplicacionMatrices(m);
    mostrar(m);

    return 0;
}
