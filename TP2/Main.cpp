#include <iostream>
#include <cmath>
#include "Rectangle.hpp"
#include "Cercle.hpp"
#include "Triangle.hpp"

int main(int argc, const char* argv[]) {

	const float COORDONNEE_X = 0;
	const float COORDONNEE_Y = 2.5;
	const Point p(COORDONNEE_X, COORDONNEE_Y);

	const int LARGEUR_RECTANGLE(20);
	const int LONGUEUR_RECTANGLE(40);
	const Point COIN_SUP_GAUCHE_RECTANGLE(10, 20);
	Rectangle rectangle(LARGEUR_RECTANGLE, LONGUEUR_RECTANGLE, COIN_SUP_GAUCHE_RECTANGLE);

	const int LARGEUR_RECTANGLE_DEUX(10);
	const int LONGUEUR_RECTANGLE_DEUX(20);
	const Point COIN_SUP_GAUCHE_RECTANGLE_DEUX(10, 20);
	Rectangle rectangleDeux(LARGEUR_RECTANGLE_DEUX, LONGUEUR_RECTANGLE_DEUX, COIN_SUP_GAUCHE_RECTANGLE_DEUX);

	const Point CENTRE_CERCLE(0, 0);
	const int DIAMETRE_CERCLE(5);
	Cercle cercle(CENTRE_CERCLE, DIAMETRE_CERCLE);

	////JEU DE TEST POUR AVOIR UN TRIANGLE EQUILATERAL
	//const Point pointUnTriangle(1,2);
	//const Point pointDeuxTriangle(5,4);
	//const Point pointTroisTriangle(3-sqrt(3),3+2*sqrt(3));

	////JEU DE TEST POUR AVOIR UN TRIANGLE RECTANGLE + ISOCELE
	//const Point pointUnTriangle(0, 0);
	//const Point pointDeuxTriangle(0, 10);
	//const Point pointTroisTriangle(10, 0);

	const Point POINT_UN_TRIANGLE(0, 0);
	const Point POINT_DEUX_TRIANGLE(0, 10);
	const Point POINT_TROIS_TRIANGLE(10, 0);
	Triangle triangle(POINT_UN_TRIANGLE, POINT_DEUX_TRIANGLE, POINT_TROIS_TRIANGLE);

	//RECTANGLE + BONUS
	cout << "\n========= Rectangle 1 =========\n" << rectangle.Afficher() << endl;
	cout << "\n========= Rectangle 2 =========\n" << rectangleDeux.Afficher() << endl;
	cout << "\nle rectangle un a un plus grand perimetre que le rectangle deux ? (1 = vrai, 0 = faux) : " << rectangle.EstPlusGrandPerimetre(rectangleDeux) << endl;
	cout << "le rectangle un a une plus grande surface que le rectangle deux ? (1 = vrai, 0 = faux) : " << rectangle.EstPlusGrandSurface(rectangleDeux) << endl;

	cout << "\n========= Cercle =========\n" << cercle.Afficher() << endl;
	cout << "\npoint p : " << p.Afficher();
	cout << "distance du centre du cercle vers le point p : " << cercle.GetCentre().DistanceTo(p) << "cm" << endl;
	cout << "le point p est sur le cercle ? (1 = vrai, 0 = faux) : " << cercle.EstSurCercle(p) << endl;
	cout << "le point p est dans le cercle ? (1 = vrai, 0 = faux) : " << cercle.EstDansCercle(p) << endl;

	cout << "\n========= Triangle =========\n" << triangle.Afficher() << endl;


	return 0;
}
