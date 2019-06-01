#ifndef DOISCARANUMAMOTO_H
#define DOISCARANUMAMOTO_H

#include<Curva.h>

class DoisCaraNumaMoto : public Objeto
{
public:
    Model3DS *modelo;
    float u;
    int p;

    DoisCaraNumaMoto();
    void desenha();
    void desenhaNaCurva(Curva &c, const vector<Vetor3D> &pontosControle);
    void mover();
};

#endif // DOISCARANUMAMOTO_H
