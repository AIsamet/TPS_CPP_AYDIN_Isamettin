#include <iostream>
#include <iomanip>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include "EX1.h"

using namespace std;

string PointsJoueurs(int echangeJoueur, int echangeJoueurB) {
    switch (echangeJoueur) {
    case 0:
        return "0";
    case 1:
        return "15";
    case 2:
        return "30";
    case 3:
        return "40";
        break;
    default :
        if (echangeJoueur-1 == echangeJoueurB) {
            return "Avantage";
            break;
        }
        else if (echangeJoueur-2 >= echangeJoueurB) {
            return "Jeu";
            break;
        }
        else if (echangeJoueurB == echangeJoueur) {
            return "Egalite";
        }
        return "40";
        break;
    }
}

void AfficherScore(int nbEchangeJoueurUn, int nbEchangeJoueurDeux, int jeuJoueurUn, int jeuJoueurDeux) {
    const char separator = ' ';
    const int Width = 10;
    cout << left << setw(Width) << setfill(separator) << "";
    cout << left << setw(Width) << setfill(separator) << "Sets";
    cout << left << setw(Width) << setfill(separator) << "Jeux";
    cout << left << setw(Width) << setfill(separator) << "Points" << endl;
    cout << left << setw(Width) << setfill(separator) << "Joueur A";
    cout << left << setw(Width) << setfill(separator) << "";
    cout << left << setw(Width) << setfill(separator) << jeuJoueurUn;
    cout << left << setw(Width) << setfill(separator) <<  PointsJoueurs(nbEchangeJoueurUn, nbEchangeJoueurDeux) << endl;
    cout << left << setw(Width) << setfill(separator) << "Joueur B";
    cout << left << setw(Width) << setfill(separator) << "";
    cout << left << setw(Width) << setfill(separator) << jeuJoueurDeux;
    cout << left << setw(Width) << setfill(separator) << PointsJoueurs(nbEchangeJoueurDeux, nbEchangeJoueurUn) << "\n\n";
}

//INFOS : un set = 6jeux
//MATCH PEUT SE JOUER EN 3 OU 5 SETS


void ScoreTenis() {
    int setJoueurUn = 0;
    int setJoueurDeux = 0;
    int jeuJoueurUn = 0;
    int jeuJoueurDeux = 0;
    int nbEchangeJoueurUn = 0;
    int nbEchangeJoueurDeux = 0;
    int i = 0;

    //while ((setJoueurUn < 3 && setJoueurDeux < 3) || (setJoueurUn == setJoueurDeux) || (setJoueurUn + 2 != setJoueurDeux && setJoueurDeux + 2 != setJoueurUn)) {

    //    jeuJoueurUn = 0;
    //    jeuJoueurDeux = 0;


        while ((jeuJoueurUn <= 6 && jeuJoueurDeux <= 6) || (jeuJoueurUn == jeuJoueurDeux) || (jeuJoueurUn + 2 != jeuJoueurDeux && jeuJoueurDeux + 2 != jeuJoueurUn)) {

            nbEchangeJoueurUn = 0;
            nbEchangeJoueurDeux = 0;

            cout << "Jeu numero " << i + 1 << "\n\n";

            AfficherScore(nbEchangeJoueurUn, nbEchangeJoueurDeux, jeuJoueurUn, jeuJoueurDeux);
                                                                                                                       //SI a-2 == b on arrete la boucle (!(nbEchangeJoueurUn-2 >= nbEchangeJoueurDeux) && !(nbEchangeJoueurDeux -2 >= nbEchangeJoueurUn))
            while ((nbEchangeJoueurUn < 4 && nbEchangeJoueurDeux < 4) || (PointsJoueurs(nbEchangeJoueurUn,nbEchangeJoueurDeux)!="Jeu" && PointsJoueurs(nbEchangeJoueurDeux,nbEchangeJoueurUn) != "Jeu")) {

                if ((rand() % 2) == 0) {
                    nbEchangeJoueurUn += 1;
                    cout << "------------------------------------------------" << endl;
                    cout << "Le joueur A gagne l'echange, etat des points : " << "\n\n";
                }
                else {
                    nbEchangeJoueurDeux += 1;
                    cout << "------------------------------------------------" << endl;
                    cout << "Le joueur B gagne l'echange, etat des points : " << "\n\n";
                }

                AfficherScore(nbEchangeJoueurUn, nbEchangeJoueurDeux, jeuJoueurUn, jeuJoueurDeux);
                cout << nbEchangeJoueurUn << "\n" << nbEchangeJoueurDeux << endl;
                //this_thread::sleep_for(std::chrono::seconds(1));
            }

            cout << "------------------------------------------------" << endl;

            if (nbEchangeJoueurUn > nbEchangeJoueurDeux) {
                jeuJoueurUn += 1;
                cout << "Le joueur A gagne le jeu" << "\n\n";
            }
            else {
                jeuJoueurDeux += 1;
                cout << "Le joueur B gagne le jeu" << "\n\n";
            }

            nbEchangeJoueurUn = 0;
            nbEchangeJoueurDeux = 0;
            AfficherScore(nbEchangeJoueurUn, nbEchangeJoueurDeux, jeuJoueurUn, jeuJoueurDeux);
            cout << nbEchangeJoueurUn << "\n" << nbEchangeJoueurDeux << endl;

            cout << "***********************************************************************************************************************" << endl;

            i++;
        }

        AfficherScore(nbEchangeJoueurUn, nbEchangeJoueurDeux, jeuJoueurUn, jeuJoueurDeux);

        

    }
    //if (jeuJoueurUn > jeuJoueurDeux) {
    //    setJoueurUn += 1;
    //}
    //else {
    //    setJoueurDeux += 1;
    //}
//}


