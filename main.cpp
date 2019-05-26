#include "Case.h"

#include "Deplacement.h"
#include "Echiquier.h"
#include "Piece.h"
#include "Pion.h"
#include "Cavalier.h"
#include "Joueur.h"
#include "partie.h"
#include "Machine_bete.h"
#include "Machine_intel.h"
#include "Machine_intelpp.h"

#include <iostream>
#include <time.h>
#include <vector>
using namespace std ;


int main()
{
    Position pos(0,5);
    Pion p(pos,"blanc");
    pos.Setx(2);
    Pion *p1 = new Pion(pos,"noir");

    Piece **lpb= new Piece*[1],**lpn = new Piece*[1];
    lpb[0] = &p;
    lpn[0] = p1;

Homme yas("yas","blanc","echec_emat");
Homme kha("khayri","noir","normal");
Machine_bete mb1("blanc");
Machine_bete mb2("noir");
Machine_intel m2("noir");
Machine_intelpp mpp2("noir");
/*
Deplacement dep;
dep.saisir();
dep.afficher();
*/
Partie partie1(mb1,mpp2);
partie1.lancer();


return 0;
}
