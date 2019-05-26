#ifndef DEPLACEMENT_H
#define DEPLACEMENT_H


#include<iostream>
#include <string>

#include "Position.h"

using namespace std;
class Deplacement
{
    public:
        Deplacement();
        Deplacement(const Deplacement& dep);
        ~Deplacement();
        Deplacement(Position pi , Position pf);
        Position Getpos_i() { return pos_i; }
        void Setpos_i(Position val) { pos_i = val; }
        Position Getpos_f() { return pos_f; }
        void Setpos_f(Position val) { pos_f = val; }
        void afficher();
        void saisir();


    private:
        Position pos_i;
        Position pos_f;
};

#endif // DEPLACEMENT_H
