#ifndef Character_H
#define Character_H

class Character {
  private:
    int vida;
    int ataque;
    int cura;
  public:
    Character(int vida, int ataque, int cura);

    void atacar(Character *inimigo);
    void defender(int danoLevado);
    void curar(int cura);

    void opcoes();

    int getVida();
    int getAtaque();
    int getCura();
};

#endif