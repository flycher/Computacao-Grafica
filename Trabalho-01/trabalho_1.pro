TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += bib
INCLUDEPATH += gui_glut
INCLUDEPATH += pessoal

LIBS += -lGL -lGLU -lglut -l3ds -lSDL2_image -lSDL2

SOURCES += \
    main.cpp \
    bib/Camera.cpp \
    bib/CameraDistante.cpp \
    bib/CameraJogo.cpp \
    bib/Desenha.cpp \
    bib/model3ds.cpp \
    bib/Vetor3D.cpp \
    gui_glut/extra.cpp \
    gui_glut/gui.cpp \
    pessoal/Personagem.cpp \
    pessoal/Objeto.cpp \
    pessoal/Helicoptero.cpp \
    pessoal/Veiculo.cpp \
    pessoal/Imovel.cpp \
    pessoal/DoisCaraNumaMoto.cpp \
    pessoal/Pantheon.cpp

HEADERS += \
    bib/Camera.h \
    bib/CameraDistante.h \
    bib/CameraJogo.h \
    bib/Desenha.h \
    bib/model3ds.h \
    bib/Vetor3D.h \
    gui_glut/extra.h \
    gui_glut/gui.h \
    pessoal/Personagem.h \
    pessoal/Objeto.h \
    pessoal/Helicoptero.h \
    pessoal/Veiculo.h \
    pessoal/Imovel.h \
    pessoal/DoisCaraNumaMoto.h \
    pessoal/Pantheon.h

DISTFILES += \
    3ds/apartamento1.3DS \
    3ds/apartamento2.3DS \
    3ds/bicicleta.3DS \
    3ds/carro1.3DS \
    3ds/carro2.3DS \
    3ds/casa1.3DS \
    3ds/casa2.3DS \
    3ds/moto.3DS \
    3ds/2cara1moto.3DS \
    sound/datena.wav \
    save/cenario.txt \
    save/save.txt
