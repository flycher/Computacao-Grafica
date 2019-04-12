#include "Objeto.h"

Objeto::Objeto()
{

}

void Objeto::desenha()
{
    glTranslatef(t.x,t.y,t.z);
    glRotatef(a.z,0,0,1);
    glRotatef(a.y,0,1,0);
    glRotatef(a.x,1,0,0);

    if (selecionado) {
        int num_segments = 36;
        GUI::setColor(0, 1, 0);
        glBegin(GL_POLYGON);
        glNormal3f(0, 0, -1);
        for (int ii = 0; ii < num_segments; ii++)   {
            float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle
            float z = cosf(theta);//calculate the x component
            float x = sinf(theta);//calculate the y component
            glVertex3f(x, 0, z);//output vertex
        }
        glEnd();
    }
    if(origem) {
        GUI::drawOrigin(1);
    }

    glScalef(s.x,s.y,s.z);
}

void Objeto::cubo()
{
    glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);
        glVertex3f(1, 1, 0);
        glVertex3f(0, 1, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(1, 0, 0);
    glEnd();

    glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);
        glVertex3f(0, 0, -1);
        glVertex3f(0, 1, -1);
        glVertex3f(1, 1, -1);
        glVertex3f(1, 0, -1);
    glEnd();

    glBegin(GL_QUADS);
        glNormal3f(-1, 0, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 1, 0);
        glVertex3f(0, 1, -1);
        glVertex3f(0, 0, -1);
    glEnd();

    glBegin(GL_QUADS);
        glNormal3f(1, 0, 0);
        glVertex3f(1, 0, -1);
        glVertex3f(1, 1, -1);
        glVertex3f(1, 1, 0);
        glVertex3f(1, 0, 0);
    glEnd();

    glBegin(GL_QUADS);
        glNormal3f(0, 1, 0);
        glVertex3f(0, 1, 0);
        glVertex3f(1, 1, 0);
        glVertex3f(1, 1, -1);
        glVertex3f(0, 1, -1);
    glEnd();

    glBegin(GL_QUADS);
        glNormal3f(0, -1, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 0, -1);
        glVertex3f(1, 0, -1);
        glVertex3f(1, 0, 0);
    glEnd();
}
