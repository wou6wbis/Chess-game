#include"Case.h"

Case::Case()
{
    piece =0;
}
Case::Case(Piece *p)
{
    piece = p;
}
Case::Case(string c)
{
    couleur = c;
}
Case::~Case()
{

}
/*
void Case::Set_pos(Position &po)
{
    pos = po;
}*/
void Case::Set_piece(Piece *pi)
{
    piece = pi;
}
void Case::afficher()
{
    if(piece != 0)
    piece->afficher();
    else cout <<"     ";
}
