#ifndef MACHINE_INTEL_H
#define MACHINE_INTEL_H

#include "Machine.h"
#include <string>
#include <ctime>

using namespace std;
class Machine_intel : public Machine
{
    public:

                Machine_intel();
        Machine_intel(string c);
        Deplacement jouer(Echiquier &ech,Joueur &j_adv);
        virtual ~Machine_intel();


};

#endif // MACHINE_INTEL_H
