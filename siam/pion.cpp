#include "pion.h"

Pion::Pion() {
  this->d = HAUT;
  this->type = VIDE;
}

void Pion::Pivoter(Direction d) { this->d = d; }

string Pion::Texte() {
  string s = "";
  switch (this->type) {
    case VIDE:
      return "   ";
    case MONTAGNE:
      return " M ";
    case ELEPHANT:
      s += " E";
      break;
    case RHINOCEROS:
      s += " R";
      break;
    default:
      s += " ?";
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
      break;
    case GAUCHE:
      s += "<";
      break;
    default:
      s += "?";
  }

  return s;
}
