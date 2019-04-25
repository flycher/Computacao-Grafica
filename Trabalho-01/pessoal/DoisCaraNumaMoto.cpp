#include "DoisCaraNumaMoto.h"

DoisCaraNumaMoto::DoisCaraNumaMoto()
{
    tipo = CARASMOTO;
    model = new Model3DS("../3ds/2cara1moto.3DS");
}

void DoisCaraNumaMoto::desenha()
{
    glPushMatrix();
        Objeto::desenha();
        glRotatef(-90, 1, 0, 0);
        glScalef(0.003, 0.003, 0.003);
        model->draw();
    glPopMatrix();
}
