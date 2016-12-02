#ifndef DIRECTION_H
#define DIRECTION_H

#include <string>

using namespace std;

enum Direction { INVALIDE, HAUT, BAS, DROITE, GAUCHE };

Direction convertirDirection(char d) {
  switch (d) {
    case 'H':
      return HAUT;
    case 'B':
      return BAS;
    case 'D':
      return DROITE;
    case 'G':
      return GAUCHE;
    default:
      return INVALIDE;
  }
}

#endif  // DIRECTION_H
