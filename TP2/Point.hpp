#ifndef Point_hpp
#define Point_hpp
#define _USE_MATH_DEFINES

#include <cmath>
#include <iomanip>
#include <string>  
#include <iostream>
using namespace std;

//1
struct Point {

	float x;
	float y;

    Point();
	Point(const float& X, const float& Y);
	~Point();

    string Afficher() const;

	//Ajout d'une methode distanceTo pour calculer la distance vers un point p
	//afin de simplifier les methodes dans les classes Cercle et Triangle
    float DistanceTo(const Point& p) const;
};

#endif /* Point_hpp */
