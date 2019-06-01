#include "DoisCaraNumaMoto.h"

DoisCaraNumaMoto::DoisCaraNumaMoto()
{
    modelo = new Model3DS("../3ds/2cara1moto.3DS");
    u = 0.0;
    p = 0;
}

void DoisCaraNumaMoto::desenha()
{
    glPushMatrix();
        Objeto::desenha();
        glRotatef(90, 1, 0, 0);
        glScalef(0.003, 0.003, 0.003);
        modelo->draw();
        glPopMatrix();
}

void DoisCaraNumaMoto::desenhaNaCurva(Curva &curva, const vector<Vetor3D> &pontosControle)
{
    vector<Vetor3D> pontos(4);
    for(int j = 0; j < 4; j++)
    {
        pontos[j] = pontosControle[(p + j) % pontosControle.size()];
    }
    Vetor3D o = curva.pT(u, pontos, 0);
    Vetor3D k = curva.pT(u, pontos, 1) * (-1);
    Vetor3D j = curva.pT(u, pontos, 2);
    Vetor3D i = j ^ k;
    j = k ^ i;
    i.normaliza();
    j.normaliza();
    k.normaliza();

    double T[] = {
        i.x, j.x, k.x, o.x,
        i.y, j.y, k.y, o.y,
        i.z, j.z, k.z, o.z,
        0   , 0   , 0   , 1
    };

    glPushMatrix();
        glMultTransposeMatrixd(T);
        this->desenha();
    glPopMatrix();
}

void DoisCaraNumaMoto::mover()
{
    u += 0.0085;
    if(u >= 1){
        u = 0.0;
        p++;
    };
}
