#include "manager.h"
#include <iostream>
#include "direction.h"

using namespace std;

Manager::Manager() { this->grille = new Grille(); }

Manager::~Manager() {}

void Manager::ChangerJoueur(TypePion t) { this->joueur = t; }

void Manager::RafraichirAffichage() {
  CLEAR();
  this->grille->Afficher();
}

void Manager::AjouterPion() {
  int x, y;
  char c;
  Direction d = INVALIDE;

  RafraichirAffichage();
  cout << "Vous avez choisi de rentrer un pion sur la grille" << endl;
  cout << "Indiquez les coordonnées voulues" << endl;
  cout << "Quelle colonne ? (1-5) ";
  cin >> x;
  cout << endl << "Quelle ligne ? (1-5) ";
  cin >> y;

  while ((x < 0) || (x > 5) || (y < 0) || (y > 5)) {
    RafraichirAffichage();
    cout << endl << "les coordonnées choisies sont erronées" << endl;
    cout << "Vous avez choisi de rentrer un pion sur la grille" << endl;
    cout << "Indiquez les coordonnées voulues" << endl;
    cout << "Quelle colonne ? (1-5) ";
    cin >> x;
    cout << endl << "Quelle ligne ? (1-5) ";
    cin >> y;
  }

  RafraichirAffichage();
  cout << endl << "Quelle orientation voulez vous donner à votre pion?" << endl;
  cout << "haut: H, bas: B, gauche: G, droite: D" << endl;
  cin >> c;

  while (d == INVALIDE) {
    RafraichirAffichage();
    cout << "erreur de saisis" << endl;
    cout << "Quelle orientation voulez vous donner à votre pion?" << endl;
    cout << "haut: h, bas: b, gauche: g, droite d" << endl;
    cin >> c;
    CONVERTIR_DIRECTION(c, d);
  }

  if (grille->EstVide(x, y)) {
    grille->AjouterPion(x, y, joueur, d);
  } else
    ;
}

void Manager::PivoterPion() {
  int x, y;
  char c;
  Direction d = INVALIDE;

  RafraichirAffichage();
  cout << "vous avez choisi de changer la direction d'un de vos pions" << endl;
  cout << "Indiquez les coordonnées du pion concerné" << endl;
  cout << "Quelle colonne ? (1-5) ";
  cin >> x;
  cout << endl << "Quelle ligne ? (1-5) ";
  cin >> y;

  while ((x < 0) || (x > 5) || (y < 0) || (y > 5)) {
    RafraichirAffichage();
    cout << "les coordonnées choisies sont erronées" << endl;
    cout << "vous avez choisi de changer la direction d'un de vos pions"
         << endl;
    cout << "Indiquez les coordonnées voulues" << endl;
    cout << "Quelle colonne ? (1-5)" << endl;
    cin >> x;
    cout << "Quelle ligne ? (1-5)" << endl;
    cin >> y;
  }

  RafraichirAffichage();
  cout << "quelle direction voulez vous attribuer à votre pion?" << endl;
  cout << "haut: H, bas: B, gauche: G, droite D" << endl;
  cin >> c;

  while (d == INVALIDE) {
    RafraichirAffichage();
    cout << "erreur de saisie" << endl;
    cout << "Quelle orientation voulez vous donner à votre pion ?" << endl;
    cout << "haut: H, bas: B, gauche: G, droite D" << endl;
    cin >> c;
    CONVERTIR_DIRECTION(c, d);
  }
}

void Manager::RetirerPion() {
  int x, y;

  RafraichirAffichage();
  cout << "vous avez choisi d'enlever un pion de la grille" << endl;
  cout << "Quelles sont ses coordonnées?" << endl;
  cout << "Quelle colonne ? (1-5) " << endl;
  cin >> x;
  cout << "Quelle ligne ? (1-5) " << endl;
  cin >> y;

  while ((x < 0) || (x > 5) || (y < 0) || (y > 5)) {
    RafraichirAffichage();
    cout << "les coordonnées choisies sont erronées" << endl;
    cout << "vous avez choisi d'enlever un pion de la grille" << endl;
    cout << "Indiquez les coordonnées voulues" << endl;
    cout << "Quelle colonne ? (1-5)" << endl;
    cin >> x;
    cout << "Quelle ligne ? (1-5)" << endl;
    cin >> y;
  }
}

