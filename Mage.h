#include "Character.h"

#ifndef Mage_H
#define Mage_H

class Mage : public Character {
  private:
    bool regenerando;
    int turnosRegenerando;
  public:
    Mage(int vida, int ataque, int cura);
    void regenerar();
    void opcoes(Character *inimigo);
};

#endif