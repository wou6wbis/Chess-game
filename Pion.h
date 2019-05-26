#ifndef PION_H
#define PION_H


#include"Piece.h"
#include "Echiquier.h"
#include<iostream>
using namespace std;

class Pion : public Piece
{
    public:
        Pion();
        ~Pion();
        Pion(Position p,string  c);
        bool verifer_deplacement(Position p);
        bool verifer_chemain(Position p,Piece* lp[],int n,Piece* lp_adv[],int n_adv);
        int liste_deplacement_possible(Deplacement *liste_dep,Piece* lp[],int n,Piece* lp_adv[],int n_adv);
};

#endif // PION_H
