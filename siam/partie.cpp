#include "partie.h"
#include <iostream>

Partie::Partie() {
  string name = "";
  while (name.length() <= 0) {
    CLEAR();
    cout << "----- [ Bienvenue sur le jeu de SIAM ] -----" << endl;
    cout << "Comment s'appelle le Joueur 1 (Elephants) ? ";
    cin >> name;
  }

  this->j1 = name;

  name = "";
  while (name.length() <= 0) {
    CLEAR();
    cout << "Comment s'appelle le Joueur 2 (Rhinoceros) ? ";
    cin >> name;
  }
  this->j2 = name;

  this->nbJ1 = 0;
  this->nbJ2 = 0;

  this->manager = new Manager();
  this->terminee = false;
  this->rhino = false;
}

void Partie::Commencer() {
  string s;
  for (this->tours = 0; !terminee; this->tours++) {
    this->TourSuivant();
  }
}

void Partie::TourSuivant() {
  this->rhino = !this->rhino;

  int choix = 0;

  while (choix < 1 || choix > 5) {
    CLEAR();
    this->manager->grille->Afficher();
    cout << "C'est au tour des " << (this->rhino ? "Rhinoceros" : "Elephants!")
         << " (" << (this->rhino ? j2 : j1) << ")" << endl;
    cout << "  (1)  Entrer un pion sur le terrain" << endl;
    cout << "  (2)  Se déplacer vers une case libre" << endl;
    cout << "  (3)  Faire pivoter un pion" << endl;
    cout << "  (4)  Sortir un pion" << endl;
    cout << "  (5)  Déplacer un pion et pousser" << endl;
    cout << "Que voulez vous faire >> ";
    cin >> choix;
  }
}
