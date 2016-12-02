#ifndef PION_H
#define PION_H

#include <string>
#include "direction.h"

using namespace std;

enum TypePion { VIDE, MONTAGNE, RHINOCEROS, ELEPHANT };

class Pion {
 private:

 public:
  Direction d;
  TypePion type;

  Pion();
  string texte();
  void pivoter(Direction d);
};

#endif  // PION_H
