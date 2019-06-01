#ifndef HELICOPTERO_H
#define HELICOPTERO_H

#include "Objeto.h"

class Helicoptero : public Objeto
{
public:
    int h = rand()/360;

    Helicoptero();
    void desenha();
};

#endif // HELICOPTERO_H
