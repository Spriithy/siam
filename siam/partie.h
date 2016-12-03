#ifndef PARTIE_H
#define PARTIE_H

#include <string>
#include "manager.h"

using namespace std;

class Partie {
 public:
  string j1, j2;
  int nbJ1, nbJ2, tours;
  TypePion j;
  Manager *manager;
  bool terminee;

  Partie();
  void Commencer();
  void TourSuivant();
};

#endif  // PARTIE_H
