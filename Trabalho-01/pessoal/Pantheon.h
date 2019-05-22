#ifndef PANTHEON_H
#define PANTHEON_H

#include "Objeto.h"

class Pantheon : public Objeto
{
public:

    CameraJogo *cam;

    Pantheon();
    void desenha();
    void atualiza(int a) {};
    void camera() {};
};

#endif // PANTHEON_H
