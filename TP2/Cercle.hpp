#ifndef Cercle_hpp
#define Cercle_hpp

#include "Point.hpp"

class Cercle {

public:
	//3.1.1
	Cercle(const Point& Centre, const int& Diametre);
	Cercle();
	~Cercle();
	string Afficher() const;

	//3.2.1
    Point GetCentre() const;
    inline int GetDiametre() const;

    inline void SetCentre(const Point& Centre);
    inline void SetDiametre(const int& Diametre);

	//3.2.2
    inline float GetPerimetre() const;
    inline float GetSurface() const;

	//3.2.3
	bool EstSurCercle(const Point& p) const;

	//3.2.4
	bool EstDansCercle(const Point& p) const;

//3.1.1
private:
	Point centre;
	int diametre;
};

#endif /* Cercle_hpp */
