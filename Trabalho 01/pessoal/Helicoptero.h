#ifndef HELICOPTERO_H
#define HELICOPTERO_H

#include "Objeto.h"

class Helicoptero : public Objeto
{
public:
    float h = 0;
    CameraJogo *cam;

    Helicoptero();
    void desenha();
    void atualiza(float a);
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
