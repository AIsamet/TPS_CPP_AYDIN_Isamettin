#include <iostream>
#include <cmath>
#include "Rectangle.hpp"
#include "Cercle.hpp"
#include "Triangle.hpp"

int main(int argc, const char* argv[]) {

	const int coordonneX = 0;
	const int coordonneY = 5;
	const Point p(coordonneX, coordonneY);

	const int largeurRectangle(20);
	const int longueurRectangle(40);
	const Point coinSupGaucheRectangle(10, 20);
	Rectangle rectangle(largeurRectangle, longueurRectangle, coinSupGaucheRectangle);

	const int largeurRectangleDeux(10);
	const int longueurRectangleDeux(20);
	const Point coinSupGaucheRectangleDeux(10, 20);
	Rectangle rectangleDeux(largeurRectangleDeux, longueurRectangleDeux, coinSupGaucheRectangleDeux);

	const Point centreCercle(0, 0);
	const int diametreCercle(10);
	Cercle cercle(centreCercle, diametreCercle);

	////JEU DE TEST POUR AVOIR UN TRIANGLE EQUILATERAL
	//const Point p1(1,2);
	//const Point p2(5,4);
	//const Point p3(3-sqrt(3),3+2*sqrt(3));

	////JEU DE TEST POUR AVOIR UN TRIANGLE RECTANGLE + ISOCELE
	//const Point p1(0, 0);
	//const Point p2(0, 10);
	//const Point p3(10, 0);

	const Point pointUnTriangle(0, 0);
	const Point pointDeuxTriangle(0, 10);
	const Point pointTroisTriangle(10, 0);
	Triangle triangle(pointUnTriangle, pointDeuxTriangle, pointTroisTriangle);

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
