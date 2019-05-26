#include "Machine_intelpp.h"

Machine_intelpp::Machine_intelpp()
{
    //ctor
}
Machine_intelpp::Machine_intelpp(string c) : Machine(c,3)
{

}
Machine_intelpp::~Machine_intelpp()
{
    //dtor
}
Deplacement Machine_intelpp::jouer(Echiquier &ech,Joueur &j_adv)
{
    Deplacement *liste_dep;
    vector <Position> liste_pos_pp;
    vector <Piece*> liste_piece_pp;
    int  indice[16],j=0,_j,_i,n,l;

    for(int i=0; i<taille; i++)
    {
        liste_dep = new Deplacement[100];

        n = liste_pieces[i]->liste_deplacement_possible(liste_dep,liste_pieces,taille,j_adv.get_liste_pieces(),j_adv.GetTaille());
        if(n> 0)
        {

            for(int k =0; k<n; k++)
            {

                Deplacement dep(liste_dep[k]);
                if(ech.Get_case(dep.Getpos_f().Getx(),dep.Getpos_f().Gety()).Get_piece() != 0
                        && ech.Get_case(dep.Getpos_f().Getx(),dep.Getpos_f().Gety()).Get_piece()->Getcouleur() == j_adv.Getcouleur())
                {
                    liste_pos_pp.push_back(dep.Getpos_f());
                    liste_piece_pp.push_back(liste_pieces[i]);
                }

            }
            indice[j++] = i;
        }

    }
    Deplacement dep;
    if(liste_pos_pp.size() >0)
    {

        int ind=0;
        for(int i=1;i<liste_pos_pp.size();i++)
        {
            if(liste_piece_pp[i]->Getvaleur()>liste_piece_pp[ind]->Getvaleur() )
            {
                ind = i;
            }
        }

          ech.Set_case(dep.Getpos_i().Getx(),dep.Getpos_i().Gety(),0);

dep.Setpos_i(liste_piece_pp[ind]->Getpos());
dep.Setpos_f(liste_pos_pp[ind]);


    liste_pieces[indice[ind]]->deplacer(dep.Getpos_f());
    ech.Set_case(dep.Getpos_f().Getx(),dep.Getpos_f().Gety(),liste_pieces[ind]);
    }
    else
    {
         srand(time(0));
    _j = rand()%j;
    n = liste_pieces[indice[_j]]->liste_deplacement_possible(liste_dep,liste_pieces,taille,j_adv.get_liste_pieces(),j_adv.GetTaille());
    _i = rand()%n;
dep=liste_dep[_i];
  ech.Set_case(dep.Getpos_i().Getx(),dep.Getpos_i().Gety(),0);
    liste_pieces[indice[_j]]->deplacer(dep.Getpos_f());
    ech.Set_case(dep.Getpos_f().Getx(),dep.Getpos_f().Gety(),liste_pieces[indice[_j]]);
    }



    int ind_adv  = -1;
    for(int i=0; i<j_adv.GetTaille(); i++)
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
