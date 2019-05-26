#include "Pion.h"

Pion::Pion(Position p,string  c)
{
    valeur=1;
    couleur=c;
    nom="Pion";
    symbole = couleur == "blanc" ?" P_b ":" P_n ";


    pos.Setx(p.Getx());
    pos.Sety(p.Gety());


}


Pion::~Pion()
{
    //dtor
}

bool Pion::verifer_deplacement(Position p)
{
    int _x, _y;
    _x = p.Getx();
    _y=p.Gety();
    if(couleur == "noir")
    {
        if(_x == pos.Getx())
        {
            if(_y == 3 && pos.Gety()==1)
            {
                return true;
            }
            else if(_y - pos.Gety() == 1)
            {
                return true;
            }
            else
                return false;

        }
        else if( abs(_x - pos.Getx())== 1 && _y - pos.Gety() == 1)
        {
            return true;
        }
        else
            return false;

    }
    if(couleur == "blanc")
    {
        if(_x == pos.Getx())
        {
            if(_y == 4 && pos.Gety()==6)
            {
                return true;
            }
            else if(_y - pos.Gety() == -1)
            {

                return true;
            }
            else return false;

        }
        else if( abs(_x - pos.Getx())== 1 && _y - pos.Gety() == -1)
        {

            return true;
        }
        else return false;


    }

}

bool Pion::verifer_chemain(Position p,Piece* lp[],int n,Piece* lp_adv[],int n_adv)
{
      if(!p.dans_echiquier())
        return false;

    int xf= p.Getx(), yf=p.Gety(), k;
    if(couleur == "noir")
    {
        if(xf == pos.Getx())
        {
            if(yf == 3 && pos.Gety()==1)
            {
                k =0;
                Position p1(xf,2),p2(xf,3);
                while(k<n)
                {
                    if(lp[k] != 0 && lp[k] != this)
                        if(lp[k]->Getpos() == p1 || lp[k]->Getpos() == p2)
                            return false;
                    k++;
                }
                k = 0;
                while(k<n_adv)
                {
                    if(lp_adv[k] != 0)
                        if(lp_adv[k]->Getpos() == p1 || lp_adv[k]->Getpos() == p2)
                            return false;
                    k++;
                }
                return true;
            }
            else if(yf - pos.Gety() == 1)
            {
                k =0;
                while(k<n)
                {
                    if(lp[k] != 0 && lp[k] != this)
                        if(lp[k]->Getpos() == p)
                            return false;
                    k++;
                }
                k = 0;
                while(k<n_adv)
                {
                    if(lp_adv[k] != 0)
                        if(lp_adv[k]->Getpos() == p)
                            return false;
                    k++;
                }
                return true;
            }

        }
        else if( abs(xf - pos.Getx()) == 1 && (yf - pos.Gety() == 1) )
        {
           k = 0;
                while(k<n_adv)
                {
                    if(lp_adv[k] != 0)
                        if(lp_adv[k]->Getpos() == p)
                            return true;
                    k++;
                }
                return false;
        }
    }
    else if(couleur == "blanc")
    {
        if(xf == pos.Getx())
        {
            if(yf == 4 && pos.Gety()==6)
            {
                k =0;
                Position p1(xf,5),p2(xf,4);
                while(k<n)
                {
                    if(lp[k] != 0 && lp[k] != this)
                        if(lp[k]->Getpos() == p1 || lp[k]->Getpos() == p2)
                            return false;
                    k++;
                }
                k = 0;
                while(k<n_adv)
                {
                    if(lp_adv[k] != 0)
                        if(lp_adv[k]->Getpos() == p1 || lp_adv[k]->Getpos() == p2)
                            return false;
                    k++;
                }
                return true;
            }
            else if(yf - pos.Gety() == -1)
            {

                 k =0;
                while(k<n)
                {
                    if(lp[k] != 0 && lp[k] != this)
                        if(lp[k]->Getpos() == p)
                            return false;
                    k++;
                }
                k = 0;
                while(k<n_adv)
                {
                    if(lp_adv[k] != 0)
                        if(lp_adv[k]->Getpos() == p)
                            return false;
                    k++;
                }
                return true;
            }

        }
        else if( abs(xf - pos.Getx())== 1 &&(yf - pos.Gety() == -1) )
        {

             k = 0;
                while(k<n_adv)
                {
                    if(lp_adv[k] != 0)
                        if(lp_adv[k]->Getpos() == p)
                            return true;
                    k++;
                }
                return false;
        }
    }

}
int Pion::liste_deplacement_possible(Deplacement *liste_dep,Piece* lp[],int n,Piece* lp_adv[],int n_adv)
{
    Position p;
    int taille = 0;

    if(couleur == "noir")
    {

            if(pos.Gety()==1)
            {
                p.Setx(pos.Getx());
                p.Sety(3);
                if(verifer_chemain(p,lp,n,lp_adv,n_adv))
                {
                    liste_dep[taille++] = Deplacement(pos,p);
                }
            }
            p.Setx(pos.Getx());
                p.Sety(pos.Gety()+1);
            if(verifer_chemain(p,lp,n,lp_adv,n_adv))
                    liste_dep[taille++] = Deplacement(pos,p);
            p.Setx(pos.Getx()+1);
            p.Sety(pos.Gety()+1);
            if(verifer_chemain(p,lp,n,lp_adv,n_adv))
                    liste_dep[taille++] = Deplacement(pos,p);
            p.Setx(pos.Getx()-1);
            p.Sety(pos.Gety()+1);
            if(verifer_chemain(p,lp,n,lp_adv,n_adv))
                    liste_dep[taille++] = Deplacement(pos,p);
            return taille;

    }
    if(couleur == "blanc")
    {
        if(pos.Gety()==6)
            {
                p.Setx(pos.Getx());
                p.Sety(4);
                if(verifer_chemain(p,lp,n,lp_adv,n_adv))
                {
                    liste_dep[taille++] = Deplacement(pos,p);
                }

            }
            p.Setx(pos.Getx());
                p.Sety(pos.Gety()-1);
            if(verifer_chemain(p,lp,n,lp_adv,n_adv))
                    {

                    liste_dep[taille++] = Deplacement(pos,p);
                }
            p.Setx(pos.Getx()+1);
            p.Sety(pos.Gety()-1);
            if(verifer_chemain(p,lp,n,lp_adv,n_adv))
                    liste_dep[taille++] = Deplacement(pos,p);
            p.Setx(pos.Getx()-1);
            p.Sety(pos.Gety()-1);
            if(verifer_chemain(p,lp,n,lp_adv,n_adv))
                    liste_dep[taille++] = Deplacement(pos,p);
       return taille;

}
}

