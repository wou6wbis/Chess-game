#ifndef PIECE_H
#define PIECE_H


#include "Position.h"
#include "Deplacement.h"
//#include "Echiquier.h"
#include<iostream>
#include<string>
#include <cmath>

using namespace std ;

class Piece
{
public:
    Piece();
    ~Piece();
    Piece(string n, string c, int v, Position p );
    Piece(Position p,string c);
    string Getnom()
    {
        return nom;
    }
    string Getsymbole()
    {
        return symbole;
    }
    string Getcouleur()
    {
        return couleur;
    }
    int Getvaleur()
    {
        return valeur;
    }
    Position Getpos()
    {
        return pos;
    }
    void Setpos(Position val)
    {
        pos = val;
    }

    virtual bool verifer_deplacement(Position p)=0;
    virtual bool verifer_chemain(Position p,Piece* lp[],int n,Piece* lp_adv[],int n_adv) = 0;
    virtual int  liste_deplacement_possible(Deplacement *liste_dep,Piece* lp[],int n,Piece* lp_adv[],int n_adv) =0;
    void deplacer(Position p);
    void afficher();

protected:
    string nom;
    string couleur;
    int valeur;
    Position pos;
    string symbole;

};

#endif // PIECE_H
