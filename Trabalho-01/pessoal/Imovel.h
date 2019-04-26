#ifndef IMOVEL_H
#define IMOVEL_H

#include "Objeto.h"

class Imovel : public Objeto
{
public:
    Model3DS* model;

    Imovel(TIPO t);
    void desenha();
    void atualiza(int a){}
    void camera() {}
};

#endif // IMOVEL_H
