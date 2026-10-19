#include <iostream>
#include "Mage.h"

Mage::Mage(int vida, int ataque, int cura): Character::Character(vida, ataque, cura){
  this->especial = false;
};

void Mage::regenerar(){
  if (this->especial) {
    this->curar(this->getCura() / 2);
  }
  if (this->turnosEspecial > 3) {
    this->turnosEspecial = 0;
    this->especial = false;
  }
  this->turnosEspecial++;
};

std::string Mage::getEspecialAtivo(){
  std::string estaRegenerando = this->especial == false ? "False" : "True";
  return "Regenerando: " + estaRegenerando;
}

void Mage::opcoes(Character *inimigo) {
  int opcao;

  this->regenerar();
  
  std::cout << "\nEscolha uma ação: \n";
  std::cout << "1 - Atacar \n";
  std::cout << "2 - Curar \n";
  std::cout << "3 - Regenerar \n";
  std::cin >> opcao;
  switch (opcao) {
  case 1:
    this->atacar(inimigo);
    break;

  case 2:
    this->curar(this->getCura());
    break;
  
  case 3:
    this->especial = true;
    break;
  
  default:
    std::cout << "Opção inválida, curando por padrão...\n";
    this->curar(this->getCura());
    break;
  }
}

void Mage::opcaoInimigo(Character *inimigo) {
  int opcao = !this->especial ? this->gerarOpcaoAleatoria() : 1;
  switch (opcao) {
  case 1:
    this->atacar(inimigo);
    break;

  case 2:
    this->curar(this->getCura());
    break;
  
  case 3:
    this->especial = true;
    break;
  
  default:
    break;
  }
}


