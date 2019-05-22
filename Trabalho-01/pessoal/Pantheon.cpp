#include "Pantheon.h"

Pantheon::Pantheon()
{
    tipo = PANTHEON;
}

void Pantheon::desenha()
{

    glPushMatrix();
        glTranslatef(-0.6, 0, 0),
        Objeto::desenha();
        glScalef(1.2, 1.6, 2);

        GUI::setColor(1, 0, 0);
        glPushMatrix();
            glScalef(1, 0.1, 1.3);
            Objeto::cubo();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0, 0.7, 0);
            glScalef(1, 0.1, 1.3);
            Objeto::cubo();
        glPopMatrix();
        GUI::setColor(1, 1, 1);
        glPushMatrix();
            glTranslatef(0.2, 0.1, -0.1);
            glScalef(0.1, 0.8, 0.1);
            Objeto::cubo();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.2, 0.1, -0.4);
            glScalef(0.1, 0.8, 0.1);
            Objeto::cubo();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.2, 0.1, -0.7);
            glScalef(0.1, 0.8, 0.1);
            Objeto::cubo();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.2, 0.1, -1);
            glScalef(0.1, 0.8, 0.1);
            Objeto::cubo();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.45, 0.1, -0.1);
            glScalef(0.1, 0.8, 0.1);
            Objeto::cubo();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.7, 0.1, -0.1);
            glScalef(0.1, 0.8, 0.1);
            Objeto::cubo();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.7, 0.1, -0.4);
            glScalef(0.1, 0.8, 0.1);
            Objeto::cubo();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.7, 0.1, -0.7);
            glScalef(0.1, 0.8, 0.1);
            Objeto::cubo();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.7, 0.1, -1);
            glScalef(0.1, 0.8, 0.1);
            Objeto::cubo();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.45, 0.1, -1);
            glScalef(0.1, 0.8, 0.1);
            Objeto::cubo();
        glPopMatrix();
        GUI::setColor(0, 0, 1);
        glPushMatrix();
            glTranslatef(0, 0.7, 0);
            glRotatef(45, 0, 0, 1);
            glScalef(1, 0.1, 1.3);
            Objeto::cubo();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.3, 1.4, 0);
            glRotatef(-45, 0, 0, 1);
            glScalef(1, 0.1, 1.3);
            Objeto::cubo();
        glPopMatrix();

    glPopMatrix();
}
