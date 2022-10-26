#include "Point.hpp"

//1
//Constructeur
Point::Point(const float& X, const float& Y) {
    x = X;
    y = Y;
}

//Constructeur par defaut
Point::Point() {
	x = 5;
	y = 10;
}

//Destructeur
Point::~Point() {
	//cout << "Destructeur Point executé" << endl;
}

//Méthode qui retourne un affichage de l'instance
string Point::Afficher() const {
	return "x : " + to_string(x) + ", y : " + to_string(y) + "\n";
}

//Méthode qui retourne la distance d'une instance de Point vers un point passé en paramètre
//Suivant la formule : sqrt ( pow ( x - p.x, 2 ) + pow ( y - p.y, 2 ) )
float Point::DistanceTo(const Point& p) const {
	return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
}
