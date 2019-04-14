#ifndef VEICULO_H
#define VEICULO_H

#include <Objeto.h>

class Veiculo : public Objeto
{
public:
    Model3DS* model;

    Veiculo(TIPO t);
    void desenha();
    void atualiza(float a){}
    void camera() {}
};

#endif // VEICULO_H
