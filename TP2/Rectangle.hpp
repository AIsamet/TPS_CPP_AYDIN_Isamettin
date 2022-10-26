#ifndef Rectangle_hpp
#define Rectangle_hpp

#include "Point.hpp"

class Rectangle {

public:
	//2.1.1 & 2.1.2
	Rectangle(const int& Largeur, const int& Longueur, const Point& CoinSupGauche);
	Rectangle();
	~Rectangle();
    string Afficher() const;

	//2.2.1
	inline int GetLargeur() const;
    inline int GetLongueur() const;
    inline Point GetCoinSupGauche() const;

    inline void SetLargeur(const int& Largeur);
    inline void SetLongueur(const int& Longueur);
    inline void SetCoinSupGauche(const Point& CoinSupGauche);

	//2.2.2
    inline int GetPerimetre() const;
    inline int GetSurface() const;

	//BONUS 2.3.1
    bool EstPlusGrandPerimetre(const Rectangle& Rectangle) const;

	//BONUS 2.3.2
    bool EstPlusGrandSurface(const Rectangle& Rectangle) const;

//2.1.1 & 2.1.2
private:
	int longueur;
	int largeur;
	Point coinSupGauche;
};

#endif /* Rectangle_hpp */
