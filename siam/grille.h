#ifndef GRILLE_H
#define GRILLE_H

#include <stdlib.h>
#include <vector>
#include "pion.h"

#ifdef _WIN32
// define something for Windows (32-bit and 64-bit, this part is common)
#ifdef _WIN64
#define CLEAR() system("cls")
#endif
#elif __APPLE__
#define CLEAR() system("clear")
#elif __linux__
#define CLEAR() system("clear")
#elif __unix__  // all unices not caught above
#define CLEAR() system("clear")
#elif defined(_POSIX_VERSION)
#define CLEAR() system("clear")
#else
#error "Unknown compiler"
#endif

using namespace std;

class Grille {
 private:
  vector<vector<Pion> > contenu;

 public:
  Grille();
  void ajouterPion(TypePion t);
  void afficher();
};

#endif  // GRILLE_H
