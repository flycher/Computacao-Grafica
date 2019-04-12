#ifndef OBJETO_H
#define OBJETO_H

#include <gui.h>

class Objeto
{
public:
    Vetor3D t = Vetor3D(0,0,0);
    Vetor3D a = Vetor3D(0,0,0);
    Vetor3D s = Vetor3D(1,1,1);

    bool selecionado = false;
    bool origem = false;

    Objeto();
    virtual void desenha();
    virtual void atualiza(float a) = 0;
    void cubo();
};

#endif // OBJETO_H
