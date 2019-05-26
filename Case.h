#ifndef CASE_H_INCLUDED
#define CASE_H_INCLUDED


#include "Piece.h"


using namespace std ;

class Case
{
    private:
    //Position pos;
    Piece *piece;
    string couleur;

    public:
    Case ();
    Case (Piece *p);
    Case(string c);
    Piece* Get_piece()const {return piece;}
    //Case (Piece &p,Position po);
    ~Case();

    void inserer_piece()
    {
       /* Setx
        Sety*/
    }
    void afficher();
   /* void Set_pos(Position &po);
    Position& Get_pos() const;*/
    void Set_piece(Piece *pi);
    string Getcouleur()const {return couleur;}
    void Setcouleur(string c){couleur = c;}


};


#endif // CASE_H_INCLUDED
