#ifndef DIRECTION_H
#define DIRECTION_H

#include <string>

using namespace std;

enum Direction { HAUT, BAS, DROITE, GAUCHE };

string afficherDirection(Direction d) {
  switch (d) {
    case HAUT:
      return "^";
    case BAS:
      return "v";
    case DROITE:
      return ">";
    case GAUCHE:
      return "<";
  }
  return "?";
}

#endif  // DIRECTION_H
