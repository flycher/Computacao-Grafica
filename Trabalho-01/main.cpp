
#include <iostream>
#include <fstream>

using namespace std;

#include <vector>

#include "Personagem.h"
#include "Helicoptero.h"
#include "Veiculo.h"
#include "Imovel.h"
#include "DoisCaraNumaMoto.h"
#include "Pantheon.h"

vector<Objeto*> objetos;
vector<Camera*> cameras;
vector<Camera*> camerasO;
vector<Camera*> camerasP;

int posSelecionado = -1;
int posCam = -1;
int posCamO = -1;
int posCamP = -1;

//-------------------sombra-------------------
bool drawShadow = false;
bool pontual = true;
vector<GLfloat*> planos;
//-------------------sombra-------------------

void salvaCenario()
{
    ofstream file_obj("../save/salvo.txt");

    file_obj << objetos.size() << '\n';
    for(auto obj: objetos){
       file_obj << obj->tipo << '\n';
       file_obj << obj->t.x << '\n' << obj->t.y << '\n' << obj->t.z << '\n';
       file_obj << obj->a.x << '\n' << obj->a.y << '\n' << obj->a.z << '\n';
       file_obj << obj->s.x << '\n' << obj->s.y << '\n' << obj->s.z << '\n';
    }
}

void carregaCenario(string arquivo) {
    ifstream file_obj(arquivo);

    string atual;
    getline(file_obj, atual);
    int n = strtof(atual.c_str(),0);

    int tipo;
    float t[3], a[3], s[3];
    for(int i = 0; i < n; i++)
    {
        getline(file_obj, atual);
        tipo = strtof(atual.c_str(),0);
        getline(file_obj, atual);
        t[0] = strtof(atual.c_str(),0);
        getline(file_obj, atual);
        t[1] = strtof(atual.c_str(),0);
        getline(file_obj, atual);
        t[2] = strtof(atual.c_str(),0);
        getline(file_obj, atual);
        a[0] = strtof(atual.c_str(),0);
        getline(file_obj, atual);
        a[1] = strtof(atual.c_str(),0);
        getline(file_obj, atual);
        a[2] = strtof(atual.c_str(),0);
        getline(file_obj, atual);
        s[0] = strtof(atual.c_str(),0);
        getline(file_obj, atual);
        s[1] = strtof(atual.c_str(),0);
        getline(file_obj, atual);
        s[2] = strtof(atual.c_str(),0);

        switch (tipo) {
        case PERSONAGEM:
            objetos.push_back( new Personagem() );
            break;

        case HELICOPTERO:
            objetos.push_back( new Helicoptero() );
            break;

        case CARRO1:
            objetos.push_back( new Veiculo(CARRO1) );
            break;

        case CARRO2:
            objetos.push_back( new Veiculo(CARRO2) );
            break;

        case MOTO:
            objetos.push_back( new Veiculo(MOTO) );
            break;

        case BICICLETA:
            objetos.push_back( new Veiculo(BICICLETA) );
            break;

        case IMOVEL1:
            objetos.push_back( new Imovel(IMOVEL1) );
            break;

        case IMOVEL2:
            objetos.push_back( new Imovel(IMOVEL2) );
            break;

        case CARASMOTO:
            objetos.push_back( new DoisCaraNumaMoto());
            break;

        case PANTHEON:
            objetos.push_back( new Pantheon());
            break;

        default:
            break;
        }
        objetos[i]->t = Vetor3D(t[0], t[1], t[2]);
        objetos[i]->a = Vetor3D(a[0], a[1], a[2]);
        objetos[i]->s = Vetor3D(s[0], s[1], s[2]);
    }
}

