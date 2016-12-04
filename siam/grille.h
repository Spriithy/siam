#ifndef GRILLE_H
#define GRILLE_H

#include <stdlib.h>
#include <vector>
#include "pion.h"

#ifdef __APPLE__
#define CLEAR() system("clear")
#elif __linux__
#define CLEAR() system("clear")
#elif __unix__
#define CLEAR() system("clear")
#elif defined(_POSIX_VERSION)
#define CLEAR() system("clear")
#else
#define CLEAR() system("cls")
#endif

using namespace std;

class Grille {
 private:
  Pion* contenu[5][5];  // contenu[x][y]

 public:
  Grille();
  bool EstVide(int x, int y);
  bool EstDeType(int x, int y, TypePion t);
  void AjouterPion(int x, int y, TypePion t, Direction d);
  void RetirerPion(int x, int y);
  void PivoterPion(int x, int y, Direction d);
  void Deplacer(int x, int y, int dx, int dy);
  void Afficher();
};

#endif  // GRILLE_H
