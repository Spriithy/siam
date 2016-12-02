#ifndef MANAGER_H
#define MANAGER_H


class Manager
{
public:
    Grille *grille;
    Manager();
    ~Manager();

    void AjouterPion();
    void PivoterPion();
};

#endif // MANAGER_H
