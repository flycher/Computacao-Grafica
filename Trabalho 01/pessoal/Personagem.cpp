#include "Personagem.h"

Personagem::Personagem()
{

}



void Personagem::desenha()
{
    glPushMatrix();
        Objeto::desenha();

        glScalef(0.2, 0.2, 0.2);

        GUI::setColor(1,0,1);
        //perna esquerdo
        glPushMatrix();
            glTranslatef(-0.1f, 1, 0);
            glRotatef(0, 1, 0, 0);
            glRotatef(180, 0, 0, 1);
            GUI::drawBox(0, 0, 0, 0.3f, 1, 0.25);
        glPopMatrix();

        //perna direita
        glPushMatrix();
            glTranslatef(0.5f, 1, 0);
            glRotatef(0, 1, 0, 0);
            glRotatef(180, 0, 0, 1);
            GUI::drawBox(0, 0, 0, 0.3f, 1, 0.25);
        glPopMatrix();

        GUI::setColor(0,0,1);
        //tronco
        glPushMatrix();
            glTranslatef(-0.45f, 1, 0);
            GUI::drawBox(0, 0, 0, 1.05f, 1.3f, 0.3f);
        glPopMatrix();

        GUI::setColor(0,0.5,0);

        //braço esquerdo
        glPushMatrix();
            glTranslatef(-0.4f, 2.1f, 0);
            glRotatef(45, 0, 0, 1);
            glRotatef(0, 0, 1, 0);
            glRotatef(180, 0, 0, 1);
            GUI::drawBox(0, 0, 0, 1.1f, 0.25, 0.25);
        glPopMatrix();

        //braço direito
        glPushMatrix();
            glTranslatef(0.4f, 1.9f, 0);
            glRotatef(-45, 0, 0, 1);
            glRotatef(0, 0, 1, 0);
            GUI::drawBox(0, 0, 0, 1.1f, 0.25, 0.25);
        glPopMatrix();

        GUI::setColor(0,0,0);
        //cabeça
        glPushMatrix();
            glTranslatef(-0.3f, 2.2f, 0);
            GUI::drawBox(0, 0, 0, 0.75, 0.75, 0.5);
        glPopMatrix();


        glPopMatrix();
}

void Personagem::atualiza(float a)
{

}
