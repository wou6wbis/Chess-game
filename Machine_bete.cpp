#include "Machine_bete.h"

Machine_bete::Machine_bete()
{
    //ctor
}
Machine_bete::Machine_bete(string c) : Machine(c,1)
{
    //ctor
}
Machine_bete::~Machine_bete()
{
    //dtor
}
Deplacement Machine_bete::jouer(Echiquier &ech, Joueur & j_adv)
{
    Deplacement *liste_dep;
    int  indice[16],j=0,_j,_i,n;

    for(int i=0;i<taille;i++)
    {
        liste_dep = new Deplacement[100];
        if(liste_pieces[i] != 0)
        if(liste_pieces[i]->liste_deplacement_possible(liste_dep,liste_pieces,taille,j_adv.get_liste_pieces(),j_adv.GetTaille()) > 0)
        {
            indice[j++] = i;
        }
    }
    srand(time(0));
    _j = rand()%j;
    n = liste_pieces[indice[_j]]->liste_deplacement_possible(liste_dep,liste_pieces,taille,j_adv.get_liste_pieces(),j_adv.GetTaille());
    _i = rand()%n;

    Deplacement dep(liste_dep[_i]);
    ech.Set_case(dep.Getpos_i().Getx(),dep.Getpos_i().Gety(),0);
    liste_pieces[indice[_j]]->deplacer(dep.Getpos_f());
    ech.Set_case(dep.Getpos_f().Getx(),dep.Getpos_f().Gety(),liste_pieces[indice[_j]]);

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

    return dep;

}
