#ifndef CAVALIER_H
#define CAVALIER_H
#include<iostream>
#include"Piece.h"
#include "Echiquier.h"
using namespace std;
class Cavalier : public Piece
{
    public:
        Cavalier();
        Cavalier(Position p ,string c);
   ~Cavalier();
  bool verifer_deplacement(Position p);
  bool verifer_chemain(Position p,Piece* lp[],int n,Piece* lp_adv[],int n_adv);
  int  liste_deplacement_possible(Deplacement *liste_dep,Piece* lp[],int n,Piece* lp_adv[],int n_adv);
};


#endif // CAVALIER_H
