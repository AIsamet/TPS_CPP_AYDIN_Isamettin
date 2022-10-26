#include "Rectangle.hpp"

//2.1.1 & 2.1.2
//Constructeur
Rectangle::Rectangle(const int& Largeur, const int& Longueur, const Point& CoinSupGauche) {
	largeur = Largeur;
	longueur = Longueur;
	coinSupGauche = CoinSupGauche;
}

//Constructeur par défaut
Rectangle::Rectangle() {
	largeur = 10;
	longueur = 10;
	//2.1.2
	coinSupGauche = Point(10, 10);
}

//Destructeur
Rectangle::~Rectangle() {
	//cout << "Destructeur Rectangle executÈ" << endl;
}

//MÈthode qui retourne un affichage de l'instance
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

//2.2.2 MÈthode qui retourne le pÈrimËtre d'une instance de Rectangle
//Suivant la formule : ( longueur + largeur ) * 2
inline int Rectangle::GetPerimetre() const
{
	return ((longueur + largeur) * 2);
}

//MÈthode qui retourne la surface d'une instance de Rectangle
//Suivant la formule : longueur * largeur
inline int Rectangle::GetSurface() const
{
	return longueur * largeur;
}

//BONUS 2.3.1 MÈthode qui retourne un boolÈen true si l'instance possËde un pÈrimËtre plus grand
//que l'instance en paramËtre, sinon false
bool Rectangle::EstPlusGrandPerimetre(const Rectangle& Rectangle) const {
	if (GetPerimetre() > Rectangle.GetPerimetre()) { return true; }
	else { return false; }
}

//BONUS 2.3.2 Methode qui retourne un booleen true si l'instance possede une surface plus grande
//que l'instance en paramËtre, sinon false
bool Rectangle::EstPlusGrandSurface(const Rectangle& Rectangle) const {
	if (GetSurface() > Rectangle.GetSurface()) { return true; }
	else { return false; }
}
