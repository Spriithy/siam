#include "grille.h"
#include <iostream>
#include <string>

using namespace std;

Grille::Grille() {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      this->contenu[i][j] = new Vide();
    }
  }

  // Montagnes
  this->contenu[2][1] = new Montagne();
  this->contenu[2][2] = new Montagne();
  this->contenu[2][3] = new Montagne();
}

void Grille::afficher() {
  string vertM = "┃", vertHG = "┏", vertHD = "┓", vertBG = "┗", vertBD = "┛",
         horM = "━", horLG = "┣", horLD = "┫", horL4 = "╋", horLB = "┻",
         horLH = "┳";

  cout << vertHG;
  for (int j = 0; j < 4; j++) cout << horM << horM << horLH;
  cout << horM << horM << vertHD << endl;
  for (int i = 0; i < 5; i++) {
    cout << vertM;
    for (int j = 0; j < 5; j++) cout << this->contenu[i][j]->texte() << vertM;
    cout << endl;

    if (i == 4) {
      cout << vertBG;
      for (int j = 0; j < 4; j++) cout << horM << horM << horLB;
      cout << horM << horM << vertBD;
    } else {
      cout << horLG << horM << horM << horL4 << horM << horM << horL4 << horM
           << horM << horL4 << horM << horM << horL4 << horM << horM << horLD;
    }
    cout << endl;
  }
}

void Grille::ajouterPion(int x, int y, TypePion t) {}

void Grille::pivoterPion(int x, int y, Direction d) {}

void Grille::retirerPion(int x, int y) {}

void Grille::deplacer(int x, int y, int dx, int dy) {}
