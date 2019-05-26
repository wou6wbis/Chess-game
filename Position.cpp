#include "Position.h"

using namespace std;
Position::Position(int _x , int _y) : x(_x) , y(_y)
{

}
Position::Position():x(0),y(0)
{

}
Position::Position(const Position &p):x(p.x),y(p.y)
{

}

Position::~Position()
{

}
void Position::saisir()
{
    int _x,_y;
    cout <<"x :";
    cin >>_x;
    cout <<"y :";
    cin >>_y;
    Setx(_x);
    Sety(_y);
}
void Position::afficher() const
{
    cout << "x : "<< x<< endl;
    cout << "y : "<< y<<endl;
}

bool Position::operator==(const Position &p)
{
    if(p.x == x && p.y == y)
        return true;
    return false;
}
int Position::chercher(Position lp[],int n)const
{
    for(int i=0;i<n;i++)
        if(lp[i] == *this)
            return i;
    return -1;
}




bool Position::dans_echiquier()const
{
    if(x >=0 && x<=7 && y >=0 && y<=7)
        return true;
    return false;
}
