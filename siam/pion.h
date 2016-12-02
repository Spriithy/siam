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

class Montagne : public Pion {
 public:
  Montagne() {}
};

class Vide : public Pion {
 public:
  Vide() {}
};

class PionJoueur : public Pion {
 public:
  PionJoueur(TypePion t, Direction d) {
    this->d = d;
    this->type = t;
  }
};

#endif  // PION_H
