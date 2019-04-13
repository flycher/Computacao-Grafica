#ifndef IMOVEL_H
#define IMOVEL_H

#include "Objeto.h"

class Imovel : public Objeto
{
public:
    Model3DS* model;
    int escolha;

    Imovel(int o);
    void desenha();
    void atualiza(float a){}
    void camera() {}
};

#endif // IMOVEL_H
