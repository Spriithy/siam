#ifndef DIRECTION_H
#define DIRECTION_H

#include <string>

using namespace std;

enum Direction { INVALIDE, HAUT, BAS, DROITE, GAUCHE };

#define CONVERTIR_DIRECTION(src, dst) \
  switch (src) {                      \
    case 'H':                         \
      dst = HAUT;                     \
    case 'B':                         \
      dst = BAS;                      \
    case 'D':                         \
      dst = DROITE;                   \
    case 'G':                         \
      dst = GAUCHE;                   \
    default:                          \
      dst = INVALIDE;                 \
  }

#endif  // DIRECTION_H
