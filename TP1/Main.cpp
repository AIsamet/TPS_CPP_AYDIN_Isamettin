#include <iostream>
using namespace std;

#include "EX1.h"


int main()
{
    //1.1.1
    int a = 1;
    int b = 2;
    int c = 0;
    cout << Somme(a,b) << endl;

    //1.1.2
    Inverse(a,b);
    cout << a << "\n" << b << endl;

    //1.1.3
    TroisEntiersPtr(&a,&b,&c);
    TroisEntiersRef(a,b,c);

    //1.1.4
    Tableau();

    //2


    return 0;
}