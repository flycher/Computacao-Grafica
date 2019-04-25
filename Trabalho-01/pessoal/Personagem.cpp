#include "Personagem.h"

Personagem::Personagem()
{
    tipo = PERSONAGEM;

    r[0] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    r[1] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    r[2] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    r[3] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

    g[0] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    g[1] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    g[2] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    g[3] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

    b[0] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    b[1] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    b[2] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    b[3] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}

void Personagem::desenha()
{
    glPushMatrix();
        Objeto::desenha();

        glRotatef(180, 0, 1, 0);
        glScalef(0.1, 0.1, 0.1);

        GUI::setColor(r[0],g[0],b[0]);
        //perna esquerdo
        glPushMatrix();
            glTranslatef(-0.1f, 1, 0);
            glRotatef(0, 1, 0, 0);
            glRotatef(180, 0, 0, 1);
            glScalef(0.3, 1, 0.25);
            Objeto::cubo();
        glPopMatrix();

        //perna direita
        glPushMatrix();
            glTranslatef(0.5f, 1, 0);
            glRotatef(0, 1, 0, 0);
            glRotatef(180, 0, 0, 1);
            glScalef(0.3, 1, 0.25);
            Objeto::cubo();
        glPopMatrix();

        GUI::setColor(r[1],g[1],b[1]);
        //tronco
        glPushMatrix();
            glTranslatef(-0.45f, 1, 0);
            glScalef(1.05, 1.3, 0.3);
            Objeto::cubo();
        glPopMatrix();

        GUI::setColor(r[2],g[2],b[2]);
        //braço esquerdo
        glPushMatrix();
            glTranslatef(-0.4f, 2.1f, 0);
            glRotatef(45, 0, 0, 1);
            glRotatef(0, 0, 1, 0);
            glRotatef(180, 0, 0, 1);
            glScalef(1.1, 0.25, 0.25);
            Objeto::cubo();
        glPopMatrix();

        //braço direito
        glPushMatrix();
            glTranslatef(0.4f, 1.9f, 0);
            glRotatef(-45, 0, 0, 1);
            glRotatef(0, 0, 1, 0);
            glScalef(1.1, 0.25, 0.25);
            Objeto::cubo();
        glPopMatrix();

        GUI::setColor(r[3],g[3],b[3]);
        //cabeça
        glPushMatrix();
            glTranslatef(-0.3f, 2.2f, 0);
            glScalef(0.75, 0.75, 0.5);
            Objeto::cubo();
        glPopMatrix();

        glPopMatrix();
}

void Personagem::camera() {
    cam = new CameraJogo(t + Vetor3D(0, 0.1, 0), Vetor3D(-t.x, -t.y, -t.z), Vetor3D(0, 1, 0));
    glutGUI::cam = cam;
}
