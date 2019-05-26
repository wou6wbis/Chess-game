#include "Homme.h"

Homme::Homme()
{
    //ctor
}

Homme::Homme(string n = "",string c="",string e= "",int t=0,Piece **lp = 0) :Joueur(n,c,e,t,lp)
{

}
Homme::Homme(string n,string c) :Joueur(n,c,"normal")
{

}
Homme::Homme(string n = "",string c="",string e= "") :Joueur(n,c,e)
{

}
Homme::Homme(Homme& h) : Joueur(h)
{

}
Homme::~Homme()
{
    //dtor
}

Deplacement Homme::jouer(Echiquier &ech,Joueur &j_adv)
{
    bool stop = true,l;
    Deplacement dep;
    int ind;
    do
    {

        saisir(dep);

        if(!dep.Getpos_i().dans_echiquier() || !dep.Getpos_f().dans_echiquier())
            stop = false;
       else
       {
           Position l_pos[taille];
           for(int i=0;i<taille;i++)
           {
               if(liste_pieces[i] != 0)
               l_pos[i] = liste_pieces[i]->Getpos();
           }

           ind = dep.Getpos_i().chercher(l_pos,taille);

           if(ind == -1)
           {
               stop = false;


           }

           //
           else if(liste_pieces[ind]->verifer_deplacement(dep.Getpos_f()) == false)
           {
               stop = false;


           }
           else if(liste_pieces[ind]->verifer_chemain(dep.Getpos_f(),liste_pieces,taille,j_adv.get_liste_pieces(),j_adv.GetTaille()) == false)
           {

               stop = false;
           }
           else
           {
            stop = true;
           }

       }
    }while(!stop);
    if(stop)
    {

        int x = liste_pieces[ind]->Getpos().Getx(),y = liste_pieces[ind]->Getpos().Gety();

        ech.Set_case(dep.Getpos_i().Getx(),dep.Getpos_i().Gety(),0);
        int ind_adv  = -1;
        for(int i=0;i<j_adv.GetTaille();i++)
        {
            if(j_adv.get_liste_pieces()[i] != 0 &&j_adv.get_liste_pieces()[i]->Getpos() == dep.Getpos_f())
            {
                ind_adv = i;
                break;
            }
        }
        if(ind_adv >=0)
        {
            j_adv.get_liste_pieces()[ind_adv] = 0;
        }
        liste_pieces[ind]->deplacer(dep.Getpos_f());

        x = liste_pieces[ind]->Getpos().Getx();y = liste_pieces[ind]->Getpos().Gety();
        ech.Set_case(x,y,liste_pieces[ind]);


    }

}
