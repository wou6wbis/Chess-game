#ifndef ECHIQUIER_H_INCLUDED
#define ECHIQUIER_H_INCLUDED





#include "Deplacement.h"
#include "Case.h"

#include <windows.h>

using namespace std;

class Echiquier
{
 private:
    Case ech[8][8];

 public:
    Echiquier(Piece* lpb[],int tb,Piece* lpn[],int tn);
   ~Echiquier();
    void init_ech();
    void afficher();
    Position* Get_liste_pos();
//    Piece* Get_piece(int ind){return liste_piece[ind];}
  //  bool Set_piece(int ind,Position p){return liste_piece[ind]->deplacer(p);}
    Case Get_case(int i,int j){return ech[i][j];}
    void Set_case(int i,int j,Piece *p) {ech[i][j].Set_piece(p);}
    bool m_a_j(Deplacement &dep);
    void m_a_j_ech();

};


#endif // ECHIQUIER_H_INCLUDED
