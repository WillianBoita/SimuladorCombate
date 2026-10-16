#include <iostream>
#include "Warrior.h"

Warrior::Warrior(int vida, int ataque, int cura): Character::Character(vida, ataque, cura){
  this->critico = false;
  this->turnosCritico = 0;
};

void Warrior::atacar(Character *inimigo) {
  if (this->critico) {
    inimigo->defender(this->getAtaque() * 2);
    this->turnosCritico++;
    if (this->turnosCritico > 1) {
      this->turnosCritico = 0;
      this->critico = false;
    }
    
  } else {
    inimigo->defender(this->getAtaque());
  }
}

void Warrior::opcoes(Character *inimigo) {
  int opcao;
  
  std::cout << "\nEscolha uma ação: \n";
  std::cout << "1 - Atacar: \n";
  std::cout << "2 - Curar: \n";
  std::cout << "3 - Ativar dano crítico: \n";
  std::cin >> opcao;
  switch (opcao)
  {
  case 1:
    this->atacar(inimigo);
    break;

  case 2:
    this->curar(this->getCura());
    break;
  
  case 3:
    this->critico = true;
    break;
  
  default:
    break;
  }
}