#include "Cavalier.h"
#include"Piece.h"
Cavalier::Cavalier(Position p,string c)
{
    nom = "Cavalier";
    couleur = c;
    valeur = 3;
    pos.Setx(p.Getx());
    pos.Sety(p.Gety());
    symbole = couleur == "blanc" ?" C_b ":" C_n ";




}

Cavalier::~Cavalier()
{
    //dtor
}

bool Cavalier::verifer_deplacement( Position p)
{
    int _x = p.Getx(),_y = p.Gety();

    if( abs(_x - pos.Getx())== 1 && abs(_y - pos.Gety())== 2)
    {
        return true;
    }
    else if(abs(_x - pos.Getx())== 2 && abs(_y - pos.Gety())== 1)
    {
        return true;
    }
    else return false;
}

bool Cavalier::verifer_chemain(Position p,Piece* lp[],int n,Piece* lp_adv[],int n_adv)
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
int Cavalier::liste_deplacement_possible(Deplacement* liste_dep,Piece* lp[],int n,Piece* lp_adv[],int n_adv)
{
    Position p;
    int taille = 0;
    p.Setx(pos.Getx()+2);
    p.Sety(pos.Gety()+1);
    if(verifer_chemain(p,lp,n,lp_adv,n_adv))
    {
        liste_dep[taille++] = Deplacement(pos,p);
    }
    p.Setx(pos.Getx()-2);
    p.Sety(pos.Gety()+1);
    if(verifer_chemain(p,lp,n,lp_adv,n_adv))
    {
        liste_dep[taille++] = Deplacement(pos,p);
    }
    p.Setx(pos.Getx()+2);
    p.Sety(pos.Gety()-1);
    if(verifer_chemain(p,lp,n,lp_adv,n_adv))
    {
        liste_dep[taille++] = Deplacement(pos,p);
    }
    p.Setx(pos.Getx()-2);
    p.Sety(pos.Gety()-1);
    if(verifer_chemain(p,lp,n,lp_adv,n_adv))
    {
        liste_dep[taille++] = Deplacement(pos,p);
    }

    p.Setx(pos.Getx()+1);
    p.Sety(pos.Gety()+2);
    if(verifer_chemain(p,lp,n,lp_adv,n_adv))
    {
        liste_dep[taille++] = Deplacement(pos,p);
    }
    p.Setx(pos.Getx()-1);
    p.Sety(pos.Gety()+2);
    if(verifer_chemain(p,lp,n,lp_adv,n_adv))
    {
        liste_dep[taille++] = Deplacement(pos,p);
    }
    p.Setx(pos.Getx()+1);
    p.Sety(pos.Gety()-2);
    if(verifer_chemain(p,lp,n,lp_adv,n_adv))
    {
        liste_dep[taille++] = Deplacement(pos,p);
    }
    p.Setx(pos.Getx()-1);
    p.Sety(pos.Gety()-2);
    if(verifer_chemain(p,lp,n,lp_adv,n_adv))
    {
        liste_dep[taille++] = Deplacement(pos,p);
    }

    return taille;

}
