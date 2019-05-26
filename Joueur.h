#ifndef JOUEUR_H
#define JOUEUR_H
#include "Deplacement.h"
#include "Echiquier.h"
#include "Pion.h"
#include "Cavalier.h"
#include "Tour.h"
#include "Fou.h"
#include "Reine.h"
#include "Roi.h"

#include <iostream>

using namespace std;
class Joueur
{
public:
    Joueur();
    Joueur(string,string,string,int,Piece **lp) ;
    Joueur(const Joueur& j);
    Joueur(string n ,string c,string e);
    virtual ~Joueur();

    string Getnom()
    {
        return nom;
    }
    void Setnom(string val)
    {
        nom = val;
    }
    string Getcouleur()
    {
        return couleur;
    }
    void Setcouleur(string val)
    {
        couleur = val;
    }
    string Getetat()
    {
        return etat;
    }
    void Setetat(string val)
    {
        etat = val;
    }
    virtual void afficher() const;
    void saisir(Deplacement &dep);
    virtual Deplacement jouer(Echiquier &ech,Joueur &j_adv) = 0;
    void set_liste_pieces(Piece *lp[],int n);
    void initialiser_pieces(string c);
    int GetTaille(){return taille;}
    Piece** get_liste_pieces(){return liste_pieces;}
    void initialiser_pieces();
    string m_a_j_etat(const Joueur& j_adv);

protected:
    string nom;
    string couleur;
    string etat;
    Piece **liste_pieces;
    int taille;

private:
};

#endif // JOUEUR_H
