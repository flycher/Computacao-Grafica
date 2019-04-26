#ifndef HELICOPTERO_H
#define HELICOPTERO_H

#include "Objeto.h"

class Helicoptero : public Objeto
{
public:
    int h = rand()/360;
    CameraJogo *cam;

    Helicoptero();
    void desenha();
    void atualiza(int a);
    void camera();

    struct AudioData
    {
        Uint8* position;
        Uint32 length;
    };

    static void audioCallback(void* userData, Uint8* stream, int streamLength);

    void playAudio();
};

#endif // HELICOPTERO_H
