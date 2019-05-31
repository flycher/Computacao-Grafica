#ifndef CURVA_H
#define CURVA_H

#include<gui.h>
#include<vector>
#include<Pista.h>

enum matriz {I, H, B, CM, BS};

class Curva
{
public:
    vector<vector<float>> Matriz;
    Pista *pista;

    Curva();
    vector<vector<float>> Interpoladora();
    vector<vector<float>> Hermite();
    vector<vector<float>> Bezier();
    vector<vector<float>> CatmullRom();
    vector<vector<float>> Bspline();
    void mudaMatriz(matriz M);
    Vetor3D pT(float u, const vector<Vetor3D>& points, int degree);
    void desenhaCurva(const vector<Vetor3D> &pontosControle, float delta_u);
};

#endif // CURVA_H
