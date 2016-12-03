#include "manager.h"
#include <iostream>
#include "direction.h"

using namespace std;

Manager::Manager() { this->grille = new Grille(); }

Manager::~Manager() {}

void Manager::ChangerJoueur(TypePion t) { this->joueur = t; }

void Manager::RafraichirAffichage() { CLEAR(); }

void Manager::AjouterPion() {
  int x, y;
  char c;
  Direction d = INVALIDE;

  CLEAR();
  this->grille->Afficher();
  cout << "Vous avez choisi de rentrer un pion sur la grille" << endl;
  cout << "Indiquez les coordonnées voulues" << endl;
  cout << "Quelle colonne ? (1-5) ";
  cin >> x;
  cout << endl << "Quelle ligne ? (1-5) ";
  cin >> y;

  while ((x < 0) || (x > 5) || (y < 0) || (y > 5)) {
    CLEAR();
    this->grille->Afficher();
    cout << endl << "les coordonnées choisies sont erronées" << endl;
    cout << "Vous avez choisi de rentrer un pion sur la grille" << endl;
    cout << "Indiquez les coordonnées voulues" << endl;
    cout << "Quelle colonne ? (1-5) ";
    cin >> x;
    cout << endl << "Quelle ligne ? (1-5) ";
    cin >> y;
  }

  CLEAR();
  this->grille->Afficher();
  cout << endl << "Quelle orientation voulez vous donner à votre pion?" << endl;
  cout << "haut: H, bas: B, gauche: G, droite: D" << endl;
  cin >> c;

  while (d == INVALIDE) {
    CLEAR();
    this->grille->Afficher();
    cout << "erreur de saisis" << endl;
    cout << "Quelle orientation voulez vous donner à votre pion?" << endl;
    cout << "haut: h, bas: b, gauche: g, droite d" << endl;
    cin >> c;
    CONVERTIR_DIRECTION(c, d);
  }

  if (this->grille->EstVide(x, y)) {
    this->grille->AjouterPion(x, y, this->joueur, d);
  } else
    ;
}

void Manager::PivoterPion() {
  int x, y;
  char c;
  Direction d = INVALIDE;

  CLEAR();
  this->grille->Afficher();
  cout << "vous avez choisi de changer la direction d'un de vos pions" << endl;
  cout << "Indiquez les coordonnées du pion concerné" << endl;
  cout << "Quelle colonne ? (1-5) ";
  cin >> x;
  cout << endl << "Quelle ligne ? (1-5) ";
  cin >> y;

  while ((x < 0) || (x > 5) || (y < 0) || (y > 5)) {
    CLEAR();
    this->grille->Afficher();
    cout << "les coordonnées choisies sont erronées" << endl;
    cout << "vous avez choisi de changer la direction d'un de vos pions"
         << endl;
    cout << "Indiquez les coordonnées voulues" << endl;
    cout << "Quelle colonne ? (1-5)" << endl;
    cin >> x;
    cout << "Quelle ligne ? (1-5)" << endl;
    cin >> y;
  }

  CLEAR();
  this->grille->Afficher();
  cout << "quelle direction voulez vous attribuer à votre pion?" << endl;
  cout << "haut: H, bas: B, gauche: G, droite D" << endl;
  cin >> c;

  while (d == INVALIDE) {
    CLEAR();
    this->grille->Afficher();
    cout << "erreur de saisie" << endl;
    cout << "Quelle orientation voulez vous donner à votre pion ?" << endl;
    cout << "haut: H, bas: B, gauche: G, droite D" << endl;
    cin >> c;
    CONVERTIR_DIRECTION(c, d);
  }
}

void Manager::RetirerPion() {
  int x, y;

  CLEAR();
  this->grille->Afficher();
  cout << "vous avez choisi d'enlever un pion de la grille" << endl;
  cout << "Quelles sont ses coordonnées?" << endl;
  cout << "Quelle colonne ? (1-5) " << endl;
  cin >> x;
  cout << "Quelle ligne ? (1-5) " << endl;
  cin >> y;

  while ((x < 0) || (x > 5) || (y < 0) || (y > 5)) {
    CLEAR();
    this->grille->Afficher();
    cout << "les coordonnées choisies sont erronées" << endl;
    cout << "vous avez choisi d'enlever un pion de la grille" << endl;
    cout << "Indiquez les coordonnées voulues" << endl;
    cout << "Quelle colonne ? (1-5)" << endl;
    cin >> x;
    cout << "Quelle ligne ? (1-5)" << endl;
    cin >> y;
  }
}
