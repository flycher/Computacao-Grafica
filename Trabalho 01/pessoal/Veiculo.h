#ifndef VEICULO_H
#define VEICULO_H

#include <Objeto.h>

class Veiculo : public Objeto
{
public:
    Model3DS* model;
    int tipo, escolha;

    Veiculo(int tipo, int escolha);
    void desenha();
    void atualiza(float a){}
    void camera() {}
};

#endif // VEICULO_H
