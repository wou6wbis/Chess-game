#ifndef POSITION_H
#define POSITION_H


#include <iostream>

class Position
{
    public:
        Position();
        Position(int _x , int _y  );
        Position(const Position &p);

         ~Position();

        int Getx() { return x; }
        void Setx(int val) { x = val; }
        int Gety() { return y; }
        void Sety(int val) { y = val; }
        void afficher() const;
        bool operator==(const Position &p);
        bool dans_echiquier()const ;
        void saisir();
        int chercher(Position lp[],int n)const;

    private:
        int x;
        int y;
};

#endif // POSITION_H
