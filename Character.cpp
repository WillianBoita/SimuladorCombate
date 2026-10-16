#include "Character.h"
#include <iostream>

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

void Character::opcoes() {}

int Character::getVida(){
  return this->vida;
}

int Character::getAtaque(){
  return this->ataque;
}

int Character::getCura(){
  return this->cura;
}