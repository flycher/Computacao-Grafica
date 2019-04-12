#ifndef HELICOPTERO_H
#define HELICOPTERO_H

#include <Objeto.h>

class Helicoptero : public Objeto
{
public:
    float h = 0;
    Helicoptero();
    void desenha();
    void atualiza(float a);
};

#endif // HELICOPTERO_H
