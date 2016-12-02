#ifndef PARTIE_H
#define PARTIE_H

class Partie {
 public:
  string j1, j2;
  int nbJ1, nbJ2;
  TypeJouer j;
  Manager *manager;

  Partie();
  Commencer();
};

#endif  // PARTIE_H
