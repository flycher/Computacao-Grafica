#include <iostream>

using namespace std;

#include<Curva.h>
#include<DoisCaraNumaMoto.h>

Curva *curva = new Curva();
DoisCaraNumaMoto *doisuma = new DoisCaraNumaMoto();
float delta_u = 0.1;
bool mover = false;
Camera *cameraH = new CameraJogo();
Camera *cameraD = new CameraDistante(Vetor3D(-5, 7, 15), Vetor3D(), Vetor3D(0, 1, 0));
Camera *principal;
Camera *secundaria;
bool visao = true;
bool vision = true;
//-------------------picking------------------
vector<Vetor3D> pontosControle;

int pontoSelecionado = 0; //names = [1,n] //n = pontosControle.size()
//bool transPontos = glutGUI::trans_obj; //= true;

void desenhaPontosDeControle()
{
    //desenhando pontos de controle
    for (int i=0; i<pontosControle.size(); i++) {
        //definindo cor da selecao
        if (i == pontoSelecionado-1) {
            GUI::setColor(1,1,1,1,true);
        } else {
            GUI::setColor(0,0,1,1,true);
        }
        //desenhando (definindo nomes para o picking)
        Vetor3D p = pontosControle[i];
        glPushName(i+1); //não se deve definir name = 0!
            GUI::drawSphere(p.x,p.y,p.z,0.075);
        glPopName();
    }
}

//picking
int picking( GLint cursorX, GLint cursorY, int w, int h ) {
    int BUFSIZE = 512;
    GLuint selectBuf[512];

    GUI::pickingInit(cursorX,cursorY,w,h,selectBuf,BUFSIZE);

//de acordo com a implementacao original da funcao display
    //lembrar de nao inicializar a matriz de projecao, para nao ignorar a gluPickMatrix
    GUI::displayInit();
    //só precisa desenhar o que for selecionavel
    desenhaPontosDeControle();
//fim-de acordo com a implementacao original da funcao display

    //retornando o name do objeto (ponto de controle) mais proximo da camera (z minimo! *[matrizes de normalizacao da projecao])
    return GUI::pickingClosestName(selectBuf,BUFSIZE);
}
//-------------------picking------------------

//-------------------viewPorts------------------
bool viewports = false;
bool scissored = false;

void cenario();

//visao de duas cameras (duas viewports), viewport auxiliar sobrepondo a principal
void viewPorts() {
    float width = glutGUI::width;
    float height = glutGUI::height;

    if(visao)
    {
        principal = cameraD;
        secundaria = cameraH;
    }
    else
    {
        principal = cameraH;
        secundaria = cameraD;
    }

    //viewport principal
    glViewport(0, 0, width, height);
        glLoadIdentity();
        gluLookAt(principal->e.x,principal->e.y,principal->e.z,
                  principal->c.x,principal->c.y,principal->c.z,
                  principal->u.x,principal->u.y,principal->u.z);
            cenario();

    //viewport auxiliar sobrepondo a principal
    if (!scissored) {
        //misturando com a principal
        glViewport(0, 3*height/4, width/4, height/4);
    } else {
        //recortando/substituindo o pedaço
        GUI::glScissoredViewport(0, 3*height/4, width/4, height/4);
    }
        glLoadIdentity();
        gluLookAt(secundaria->e.x, secundaria->e.y, secundaria->e.z,
                  secundaria->u.x, secundaria->u.y, secundaria->u.z,
                  secundaria->c.x, secundaria->c.y, secundaria->c.z);
            cenario();

    glLoadIdentity();
    glMatrixMode (GL_PROJECTION);
        glPushMatrix ();
            glLoadIdentity ();
            glLineWidth(100);
            GUI::setColor(0, 0, 0);
            glBegin (GL_LINES);
                glVertex3i (-1, -1, -1);
                glVertex3i (1, -1, -1);
                glVertex3i (1, 1, -1);
                glVertex3i (-1, 1, -1);
                glVertex3i (-1, -1, -1);
                glVertex3i (-1, 1, -1);
                glVertex3i (1, -1, -1);
                glVertex3i (1, 1, -1);
            glEnd ();
        glPopMatrix ();
    glMatrixMode(GL_MODELVIEW);

}
//-------------------viewPorts------------------

