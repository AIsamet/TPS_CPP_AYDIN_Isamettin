#ifndef Triangle_hpp
#define Triangle_hpp

#include "Point.hpp"

class Triangle {

public:
    //4.1.1
	Triangle();
	Triangle(const Point& PointUn, const Point& PointDeux, const Point& PointTrois);
	~Triangle();
	string Afficher() const;

	//4.2.1
    inline Point GetP1() const;
    inline Point GetP2() const;
    inline Point GetP3() const;

    inline void SetP1(const Point& Point);
    inline void SetP2(const Point& Point);
    inline void SetP3(const Point& Point);

	//4.2.2
    inline float GetBase() const;
    inline float GetHauteur() const;
    inline float GetSurface() const;
    inline string GetLongueurs() const;
    inline bool EstIsocele() const;
    inline bool EstRectangle() const;
    inline bool EstEquilateral() const;

//4.1.1
private:
	Point pointUn;
	Point pointDeux;
	Point pointTrois;
};

#endif /* Triangle_hpp */
