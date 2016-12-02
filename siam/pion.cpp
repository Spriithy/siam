#include "pion.h"

Pion::Pion() {
  this->d = HAUT;
  this->type = VIDE;
}

void Pion::pivoter(Direction d) { this->d = d; }
string Pion::texte() {
  string s = " ";
  switch (this->d) {
    case HAUT:
      s += "^";
      break;
    case BAS:
      s += "v";
      break;
    case DROITE:
      s += ">";
    case GAUCHE:
      s += "<";
    default:
      s += "?";
      break;
  }
  return s;
}
