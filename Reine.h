#ifndef REINE_H
#define REINE_H
#include<iostream>
#include"Piece.h"
#include "Echiquier.h"
class Reine : public Piece
{
public:
    Reine();
    virtual ~Reine();
    Reine(Position p,string c);
bool verifer_deplacement(Position p);
bool verifer_chemain(Position p,Piece* lp[],int n,Piece* lp_adv[],int n_adv);
int liste_deplacement_possible(Deplacement *liste_dep,Piece* lp[],int n,Piece* lp_adv[],int n_adv);
};

#endif // REINE_H
