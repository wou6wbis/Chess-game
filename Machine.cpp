#include "Machine.h"

Machine::Machine() : niveau(0)
{
    //ctor
}

Machine::Machine(string c,string e,int niv) :Joueur("Machine",c,e), niveau(niv)
{

}
Machine::Machine(string c,int n) : Joueur("Machine",c,"normal"), niveau(n)
{

}
Machine::Machine(const Machine& m) : Joueur(m), niveau(m.niveau)
{

}
Machine::~Machine()
{
    //dtor
}

void Machine::afficher() const
{
    cout << "info sur le joueur : "<<endl;
    cout << nom <<endl;
    cout << couleur << endl;
    cout << etat << endl;
    cout << " liste de pieces  : "<<endl;
    for(int i=0; i<taille; i++)
        if(liste_pieces[i] != 0)
            liste_pieces[i]->afficher();
    cout << endl<<niveau << endl;
}

