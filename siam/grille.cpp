#include "grille.h"
#include <iostream>
#include <string>

using namespace std;

Grille::Grille() {
  this->contenu = vector<vector<Pion> >();
  this->contenu.reserve(5);
  for (auto c : this->contenu) {
    c.reserve(5);
    for (int i = 0; i < 5; i++) {
      c[i] = Pion();
    }
  }
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
    for (int j = 0; j < 5; j++)
      cout << this->contenu.at(i).at(j).texte() << vertM;
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
