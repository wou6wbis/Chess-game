#include "Tour.h"

Tour::Tour(Position p,string c)
{


    pos.Setx(p.Getx());
    pos.Sety(p.Gety());
    nom = "Tour";
    valeur =5;
    couleur = c;
    symbole = couleur == "blanc" ?" T_b ":" T_n ";


}
Tour::~Tour()
{
    //dtor
}


bool Tour::verifer_deplacement(Position p)
{
      if(!p.dans_echiquier())
        return false;
    int _x = p.Getx(),_y=p.Gety();
    if(_x == pos.Getx())
    {
        return true;
    }
    else if(_y == pos.Gety())
    {
        return true;
    }
    else return false;
}

bool Tour::verifer_chemain(Position p,Piece* lp[],int n,Piece* lp_adv[],int n_adv)
{

    if(!p.dans_echiquier())
        return false;

    int xf = p.Getx(), yf = p.Gety(), i = pos.Getx(), j= pos.Gety(),k;


    Position pos_v;
    if(i == xf)
    {

        int cj =  (yf > j)? 1: -1;

        j += cj;
        while(j!=yf)
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

            j += cj;
        }

        k = 0;

        while(k<n)
        {


            if(lp[k] != 0)
                if(lp[k]->Getpos() == p)
                    return false;
            k++;
        }

        return true;

    }
    else if(j == yf)
    {
        int ci =  (xf > i)? 1: -1;
        i += ci;
        while(i != xf)
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
        }

        k = 0;
        while(k<n)
        {
            if(lp[k] != 0)
                if(lp[k]->Getpos() == p)
                    return false;
            k++;
        }
        return true;
    }

}

int Tour::liste_deplacement_possible(Deplacement *liste_dep,Piece* lp[],int n,Piece* lp_adv[],int n_adv)
{

Position p;
    int taille = 0,x = pos.Getx(),y = pos.Gety();
    bool stop = false;

    do
    {
        x++;
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
        x--;
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
        y++;
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
        y--;
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

