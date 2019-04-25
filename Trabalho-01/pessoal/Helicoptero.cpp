#include "Helicoptero.h"

Helicoptero::Helicoptero()
{
    tipo = HELICOPTERO;
}

void Helicoptero::desenha()
{
    glPushMatrix();
        Objeto::desenha();

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
}

void Helicoptero::atualiza(float a)
{
    this->h += a;
}


void Helicoptero::audioCallback(void* userData, Uint8* stream, int streamLength)
{
    AudioData* audio = (AudioData*)userData;

    if (audio->length == 0)
    {
    return;
    }
    Uint32 length = (Uint32)streamLength;

    length = (length > audio->length ? audio->length : length);

    SDL_memcpy(stream, audio->position, length);

    audio->position += length;
    audio->length -= length;
}

void Helicoptero::playAudio()
{
    SDL_Init(SDL_INIT_AUDIO);

    SDL_AudioSpec wavSpec;
    Uint8* wavStart;
    Uint32 wavLength;
    char* filePath = "../sound/datena.wav";

    if(SDL_LoadWAV(filePath, &wavSpec, &wavStart, &wavLength) == NULL)
    {
        //std::cerr << "Error: file could not be loaded as an audio file." << std::endl;
        return;
    }

    AudioData audio;
    audio.position = wavStart;
    audio.length = wavLength;

    wavSpec.callback = audioCallback;
    wavSpec.userdata = &audio;

    SDL_AudioDeviceID audioDevice;
    audioDevice = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, SDL_AUDIO_ALLOW_ANY_CHANGE);

    if (audioDevice == 0)
    {
        //std::cerr << "Error: " << SDL_GetError() << std::endl;
        return;
    }

    SDL_PauseAudioDevice(audioDevice, 0);

    while (audio.length > 0)
    {
        SDL_Delay(100);
    }

    SDL_CloseAudioDevice(audioDevice);
    SDL_FreeWAV(wavStart);
    SDL_Quit();

    return;
}

void Helicoptero::camera() {
    cam = new CameraJogo(t, Vetor3D(-t.x, -t.y, -t.z), Vetor3D(0, 1, 0));
    glutGUI::cam = cam;
    playAudio();
}
