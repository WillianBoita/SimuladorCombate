#include <iostream>
#include "Mage.h"

Mage::Mage(int vida, int ataque, int cura): Character::Character(vida, ataque, cura){
  this->especial = false;
  this->turnosEspecial = 0;
};

Mage::~Mage() {};

void Mage::regenerar(){
  if (this->especial) {
    this->curar(this->getCura() / 2);
    this->turnosEspecial++;
  }
  if (this->turnosEspecial > 3) {
    this->turnosEspecial = 0;
    this->especial = false;
  }
};

std::string Mage::getEspecialAtivo(){
  std::string estaRegenerando = this->especial == false ? "False" : "True";
  return "Regenerando: " + estaRegenerando;
};

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
};

void Mage::opcaoInimigo(Character *inimigo) {
  int aleatorio = this->gerarOpcaoAleatoria();
  int opcao = this->getVida() + this->getCura() >= this->getVidaMaxima() ? 1 : !this->especial ? 3 : aleatorio != 3 ? aleatorio : 2;

  this->regenerar();

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
};