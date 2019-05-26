#ifndef FOU_H
#define FOU_H
#include<iostream>
#include"Piece.h"
#include "Echiquier.h"

class Fou : public Piece
{
    public:
        Fou();
        Fou(Position p , string c);
        virtual ~Fou();

        bool verifer_deplacement(Position p);
        bool verifer_chemain(Position p,Piece* lp[],int n,Piece* lp_adv[],int n_adv);
        int liste_deplacement_possible(Deplacement *liste_dep,Piece* lp[],int n,Piece* lp_adv[],int n_adv);
};

#endif // FOU_H
