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
        GUI::setColor(1, 0, 0);
        glBegin(GL_POLYGON);
        glNormal3f(0, 0, 1);
        for (int i = 0; i < num_segments; i++)   {
            float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
            float z = cosf(theta);
            float x = sinf(theta);
            glVertex3f(x, 0, z);
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
        glNormal3f(0, 0, -1);
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
