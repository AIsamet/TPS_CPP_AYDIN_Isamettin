#include <iostream>
#include <iomanip>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds

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
	default:
		if (echangeJoueur - 1 == echangeJoueurB) {
			return "Avantage";
			break;
		}
		else if (echangeJoueur - 2 >= echangeJoueurB) {
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

string JeuJoueurs(int jeuJoueurUn, int jeuJoueurDeux) {
	switch (jeuJoueurUn) {
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		return "- 1";
		break;
	default:
		if (jeuJoueurUn - 2 >= jeuJoueurDeux) {
			return "Jeu";
			break;
		}
		return "Rejouez";
		break;
	}
}

void AfficherScore(int nbEchangeJoueurUn, int nbEchangeJoueurDeux, int jeuJoueurUn, int jeuJoueurDeux, int setJoueurUn, int setJoueurDeux) {
	const char separator = ' ';
	const int Width = 10;
	cout << left << setw(Width) << setfill(separator) << "";
	cout << left << setw(Width) << setfill(separator) << "Sets";
	cout << left << setw(Width) << setfill(separator) << "Jeux";
	cout << left << setw(Width) << setfill(separator) << "Points" << endl;
	cout << left << setw(Width) << setfill(separator) << "Joueur A";
	cout << left << setw(Width) << setfill(separator) << setJoueurUn;
	cout << left << setw(Width) << setfill(separator) << jeuJoueurUn;
	cout << left << setw(Width) << setfill(separator) << PointsJoueurs(nbEchangeJoueurUn, nbEchangeJoueurDeux) << endl;
	cout << left << setw(Width) << setfill(separator) << "Joueur B";
	cout << left << setw(Width) << setfill(separator) << setJoueurDeux;
	cout << left << setw(Width) << setfill(separator) << jeuJoueurDeux;
	cout << left << setw(Width) << setfill(separator) << PointsJoueurs(nbEchangeJoueurDeux, nbEchangeJoueurUn) << "\n\n";
	cout << "***********************************************************************************************************************\n" << endl;

}

//INFOS : un set = 6jeux
//MATCH PEUT SE JOUER EN 3 OU 5 SETS


void ScoreTennis() {
	int setJoueurUn = 0;
	int setJoueurDeux = 0;
	int jeuJoueurUn = 0;
	int jeuJoueurDeux = 0;
	int nbEchangeJoueurUn = 0;
	int nbEchangeJoueurDeux = 0;
	int i = 0;
	srand(time(NULL));

	//Il faut 2 sets sur un match a 3 set pour gagner le match
	while ((setJoueurUn < 3 && setJoueurDeux < 3) && (setJoueurUn != 2 && setJoueurDeux != 2)) {

		// Il faut 6 jeux avec 2 point de difference pour gagner le set
		while ((jeuJoueurUn < 6 && jeuJoueurDeux < 6) || (JeuJoueurs(jeuJoueurUn, jeuJoueurDeux) != "Jeu" && JeuJoueurs(jeuJoueurDeux, jeuJoueurUn) != "Jeu")) {

			cout << "Jeu numero " << i + 1 << "\n\n";

			// Il faut 4 echanges pour gagner le jeu (sans cas d'egalité)
			while ((nbEchangeJoueurUn < 4 && nbEchangeJoueurDeux < 4) || (PointsJoueurs(nbEchangeJoueurUn, nbEchangeJoueurDeux) != "Jeu" && PointsJoueurs(nbEchangeJoueurDeux, nbEchangeJoueurUn) != "Jeu")) {

				if ((rand() % 2) == 0) {
					nbEchangeJoueurUn += 1;

					//DESACTIVEZ LES COMMENTAIRES POUR AVOIR LES DETAILS DES JEUX
					/*cout << "Le joueur A gagne l'echange, etat des points : " << "\n\n";
					AfficherScore(nbEchangeJoueurUn, nbEchangeJoueurDeux, jeuJoueurUn, jeuJoueurDeux, setJoueurUn, setJoueurDeux);*/
				}
				else {
					nbEchangeJoueurDeux += 1;

					//DESACTIVEZ LES COMMENTAIRES POUR AVOIR LES DETAILS DES JEUX
					/*cout << "Le joueur B gagne l'echange, etat des points : " << "\n\n";
					AfficherScore(nbEchangeJoueurUn, nbEchangeJoueurDeux, jeuJoueurUn, jeuJoueurDeux, setJoueurUn, setJoueurDeux);*/
				}
			}

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
			AfficherScore(nbEchangeJoueurUn, nbEchangeJoueurDeux, jeuJoueurUn, jeuJoueurDeux, setJoueurUn, setJoueurDeux);
			i++;
		}

		if (jeuJoueurUn > jeuJoueurDeux) {
			setJoueurUn += 1;
			cout << "Le joueur A remporte le set\n" << endl;
		}
		else {
			setJoueurDeux += 1;
			cout << "Le joueur B remporte le set\n" << endl;
		}

		jeuJoueurUn = 0;
		jeuJoueurDeux = 0;
		AfficherScore(nbEchangeJoueurUn, nbEchangeJoueurDeux, jeuJoueurUn, jeuJoueurDeux, setJoueurUn, setJoueurDeux);
	}

	if (setJoueurUn > setJoueurDeux) {
		cout << "Felicitation joueur un vous avez gagné !" << endl;
	}
	else {
		cout << "Felicitation joueur deux vous avez gagné !" << endl;
	}
}


