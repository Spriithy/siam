#ifndef DIRECTION_H
#define DIRECTION_H

#include <string>

using namespace std;

enum Direction { INVALIDE, HAUT, BAS, DROITE, GAUCHE };

#define CONVERTIR_DIRECTION(src, dst) \
  switch (src) {                      \
    case 1:                           \
      dst = HAUT;                     \
      break;                          \
    case 2:                           \
      dst = BAS;                      \
      break;                          \
    case 3:                           \
      dst = GAUCHE;                   \
      break;                          \
    case 4:                           \
      dst = DROITE;                   \
      break;                          \
    default:                          \
      dst = INVALIDE;                 \
  }

#endif  // DIRECTION_H
