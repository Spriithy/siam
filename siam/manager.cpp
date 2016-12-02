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
    Direction d= INVALIDE;
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


    cout<<"Quelle orientation voulez vous donner à votre pion?"<<endl;
    cout<<"haut: h, bas: b, gauche: g, droite d"<<endl;
    cin>>c;

    while ( d == INVALIDE)
    {
        cout<<"erreur de saisis"<<endl;
        cout<<"Quelle orientation voulez vous donner à votre pion?"<<endl;
        cout<<"haut: h, bas: b, gauche: g, droite d"<<endl;
        cin>>c;
        d=convertirDirection(c);

    }

    if ( this->grille->estVide(x,y))
    {
        this->grille->ajouterPion(x,y,this->joueur);
    }
    else




}

void PivoterPion()
{
    int x,y;
    char c;
    Direction d=INVALIDE;
    cout<<"vous avez choisi de changer la direction d'un de vos pions"<<endl;
    cout<<"quelles sont les coordonnées de ce pion?"<<endl;
    cout<<"quelle est la colonne? ( 1,2,3,4 ou 5)"<<endl;
    cin>>x;
    cout<<"quelle est la ligne? ( 1,2,3,4 ou 5)"<<endl;
    cin>>y;

    while ((x<0) || (x>5)|| (y<0) || (y>5) )
    {
        cout<<"les coordonnées choisies sont erronées"<<endl;
        cout<<"vous avez choisi de changer la direction d'un de vos pions"<<endl;
        cout<<"Indiquez les coordonnées voulues"<<endl;
        cout<<"Quelle colonne? ( 1,2,3,4 ou 5)"<<endl;
        cin>>x;
        cout<<"Quelle ligne? ( 1,2,3,4 ou 5)"<<endl;
        cin>>y;
    }

    cout<<"quelle direction voulez vous attribuer à votre pion?"<<endl;
    cout<<"haut: h, bas: b, gauche: g, droite d"<<endl;
    cin>>c;

    while ( d == INVALIDE)
    {
        cout<<"erreur de saisis"<<endl;
        cout<<"Quelle orientation voulez vous donner à votre pion?"<<endl;
        cout<<"haut: h, bas: b, gauche: g, droite d"<<endl;
        cin>>c;
        d=convertirDirection(c);

    }




}

void RetirerPion()
{
    int x,y;
    cout<<"vous avez choisi d'enlever un pion de la grille"<<endl;
    cout<<"Quelles sont ses coordonnées?"<<endl;
    cout<<"Quelle colonne? ( 1,2,3,4 ou 5)"<<endl;
    cin>>x;
    cout<<"Quelle ligne? ( 1,2,3,4 ou 5)"<<endl;
    cin>>y;

    while ((x<0) || (x>5)|| (y<0) || (y>5) )
    {
        cout<<"les coordonnées choisies sont erronées"<<endl;
        cout<<"vous avez choisi d'enlever un pion de la grille"<<endl;
        cout<<"Indiquez les coordonnées voulues"<<endl;
        cout<<"Quelle colonne? ( 1,2,3,4 ou 5)"<<endl;
        cin>>x;
        cout<<"Quelle ligne? ( 1,2,3,4 ou 5)"<<endl;
        cin>>y;
    }

    while ( grille-> )

    this->grille->RetirerPion(x,y);



}











