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

  void ChangerJoueur(TypePion t);
  void AjouterPion();
  void PivoterPion();
  void RetirerPion();
  void RafraichirAffichage();
};

#endif  // MANAGER_H
