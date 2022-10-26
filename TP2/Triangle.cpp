#include "Triangle.hpp"

//4.1.1
//Constructeur
Triangle::Triangle(const Point& P1, const Point& P2, const Point& P3) {
    p1 = P1;
    p2 = P2;
    p3 = P3;
}

//Constructeur par defaut
Triangle::Triangle() {
	p1 = Point(1, 1);
	p2 = Point(5, 5);
	p3 = Point(10, 1);
}

//Destructeur
Triangle::~Triangle() {
	//cout << "Destructeur Triangle executÈ" << endl;
}

//MÈthode qui retourne un affichage de l'instance
string Triangle::Afficher() const {
	return "point 1 : \n" + p1.Afficher() + "\npoint 2 : \n" + p2.Afficher() + "\npoint 3 : \n" + p3.Afficher()
		+ "\nbase : " + to_string(GetBase()) + "cm\nsurface : " + to_string(GetSurface()) + "cm carres\nhauteur : "
		+ to_string(GetHauteur()) + "cm\n" + GetLongueurs() + "\nest isocele ? (1 = vrai, 0 = faux) : " + to_string(EstIsocele())
		+ "\nest rectangle ? (1 = vrai, 0 = faux) : " + to_string(EstRectangle()) + "\nest equilateral ? (1 = vrai, 0 = faux) : " + to_string(EstEquilateral());
}

//4.2.1 Getters and Setters
inline Point Triangle::GetP1() const {
	return p1;
}

inline Point Triangle::GetP2() const {
	return p2;
}

inline Point Triangle::GetP3() const {
	return p3;
}

inline void Triangle::SetP1(const Point& p) {
	p1 = p;
}

inline void Triangle::SetP2(const Point& p) {
	p2 = p;
}

inline void Triangle::SetP3(const Point& p) {
	p3 = p;
}

//4.2.2 MÈthode qui retourne la base d'une instance de Triangle (le cotÈ ayant la plus grande longueur)
inline double Triangle::GetBase() const {
	double d1 = p1.DistanceTo(p2);
	double d2 = p2.DistanceTo(p3);
	double d3 = p3.DistanceTo(p1);

	if (d1 >= d2 and d1 >= d3) { return d1; }
	else if (d2 >= d1 and d2 >= d3) { return d2; }
	else return d3;
}

//MÈthode qui retourne la surface d'une instance de Triangle
//Suivant la formule de HÈron : sqrt( d * ( d - a ) ( d - b ) ( d - c ) ),
//o˘ù a, b et c sont les longueurs de chaque cotÈ respectif du triangle et d le demi-pÈrimËètre du triangle
inline double Triangle::GetSurface() const {
	double demiPerimetre = (p1.DistanceTo(p2) + p2.DistanceTo(p3) + p3.DistanceTo(p1)) / 2;
	return sqrt(demiPerimetre * (demiPerimetre - p1.DistanceTo(p2)) * (demiPerimetre - p2.DistanceTo(p3)) * (demiPerimetre - p3.DistanceTo(p1)));
}

//MÈthode qui retourne la hauteur d'une instance de Triangle
//Suivant la formule : ( Surface / ( Base * 0,5 ) )
inline double Triangle::GetHauteur() const {
	return (GetSurface() / (GetBase() * 0.5));
}

//MÈthode qui retourne un affichage des longueurs des cotÈs d'une instance de Triangle
inline string Triangle::GetLongueurs() const {
	return "longueur p1 vers p2 : " + to_string(p1.DistanceTo(p2)) + "cm\n"
		+ "longueur p2 vers p3 : " + to_string(p2.DistanceTo(p3)) + "cm\n"
		+ "longueur p3 vers p1 : " + to_string(p3.DistanceTo(p1)) + "cm";
}

//MÈthode qui retourne un booleen true si l'instance de Triangle est isocËle, sinon false
inline bool Triangle::EstIsocele() const {
	float a = p1.DistanceTo(p2);
	float b = p2.DistanceTo(p3);
	float c = p3.DistanceTo(p1);

	if ((a == b && b != c) || (b == c && c != a) || (c == a && a != b)) {
		return true;
	}
	else return false;
}

//MÈthode qui retourne un booleen true si l'instance de Triangle est rectangle, sinon false
inline bool Triangle::EstRectangle() const {
	float a = p1.DistanceTo(p2);
	float b = p2.DistanceTo(p3);
	float c = p3.DistanceTo(p1);

	if ((a * a) == (b * b) + (c * c) || (b * b) == (a * a) + (c * c) || (c * c) == (a * a) + (b * b))
	{
		return true;
	}
	else return false;
}

//MÈthode qui retourne un booleen true si l'instance de Triangle est ÈquilatÈral, sinon false
inline bool Triangle::EstEquilateral() const {
	float a = floor(p1.DistanceTo(p2) * 100) / 100;
	float b = floor(p2.DistanceTo(p3) * 100) / 100;
	float c = floor(p3.DistanceTo(p1) * 100) / 100;

	if (a == b && b == c && c == a) {
		return true;
	}
	else return false;
}
