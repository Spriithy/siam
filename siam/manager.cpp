#include "manager.h"
#include "direction.h"

Manager::Manager()
{

}

Manager::~Manager()
{

}

void Manager::AjouterPion()
{
    int x,y;
    char c;
    Direction d;
    cout<<"Vous avez choisi de rentrer un pion sur la grille"<<endl;
    cout<<"Indiquez les coordonnées voulues"<<endl;
    cout<<"Quelle colonne? ( 1,2,3,4 ou 5)"<<endl;
    cin>>x;
    cout<<"Quelle ligne? ( 1,2,3,4 ou 5)"<<endl;
    cin>>y;

    while ((x<0) || (x>5)|| (y<0) || (y>5) )
    {
        cout<<"les coordonnées choisies sont erronées"<<endl;
        cout<<"Vous avez choisi de rentrer un pion sur la grille"<<endl;
        cout<<"Indiquez les coordonnées voulues"<<endl;
        cout<<"Quelle colonne? ( 1,2,3,4 ou 5)"<<endl;
        cin>>x;
        cout<<"Quelle ligne? ( 1,2,3,4 ou 5)"<<endl;
        cin>>y;
    }

    if ( this->grille->estVide(x,y))
    {
        this->grille->AjouterPion(x,y);
    }
    else


    cout<<"Quelle orientation voulez vous donner à votre pion?"<<endl;
    cout<<"haut: h, bas: b, gauche: g, droite d"<<endl;
    cin>>c;

    while ( d == INVALID)
    {
        cout<<"erreur de saisis"<<endl;
        cout<<"Quelle orientation voulez vous donner à votre pion?"<<endl;
        cout<<"haut: h, bas: b, gauche: g, droite d"<<endl;
        cin>>c;
        d=convertirDirection(c);

    }






}

void
