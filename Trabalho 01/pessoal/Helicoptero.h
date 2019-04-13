#ifndef HELICOPTERO_H
#define HELICOPTERO_H

#include <Objeto.h>

class Helicoptero : public Objeto
{
public:
    float h = 0;
    CameraJogo *cam;

    Helicoptero();
    void desenha();
    void atualiza(float a);
    void camera();
};

#endif // HELICOPTERO_H
