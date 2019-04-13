#include "Imovel.h"

Imovel::Imovel(int escolha)
{
    this->escolha = escolha;
    if(escolha)
        model = new Model3DS("../3ds/apartamento1.3DS");
    else
        model = new Model3DS("../3ds/apartamento2.3DS");
}

void Imovel::desenha()
{
    glPushMatrix();
        Objeto::desenha();

        glRotatef(-90, 1, 0, 0);
        if(this->escolha)
        {
            glRotatef(180, 0, 1, 0);
            glRotatef(180, 1, 0, 0);
            glScalef(20, 20, 20);
        }
        glScalef(0.01, 0.01, 0.01);
        model->draw();
    glPopMatrix();
}