void desenha() {
    GUI::displayInit();


    //GUI::setLight(0,10,10,10,true,false);
    //GUI::setLight(1,-10,10,-10,true,false);


    GUI::drawOrigin(1);

    GUI::setColor(0,1,0);
    //GUI::drawFloor(10, 10);

    //-------------------bottom-------------------
    glPushMatrix();
        glTranslated(0.0,-0.01,0.0);
        GUI::drawFloor(20,20);
    glPopMatrix();
    if(drawShadow)
    {
        //-------------------back-------------------
        glPushMatrix();
            glTranslated(0.0,5.0,-10-0.01);
            glRotatef(45, 1, 0, 0);
            GUI::drawFloor(20,20);
        glPopMatrix();

        //-------------------front-------------------
        glPushMatrix();
            glTranslated(0.0,5.0,10+0.01);
            glRotatef(-45, 1, 0, 0);
            GUI::drawFloor(20,20);
        glPopMatrix();

        //-------------------left-------------------
        glPushMatrix();
            glTranslated(-5-0.01,10.0,0.0);
            glRotated(-90, 0, 0, 1);
            GUI::drawFloor(20,20);
        glPopMatrix();

        //-------------------right-------------------
        glPushMatrix();
            glTranslated(5+0.01,10.0,0.0);
            glRotatef(90, 0, 0, 1);
            GUI::drawFloor(20,20);
        glPopMatrix();
        //----------------
    }
    for (int i = 0; i < objetos.size(); ++i) {
        glPushMatrix();
            objetos[i]->atualiza(5);
            objetos[i]->desenha();
        glPopMatrix();
    }

    if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
        objetos[posSelecionado]->t.x += glutGUI::dtx;
        objetos[posSelecionado]->t.y += glutGUI::dty;
        objetos[posSelecionado]->t.z += glutGUI::dtz;

        objetos[posSelecionado]->a.x += glutGUI::dax;
        objetos[posSelecionado]->a.y += glutGUI::day;
        objetos[posSelecionado]->a.z += glutGUI::daz;

        objetos[posSelecionado]->s.x += glutGUI::dsx;
        objetos[posSelecionado]->s.y += glutGUI::dsy;
        objetos[posSelecionado]->s.z += glutGUI::dsz;
    }

    //-------------------sombra-------------------
    //definindo a luz que sera usada para gerar a sombra
    float lightPos[4] = {0+glutGUI::lx,5+glutGUI::ly,0+glutGUI::lz,pontual};
    //GUI::setLight(0,lightPos[0],lightPos[1],lightPos[2],true,false,false,false,pontual);
    GUI::setLight(0,0,5,0,true,false,false,false,pontual);
    //desenhando os objetos projetados
    glDisable(GL_LIGHTING);
    glColor4d(0.0,0.0,0.0, 0.7);
    for(int i = 0; i < planos.size(); i++) {
        glPushMatrix();
                //matriz de projecao para gerar sombra no plano y=k
                GLfloat sombra[4][4];
                //GUI::shadowMatrixYk(sombra,lightPos,k);
                //GLfloat plano[4] = {0,1,0,-k};
                GUI::shadowMatrix(sombra,planos[i],lightPos);
                glMultTransposeMatrixf( (GLfloat*)sombra );

                if (drawShadow) {
                    bool aux = glutGUI::draw_eixos;
                    glutGUI::draw_eixos = false;
                    for (int i = 0; i < objetos.size(); ++i) {
                        glPushMatrix();
                            if(objetos[i]->sombra)
                                objetos[i]->desenha();
                        glPopMatrix();
                    }
                    glutGUI::draw_eixos = aux;
                }
        glPopMatrix();
    }
    glEnable(GL_LIGHTING);
    //-------------------sombra-------------------

    glEnable(GL_CULL_FACE);
    GUI::displayEnd();
}

bool incluirObjeto = false;

