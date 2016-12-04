#include "grille.h"
#include <iostream>
#include <string>

using namespace std;

Grille::Grille() {  // Déclaration de la grille avec les montagnes
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      contenu[i][j] = new Vide();
    }
  }

  // Montagnes
  contenu[1][2] = new Montagne();
  contenu[2][2] = new Montagne();
  contenu[3][2] = new Montagne();
}

bool Grille::EstVide(int x, int y) { return contenu[x][y]->type == VIDE; }

// on vérifie le contenu de grille
bool Grille::EstDeType(int x, int y, TypePion t) {
  return contenu[x][y]->type == t;
}

// Affichage de la grille avec la table ASCII
void Grille::Afficher() {
  string vertM = "|", vertHG = "+", vertHD = "+", vertBG = "+", vertBD = "+",
         horM = "-", horLG = "|", horLD = "|", horL4 = "+", horLB = "+",
         horLH = "+";

  cout << vertHG;
  for (int j = 0; j < 4; j++) cout << horM << horM << horM << horLH;
  cout << horM << horM << horM << vertHD << endl;
  for (int i = 0; i < 5; i++) {
    cout << vertM;
    for (int j = 0; j < 5; j++) cout << contenu[j][i]->Texte() << vertM;
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

// on ajoute un pion selon son type: rhinocéros ou éléphant
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

// on pivote le pion sur lui-meme
void Grille::PivoterPion(int x, int y, Direction d) {
  switch (d) {
    case INVALIDE:
      return;
    default:
      contenu[x][y]->d = d;
  }
}

// On cree un pion de type vide pour retirer le pion existant
void Grille::RetirerPion(int x, int y) { contenu[x][y] = new Vide(); }

// dx et dy sont les coordonnees du futur emplacement du pion
void Grille::Deplacer(int x, int y, int dx, int dy) {
  contenu[dx][dy] = contenu[x][y];
  contenu[x][y] = new Vide();
}
