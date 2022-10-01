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

int PointsJoueurs(int echangeJoueur) {
    switch (echangeJoueur) {
    case 0:
        return 0;
    case 1:
        return 15;
    case 2:
        return 30;
    case 3:
        return 40;
        break;
    default:
        return 40;
    }
}

void ScoreTenis() {
    int jeuJoueurUn = 0;
    int jeuJoueurDeux = 0;

    for (int i = 0; i < 6; i++) {
        int nbEchangeJoueurUn = 0;
        int nbEchangeJoueurDeux = 0;


        while (nbEchangeJoueurUn < 3 && nbEchangeJoueurDeux < 3) {

            int echangeRandom = rand() % 2;
            int echangeJoueurUn = rand() % 2;
            int echangeJoueurDeux = rand() % 2;

            /*          if(echangeRandom == 0){
                            nbEchangeJoueurUn+=1;
                        }
                        if(echangeRandom == 1){
                            nbEchangeJoueurDeux+=1;
                        }*/

            if (echangeJoueurUn == 1) {
                nbEchangeJoueurUn += 1;
            }
            if (echangeJoueurDeux == 1) {
                nbEchangeJoueurDeux += 1;
            }

            /*cout << echangeJoueurUn;*/

        }
        //JUSQU'ICI ON EST A 3 ECHANGES = 40PTS
        if (nbEchangeJoueurUn == nbEchangeJoueurDeux)
        {
            int echangeRandom = rand() % 2;

            if (echangeRandom == 0) {
                nbEchangeJoueurUn += 1;
                cout << "avantage A, resultat : " << endl;
            }
            if (echangeRandom == 1) {
                nbEchangeJoueurDeux += 1;
                cout << "avantage B, resultat : ";
            }

            echangeRandom = rand() % 2;

            if (echangeRandom == 0) {
                nbEchangeJoueurUn += 1;
            }
            else if (echangeRandom == 1) {
                nbEchangeJoueurDeux += 1;
            }

            if (nbEchangeJoueurUn < nbEchangeJoueurDeux) {
                cout << "Joueur B Gagne !" << endl;
            }
            else if (nbEchangeJoueurUn > nbEchangeJoueurDeux) {
                cout << "Joueur A Gagne !" << endl;
            }
            else if (nbEchangeJoueurUn == nbEchangeJoueurDeux) {
                cout << "Egalité" << endl;
            }

        }
        else if (nbEchangeJoueurUn != nbEchangeJoueurDeux) {
            int echangeRandom = rand() % 2;

            if (echangeRandom == 0) {
                nbEchangeJoueurUn += 1;
                cout << "Joueur A Gagne !" << endl;
            }
            else if (echangeRandom == 1) {
                nbEchangeJoueurDeux += 1;
                cout << "Joueur B Gagne !" << endl;
            }
        }


        cout << "Total Joueur A : " << nbEchangeJoueurUn << ", Points : " << PointsJoueurs(nbEchangeJoueurUn) << endl;
        cout << "Total Joueur B : " << nbEchangeJoueurDeux << ", Points : " << PointsJoueurs(nbEchangeJoueurDeux) << endl << endl;

    }
}

int main()
{
    //1.1.1
    int a = 1;
    int b = 2;
    int c = 0;
    //cout << somme(a,b);

    //1.1.2
    /*Inverse(a,b);
    cout << a << "\n" << b << endl;*/

    //1.1.3
    /*TroisEntiersPtr(&a,&b,&c);
    TroisEntiersRef(a,b,c);*/

    //1.1.4
    //Tableau();

    //2

    ScoreTenis();



    return 0;
}