void teclado(unsigned char key, int x, int y) {
    //if (!incluirObjeto) {
        GUI::keyInit(key,x,y);
    //}

    switch (key) {
    case 't':
        glutGUI::trans_obj = !glutGUI::trans_obj;
        break;
    case 'l':
        glutGUI::trans_luz = !glutGUI::trans_luz;
        break;

    //----------sombra
    case 'L':
        drawShadow = !drawShadow;
        break;

    case 'W':
        pontual = !pontual;
        break;

    //----------projeção
    case '(':
        glutGUI::anglePerspective++;
        break;
    case ')':
        glutGUI::anglePerspective--;
        break;
    case '[':
        glutGUI::obliquaX++;
        break;
    case ']':
        glutGUI::obliquaX--;
        break;
    case '{':
        glutGUI::obliquaY++;
        break;
    case '}':
        glutGUI::obliquaY--;
        break;

    case '=':
        glutGUI::perspective = 1;
        posCamO++;
        if (posCamO >= camerasO.size()) {
            posCamO = 0;
        }
        glutGUI::cam = new CameraDistante(camerasO[posCamO]->e, camerasO[posCamO]->c, camerasO[posCamO]->u);
        break;

    case '-':
        glutGUI::perspective = 0;
        posCamP++;
        if (posCamP >= camerasP.size()) {
            posCamP = 0;
        }
        glutGUI::cam = new CameraDistante(camerasP[posCamP]->e, camerasP[posCamP]->c, camerasP[posCamP]->u);
        break;

    case 'k':
        if(posSelecionado >= 0 and posSelecionado < objetos.size())
        {
            objetos[posSelecionado]->origem = !objetos[posSelecionado]->origem;
        }
        break;

    case 's':
    if(posSelecionado >= 0 and posSelecionado < objetos.size())
    {
        objetos[posSelecionado]->sombra = !objetos[posSelecionado]->sombra;
    }
    break;

    case 'n':
        if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
            objetos[posSelecionado]->selecionado = false;
        }
        posSelecionado++;
        if (posSelecionado >= objetos.size()) {
            posSelecionado = 0;
        }
        if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
            objetos[posSelecionado]->selecionado = true;
        }
        break;

    case 'b':
        if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
            objetos[posSelecionado]->selecionado = false;
        }
        posSelecionado--;
        if (posSelecionado < 0) {
            posSelecionado = objetos.size()-1;
        }
        if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
            objetos[posSelecionado]->selecionado = true;
        }
        break;

    case 'O':
        incluirObjeto = !incluirObjeto;
        break;

    case 'p':
        if (incluirObjeto) {
            objetos.push_back( new Personagem() );
        }
        break;

    case 'P':
        if (incluirObjeto) {
            objetos.push_back( new Pantheon() );
        }
        break;

    case 'h':
        if (incluirObjeto) {
            objetos.push_back( new Helicoptero() );
        }
        break;

    case 'v':
        if (incluirObjeto) {
            objetos.push_back( new Veiculo(CARRO1) );
        }
        break;

    case 'V':
        if (incluirObjeto) {
            objetos.push_back( new Veiculo(CARRO2) );
        }
        break;

    case 'g':
        if (incluirObjeto) {
            objetos.push_back( new Veiculo(MOTO) );
        }
        break;

    case 'G':
        if (incluirObjeto) {
            objetos.push_back( new Veiculo(BICICLETA) );
        }
        break;

    case 'i':
        if (incluirObjeto) {
            objetos.push_back( new Imovel(IMOVEL1) );
        }
        break;

    case 'I':
        if (incluirObjeto) {
            objetos.push_back( new Imovel(IMOVEL2) );
        }
        break;

    case 'a':
        if(incluirObjeto) {
            objetos.push_back( new DoisCaraNumaMoto());
        }
        break;

    case 'd':
        if(posSelecionado >= 0 and posSelecionado < objetos.size()) {
            objetos.erase(objetos.begin() + posSelecionado, objetos.begin() + posSelecionado + 1);
        }
        if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
            objetos[posSelecionado]->selecionado = true;
        }
        break;

    case 'D':
        if(!objetos.empty())
            objetos.pop_back();
        break;

    case 'q':
        if(posSelecionado >= 0 and posSelecionado < objetos.size()) {
            objetos[posSelecionado]->camera();
        }
        break;

    case 'Q':
        glutGUI::cam = new CameraDistante(Vetor3D(0, 10, 15), Vetor3D(0, 0, 0), Vetor3D(0, 1, 0));
        break;

    case 'e':
        posCam++;
        if (posCam >= cameras.size()) {
            posCam = 0;
        }
        glutGUI::cam = new CameraDistante(cameras[posCam]->e, cameras[posCam]->c, cameras[posCam]->u);
        break;

    case 'E':
        glutGUI::cam = new CameraDistante(Vetor3D(0, 10, 15), Vetor3D(0, 0, 0), Vetor3D(0, 1, 0));
        break;

    case 'S':
        salvaCenario();
        break;

    default:
        break;
    }
}

