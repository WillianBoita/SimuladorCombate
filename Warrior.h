#include "Character.h"

#ifndef Warrior_H
#define Warrior_H

class Warrior : public Character {
  public:
    Warrior(int vida, int ataque, int cura);
    ~Warrior() override;
    void atacar(Character *inimigo);
    void opcoes(Character *inimigo) override;
    void opcaoInimigo(Character *inimigo) override;
    std::string getEspecialAtivo() override;
};

#endif