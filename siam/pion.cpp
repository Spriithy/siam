#include "pion.h"

Pion::Pion() {
  this->d = HAUT;
  this->type = VIDE;
}

void Pion::pivoter(Direction d) { this->d = d; }
string Pion::texte() {
  string s = "";
  switch (this->type) {
    case VIDE:
      return "  ";
    case MONTAGNE:
      s += "M";
      break;
    case ELEPHANT:
      s += "E";
    case RHINOCEROS:
      s += "R";
      break;
    default:
      s += "?";
  }

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
  }

  return s;
}