void instrucoes()
{
    cout << "Teclas para adicionar objetos" << endl;
    cout << " 'i' : Imovel 1" << endl;
    cout << " 'I' : Imovel 2" << endl;
    cout << " 'v' : Veiculo 1" << endl;
    cout << " 'V' : Veiculo 2" << endl;
    cout << " 'g' : Moto" << endl;
    cout << " 'G' : Bicicleta" << endl;
    cout << " 'p' : Personagem" << endl;
    cout << " 'P' : Pantheon" << endl;
    cout << " 'h' : Helicoptero" << endl;
    cout << " 'a' : 2 caras numa moto" << endl;
    cout << endl;
    cout << "'n' para selecionar proximo, 'b' para selecionar anterior" << endl;
    cout << "O objeto selecionado exibira um circulo vermelho em baixo de si" << endl;
    cout << "'d' para apagar o objeto selecionado, 'D' para apagar o ultimo objeto" << endl;
    cout << "Se um personagem ou helicoptero estiver selecionado, 'q' para mudar a camera" << endl;
    cout << "Para as cameras alternativas, 'e'" << endl;
    cout << "'Q' ou 'E' para voltar a camera padrao" << endl;
    cout << "'L' para ativar/desativar sombras" << endl;
    cout << "'s' para ativar/desativar sombra do objeto selecionado" << endl;
    cout << "'W' para mudar perspectiva de luz" << endl;
    cout << "'o' para mudar perspectiva de visão" << endl;
    cout << "'-' para visões perspectivas clássicas" << endl;
    cout << "'=' para visões ortogonais clássicas" << endl;
    cout << "'S' para salvar o cenario atual" << endl;
    cout << "Digite 1 para carregar o cenário modelado, 2 para um cenário salvo" << endl;
    cout << "qualquer outro para um cenário novo" << endl;
    cout << "-> ";
    int op;
    cin >> op;
    switch (op) {
    case 1:
        carregaCenario("../save/cenario.txt");
        break;

    case 2:
        carregaCenario("../save/salvo.txt");
        break;

    default:
        break;
    }
}

int main()
{
    cameras.push_back(new CameraDistante(Vetor3D(0, 20, 0.1), Vetor3D(0, 0, 0), Vetor3D(0, 1, 0)));
    cameras.push_back(new CameraDistante(Vetor3D(20, 5, 5), Vetor3D(0, 0, 0), Vetor3D(0, 1, 0)));
    cameras.push_back(new CameraDistante(Vetor3D(10, 5, 20), Vetor3D(0, 0, 0), Vetor3D(0, -1, 0)));

    //clássicas ortogonais
    camerasO.push_back(new CameraDistante(Vetor3D(0, 0, 10), Vetor3D(), Vetor3D(0, 1, 0)));
    camerasO.push_back(new CameraDistante(Vetor3D(5, 5, 5), Vetor3D(0.7, 1.3, 0), Vetor3D(0, 1, 0)));
    camerasO.push_back(new CameraDistante(Vetor3D(5, 2, 5), Vetor3D(0.7, 1.3, 0), Vetor3D(0, 1, 0)));
    camerasO.push_back(new CameraDistante(Vetor3D(5, 7, 2), Vetor3D(0.7, 1.3, 0), Vetor3D(0, 1, 0)));

    //pontos de fuga perspectiva
    camerasP.push_back(new CameraDistante(Vetor3D(0, 0, 10), Vetor3D(), Vetor3D(0, 1, 0)));
    camerasP.push_back(new CameraDistante(Vetor3D(5, 0, 5), Vetor3D(), Vetor3D(0, 1, 0)));
    camerasP.push_back(new CameraDistante(Vetor3D(4, 2, 7), Vetor3D(), Vetor3D(0, 1, 0)));


    instrucoes();

    glutGUI::cam = new CameraDistante(Vetor3D(0, 10, 15), Vetor3D(0, 0, 0), Vetor3D(0, 1, 0));

    //-------------------sombra-------------------
    GLfloat plano_d[4] = {0,1,0,0};
    planos.push_back(plano_d);
    GLfloat plano_b[4] = {0,1,1,5};
    planos.push_back(plano_b);
    GLfloat plano_f[4] = {0,1,-1,5};
    planos.push_back(plano_f);
    GLfloat plano_l[4] = {1,0,0,5};
    planos.push_back(plano_l);
    GLfloat plano_r[4] = {-1,0,0,5};
    planos.push_back(plano_r);
    //-------------------sombra-------------------

//    objetos.push_back(new Pantheon());

    GUI gui = GUI(800,600,desenha,teclado);
}
