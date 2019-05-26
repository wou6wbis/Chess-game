#ifndef TOUR_H
#define TOUR_H
#include<iostream>
#include"Piece.h"
#include "Echiquier.h"

class Tour  : public Piece
{
    public:
        Tour();
        Tour(Position p,string c);
        virtual ~Tour();
bool verifer_deplacement(Position p);
bool verifer_chemain(Position p,Piece* lp[],int n,Piece* lp_adv[],int n_adv);
int liste_deplacement_possible(Deplacement *liste_dep,Piece* lp[],int n,Piece* lp_adv[],int n_adv);


};

#endif // TOUR_H
