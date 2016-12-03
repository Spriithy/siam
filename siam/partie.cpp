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
}

void Partie::Commencer() {
  for (this->tours = 0; !terminee; this->tours++) {
    this->TourSuivant();
  }
}

void Partie::TourSuivant() {
  CLEAR();
  this->manager->grille->Afficher();
}
