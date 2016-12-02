#ifndef GRILLE_H
#define GRILLE_H

#include <stdlib.h>
#include <vector>
#include "montagne.h"
#include "pion.h"
#include "pionjoueur.h"
#include "vide.h"

#ifdef _WIN32
#ifdef _WIN64
#define CLEAR() system("cls")
#endif
#elif __APPLE__
#define CLEAR() system("clear")
#elif __linux__
#define CLEAR() system("clear")
#elif __unix__
#define CLEAR() system("clear")
#elif defined(_POSIX_VERSION)
#define CLEAR() system("clear")
#else
#error "COmpilateur inconnu"
#endif

using namespace std;

class Grille {
 private:
  Pion* contenu[5][5];

 public:
  Grille();
  void ajouterPion(int x, int y, TypePion t);
  void retirerPion(int x, int y);
  void pivoterPion(int x, int y, Direction d);
  void deplacer(int x, int y, int dx, int dy);
  void afficher();
};

#endif  // GRILLE_H
