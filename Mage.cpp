#include <iostream>
#include "Mage.h"

Mage::Mage(int vida, int ataque, int cura): Character::Character(vida, ataque, cura){
  this->regenerando = false;
};

void Mage::regenerar(){
  if (this->regenerando) {
    this->curar(this->getCura() / 2);
  } if (this->turnosRegenerando > 3) {
      this->turnosRegenerando = 0;
      this->regenerando = false;
    }
};


void Mage::opcoes(Character *inimigo) {
  int opcao;
  
  std::cout << "\nEscolha uma ação: \n";
  std::cout << "1 - Atacar: \n";
  std::cout << "2 - Curar: \n";
  std::cout << "3 - Regenerar: \n";
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
    this->regenerando = true;
    break;
  
  default:
    break;
  }
}
