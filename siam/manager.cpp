#include "manager.h"
#include <iostream>
#include "direction.h"

using namespace std;

Manager::Manager() {
  grille = new Grille();
  joueur = RHINOCEROS;
}

Manager::~Manager() {}

void Manager::ChangerJoueur(bool rhino) {
  if (rhino)
    joueur = RHINOCEROS;
  else
    joueur = ELEPHANT;
}

void Manager::RafraichirAffichage() {
  CLEAR();
  grille->Afficher();
}

void Manager::AjouterPion() {
  int x, y;
  int c;
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
  cout << "haut: 1, bas: 2, gauche: 3, droite: 4" << endl;
  cin >> c;
  CONVERTIR_DIRECTION(c, d);

  while (d == INVALIDE) {
    RafraichirAffichage();
    cout << "erreur de saisie" << endl;
    cout << "Quelle orientation voulez vous donner à votre pion?" << endl;
    cout << "haut: 1, bas: 2, gauche: 3, droite: 4" << endl;
    cin >> c;
    CONVERTIR_DIRECTION(c, d);
  }

  if (grille->EstVide(x - 1, y - 1)) {
    grille->AjouterPion(x - 1, y - 1, joueur, d);
    cout << "Le Pion a bien été ajouté!" << endl;
  } else {
    cout << "La case choisie n'est pas vide, ou pas en bordure!" << endl;
    AjouterPion();
  }
}

void Manager::PivoterPion() {
  int x, y;
  int c;
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
  cout << "haut: 1, bas: 2, gauche: 3, droite: 4" << endl;
  cin >> c;
  CONVERTIR_DIRECTION(c, d);

  while (d == INVALIDE) {
    RafraichirAffichage();
    cout << "erreur de saisie" << endl;
    cout << "Quelle orientation voulez vous donner à votre pion ?" << endl;
    cout << "haut: 1, bas: 2, gauche: 3, droite: 4" << endl;
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

void Manager::DeplacerCaseLibre(string message) {
  int x, y;
  int c;
  Direction d = INVALIDE;

  RafraichirAffichage();
  if (message.length() > 0) cout << message << endl;
  cout << "vous avez choisi de deplacer votre pion vers une case libre" << endl;
  cout << "Indiquez les coordonnées de votre pion" << endl;
  cout << "Quelle colonne ? (1-5) ";
  cin >> x;
  cout << "Quelle ligne ? (1-5) ";
  cin >> y;

  if ((x < 1) || (x > 5) || (y < 1) || (y > 5)) {
    DeplacerCaseLibre("Coordonnées invalides!");
    return;
  }

  if (!grille->EstDeType(x - 1, y - 1, joueur)) {
    DeplacerCaseLibre("Ce n'est pas votre pion!");
    return;
  }

  string p = "";
  while (p != "o" || p != "n") {
    cout << "Voulez vous pivoter ? (o/n) ";
    cin >> p;
  }

  if (p == "o") {
    RafraichirAffichage();
    cout << "Dans quelle direction voulez vous pivoter?" << endl;
    cout << "haut: 1, bas: 2, gauche: 3, droite: 4" << endl;
    cin >> c;
    CONVERTIR_DIRECTION(c, d);

    switch (d) {
      case INVALIDE:
        DeplacerCaseLibre("Direction de pivot inconnue!");
        return;
      default:
        grille->PivoterPion(x - 1, y - 1, d);
    }
  }

  RafraichirAffichage();
  cout << "Dans quelle direction voulez vous aller?" << endl;
  cout << "haut: 1, bas: 2, gauche: 3, droite: 4" << endl;
  cin >> c;
  CONVERTIR_DIRECTION(c, d);

  switch (d) {
    case HAUT:
      if (y == 1) DeplacerCaseLibre("Ce pion ne peut pas monter!");
      if (grille->EstVide(x - 1, y - 2))
        grille->Deplacer(x - 1, y - 1, x - 1, y - 2);
      else
        DeplacerCaseLibre("La case du dessus n'est pas libre!");
      return;
    case BAS:
      if (y == 5) DeplacerCaseLibre("Ce pion ne peut pas décendre!");
      if (grille->EstVide(x - 1, y))
        grille->Deplacer(x - 1, y - 1, x - 1, y);
      else
        DeplacerCaseLibre("La case du dessous n'est pas libre!");
      return;
    case GAUCHE:
      if (x == 1) DeplacerCaseLibre("Ce pion ne peut pas aller a gauche!");
      if (grille->EstVide(x - 2, y - 1))
        grille->Deplacer(x - 1, y - 1, x - 2, y - 1);
      else
        DeplacerCaseLibre("La case a gauche n'est pas libre!");
      return;
    case DROITE:
      if (x == 5) DeplacerCaseLibre("Ce pion ne peut pas aller a droite!");
      if (grille->EstVide(x, y - 1))
        grille->Deplacer(x - 1, y - 1, x, y - 1);
      else
        DeplacerCaseLibre("La case a droite n'est pas libre!");
      return;
    default:
      DeplacerCaseLibre("Direction inconnue!");
  }
}

void Manager::PousserPion() {}
