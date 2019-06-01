#include "Helicoptero.h"

Helicoptero::Helicoptero()
{

}

void Helicoptero::desenha()
{
    glPushMatrix();
        Objeto::desenha();


        glRotatef(180, 1, 0, 0);
        glRotatef(90, 0, 1, 0);
        glScalef(0.25, 0.25, 0.25);
        glTranslatef(0, 0.33, 0.5);
        GUI::setColor(0, 0.75, 1);
        //cabine
        glPushMatrix();
            glBegin(GL_POLYGON);
                glNormal3f(0, 0, 1);
                glVertex3f(0, 0, 0);
                glVertex3f(0, 1, 0);
                glVertex3f(-1, 0, 0);
            glEnd();

            glBegin(GL_POLYGON);
                glNormal3f(0, 0, 1);
                glVertex3f(0, 0, -1);
                glVertex3f(-1, 0, -1);
                glVertex3f(0, 1, -1);
            glEnd();

            glBegin(GL_POLYGON);
                glNormal3f(0, 1, 1);
                glVertex3f(0, 1, 0);
                glVertex3f(0, 1, -1);
                glVertex3f(-1, 0, -1);
                glVertex3f(-1, 0, 0);
            glEnd();

            glBegin(GL_POLYGON);
                glNormal3f(0, -1, 0);
                glVertex3f(0, 0, 0);
                glVertex3f(-1, 0, 0);
                glVertex3f(-1, 0, -1);
                glVertex3f(0, 0, -1);
            glEnd();
        glPopMatrix();

        glPushMatrix();
            GUI::setColor(1, 0.49, 0.25);
            //corpo
            glPushMatrix();
                Objeto::cubo();
            glPopMatrix();

            //pouso
            glPushMatrix();
                glPushMatrix();
                    glScalef(0.2, 0.2, 0.2);
                    glPushMatrix();
                        glTranslatef(0, -1, 0);
                        Objeto::cubo();
                    glPopMatrix();
                    glPushMatrix();
                        glTranslatef(0, -1, -4);
                        Objeto::cubo();
                    glPopMatrix();
                    glPushMatrix();
                        glTranslatef(4, -1, 0);
                        Objeto::cubo();
                    glPopMatrix();
                    glPushMatrix();
                        glTranslatef(4, -1, -4);
                        Objeto::cubo();
                    glPopMatrix();
                glPopMatrix();

                glPushMatrix();
                    glTranslatef(-0.2, -0.2, 0);
                    glScalef(1.4, 0.15, 0.2);
                    glPushMatrix();
                        glTranslatef(0, -1, 0);
                        Objeto::cubo();
                    glPopMatrix();
                    glPushMatrix();
                        glTranslatef(0, -1, -4);
                        Objeto::cubo();
                    glPopMatrix();
                glPopMatrix();
            glPopMatrix();

            //cauda
            GUI::setColor(1, 0.19, 0.19);
            glPushMatrix();
                glPushMatrix();
                    glTranslated(1, 0.4, -0.3);
                    glScalef(0.8, 0.4, 0.4);
                    Objeto::cubo();
                glPopMatrix();
                glPushMatrix();
                    glTranslatef(1.8, 0.4, -0.3);
                    glScalef(0.4, 0.4, 0.4);
                    glBegin(GL_POLYGON);
                        glNormal3f(0, 0, 1);
                        glVertex3f(0, 0, 0);
                        glVertex3f(1, 0, 0);
                        glVertex3f(0, 1, 0);
                    glEnd();
                    glBegin(GL_POLYGON);
                        glNormal3f(0, 0, 1);
                        glVertex3f(0, 0, -1);
                        glVertex3f(0, 1, -1);
                        glVertex3f(1, 0, -1);
                    glEnd();
                    glBegin(GL_POLYGON);
                        glNormal3f(0, -1, 0);
                        glVertex3f(0, 0, 0);
                        glVertex3f(0, 0, -1);
                        glVertex3f(1, 0, -1);
                        glVertex3f(1, 0, 0);
                    glEnd();
                    glBegin(GL_POLYGON);
                        glNormal3f(1, 1, 0);
                        glVertex3f(0, 1, 0);
                        glVertex3f(1, 0, 0);
                        glVertex3f(1, 0, -1);
                        glVertex3f(0, 1, -1);
                    glEnd();
                glPopMatrix();
            glPopMatrix();

            //helice
            GUI::setColor(1, 0.84, 0);
            glPushMatrix();
                glTranslatef(0.5, 1, -0.5);
                glRotatef(h, 0, 1, 0);
                glTranslatef(-0.5, -1, 0.5);
                glPushMatrix();
                    glTranslatef(0.4, 1, -0.4);
                    glScalef(0.3, 0.3, 0.3);
                    Objeto::cubo();
                glPopMatrix();
                glPushMatrix();
                    glTranslatef(0.7, 1.1, -0.4);
                    glScalef(1, 0.3, 0.3);
                    Objeto::cubo();
                glPopMatrix();
                glPushMatrix();
                    glTranslatef(0.7, 1.1, -0.4);
                    glRotatef(90, 0, 1, 0);
                    glScalef(1.3, 0.3, 0.3);
                    Objeto::cubo();
                glPopMatrix();
                glPushMatrix();
                    glTranslatef(0.7, 1.1, -0.7);
                    glRotatef(180, 0, 1, 0);
                    glScalef(1.3, 0.3, 0.3);
                    Objeto::cubo();
                glPopMatrix();
                glPushMatrix();
                    glTranslatef(0.4, 1.1, -0.7);
                    glRotatef(270, 0, 1, 0);
                    glScalef(1.3, 0.3, 0.3);
                    Objeto::cubo();
                glPopMatrix();
            glPopMatrix();

        glPopMatrix();

    glPopMatrix();
    h += 1;
    h %= 360;
}
