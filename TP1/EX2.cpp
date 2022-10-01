#include <iostream>
#include "EX1.h"

using namespace std;

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

//void ScoreTenis(int nbechangesA, int nbechangesB) {
//	cout << "Etat des points : \nA : " << nbechangesA << endl << "B : " << nbechangesB << endl << endl;
//
//	//EGALITE A 40
//	if (nbechangesA == 3 and nbechangesA == nbechangesB) {
//		cout << "Le gagnant de la balle aura l'avantage et la balle de jeu." << endl;
//	}
//	//AVANTAGE JOUEUR A
//	else if (nbechangesA == 4 and nbechangesB == 3) {
//		cout << "Le joueur A a l'avantage et la balle de jeu." << endl;
//	}
//	//AVANTAGE JOUEUR B
//	else if (nbechangesB == 4 and nbechangesA == 3) {
//		cout << "Le joueur B a l'avantage et la balle de jeu." << endl;
//	}
//	//JOUEUR A GAGNE SUITE A AVANTAGE
//	else if (nbechangesA == 5 and nbechangesB == 3) {
//		cout << "Le joueur A gagne le jeu" << endl;
//	}
//	//JOUEUR B GAGNE SUITE A AVANTAGE
//	else if (nbechangesB == 5 and nbechangesA == 3) {
//		cout << "Le joueur B gagne le jeu" << endl;
//	}
//	//EGALITE FINALE
//	else if (nbechangesA == 4 and nbechangesA == nbechangesB) {
//		cout << "Egalite" << endl;
//	}
//}


