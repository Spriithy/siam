#ifndef MANAGER_H
#define MANAGER_H
#include "pion.h"


class Manager
{
public:
    TypePion joueur;
    Grille *grille;
    Manager();
    ~Manager();

    void AjouterPion();
    void PivoterPion();
};

#endif // MANAGER_H
