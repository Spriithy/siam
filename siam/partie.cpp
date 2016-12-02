#include "partie.h"
#include <iostream>
#include <string>
#include "grille.h"
#include "manager.h"

Partie::Partie() {
  string name = "";
  while (strlen(name) <= 0) {
    CLEAR();
    cout << "----- [ Bienvenue sur le jeu de SIAM ] -----" << endl;
    cout << "Comment s'appelle le Joueur 1 (Elephants) ? ";
    cin >> name;
  }
  this->j1 = name;
  name = "";
  while (strlen(name) <= 0) {
    CLEAR();
    cout << "Comment s'appelle le Joueur 2 (Rhinoceros) ? ";
    cin >> name;
  }
  this->j2 = name;

  this->nbJ1 = 0;
  this->nbJ2 = 0;

  this->manager = new Manager();
}
