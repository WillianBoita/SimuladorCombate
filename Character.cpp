#include "Character.h"
#include <iostream>
#include <random>

Character::Character(int vida, int ataque, int cura) {
  this->vida = vida;
  this->ataque = ataque;
  this->cura = cura;
}

void Character::atacar(Character *inimigo){
  inimigo->defender(this->getAtaque());
}

void Character::defender(int danoLevado) {
  this->vida -= danoLevado;
}

void Character::curar(int cura) {
  this->vida += cura;
}

int Character::gerarOpcaoAleatoria() {
    std::random_device rd;

    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> distrib(1, 3);

    int numero_aleatorio = distrib(gen);

    return numero_aleatorio;
}

int Character::getVida(){
  return this->vida;
}

int Character::getAtaque(){
  return this->ataque;
}

int Character::getCura(){
  return this->cura;
}