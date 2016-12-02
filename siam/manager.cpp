#include "manager.h"

Manager::Manager()
{

}

void Pion() {
int x,y;
cout<<"Vous avez choisi de rentrer un pion sur la grille"<<endl;
cout<<"Indiquez les coordonnées voulues"<<endl;
cout<<"Quelle colonne? ( 1,2,3,4 ou 5)"<<endl;
cin>>x;
cout<<"Quelle ligne? ( 1,2,3,4 ou 5)"<<endl;
cin>>y;

if ((x<0) || (x>5)|| (y<0) || (y>5) )
{
    cout<<"les coordonnées choisies sont erronées"<<endl;
}

else

}
