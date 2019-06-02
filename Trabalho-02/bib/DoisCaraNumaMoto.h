#ifndef DOISCARANUMAMOTO_H
#define DOISCARANUMAMOTO_H

#include<Curva.h>
#include<Helicoptero.h>

class DoisCaraNumaMoto : public Objeto
{
public:
    Model3DS *modelo;
    Helicoptero *helicoptero;
    float u;
    int p;
    int direction;

    DoisCaraNumaMoto();
    void desenha();
    void desenhaNaCurva(Curva &c, const vector<Vetor3D> &pontosControle, Camera &camera);
    void mover();
    void mudaDirecao(int d);
};

#endif // DOISCARANUMAMOTO_H
