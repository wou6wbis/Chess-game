#include "Joueur.h"

Joueur::Joueur() : nom("") , couleur("") , etat("")
{
    taille = 16;
    liste_pieces = new Piece*[taille];
    initialiser_pieces();

}

Joueur::Joueur(string n = "",string c="",string e= "",int t = 0,Piece **lp = 0) : nom(n) , couleur(c) , etat(e),taille(t)
{
    if(t > 0)
        liste_pieces = lp;
}
Joueur::Joueur(string n = "",string c="",string e= "") : nom(n) , couleur(c) , etat(e)
{

    initialiser_pieces();

}
string Joueur::m_a_j_etat(const Joueur& j_adv)
{
    int i=0;
    while(i<taille)
    {
        if(liste_pieces[i] != 0 && liste_pieces[i]->Getnom() == "Roi")
        {
            break;
        }
        else
            i++;
    }
    if(i>= taille)
        return "perdu";
    return "normal";
}

Joueur::Joueur(const Joueur& j) : nom(j.nom) , couleur(j.couleur) , etat(j.etat), taille(j.taille)
{

    if(j.taille>0)

    {

        liste_pieces = j.liste_pieces;
    }


}
Joueur::~Joueur()
{
    //dtor
}
void Joueur::afficher() const
{
    cout << "info sur le joueur : "<<endl;
    cout << nom <<endl;
    cout << couleur << endl;
    cout << etat << endl;
    cout << taille <<endl;
    cout << " liste de pieces  : "<<endl;
        for(int i=0;i<taille;i++)
            if(liste_pieces[i] != 0)
                liste_pieces[i]->afficher();
}

void Joueur::saisir(Deplacement &dep)
{
    char d[5];
    cout << "saisir le deplacement :"<<endl;
    cin >> d;
    Position pos_i,pos_f;
    pos_i.Setx(d[0] - 97);
    pos_i.Sety( 8 - (d[1] - 48));
    pos_f.Setx(d[2] - 97);
    pos_f.Sety( 8 - (d[3] - 48));
    dep.Setpos_i(pos_i);
    dep.Setpos_f(pos_f);

}



void Joueur::initialiser_pieces()
{

    Position pos;
    liste_pieces = new Piece*[16];
    taille = 16;
    if(couleur == "blanc")
    {
         for(int i=0; i<8; i++)
    {
        Position pos(i,6);

        liste_pieces[i]= new Pion(pos,couleur);
    }
    pos.Setx(7);
    pos.Sety(7);
    liste_pieces[8] =  new Tour (pos,couleur);
    pos.Setx(0);
    pos.Sety(7);
    liste_pieces[9] = new Tour (pos,couleur);

    pos.Setx(1);
    pos.Sety(7);
    liste_pieces[10] = new Cavalier (pos,couleur);
    pos.Setx(6);
    pos.Sety(7);
    liste_pieces[11] = new Cavalier (pos,couleur);

    pos.Setx(2);
    pos.Sety(7);
    liste_pieces[12] = new Fou (pos,couleur);
    pos.Setx(5);
    pos.Sety(7);
    liste_pieces[13] = new Fou(pos,couleur);
    pos.Setx(3);
    pos.Sety(7);
    liste_pieces[14] = new Reine (pos,couleur);
    pos.Setx(4);
    pos.Sety(7);
    liste_pieces[15] = new Roi (pos,couleur);
    }
    else
    {
         for(int i=0; i<8; i++)
    {
        Position pos(i,1);

        liste_pieces[i]= new Pion(pos,couleur);
    }
    pos.Setx(0);
    pos.Sety(0);
    liste_pieces[8] =  new Tour (pos,couleur);
    pos.Setx(7);
    pos.Sety(0);
    liste_pieces[9] = new Tour (pos,couleur);

    pos.Setx(1);
    pos.Sety(0);
    liste_pieces[10] = new Cavalier (pos,couleur);
    pos.Setx(6);
    pos.Sety(0);
    liste_pieces[11] = new Cavalier (pos,couleur);

    pos.Setx(2);
    pos.Sety(0);
    liste_pieces[12] = new Fou (pos,couleur);
    pos.Setx(5);
    pos.Sety(0);
    liste_pieces[13] = new Fou(pos,couleur);
    pos.Setx(3);
    pos.Sety(0);
    liste_pieces[14] = new Reine (pos,couleur);
    pos.Setx(4);
    pos.Sety(0);
    liste_pieces[15] = new Roi (pos,couleur);
    }




}
void Joueur::set_liste_pieces(Piece *lp[],int n)
{
    if(n>0)
    {
        delete[] liste_pieces;
        liste_pieces = new Piece*[n];
        for(int i=0; i<n; i++)
            liste_pieces[i] = lp[i];
    }

}
/*
void delete_piece(int ind)
{
    for(int i=ind+1;i< taille;i++)
    {
        string nom = liste_pieces[i];
        switch(nom)
        {
        case "Pion" :
            liste_pieces[i-1]
        }
    }

}
*/
