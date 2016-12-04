#ifndef MANAGER_H
#define MANAGER_H

#include "grille.h"
#include "pion.h"

class Manager {
 public:
  TypePion joueur;
  Grille *grille;
  Manager();
  ~Manager();

  void ChangerJoueur(bool rhino);
  void AjouterPion();
  void PivoterPion();
  void RetirerPion(string message);
  void RafraichirAffichage();
  void DeplacerCaseLibre(string message);
  bool PousserPion(string message);
};

#endif  // MANAGER_H
