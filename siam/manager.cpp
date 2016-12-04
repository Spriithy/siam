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
  cout << "Indiquez les coordonnees voulues" << endl;
  cout << "Quelle colonne ? (1-5) ";
  cin >> x;
  cout << endl << "Quelle ligne ? (1-5) ";
  cin >> y;

  while ((x < 1) || (x > 5) || (y < 1) || (y > 5)) {
    RafraichirAffichage();
    cout << endl << "les coordonnees choisies sont erronees" << endl;
    cout << "Vous avez choisi de rentrer un pion sur la grille" << endl;
    cout << "Indiquez les coordonnees voulues" << endl;
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
  cout << "Indiquez les coordonnees du pion concerner" << endl;
  cout << "Quelle colonne ? (1-5) ";
  cin >> x;
  cout << endl << "Quelle ligne ? (1-5) ";
  cin >> y;

  while ((x < 0) || (x > 5) || (y < 0) || (y > 5)) {
    RafraichirAffichage();
    cout << "les coordonnees choisies sont erronees" << endl;
    cout << "vous avez choisi de changer la direction d'un de vos pions"
         << endl;
    cout << "Indiquez les coordonnees voulues" << endl;
    cout << "Quelle colonne ? (1-5) ";
    cin >> x;
    cout << "Quelle ligne ? (1-5) ";
    cin >> y;
  }

  RafraichirAffichage();
  cout << "quelle direction voulez vous attribuer à votre pion ?" << endl;
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

  grille->PivoterPion(x - 1, y - 1, d);
}

void Manager::RetirerPion(string message) {
  int x, y;

  RafraichirAffichage();
  if (message.length()) cout << message << endl;
  cout << "vous avez choisi d'enlever un pion de la grille" << endl;
  cout << "Quelles sont ses coordonnees?" << endl;
  cout << "Quelle colonne ? (1-5) ";
  cin >> x;
  cout << "Quelle ligne ? (1-5) ";
  cin >> y;

  while ((x < 1) || (x > 5) || (y < 1) || (y > 5)) {
    RetirerPion("Coordonnees invalides");
    return;
  }

  if (!grille->EstDeType(x - 1, y - 1, joueur)) {
    RetirerPion("Ce n'est pas votre pion!");
    return;
  }

  grille->RetirerPion(x - 1, y - 1);
}

void Manager::DeplacerCaseLibre(string message) {
  int x, y;
  int c;
  Direction d = INVALIDE;

  RafraichirAffichage();
  if (message.length() > 0) cout << message << endl;
  cout << "vous avez choisi de deplacer votre pion vers une case libre" << endl;
  cout << "Indiquez les coordonnees de votre pion" << endl;
  cout << "Quelle colonne ? (1-5) ";
  cin >> x;
  cout << "Quelle ligne ? (1-5) ";
  cin >> y;

  if ((x < 1) || (x > 5) || (y < 1) || (y > 5)) {
    DeplacerCaseLibre("Coordonnees invalides!");
    return;
  }

  if (!grille->EstDeType(x - 1, y - 1, joueur)) {
    DeplacerCaseLibre("Ce n'est pas votre pion!");
    return;
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

bool Manager::PousserPion(string message) {
  int x, y, c;
  Direction d;

  RafraichirAffichage();
  if (message.length() > 0) cout << message << endl;
  cout << "Vous avez choisit de pousser des pions" << endl;
  cout << "Indiquez les coordonnees de votre pion" << endl;
  cout << "Quelle colonne ? (1-5) ";
  cin >> x;
  cout << "Quelle ligne ? (1-5) ";
  cin >> y;

  if ((x < 1) || (x > 5) || (y < 1) || (y > 5)) {
    return PousserPion("Coordonnees invalides!");
  }

  if (!grille->EstDeType(x - 1, y - 1, joueur)) {
    return PousserPion("Ce n'est pas votre pion!");
  }

  d = grille->contenu[x - 1][y - 1]->d;

  switch (d) {
    case HAUT: {
      if (y == 1) {
        return PousserPion("Ce pion ne peut pas pousser vers le haut!");
      }

      if (grille->contenu[x - 1][y - 2]->d == BAS) {
        cout << "Les forces se compensent!" << endl;
        return false;
      }

      if (!grille->EstDeType(x - 1, y - 2, VIDE))
        if (grille->EstDeType(x - 1, y - 2, MONTAGNE) && y == 2) {
          return true;
        } else {
          cout << "Le pion a été déplacé" << endl;
          grille->Deplacer(x - 1, y - 2, x - 1, y - 3);
        }
      grille->Deplacer(x - 1, y - 1, x - 1, y - 2);

      return false;
    }
    case BAS: {
      if (y == 5) {
        return PousserPion("Ce pion ne peut pas pousser vers le bas!");
      }
      if (grille->contenu[x - 1][y]->d == HAUT) {
        cout << "Les forces se compensent!" << endl;
        return false;
      }

      if (!grille->EstDeType(x - 1, y, VIDE))
        if (grille->EstDeType(x - 1, y, MONTAGNE) && y == 4) {
          return true;
        } else {
          cout << "Le pion a été déplacé" << endl;
          grille->Deplacer(x - 1, y, x - 1, y + 1);
        }
      grille->Deplacer(x - 1, y - 1, x - 1, y);

      return false;
    }
    case GAUCHE: {
      if (x == 1) {
        return PousserPion("Ce pion ne peut pas pousser a gauche!");
      }
      if (grille->contenu[x - 2][y - 1]->d == DROITE) {
        cout << "Les forces se compensent!" << endl;
        return false;
      }

      if (!grille->EstDeType(x - 2, y - 1, VIDE))
        if (grille->EstDeType(x - 2, y - 1, MONTAGNE) && x == 2) {
          return true;
        } else {
          cout << "Le pion a été déplacé" << endl;
          grille->Deplacer(x - 2, y - 1, x - 3, y - 1);
        }
      grille->Deplacer(x - 1, y - 1, x - 2, y - 1);

      return false;
    }
    case DROITE: {
      if (x == 5) {
        return PousserPion("Ce pion ne peut pas pousser a droite!");
      }
      if (grille->contenu[x][y - 1]->d == GAUCHE) {
        cout << "Les forces se compensent!" << endl;
        return false;
      }

      if (!grille->EstDeType(x, y - 1, VIDE))
        if (grille->EstDeType(x, y - 1, MONTAGNE) && x == 4) {
          return true;
        } else {
          cout << "Le pion a été déplacé" << endl;
          grille->Deplacer(x, y - 1, x + 1, y - 1);
        }
      grille->Deplacer(x - 1, y - 1, x, y - 1);

      return false;
    }
    default:
      cout << d << endl;
      return PousserPion("Direction du pion inconnue!");
  }
}
