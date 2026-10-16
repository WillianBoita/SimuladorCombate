#include <iostream>
#include "Arena.h"

int main() {
  Arena *jogo = new Arena();

  while (!jogo->getAcabou()) {
    jogo->simularTurno();
  }
  
  return 0;
}