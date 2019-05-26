#ifndef HOMME_H
#define HOMME_H

#include "Joueur.h"





class Homme : public Joueur
{
    public:
        Homme();
        Homme(string n ,string c,string e,int t,Piece **);
        Homme( Homme& h);
        Homme(string  n,string c,string e);
        Homme(string n,string c) ;
        virtual ~Homme();
        Deplacement jouer(Echiquier &ech,Joueur &j_adv);

    protected:

    private:
};

#endif // HOMME_H
