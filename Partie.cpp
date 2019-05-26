#include "Partie.h"

Partie::Partie()
{
    //ctor
}

Partie::Partie(Homme &h1,Homme &h2)
{
        js[0] = new Homme(h1);
        js[1] = new Homme(h2);
        ech = new Echiquier(js[0]->get_liste_pieces(),js[0]->GetTaille(),js[1]->get_liste_pieces(),js[1]->GetTaille());
        tour =0;
        terminee = false;



}
Partie::Partie(Homme &h,Machine_bete &mb)
{
        js[0] = new Homme(h);
        js[1] = new Machine_bete(mb);
        ech = new Echiquier(js[0]->get_liste_pieces(),js[0]->GetTaille(),js[1]->get_liste_pieces(),js[1]->GetTaille());

        tour =0;
        terminee = false;


}
Partie::Partie(Machine_bete &mb1,Machine_bete &mb2)
{
        js[0] = new Machine_bete(mb1);
        js[1] = new Machine_bete(mb2);
        ech = new Echiquier(js[0]->get_liste_pieces(),js[0]->GetTaille(),js[1]->get_liste_pieces(),js[1]->GetTaille());

        tour =0;
        terminee = false;


}
Partie::Partie(Machine_bete &mb1,Machine_intel &mi)
{
        js[0] = new Machine_bete(mb1);
        js[1] = new Machine_intel(mi);
        ech = new Echiquier(js[0]->get_liste_pieces(),js[0]->GetTaille(),js[1]->get_liste_pieces(),js[1]->GetTaille());

        tour =0;
        terminee = false;

}
Partie::Partie(Machine_bete &mb1,Machine_intelpp &mipp)
{
        js[0] = new Machine_bete(mb1);
        js[1] = new Machine_intelpp(mipp);
        ech = new Echiquier(js[0]->get_liste_pieces(),js[0]->GetTaille(),js[1]->get_liste_pieces(),js[1]->GetTaille());

        tour =0;
        terminee = false;

}
Partie::Partie(Homme &h,Machine_intel &mi)
{
        js[0] = new Homme(h);
        js[1] = new Machine_intel(mi);
        ech = new Echiquier(js[0]->get_liste_pieces(),js[0]->GetTaille(),js[1]->get_liste_pieces(),js[1]->GetTaille());

        tour =0;
        terminee = false;

}
Partie::Partie(Homme &h,Machine_intelpp &mipp)
{
        js[0] = new Homme(h);
        js[1] = new Machine_intelpp(mipp);
        ech = new Echiquier(js[0]->get_liste_pieces(),js[0]->GetTaille(),js[1]->get_liste_pieces(),js[1]->GetTaille());

        tour =0;
        terminee = false;

}
Partie::~Partie()
{
    //dtor
}
void Partie::afficher()
{
    system("mode 140,80");
    cout<<endl;
    js[tour]->afficher();
    cout<<endl;
    js[(tour+1)%2]->afficher();
    cout<<endl;
    ech->afficher();
    cout << "historque : "<<endl;
    for(int i=0;i<His.size();i++)
    {
        His[i].afficher();
    }
}
void Partie::lancer()
{
    Deplacement dep;
    while(!terminee)
    {
        afficher();
        string e = js[tour]->m_a_j_etat(*js[(tour+1)%2]);
        js[tour]->Setetat(e);


        if(js[tour]->Getetat() == "perdu" || js[tour]->Getetat() == "echec emat")
        {
            cout << "joueur gagnant est :"<<endl;
            js[(tour + 1)%2]->afficher();
            terminee = true;
        }
            else
            {

        dep = js[tour]->jouer(*ech,*js[(tour + 1)%2]);
        His.push_back(dep);
        tour = (tour + 1)%2;
            }

        //system("Pause");

    }

}

