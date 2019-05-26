

#include "Piece.h"

using namespace std ;

Piece::Piece()
{

}

Piece::~Piece()
{
}
Piece::Piece(string n, string c, int v, Position p ):nom(n),couleur(c),valeur(v),pos(p)
{

}
Piece::Piece( Position p, string c)
{
    couleur=c;
    pos.Setx(p.Getx());
    pos.Sety(p.Gety());
}

void   Piece::afficher()
{
    cout << nom<<" ";
}

void Piece::deplacer(Position p)
{
    pos = p;
}


