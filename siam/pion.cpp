#include "pion.h"
Pion::Pion() {
  this->d = HAUT;
  this->type = VIDE;
}

void Pion::pivoter(Direction d) { this->d = d; }
string Pion::texte() { return " " + afficherDirection(this->d); }
