#include <iostream>
#include "Arena.h"

int main() {
  bool jogarNovamente = true;
  while (jogarNovamente) {
    Arena *jogo = new Arena();
    while (!jogo->getAcabou()) {
      jogo->simularTurno();
    }

    delete jogo;
    char opcao;
    std::cout << "o jogo acabou, deseja jogar novamente? (s/n)\n";
    std::cin >> opcao;
    if (opcao == 's') {
      jogarNovamente = true;
    } else {
      jogarNovamente = false;
    }
  }
  
  
  return 0;
}