void cenario() {
    //GUI::setLight(1,1,3,5,true,false);
    //GUI::setLight(2,-1.5,0.5,-1,true,false);
    GUI::setLight(3,-5,3,5,true,false);

    GUI::drawOrigin(0.5);

    //GUI::setColor(1,0,0);
    //GUI::drawFloor();
    GUI::setColor(0,0,0);
    Desenha::drawGrid(10, 0, 10, 2 );

    desenhaPontosDeControle();

    //transladando ponto selecionado atraves do picking
    //if (pontoSelecionado > 0 and pontoSelecionado <= objetos.size()) {
    if (pontoSelecionado!=0) {
        pontosControle[pontoSelecionado-1].x += glutGUI::dtx;
        pontosControle[pontoSelecionado-1].y += glutGUI::dty;
        pontosControle[pontoSelecionado-1].z += glutGUI::dtz;
    }

    if(pontosControle.size() >= 4)
    {
        curva->desenhaCurva(pontosControle, delta_u);
        doisuma->desenhaNaCurva(*curva, pontosControle, *cameraH);
        if(mover)
            doisuma->mover();
    }
}

void desenha() {
    GUI::displayInit();

    if (!viewports) {
        cenario();
    } else {
        viewPorts();
    }

    glEnable(GL_CULL_FACE);

    GUI::displayEnd();
}

void teclado(unsigned char key, int x, int y) {
    GUI::keyInit(key,x,y);

    switch (key) {
    case 't':
        glutGUI::trans_obj = !glutGUI::trans_obj;
        //transPontos = glutGUI::trans_obj;
        break;
    case 'l':
        glutGUI::trans_luz = !glutGUI::trans_luz;
        break;

    case 'a':
        pontosControle.push_back(Vetor3D(0, 0, 0));
        break;

    case 'd':
        if(pontoSelecionado != 0)
            pontosControle.erase(pontosControle.begin()+pontoSelecionado-1, pontosControle.begin()+pontoSelecionado);
        break;

    case 'I':
        curva->mudaMatriz(I);
        break;

    case 'H':
        curva->mudaMatriz(H);
        break;

    case 'B':
        curva->mudaMatriz(B);
        break;

    case 'M':
        curva->mudaMatriz(CM);
        break;

    case 'S':
        curva->mudaMatriz(BS);
        break;

    case '-':
        if(delta_u <= 1)
            delta_u += 0.01;
        break;

    case '+':
        if(delta_u > 0.0125)
            delta_u -= 0.01;
        break;

    case 'P':
        mover = !mover;
        break;

    case 'q':
        mover = false;
        doisuma->mudaDirecao(-1);
        break;

    case 'e':
        mover = false;
        doisuma->mudaDirecao(1);
        break;

    case 'Q':
        visao = !visao;
        break;

    case 'E':
        if(vision)
        {
            glutGUI::cam = cameraD;
        }
        else
        {
            glutGUI::cam = cameraH;
        }
        vision = !vision;
        break;

    case 'v':
        viewports = !viewports;
        break;
    case 'V':
        scissored = !scissored;
        break;

    default:
        break;
    }
}

void mouse(int button, int state, int x, int y) {
    GUI::mouseButtonInit(button,state,x,y);

    // if the left button is pressed
    if (button == GLUT_LEFT_BUTTON) {
        // when the button is pressed
        if (state == GLUT_DOWN) {
            //picking
            int pick = picking( x, y, 5, 5 );
            if (pick != 0) {
                pontoSelecionado = pick;
                glutGUI::lbpressed = false;
            }
        }
    }
}

int main()
{
    pontosControle.push_back(Vetor3D(-5, 2, -8));
    pontosControle.push_back(Vetor3D(7, 4, 3));
    pontosControle.push_back(Vetor3D(-8, -1, 2));
    pontosControle.push_back(Vetor3D(4, -2, 3));
    glutGUI::cam = cameraD;
    GUI gui = GUI(800,600,desenha,teclado,mouse);
}
