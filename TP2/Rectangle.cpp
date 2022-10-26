#include "Rectangle.hpp"

//2.1.1 & 2.1.2
//Constructeur
Rectangle::Rectangle(const int& Largeur, const int& Longueur, const Point& CoinSupGauche) {
	largeur = Largeur;
	longueur = Longueur;
	coinSupGauche = CoinSupGauche;
}

//Constructeur par d�faut
Rectangle::Rectangle() {
	largeur = 10;
	longueur = 10;
	//2.1.2
	coinSupGauche = Point(10, 10);
}

//Destructeur
Rectangle::~Rectangle() {
	//cout << "Destructeur Rectangle execut�" << endl;
}

//M�thode qui retourne un affichage de l'instance
string Rectangle::Afficher() const {
	return "longueur : " + to_string(longueur) + "cm\nlargeur : " + to_string(largeur) + "cm\ncoin superieur gauche : " + coinSupGauche.Afficher()
		+ "perimetre : " + to_string(GetPerimetre()) + "cm\nsurface : " + to_string(GetSurface()) + "cm carres";
}

//2.2.1 Getters and Setters
inline int Rectangle::GetLargeur() const
{
	return largeur;
}

inline int Rectangle::GetLongueur() const
{
	return longueur;
}

inline Point Rectangle::GetCoinSupGauche() const
{
	return coinSupGauche;
}

inline void Rectangle::SetLargeur(const int& Largeur)
{
	largeur = Largeur;
}

inline void Rectangle::SetLongueur(const int& Longueur)
{
	longueur = Longueur;
}

inline void Rectangle::SetCoinSupGauche(const Point& CoinSupGauche)
{
	coinSupGauche = CoinSupGauche;
}

//2.2.2 M�thode qui retourne le p�rim�tre d'une instance de Rectangle
//Suivant la formule : ( longueur + largeur ) * 2
inline int Rectangle::GetPerimetre() const
{
	return ((longueur + largeur) * 2);
}

//M�thode qui retourne la surface d'une instance de Rectangle
//Suivant la formule : longueur * largeur
inline int Rectangle::GetSurface() const
{
	return longueur * largeur;
}

//BONUS 2.3.1 M�thode qui retourne un bool�en true si l'instance poss�de un p�rim�tre plus grand
//que l'instance en param�tre, sinon false
bool Rectangle::EstPlusGrandPerimetre(const Rectangle& Rectangle) const {
	if (GetPerimetre() > Rectangle.GetPerimetre()) { return true; }
	else { return false; }
}

//BONUS 2.3.2 Methode qui retourne un booleen true si l'instance possede une surface plus grande
//que l'instance en param�tre, sinon false
bool Rectangle::EstPlusGrandSurface(const Rectangle& Rectangle) const {
	if (GetSurface() > Rectangle.GetSurface()) { return true; }
	else { return false; }
}
