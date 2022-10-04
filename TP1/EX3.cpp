#include <iostream>
using namespace std;

//3.1.1
void Prenom() {
	string prenom = "";
	cout << "Quel est ton prenom ?" << endl;
	cin >> prenom;
	cout << "Enchanté " << prenom << endl;
}

//3.1.2
void PrenomNom() {
	string nom = "";
	string prenom = "";
	string delimiter = " ";
	
	cout << "Quel est ton nom complet ? (nom prenom)" << endl;
	cin >> nom >> prenom;

	for (int i = 0; i < nom.length(); i++) {
		nom[i] = toupper(nom[i]);
	}
;
	prenom[0] = toupper(prenom[0]);

	for (int i = 1; i < prenom.length(); i++) {
		prenom[i] = tolower(prenom[i]);
	}

	cout << nom << " " << prenom << endl;
}

//3.2.1 && 3.2.2
void devinettenNombre()
{
	srand(time(NULL));
	int aDeviner = rand() % 1001;
	int entreeUtilisateur = -1;
	int essais = 1;
	cout << aDeviner << "\n\n";

	while (entreeUtilisateur != aDeviner) {
		cout << "Essai numero : " << essais << endl;
		cout << "Entrez un nombre : ";
		cin >> entreeUtilisateur;

		if (entreeUtilisateur < aDeviner) {
			cout << "Le nombre a deviner est plus grand\n" << endl;
		}
		else if (entreeUtilisateur > aDeviner) {
			cout << "Le nombre a deviner est plus petit\n" << endl;
		}
		else if (entreeUtilisateur == aDeviner) {
			cout << "Apres " << essais << " essais c'est gagné, le nombre etait " << aDeviner << endl;
		}
		essais++;
	}
}