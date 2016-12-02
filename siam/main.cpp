#include <iostream>
#include "pion.h"

using namespace std;

int main(int argc, char *argv[]) {
  cout << "Hello World!" << endl;
  Pion *p = new Pion();
  cout << p->texte() << endl;
  return 0;
}
