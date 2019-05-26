#ifndef HISTORIQUE_H_INCLUDED
#define HISTORIQUE_H_INCLUDED
using namespace std ;
#include"Deplacement.h"

class Historique
{
private:
    Deplacement* *liste_dep;
    int sommet;
public:
    Historique ();
    ~Historique ();
    void empiler(Deplacement dep);
    Deplacement depiler();
    int get_sommet();



};


#endif // HISTORIQUE_H_INCLUDED
