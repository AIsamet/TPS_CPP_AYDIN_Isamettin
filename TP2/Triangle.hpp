#ifndef Triangle_hpp
#define Triangle_hpp

#include "Point.hpp"

class Triangle {

public:
    //4.1.1
	Triangle();
	Triangle(const Point& p1, const Point& p2, const Point& p3);
	~Triangle();
	string Afficher() const;

	//4.2.1
    inline Point GetP1() const;
    inline Point GetP2() const;
    inline Point GetP3() const;

    inline void SetP1(const Point& p);
    inline void SetP2(const Point& p);
    inline void SetP3(const Point& p);

	//4.2.2
    inline double GetBase() const;
    inline double GetHauteur() const;
    inline double GetSurface() const;
    inline string GetLongueurs() const;
    inline bool EstIsocele() const;
    inline bool EstRectangle() const;
    inline bool EstEquilateral() const;

//4.1.1
private:
	Point p1;
	Point p2;
	Point p3;
};

#endif /* Triangle_hpp */
