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
  void RetirerPion();
  void RafraichirAffichage();
  void DeplacerCaseLibre(string message);
  void PousserPion();
};

#endif  // MANAGER_H
