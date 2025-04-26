#include <iostream>
#include <vector>
#include <conio.h>
using namespace std;

bool matricesIguales(vector<int>* a, vector<int>* b, int filas, int columnas)
{
    vector<int>* pa = a;
    vector<int>* pb = b;
    while (pa != a + filas)
    {
        int* da = pa->data();
        int* db = pb->data();
        while (da != pa->data() + columnas)
        {
            if (*da != *db) return false;
            ++da;
            ++db;
        }
        ++pa;
        ++pb;
    }
    return true;
}

void mostrar(vector<int>* m, int filas, int columnas)
{
    vector<int>* fila = m;
    while (fila != m + filas)
    {
        int* col = fila->data();
        while (col != fila->data() + columnas)
        {
            if (*col == 0)
                cout << "0";
            else
                cout << *col << "  ";  
            ++col;
        }
        cout << endl;
        ++fila;
    }
}

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void juego()
{
    int filas = 3, columnas = 3;

    vector<int>* objetivo = new vector<int>[filas];
    vector<int>* desordenada = new vector<int>[filas];

    int ordenados[9] = {1, 2, 3, 4, 5, 6, 7, 8, 0};
    int inicial[9]   = {4, 2, 6, 1, 3, 7, 8, 0, 5};

    int* ptrOrden = ordenados;
    int* ptrIni = inicial;

    vector<int>* fObj = objetivo;
    vector<int>* fIni = desordenada;

    int i = 0;

while (i < filas)
{
    fObj->resize(columnas);
    fIni->resize(columnas);
    
    int* colObj = fObj->data();
    int* colIni = fIni->data();
    int j = 0;
    
    while (j < columnas)
    {
        *colObj = *ptrOrden;
        *colIni = *ptrIni;
        
        ++colObj;
        ++colIni;
        ++ptrOrden;
        ++ptrIni;
        ++j;
    }
    
    ++fObj;
    ++fIni;
    ++i;
}

    vector<int>* fCero = desordenada;
    int* pCero = nullptr;

    while (fCero != desordenada + filas)
    {
        int* c = fCero->data();
        while (c != fCero->data() + columnas)
        {
            if (*c == 0)
            {
                pCero = c;
                break;
            }
            ++c;
        }
        if (pCero) break;
        ++fCero;
    }

    while (true)
    {
        cout << "\n\n\n\n\n";  
        mostrar(desordenada, filas, columnas);
        cout << "\n";

        if (matricesIguales(desordenada, objetivo, filas, columnas))
        {
            cout << "\n ¡Ganaste el juego! \n";
            break;
        }

        cout << "\nMueve usando W A S D: ";
        char tecla = _getch();
        /*
        
        1 1 1
        1 0 1
        1 1 1
        */
        if (tecla == 'w' && fCero != desordenada)
        {
            vector<int>* arriba = fCero - 1;
            int* target = arriba->data() + (pCero - fCero->data());
            swap(pCero, target);
            fCero = arriba;
            pCero = target;
        }
        else if (tecla == 's' && fCero != desordenada + filas - 1)
        {
            vector<int>* abajo = fCero + 1;
            int* target = abajo->data() + (pCero - fCero->data());
            swap(pCero, target);
            fCero = abajo;
            pCero = target;
        }
        else if (tecla == 'a' && pCero != fCero->data())
        {
            int* target = pCero - 1;
            swap(pCero, target);
            pCero = target;
        }
        else if (tecla == 'd' && pCero != fCero->data() + columnas - 1)
        {
            int* target = pCero + 1;
            swap(pCero, target);
            pCero = target;
        }
    }

    delete[] desordenada;
    delete[] objetivo;
}

int main()
{
    juego();
    return 0;
}
