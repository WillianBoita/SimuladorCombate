#include "Character.h"

#ifndef Arena_H
#define Arena_H

class Arena {
  private: 
    int turno;
    bool acabou;
    Character *personagem;
    Character *inimigo;
    void escolherPersonagem();

  public:
    Arena();
    ~Arena();

    void simularTurno();
    void validarEncerramento();
    int getTurno();
    bool getAcabou();
};

#endif