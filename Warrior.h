#include "Character.h"

#ifndef Warrior_H
#define Warrior_H

class Warrior : public Character {
  private:
    bool critico;
    int turnosCritico;
  public:
    Warrior(int vida, int ataque, int cura);
    void atacar(Character *inimigo);
    void opcoes(Character *inimigo);
};

#endif