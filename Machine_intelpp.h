#ifndef MACHINE_INTELPP_H
#define MACHINE_INTELPP_H

#include "Machine.h"
#include <ctime>
#include <vector>


class Machine_intelpp : public Machine
{
    public:
        Machine_intelpp();
        Machine_intelpp(string c);
        Deplacement jouer(Echiquier &ech,Joueur &j_adv);
        virtual ~Machine_intelpp();

    protected:

    private:
};

#endif // MACHINE_INTELPP_H
