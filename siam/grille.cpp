#include "grille.h"
#include <iostream>
#include <string>

using namespace std;

Grille::Grille() {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      contenu[i][j] = new Vide();
    }
  }

  // Montagnes
  contenu[2][1] = new Montagne();
  contenu[2][2] = new Montagne();
  contenu[2][3] = new Montagne();
}

bool Grille::EstVide(int x, int y) { return contenu[x][y]->type != VIDE; }

bool Grille::EstDeType(int x, int y, TypePion t) {
  return contenu[x][y]->type == t;
}

void Grille::Afficher() {
  string vertM = "|", vertHG = "+", vertHD = "+", vertBG = "+", vertBD = "+",
         horM = "-", horLG = "|", horLD = "|", horL4 = "+", horLB = "+",
         horLH = "+";

  cout << vertHG;
  for (int j = 0; j < 4; j++) cout << horM << horM << horM << horLH;
  cout << horM << horM << horM << vertHD << endl;
  for (int i = 0; i < 5; i++) {
    cout << vertM;
    for (int j = 0; j < 5; j++) cout << contenu[i][j]->Texte() << vertM;
    cout << endl;

    if (i == 4) {
      cout << vertBG;
      for (int j = 0; j < 4; j++) cout << horM << horM << horM << horLB;
      cout << horM << horM << horM << vertBD;
    } else {
      cout << horLG << horM << horM << horM << horL4 << horM << horM << horM
           << horL4 << horM << horM << horM << horL4 << horM << horM << horM
           << horL4 << horM << horM << horM << horLD;
    }
    cout << endl;
  }
}

void Grille::AjouterPion(int x, int y, TypePion t, Direction d) {
  switch (t) {
    case ELEPHANT:
      contenu[x][y] = new PionJoueur(ELEPHANT, d);
      break;
    case RHINOCEROS:
      contenu[x][y] = new PionJoueur(RHINOCEROS, d);
      break;
    default:
      contenu[x][y] = new Vide();
      break;
  }
}

void Grille::PivoterPion(int x, int y, Direction d) {
  switch (d) {
    case INVALIDE:
      return;
    default:
      contenu[x][y]->d = d;
  }
}

void Grille::RetirerPion(int x, int y) { contenu[x][y] = new Vide(); }

void Grille::Deplacer(int x, int y, int dx, int dy) {
  contenu[dx][dy] = contenu[x][y];
  contenu[x][y] = new Vide();
}
