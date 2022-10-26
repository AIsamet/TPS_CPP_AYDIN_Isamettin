#include "Cercle.hpp"

//3.1.1
//Constructeur
Cercle::Cercle(const Point& Centre, const int& Diametre)
{
	centre = Centre;
	diametre = Diametre;
}

//Constructeur par defaut
Cercle::Cercle()
{
	centre = Point(10, 20);
	diametre = 10;
}

Cercle::~Cercle() {
	//cout << "Destructeur Cercle executé" << endl;
}

//Méthode qui retourne un affichage de l'instance
string Cercle::Afficher() const {
	return "centre : " + centre.Afficher() + "diametre : " + to_string(diametre)
		+ "cm\nperimetre : " + to_string(GetPerimetre()) + "cm\nsurface : " + to_string(GetSurface()) + "cm carres";
}

//3.2.1 Getters and Setters
Point Cercle::GetCentre() const
{
	return centre;
}

inline int Cercle::GetDiametre() const
{
	return diametre;
}

inline void Cercle::SetCentre(const Point& Centre)
{
	centre = Centre;
}

inline void Cercle::SetDiametre(const int& Diametre)
{
	diametre = Diametre;
}

//3.2.2 Méthode qui retourne le périmètre d'une instance de Cercle
//Suivant la formule : ( 2 * pi * rayon )
inline float Cercle::GetPerimetre() const
{
	return (2 * M_PI * (static_cast<float>(diametre) / 2));
}

//3.2.2 Méthode qui retourne la surface d'une instance de Cercle
//Suivant la formule : ( pi * ( rayon * rayon ) )
inline float Cercle::GetSurface() const
{
	float rayon = static_cast<float>(diametre) / 2;
	return (M_PI * (rayon * rayon));
}

//3.2.3 Méthode qui retourne un booleen true si un point passé en paramètre est sur l'instance de Cercle, sinon false
bool Cercle::EstSurCercle(const Point& Point) const {

    //On return true si la distance entre le centre du cercle et le point est egal au rayon du cercle
	if (centre.DistanceTo(Point) == (static_cast<float>(diametre) / 2)) { return true; }
	else return false;
}

//3.2.4 Méthode qui retourne un booleen true si un point passé en paramètre est dans l'instance de Cercle, sinon false
bool Cercle::EstDansCercle(const Point& Point) const {

    //On return true si la distance entre le centre du cercle et le point est inferieur au rayon du cercle
	if (centre.DistanceTo(Point) < (static_cast<float>(diametre) / 2)) { return true; }
	else return false;
}
