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

	for (int i = 0; i < 9; i++) {

		for (int j = 0; j < 9; j++) {
			if (tableau[j] > tableau[j + 1])
				Inverse(tableau[j], tableau[j + 1]);
		}
	}

	cout << "valeurs triés : " << endl;
	for (int i = 0; i < 10; i++) {
		cout << tableau[i] << endl;
	}
}

//BONUS 1
void Tableau1() {
	int size;
	cout << "Entrez la taille desirée : ";
	cin >> size;
	int* tableau = new int[size];

	int choixOrdre = 0;
	cout << "Entrez 1 pour un tri par ordre croissant ou 2 pour un tri par ordre décroissant : ";
	cin >> choixOrdre;

	for (int i = 0; i < size; i++) {
		tableau[i] = rand() % 100;
	}

	cout << "valeurs non triés : " << endl;
	for (int i = 0; i < size; i++) {
		cout << tableau[i] << endl;
	}

	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1; j++) {

			if (choixOrdre == 2) {
				if (tableau[j] < tableau[j + 1]) {
					Inverse(tableau[j], tableau[j + 1]);
				}
			}
			else
			{
				if (tableau[j] > tableau[j + 1]) {
					Inverse(tableau[j], tableau[j + 1]);
				}
			}
		}
	}

	cout << "valeurs triés : " << endl;
	for (int i = 0; i < size; i++) {
		cout << tableau[i] << endl;
	}
}
