#include "Veiculo.h"

Veiculo::Veiculo(TIPO t)
{
    if(t == CARRO1) {
        tipo = CARRO1;
        model = new Model3DS("../3ds/carro1.3DS");
    } else if(t == CARRO2) {
        tipo = CARRO2;
        model = new Model3DS("../3ds/carro2.3DS");
    } else if(t == MOTO){
        tipo = MOTO;
        model = new Model3DS("../3ds/moto.3DS");
    } else{
        tipo = BICICLETA;
        model = new Model3DS("../3ds/bicicleta.3DS");
    }
}

void Veiculo::desenha()
{
    glPushMatrix();
        Objeto::desenha();


        if(this->tipo == MOTO)
        {
            glTranslatef(0, 0.1, 0);
        }
        if(this->tipo == BICICLETA)
        {
            glTranslatef(0, 0.2, 0);
            glRotatef(-90, 0, 1, 0);
        }
        glRotatef(-90, 1, 0, 0);
        if(this->tipo == MOTO)
            glScalef(0.2, 0.2, 0.2);
        glScalef(0.002,0.002,0.002);
        model->draw();
    glPopMatrix();
}
