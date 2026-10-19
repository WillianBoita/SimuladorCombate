#include <iostream>

#ifndef Character_H
#define Character_H

class Character {
  private:
    int vida;
    int ataque;
    int cura;
    int vidaMaxima;
  public:
    bool especial;
    int turnosEspecial;
    Character(int vida, int ataque, int cura);
    virtual ~Character() {};

    void atacar(Character *inimigo);
    void defender(int danoLevado);
    void curar(int cura);

    virtual void opcoes(Character *inimigo) = 0;
    virtual void opcaoInimigo(Character *inimigo) = 0;
    virtual std::string getEspecialAtivo() = 0;
    int gerarOpcaoAleatoria();

    int getVida();
    int getVidaMaxima();
    int getAtaque();
    int getCura();
};

#endif