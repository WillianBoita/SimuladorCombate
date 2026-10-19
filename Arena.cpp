#include <iostream>
#include "Warrior.h"
#include "Mage.h"
#include "Arena.h"

Arena::Arena(){
  this->turno = 0;
  this->escolherPersonagem();
}

void Arena::simularTurno() {
  this->turno++;

  if (this->personagem == NULL || this->inimigo == NULL) {
    std::cout << "Erro ao selecionar personagens.\n";
    this->validarEncerramento();
    return;
  }
  

  std::cout << "Você:\n";
  std::cout << "Vida: " << this->personagem->getVida() << "\n";
  std::cout << "Dano: " << this->personagem->getAtaque() << "\n";
  std::cout << "Cura: " << this->personagem->getCura() << "\n";
  std::cout << "Habilidade: " << this->personagem->getEspecialAtivo() << "\n";
  std::cout << "------------------------\n";
  std::cout << "Inimigo:\n";
  std::cout << "Vida: " << this->inimigo->getVida() << "\n";
  std::cout << "Dano: " << this->inimigo->getAtaque() << "\n";
  std::cout << "Cura: " << this->inimigo->getCura() << "\n";
  std::cout << "Habilidade: " << this->inimigo->getEspecialAtivo() << "\n";

  this->personagem->opcoes(this->inimigo);
  this->inimigo->opcaoInimigo(this->personagem);
  this->validarEncerramento();
}

void Arena::escolherPersonagem() {
  int opcao;
  
  std::cout << "\nEscolha um personagem: \n";
  std::cout << "1 - Guerreiro \n";
  std::cout << "2 - Mago \n";
  std::cin >> opcao;
  switch (opcao)
  {
  case 1:
    this->personagem = new Warrior(100, 10, 10);
    this->inimigo = new Mage(100, 10, 10);
    break;

  case 2:
    this->personagem = new Mage(100, 10, 10);
    this->inimigo = new Warrior(100, 10, 10);
    break;
  
  default:
    std::cout << "Opção inválida.\n";
    break;
  }
}

void Arena::validarEncerramento() {
  if (this->personagem == NULL || this->inimigo == NULL) {
    this->acabou = true;
    return;
  }

  if (this->inimigo->getVida() <= 0) {
    std::cout << "Você venceu!\n";
    this->acabou = true;
    return;
  }

  if (this->personagem->getVida() <= 0) {
    std::cout << "Você perdeu.\n";
    this->acabou = true;
    return;
  }
}

int Arena::getTurno() {
  return this->turno;
}

bool Arena::getAcabou() {
  return this->acabou;
}