#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <Objeto.h>

class Personagem : public Objeto
{
public:
    Personagem();
    void desenha();
    void atualiza(float a);
};

#endif // PERSONAGEM_H
