#include "DoisCaraNumaMoto.h"

DoisCaraNumaMoto::DoisCaraNumaMoto()
{
    modelo = new Model3DS("../3ds/2cara1moto.3DS");
    helicoptero = new Helicoptero();
    u = 0.0;
    p = 0;
    direction = 1;
}

void DoisCaraNumaMoto::desenha()
{
    glPushMatrix();
        Objeto::desenha();
        glRotatef(100, 1, 0, 0);
        GUI::drawOrigin(0.5);
        glScalef(0.003, 0.003, 0.003);
        modelo->draw();
    glPopMatrix();
}

void DoisCaraNumaMoto::desenhaNaCurva(Curva &curva, const vector<Vetor3D> &pontosControle, CameraJogo &camera)
{
    int n = pontosControle.size();
    if(p <= -n || p >= n)
        p = 0;
    vector<Vetor3D> pontos(4);
    for(int j = 0; j < 4; j++)
    {
        pontos[j] = pontosControle[(p + j) % n];
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

    camera.c = o;
    camera.u = j * (-1);
    camera.e = (k + camera.u) * 2;
    glPushMatrix();
        glTranslatef(camera.e.x, camera.e.y, camera.e.z);
        glMultTransposeMatrixd(T);
        GUI::drawCamera(0.1);
        helicoptero->desenha();
    glPopMatrix();
}

void DoisCaraNumaMoto::mover()
{
    u += 0.0085 * (direction);
    if(u >= 1){
        u = 0.0;
        p += direction;
    }
    if(u < 0) {
        u = 0.99;
        p--;
    }
}

void DoisCaraNumaMoto::mudaDirecao(int d)
{
    direction = d;
    mover();
}
