#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include "Objeto.h"

class Personagem : public Objeto
{
public:
    CameraJogo *cam;
    float r[4], g[4], b[4];

    Personagem();
    void desenha();
    void atualiza(int a){}
    void camera();
};

#endif // PERSONAGEM_H
