#ifndef MACHINE_BETE_H
#define MACHINE_BETE_H

#include "Machine.h"
#include <ctime>


class Machine_bete : public Machine
{
    public:
        Machine_bete();
        Machine_bete(string c);
        Deplacement jouer(Echiquier &ech,Joueur &j_adv);
        virtual ~Machine_bete();



    protected:

    private:
};

#endif // MACHINE_BETE_H
