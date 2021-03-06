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
  string Texte();
  void Pivoter(Direction d);
};

class Montagne : public Pion {
 public:
  Montagne() { this->type = MONTAGNE; }
};

class Vide : public Pion {
 public:
  Vide() { this->type = VIDE; }
};

class PionJoueur : public Pion {
 public:
  PionJoueur(TypePion t, Direction d) {
    this->d = d;
    this->type = t;
  }
};

#endif  // PION_H
