#include "Veiculo.h"

Veiculo::Veiculo(int tipo, int escolha)
{
    this->tipo = tipo;
    this->escolha = escolha;
    if(tipo && escolha)
        model = new Model3DS("../3ds/carro1.3DS");
    else if(tipo && !escolha)
        model = new Model3DS("../3ds/carro2.3DS");
    else if(escolha)
        model = new Model3DS("../3ds/moto.3DS");
    else
        model = new Model3DS("../3ds/bicicleta.3DS");
}

void Veiculo::desenha()
{
    glPushMatrix();
        Objeto::desenha();


        if(!this->tipo && this->escolha)
        {
            glTranslatef(0, 0.1, 0);
        }
        if(!this->tipo && !this->escolha)
        {
            glTranslatef(0, 0.2, 0);
            glRotatef(-90, 0, 1, 0);
        }
        glRotatef(-90, 1, 0, 0);
        if(!this->tipo && this->escolha)
            glScalef(0.2, 0.2, 0.2);
        glScalef(0.002,0.002,0.002);
        model->draw();
    glPopMatrix();
}
