#include "Deplacement.h"

Deplacement::Deplacement()
{

   pos_i.Setx(0);
   pos_i.Sety(0);
   pos_f.Setx(0);
   pos_f.Sety(0);

}
Deplacement::Deplacement(const Deplacement& dep) : pos_i(dep.pos_i), pos_f(dep.pos_f)
{

}

Deplacement::Deplacement(Position pi , Position pf)
{
    pos_i=pi;
    pos_f=pf;
}

Deplacement::~Deplacement()
{

}
/*
void Deplacement::operator=(Deplacement & dep)
{

}*/
void Deplacement::saisir()
{
    char d[5];
    cout << "saisir le deplacement :"<<endl;
    cin >> d;
    pos_i.Setx(d[0] - 97);
    pos_i.Sety(8 - (d[1] - 48));
    pos_f.Setx(d[2] - 97);
    pos_f.Sety(8 - (d[3] - 48));

}
void Deplacement::afficher()
{
   char d[5];
    d[0] = (char)(pos_i.Getx( ) + 97);
    d[1] = 8-pos_i.Gety() + 48 ;
    d[2] = pos_f.Getx()+  97;
    d[3] = 8-pos_f.Gety() + 48 ;
    cout<< d<<"\t";
}
