#ifndef CARRO_H
#define CARRO_H

#include <Objeto.h>

class Carro : public Objeto
{
public:
    Model3DS* model;
public:
    Carro();
    void desenha();
    void atualiza(float a);
};

#endif // CARRO_H
