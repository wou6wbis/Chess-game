#include"Echiquier.h"

Echiquier::Echiquier(Piece* lpb[],int tb,Piece* lpn[],int tn)
{

    int i,j;
    for(int i=0; i<8; i++)
    {
         for(int j=0; j<8; j++)
        {
            ech[j][i].Setcouleur(((i+j)% 2 == 0 )? "noir" : "blanc") ;
        }

    }

    for(int k=0; k<tb; k++)
    {

        i = lpb[k]->Getpos().Getx();
        j = lpb[k]->Getpos().Gety();
        ech[i][j].Set_piece(lpb[k]);

    }
    for(int k=0; k<tn; k++)
    {

        i = lpn[k]->Getpos().Getx();
        j = lpn[k]->Getpos().Gety();
        ech[i][j].Set_piece(lpn[k]);

    }


}



Echiquier::~Echiquier()
{

}

void Echiquier::afficher()
{


    cout<<endl<<endl<<"\t\t\t\t";
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
            cout<<"######";
        cout<<"#"<<endl<<"\t\t\t\t";
        for(int j=0; j<8; j++)
            cout<<"#     ";
        cout<<"#"<<endl<<"\t\t\t\t";
        for(int j=0; j<8; j++)
        {
            cout<<"#";
            if(ech[j][i].Get_piece() != NULL)
            cout <<ech[j][i].Get_piece()->Getsymbole();
            else
                cout <<"     ";

        }
        cout<<"#     "<<8-i<<endl<<"\t\t\t\t";
        for(int j=0; j<8; j++)
            cout<<"#     ";
        cout<<"#"<<endl<<"\t\t\t\t";

    }
    for(int j=0; j<8; j++)
            cout<<"######";
        cout<<"#"<<endl<<"\t\t\t\t";
    cout <<endl;
    cout <<endl<<"\t\t\t\t";
    for(int j=0; j<8; j++)
            cout<<"   "<<(char)('a'+j)<<"  ";
            cout <<endl;
            cout <<endl<<"\t\t\t\t";
}

/*
void Echiquier::afficher()
{

    system("mode 140,80");
    system("color 80");

    cout<<endl<<endl<<endl<<endl;

    string *sym[7];
    sym[0] =new string("           ");
    sym[1] =new string("     *     ");
    sym[2] =new string("    ***    ");
    sym[3] =new string("     *     ");
    sym[4] =new string("    ***    ");
    sym[5] =new string("  *******  ");
    sym[6] =new string("           ");

    for(int i=0; i<8; i++)
    {
       // for(int j=0; j<6; j++)
        {
            for(int k=0; k<8; k++)
            {


                if(ech[k][i].Getcouleur() == "blanc")
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),((k + (i%2))%2 == 0 ? 79 : 127));
                else
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),((k + (i%2))%2 == 0 ? 64 : 112));
                if(ech[k][i].Get_piece() != 0)
                {
                    for(int h=0;h<11;h++);
                    cout <<sym[h];

                }
                else
                    cout <<"            ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),136);

            }
            cout <<endl;
        }
    }


        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),128);
        gotoxy(100,4);
        printf("tour de : %s   ",partie.joueurs[partie.couleur_courant].nom);
        gotoxy(100,6);
        printf("couleur : %s   ",partie.couleur_courant == 0 ? "blanche" : "noir");
        gotoxy(100,8);
        printf("score est : %d ",joueur_actuel_partie(partie).score);
        gotoxy(100,10);
        printf("type de joueur : %s   ",partie.joueurs[partie.couleur_courant].mode == 0 ? "homme" : "machine");
        gotoxy(100,18);
        printf("historiqure de deplacement:  ");
        j=0;
        for(i=0;i<partie.taille_liste;i++)
        {
            if(i%4 == 0)
                j++;
        gotoxy(100 + (i%4)*8 ,20+j);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),(i%2 == 0 ? 143 : 128));
        printf("%c%d %c%d",partie.liste_deplacements[i].pos_initiale.y + 97,8 - partie.liste_deplacements[i].pos_initiale.x,
               partie.liste_deplacements[i].pos_finale.y+  97,8 - partie.liste_deplacements[i].pos_finale.x);
        }





}
*/

/*
Position* Echiquier::Get_liste_pos()
{
    Position lp[taille];
    for(int i=0; i<taille; i++)
    {
        lp[i].Setx(liste_piece[i]->Getpos().Getx());
        lp[i].Sety(liste_piece[i]->Getpos().Gety());
    }
    return lp;
}

bool Echiquier::m_a_j(Deplacement &dep)
{
    int ind=0;
    bool stop = false;
    while(ind<taille && !stop)
    {
        if(Get_piece(ind)->Getpos() == dep.Getpos_i())
            stop = true;
        else
            ind++;
    }

    if(stop == true)
    {


        int xi = dep.Getpos_i().Getx(),yi = dep.Getpos_i().Gety(),xf = dep.Getpos_f().Getx(),yf = dep.Getpos_f().Gety();

        if(Set_piece(ind,dep.Getpos_f()))
        {
            Set_case(xi,yi,0);
            Set_case(xf,yf,Get_piece(ind));
            return true;
        }
        else
            return false;

    }
    else
        return false;



}

void Echiquier::m_a_j_ech()
{
    int i,j;

    for(int k=0; k<32; k++)
    {

        i = liste_piece[k]->Getpos().Getx();
        j = liste_piece[k]->Getpos().Gety();
        ech[i][j].Set_piece(liste_piece[k]);

    }
}
*/
