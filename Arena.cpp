#include <iostream>
#include "Warrior.h"
#include "Mage.h"
#include "Arena.h"

Arena::Arena() : turno(0), acabou(false), personagem(nullptr), inimigo(nullptr) {
  this->escolherPersonagem();
}

Arena::~Arena() {
  delete this->inimigo;
  delete this->personagem;
}

void Arena::simularTurno() {
  if (this->personagem == nullptr || this->inimigo == nullptr) {
    std::cout << "Erro ao selecionar personagens.\n";
    this->acabou = true;
    return;
  }
  
  this->turno++;

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
  this->validarEncerramento();
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
    this->personagem = new Warrior(100, 15, 10);
    this->inimigo = new Mage(70, 10, 20);
    break;

  case 2:
    this->personagem = new Mage(70, 10, 20);
    this->inimigo = new Warrior(100, 15, 10);
    break;
  
  default:
    std::cout << "Opção inválida.\n";
    break;
  }
}

void Arena::validarEncerramento() {
  if (this->personagem == nullptr || this->inimigo == nullptr) {
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