void Manager::DeplacerCaseLibre() {
  int x, y;
  char c;
  Direction d = INVALIDE;

  RafraichirAffichage();
  cout << "vous avez choisi de deplacer votre pion vers une case libre" << endl;
  cout << "Indiquez les coordonnées de votre pion" << endl;
  cout << "Quelle colonne ? (1-5)" << endl;
  cin >> x;
  cout << "Quelle ligne ? (1-5)" << endl;
  cin >> y;

  RafraichirAffichage();
  cout << "dans quelle direction voulez vous aller?" << endl;
  cout << "haut: H, bas: B, gauche: G, droite D" << endl;
  cin >> c;
  CONVERTIR_DIRECTION(c, d);

  if (d == HAUT) {
    while (grille->EstVide(x, y - 1) != VIDE) {
      cout << "la case choisi n'est pas vide" << endl;
      cout << "Indiquez les coordonnées de votre pion" << endl;
      cout << "Quelle colonne ? (1-5)" << endl;
      cin >> x;
      cout << "Quelle ligne ? (1-5)" << endl;
      cin >> y;

      cout << "dans quelle direction voulez vous aller?" << endl;
      cout << "haut: H, bas: B, gauche: G, droite D" << endl;
      cin >> c;
      CONVERTIR_DIRECTION(c, d);
    }
  } else
    grille->Deplacer(x, y, x, y - 1);

  if (d == BAS) {
    while (grille->EstVide(x, y + 1) != VIDE) {
      RafraichirAffichage();
      cout << "la case choisi n'est pas vide" << endl;
      cout << "Indiquez les coordonnées de votre pion" << endl;
      cout << "Quelle colonne ? (1-5)" << endl;
      cin >> x;
      cout << "Quelle ligne ? (1-5)" << endl;
      cin >> y;

      RafraichirAffichage();
      cout << "dans quelle direction voulez vous aller?" << endl;
      cout << "haut: H, bas: B, gauche: G, droite D" << endl;
      cin >> c;
      CONVERTIR_DIRECTION(c, d);
    }
  } else
    grille->Deplacer(x, y, x, y + 1);

  if (d == DROITE) {
    while (grille->EstVide(x + 1, y) != VIDE) {
      RafraichirAffichage();
      cout << "la case choisi n'est pas vide" << endl;
      cout << "Indiquez les coordonnées de votre pion" << endl;
      cout << "Quelle colonne ? (1-5)" << endl;
      cin >> x;
      cout << "Quelle ligne ? (1-5)" << endl;
      cin >> y;

      RafraichirAffichage();
      cout << "dans quelle direction voulez vous aller?" << endl;
      cout << "haut: H, bas: B, gauche: G, droite D" << endl;
      cin >> c;
      CONVERTIR_DIRECTION(c, d);
    }
  } else
    grille->Deplacer(x, y, x + 1, y);

  if (d == DROITE) {
    if (grille->EstVide(x - 1, y) != VIDE) {
      RafraichirAffichage();
      cout << "la case choisi n'est pas vide" << endl;
      cout << "Indiquez les coordonnées de votre pion" << endl;
      cout << "Quelle colonne ? (1-5)" << endl;
      cin >> x;
      cout << "Quelle ligne ? (1-5)" << endl;
      cin >> y;

      RafraichirAffichage();
      cout << "dans quelle direction voulez vous aller?" << endl;
      cout << "haut: H, bas: B, gauche: G, droite D" << endl;
      cin >> c;
      CONVERTIR_DIRECTION(c, d);
    }
  } else
    grille->Deplacer(x, y, x - 1, y);
}

void PousserPion() {}
