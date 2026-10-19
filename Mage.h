#include "Character.h"

#ifndef Mage_H
#define Mage_H

class Mage : public Character {
  public:
    Mage(int vida, int ataque, int cura);
    void regenerar();
    void opcoes(Character *inimigo) override;
    void opcaoInimigo(Character *inimigo) override;
    std::string getEspecialAtivo() override;
};

#endif