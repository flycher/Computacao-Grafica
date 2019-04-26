#ifndef DOISCARANUMAMOTO_H
#define DOISCARANUMAMOTO_H

#include "Objeto.h"

class DoisCaraNumaMoto : public Objeto
{
public:
    Model3DS* model;

    DoisCaraNumaMoto();
    void desenha();
    void atualiza(int a){}
    void camera() {}
};

#endif // DOISCARANUMAMOTO_H
