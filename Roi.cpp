#include "Roi.h"

Roi::Roi(Position p,string c)
{


        pos.Setx(p.Getx());
    pos.Sety(p.Gety());
        nom = "Roi";
        valeur =10;
        couleur = c;
            symbole = couleur == "blanc" ?" Rob ":" Ron ";



}

Roi::~Roi()
{
    //dtor
}
bool Roi::verifer_deplacement(Position p)
{
    int _x = p.Getx(),_y = p.Gety();
     if(abs(_x - pos.Getx()) == 1 || abs(_y - pos.Gety()) == 1)
    {

        return true;
    }
    return false;
}

bool Roi::verifer_chemain(Position p,Piece* lp[],int n,Piece* lp_adv[],int n_adv)
{
      if(!p.dans_echiquier())
        return false;

    int xf =  p.Getx(), yf = p.Gety();
    int i =0;
    while(i<n)
    {
        if(lp[i] != 0 && lp[i] != this)
        {
            if(lp[i]->Getpos() == p)
                return false;

        }
            i++;
    }
    return true;

}

int Roi::liste_deplacement_possible(Deplacement *liste_dep,Piece* lp[],int n,Piece* lp_adv[],int n_adv)
{
    return 0;
    Position p;
    int taille = 0;

    p.Setx(pos.Getx()+1);
    p.Sety(pos.Gety()+1);
    if(verifer_chemain(p,lp,n,lp_adv,n_adv))
        liste_dep[taille++] = Deplacement(pos,p);

        p.Setx(pos.Getx()-1);
    p.Sety(pos.Gety()+1);
    if(verifer_chemain(p,lp,n,lp_adv,n_adv))
        liste_dep[taille++] = Deplacement(pos,p);

        p.Setx(pos.Getx()+1);
    p.Sety(pos.Gety()-1);
    if(verifer_chemain(p,lp,n,lp_adv,n_adv))
        liste_dep[taille++] = Deplacement(pos,p);

        p.Setx(pos.Getx()-1);
    p.Sety(pos.Gety()-1);
    if(verifer_chemain(p,lp,n,lp_adv,n_adv))
        liste_dep[taille++] = Deplacement(pos,p);

        p.Setx(pos.Getx()+1);
    p.Sety(pos.Gety());
    if(verifer_chemain(p,lp,n,lp_adv,n_adv))
        liste_dep[taille++] = Deplacement(pos,p);

        p.Setx(pos.Getx());
    p.Sety(pos.Gety()+1);
    if(verifer_chemain(p,lp,n,lp_adv,n_adv))
        liste_dep[taille++] = Deplacement(pos,p);

        p.Setx(pos.Getx());
    p.Sety(pos.Gety()-1);
    if(verifer_chemain(p,lp,n,lp_adv,n_adv))
        liste_dep[taille++] = Deplacement(pos,p);

        p.Setx(pos.Getx()-1);
    p.Sety(pos.Gety());
    if(verifer_chemain(p,lp,n,lp_adv,n_adv))
        liste_dep[taille++] = Deplacement(pos,p);

return taille;
}
