#include "Triangle.hpp"

//4.1.1
//Constructeur
Triangle::Triangle(const Point& PointUn, const Point& PointDeux, const Point& PointTrois) {
    pointUn = PointUn;
    pointDeux = PointDeux;
    pointTrois = PointTrois;
}

//Constructeur par defaut
Triangle::Triangle() {
	pointUn = Point(1, 1);
	pointDeux = Point(5, 5);
	pointTrois = Point(10, 1);
}

//Destructeur
Triangle::~Triangle() {
	//cout << "Destructeur Triangle executÈ" << endl;
}

//MÈthode qui retourne un affichage de l'instance
string Triangle::Afficher() const {
	return "point 1 : \n" + pointUn.Afficher() + "\npoint 2 : \n" + pointDeux.Afficher() + "\npoint 3 : \n" + pointTrois.Afficher()
		+ "\nbase : " + to_string(GetBase()) + "cm\nsurface : " + to_string(GetSurface()) + "cm carres\nhauteur : "
		+ to_string(GetHauteur()) + "cm\n" + GetLongueurs() + "\nest isocele ? (1 = vrai, 0 = faux) : " + to_string(EstIsocele())
		+ "\nest rectangle ? (1 = vrai, 0 = faux) : " + to_string(EstRectangle()) + "\nest equilateral ? (1 = vrai, 0 = faux) : " + to_string(EstEquilateral());
}

//4.2.1 Getters and Setters
inline Point Triangle::GetP1() const {
	return pointUn;
}

inline Point Triangle::GetP2() const {
	return pointDeux;
}

inline Point Triangle::GetP3() const {
	return pointTrois;
}

inline void Triangle::SetP1(const Point& Point) {
	pointUn = Point;
}

inline void Triangle::SetP2(const Point& Point) {
	pointDeux = Point;
}

inline void Triangle::SetP3(const Point& Point) {
	pointTrois = Point;
}

//4.2.2 MÈthode qui retourne la base d'une instance de Triangle (le cotÈ ayant la plus grande longueur)
inline float Triangle::GetBase() const {
	float d1 = pointUn.DistanceTo(pointDeux);
	float d2 = pointDeux.DistanceTo(pointTrois);
	float d3 = pointTrois.DistanceTo(pointUn);

	if (d1 >= d2 and d1 >= d3) { return d1; }
	else if (d2 >= d1 and d2 >= d3) { return d2; }
	else return d3;
}

//MÈthode qui retourne la surface d'une instance de Triangle
//Suivant la formule de HÈron : sqrt( d * ( d - a ) ( d - b ) ( d - c ) ),
//o˘ù a, b et c sont les longueurs de chaque cotÈ respectif du triangle et d le demi-pÈrimËètre du triangle
inline float Triangle::GetSurface() const {
	float demiPerimetre = (pointUn.DistanceTo(pointDeux) + pointDeux.DistanceTo(pointTrois) + pointTrois.DistanceTo(pointUn)) / 2;
	return sqrt(demiPerimetre * (demiPerimetre - pointUn.DistanceTo(pointDeux)) * (demiPerimetre - pointDeux.DistanceTo(pointTrois)) * (demiPerimetre - pointTrois.DistanceTo(pointUn)));
}

//MÈthode qui retourne la hauteur d'une instance de Triangle
//Suivant la formule : ( Surface / ( Base * 0,5 ) )
inline float Triangle::GetHauteur() const {
	return (GetSurface() / (GetBase() * 0.5));
}

//MÈthode qui retourne un affichage des longueurs des cotÈs d'une instance de Triangle
inline string Triangle::GetLongueurs() const {
	return "longueur p1 vers p2 : " + to_string(pointUn.DistanceTo(pointDeux)) + "cm\n"
		+ "longueur p2 vers p3 : " + to_string(pointDeux.DistanceTo(pointTrois)) + "cm\n"
		+ "longueur p3 vers p1 : " + to_string(pointTrois.DistanceTo(pointUn)) + "cm";
}

//MÈthode qui retourne un booleen true si l'instance de Triangle est isocËle, sinon false
inline bool Triangle::EstIsocele() const {
	float a = pointUn.DistanceTo(pointDeux);
	float b = pointDeux.DistanceTo(pointTrois);
	float c = pointTrois.DistanceTo(pointUn);

	if ((a == b && b != c) || (b == c && c != a) || (c == a && a != b)) {
		return true;
	}
	else return false;
}

//MÈthode qui retourne un booleen true si l'instance de Triangle est rectangle, sinon false
inline bool Triangle::EstRectangle() const {
	float a = pointUn.DistanceTo(pointDeux);
	float b = pointDeux.DistanceTo(pointTrois);
	float c = pointTrois.DistanceTo(pointUn);

	if ((a * a) == (b * b) + (c * c) || (b * b) == (a * a) + (c * c) || (c * c) == (a * a) + (b * b))
	{
		return true;
	}
	else return false;
}

//MÈthode qui retourne un booleen true si l'instance de Triangle est ÈquilatÈral, sinon false
inline bool Triangle::EstEquilateral() const {
	float a = pointUn.DistanceTo(pointDeux) / 100;
	float b = pointDeux.DistanceTo(pointTrois) / 100;
	float c = pointTrois.DistanceTo(pointUn) / 100;

	if (a == b && b == c && c == a) {
		return true;
	}
	else return false;
}
