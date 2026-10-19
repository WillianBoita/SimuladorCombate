#include <iostream>
#include "Warrior.h"

Warrior::Warrior(int vida, int ataque, int cura): Character::Character(vida, ataque, cura){
  this->especial = false;
  this->turnosEspecial = 0;
};

void Warrior::atacar(Character *inimigo) {
  if (this->especial) {
    inimigo->defender(this->getAtaque() * 1.8);
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
  std::string ehCritico = this->especial == false ? "False" : "True";
  return "Dano crítico: " + ehCritico;
}

void Warrior::opcoes(Character *inimigo) {
  int opcao;
  
  std::cout << "\nEscolha uma ação: \n";
  std::cout << "1 - Atacar \n";
  std::cout << "2 - Curar \n";
  std::cout << "3 - Ativar dano crítico \n";
  std::cin >> opcao;
  switch (opcao) {
  case 1:
    this->atacar(inimigo);
    std::cout << "Você atacou o inimigo!\n";
    break;

  case 2:
    this->curar(this->getCura());
    std::cout << "Você se curou!\n";
    break;
  
  case 3:
    this->especial = true;
    std::cout << "Você ativou a habilidade especial!\n";
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
    std::cout << "Seu inimigo atacou!\n";
    break;

  case 2:
    this->curar(this->getCura());
    std::cout << "Seu inimigo se curou!\n";
    break;
  
  case 3:
    this->especial = true;
    std::cout << "Seu inimigo ativou a habilidade especial!\n";
    break;
  
  default:
    break;
  }
}