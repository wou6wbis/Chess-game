#include "Fou.h"

Fou::Fou(Position p,string c)
{

    pos.Setx(p.Getx());
    pos.Sety(p.Gety());
    nom = "Fou";
    valeur =3;
    couleur = c;
    symbole = couleur == "blanc" ?" F_b ":" F_n ";



}

Fou::~Fou()
{
    //dtor
}
bool Fou::verifer_deplacement(Position p)
{
      if(!p.dans_echiquier())
        return false;
    int _x = p.Getx(),_y = p.Gety();
    if(abs(_x - pos.Getx()) == abs(_y - pos.Gety()))
    {

        return true;
    }
    else return false;

}
bool Fou::verifer_chemain(Position p,Piece* lp[],int n,Piece* lp_adv[],int n_adv)
{
            if(!p.dans_echiquier())
        return false;

    int  i = pos.Getx(), j = pos.Gety(),xf= p.Getx(), yf= p.Gety(),k;
    int ci = (xf > i) ? 1:-1, cj = (yf > j)? 1:-1;
    Position pos_v;
    i += ci;
    j += cj;
    while( i != xf && j  != yf )
    {
        pos_v.Setx(i);
        pos_v.Sety(j);
        k =0;
        while(k<n)
        {
            if(lp[k] != 0 && lp[k] != this)
                if(lp[k]->Getpos() == pos_v)
                    return false;
                    k++;
        }
        k = 0;
        while(k<n_adv)
        {
            if(lp_adv[k] != 0)
                if(lp_adv[k]->Getpos() == pos_v)
                    return false;
                    k++;
        }

            i += ci;
            j += cj;
    }
    k =0;

        while(k<n)
        {
            if(lp[k] != 0 && lp[k] != this)
                if(lp[k]->Getpos() == p)
                    return false;
                    k++;
        }

        return true;


}

int Fou::liste_deplacement_possible(Deplacement *liste_dep,Piece* lp[],int n,Piece* lp_adv[],int n_adv)
{

    Position p;
    int taille = 0,x = pos.Getx(),y = pos.Gety();
    bool stop = false;
    do
    {
        x++;y++;
        p.Setx(x),p.Sety(y);
        if(verifer_chemain(p,lp,n,lp_adv,n_adv))
        {
            liste_dep[taille++] = Deplacement(pos,p);
        }
        else
            stop = true;

    }while(!stop);

    x = pos.Getx();y = pos.Gety();
    stop = false;

    do
    {
        x++;y--;
        p.Setx(x),p.Sety(y);
        if(verifer_chemain(p,lp,n,lp_adv,n_adv))
        {
            liste_dep[taille++] = Deplacement(pos,p);
        }
        else
            stop = true;

    }while(!stop);

    x = pos.Getx();y = pos.Gety();
    stop = false;

    do
    {
        x--;y--;
        p.Setx(x),p.Sety(y);
        if(verifer_chemain(p,lp,n,lp_adv,n_adv))
        {
            liste_dep[taille++] = Deplacement(pos,p);
        }
        else
            stop = true;

    }while(!stop);

    x = pos.Getx();y = pos.Gety();
    stop = false;

    do
    {
        x--;y++;
        p.Setx(x),p.Sety(y);
        if(verifer_chemain(p,lp,n,lp_adv,n_adv))
        {
            liste_dep[taille++] = Deplacement(pos,p);
        }
        else
            stop = true;

    }while(!stop);

    return taille;


}
