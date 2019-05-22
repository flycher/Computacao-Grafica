#ifndef OBJETO_H
#define OBJETO_H

#include "gui.h"

enum TIPO {CARRO1, CARRO2, MOTO, BICICLETA, IMOVEL1, IMOVEL2, PERSONAGEM, HELICOPTERO, CARASMOTO, PANTHEON, NENHUM};

class Objeto
{
public:
    TIPO tipo = NENHUM;
    Vetor3D t = Vetor3D(0,0,0);
    Vetor3D a = Vetor3D(0,0,0);
    Vetor3D s = Vetor3D(1,1,1);

    bool selecionado = false;
    bool origem = false;
    bool sombra = true;

    Objeto();
    virtual void desenha();
    virtual void atualiza(int a) = 0;
    virtual void camera() = 0;
    void cubo();
};

#endif // OBJETO_H
