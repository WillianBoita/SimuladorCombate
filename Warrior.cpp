#include <iostream>
#include "Warrior.h"

Warrior::Warrior(int vida, int ataque, int cura): Character::Character(vida, ataque, cura){
  this->especial = false;
  this->turnosEspecial = 0;
};

void Warrior::atacar(Character *inimigo) {
  if (this->especial) {
    inimigo->defender(this->getAtaque() * 1.5);
    if (this->turnosEspecial > 1) {
      this->turnosEspecial = 0;
      this->especial = false;
    }
    this->turnosEspecial++;
    
  } else {
    inimigo->defender(this->getAtaque());
  }
}

std::string Warrior::getEspecialAtivo(){
  std::string ehCritico = this->turnosEspecial == false ? "False" : "True";
  return "Dano crítico: " + ehCritico;
}

void Warrior::opcoes(Character *inimigo) {
  int opcao;
  
  std::cout << "\nEscolha uma ação: \n";
  std::cout << "1 - Atacar \n";
  std::cout << "2 - Curar \n";
  std::cout << "3 - Ativar dano crítico \n";
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
    this->especial = true;
    break;
  
  default:
    std::cout << "Opção inválida, curando por padrão...\n";
    this->curar(this->getCura());
    break;
  }
}

void Warrior::opcaoInimigo(Character *inimigo) {
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