#ifndef MACHINE_H
#define MACHINE_H

#include "Joueur.h"


class Machine : public Joueur
{
    public:
        Machine();
        Machine(string c,string e,int niv);
        Machine(string c,int n);
        Machine(const Machine& m);
        virtual ~Machine();

        int Getniveau() { return niveau; }
        void Setniveau(int val) { niveau = val; }
        void afficher() const;
        virtual Deplacement jouer(Echiquier &ech,Joueur & j_adv) = 0;
        int niveau;


};

#endif // MACHINE_H
