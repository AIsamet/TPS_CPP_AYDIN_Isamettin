#include "EX1.h"
#include <iostream>
using namespace std;


//1.1.1
int Somme(int a, int b) {
    return a + b;
}

//1.1.2
void Inverse(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

//1.1.3
void TroisEntiersPtr(int* a, int* b, int* c)
{
    *c = *a + *b;
    cout << *c << endl;;
}

void TroisEntiersRef(int& a, int& b, int& c)
{
    c = a + b;
    cout << c << endl;
}

//1.1.4
void Tableau() {
    int tableau[10];
    for (int i = 0; i < 10; i++) {
        tableau[i] = rand() % 100;
    }
    cout << "valeurs non triés : " << endl;
    for (int i = 0; i < 10; i++) {
        cout << tableau[i] << endl;
    }

    for (int i = 0; i < 10; i++) {

        for (int z = 0; z < 10; z++) {

            if (tableau[z] > tableau[i]) {

                Inverse(tableau[i], tableau[z]);
            }
        }
    }
    cout << "valeurs triés : " << endl;
    for (int i = 0; i < 10; i++) {
        cout << tableau[i] << endl;
    }
}
