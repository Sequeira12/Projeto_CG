/* ===================================================================================
 Meta 02 2021/2022 Computacao Grafica
 Bruno Eduardo Machado Sequeira 2020235721
 ======================================================================================= */

#define HEADER_H_
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GLUT/GLUT.h>
#include "materiais.h"
#include "RgbImage.h"
#define PI         3.14159

//--------------------------------- Definir cores
#define BLUE     0.0, 0.0, 1.0, 1.0
#define RED         1.0, 0.0, 0.0, 1.0
#define YELLOW     1.0, 1.0, 0.0, 1.0
#define GREEN    0.0, 1.0, 0.0, 1.0
#define ORANGE   1.0, 0.5, 0.1, 1.0
#define CYAN     0.0, 1.0, 1.0, 1.0
#define WHITE    1.0, 1.0, 1.0, 1.0
#define BLACK    0.0, 0.0, 0.0, 1.0
#define GRAY     0.3, 0.3, 0.3, 1.0
#define PI         3.14159
void DesenhaRodas();
void DesenhaBasesCarro();
void DesenhaLuzesFrente();
void DesenhaPiscas();
void DesenhaMala();
void DesenhaPorta();
void Matriculas();
void DesenhaLuzes();

GLUquadricObj* esfera = gluNewQuadric();
GLfloat theta = 0.;
GLfloat vel = 1.;
GLfloat pos[] = { 0., 0., 0.};


void initMaterials(int material) {
    
    switch (material) {
        case 0: //……………………………………………………………………………………………esmerald
            glMaterialfv(GL_FRONT, GL_AMBIENT, esmeraldAmb);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, esmeraldDif);
            glMaterialfv(GL_FRONT, GL_SPECULAR, esmeraldSpec);
            glMaterialf(GL_FRONT, GL_SHININESS, esmeraldCoef);
            break;
        case 1: //……………………………………………………………………………………………jade
            glMaterialfv(GL_FRONT, GL_AMBIENT, jadeAmb);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, jadeDif);
            glMaterialfv(GL_FRONT, GL_SPECULAR, jadeSpec);
            glMaterialf(GL_FRONT, GL_SHININESS, jadeCoef);
            break;
        case 2: //……………………………………………………………………………………………obsidian
            glMaterialfv(GL_FRONT, GL_AMBIENT, obsidianAmb);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, obsidianDif);
            glMaterialfv(GL_FRONT, GL_SPECULAR, obsidianSpec);
            glMaterialf(GL_FRONT, GL_SHININESS, obsidianCoef);
            break;
        case 3: //……………………………………………………………………………………………pearl
            glMaterialfv(GL_FRONT, GL_AMBIENT, pearlAmb);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, pearlDif);
            glMaterialfv(GL_FRONT, GL_SPECULAR, pearlSpec);
            glMaterialf(GL_FRONT, GL_SHININESS, pearlCoef);
            break;
        case 4: //……………………………………………………………………………………………ruby
            glMaterialfv(GL_FRONT, GL_AMBIENT, rubyAmb);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, rubyDif);
            glMaterialfv(GL_FRONT, GL_SPECULAR, rubySpec);
            glMaterialf(GL_FRONT, GL_SHININESS, rubyCoef);
            break;
        case 5: //……………………………………………………………………………………………turquoise
            glMaterialfv(GL_FRONT, GL_AMBIENT, turquoiseAmb);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, turquoiseDif);
            glMaterialfv(GL_FRONT, GL_SPECULAR, turquoiseSpec);
            glMaterialf(GL_FRONT, GL_SHININESS, turquoiseCoef);
            break;
        case 6: //……………………………………………………………………………………………brass
            glMaterialfv(GL_FRONT, GL_AMBIENT, brassAmb);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, brassDif);
            glMaterialfv(GL_FRONT, GL_SPECULAR, brassSpec);
            glMaterialf(GL_FRONT, GL_SHININESS, brassCoef);
            break;
        case 7: //……………………………………………………………………………………………bronze
            glMaterialfv(GL_FRONT, GL_AMBIENT, bronzeAmb);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, bronzeDif);
            glMaterialfv(GL_FRONT, GL_SPECULAR, bronzeSpec);
            glMaterialf(GL_FRONT, GL_SHININESS, bronzeCoef);
            break;
        case 8: //……………………………………………………………………………………………chrome
            glMaterialfv(GL_FRONT, GL_AMBIENT, chromeAmb);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, chromeDif);
            glMaterialfv(GL_FRONT, GL_SPECULAR, chromeSpec);
            glMaterialf(GL_FRONT, GL_SHININESS, chromeCoef);
            break;
        case 9: //……………………………………………………………………………………………copper
            glMaterialfv(GL_FRONT, GL_AMBIENT, copperAmb);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, copperDif);
            glMaterialfv(GL_FRONT, GL_SPECULAR, copperSpec);
            glMaterialf(GL_FRONT, GL_SHININESS, copperCoef);
            break;
        case 10: //……………………………………………………………………………………………gold
            glMaterialfv(GL_FRONT, GL_AMBIENT, goldAmb);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, goldDif);
            glMaterialfv(GL_FRONT, GL_SPECULAR, goldSpec);
            glMaterialf(GL_FRONT, GL_SHININESS, goldCoef);
            break;
        case 11: //……………………………………………………………………………………………silver
            glMaterialfv(GL_FRONT, GL_AMBIENT, silverAmb);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, silverDif);
            glMaterialfv(GL_FRONT, GL_SPECULAR, silverSpec);
            glMaterialf(GL_FRONT, GL_SHININESS, silverCoef);
            break;
        case 12: //……………………………………………………………………………………………blackPlastic
            glMaterialfv(GL_FRONT, GL_AMBIENT, blackPlasticAmb);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, blackPlasticDif);
            glMaterialfv(GL_FRONT, GL_SPECULAR, blackPlasticSpec);
            glMaterialf(GL_FRONT, GL_SHININESS, blackPlasticCoef);
            break;
        case 13: //……………………………………………………………………………………………cyankPlastic
            glMaterialfv(GL_FRONT, GL_AMBIENT, cyanPlasticAmb);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, cyanPlasticDif);
            glMaterialfv(GL_FRONT, GL_SPECULAR, cyanPlasticSpec);
            glMaterialf(GL_FRONT, GL_SHININESS, cyanPlasticCoef);
            break;
        case 14: //……………………………………………………………………………………………greenPlastic
            glMaterialfv(GL_FRONT, GL_AMBIENT, greenPlasticAmb);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, greenPlasticDif);
            glMaterialfv(GL_FRONT, GL_SPECULAR, greenPlasticSpec);
            glMaterialf(GL_FRONT, GL_SHININESS, greenPlasticCoef);
            break;
        case 15: //……………………………………………………………………………………………redPlastic
            glMaterialfv(GL_FRONT, GL_AMBIENT, redPlasticAmb);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, redPlasticDif);
            glMaterialfv(GL_FRONT, GL_SPECULAR, redPlasticSpec);
            glMaterialf(GL_FRONT, GL_SHININESS, redPlasticCoef);
            break;
        case 16: //……………………………………………………………………………………………yellowPlastic
            glMaterialfv(GL_FRONT, GL_AMBIENT, whitePlasticAmb);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, whitePlasticDif);
            glMaterialfv(GL_FRONT, GL_SPECULAR, whitePlasticSpec);
            glMaterialf(GL_FRONT, GL_SHININESS, whitePlasticCoef);
            break;
        case 17: //……………………………………………………………………………………………yellowPlastic
            glMaterialfv(GL_FRONT, GL_AMBIENT, yellowPlasticAmb);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, yellowPlasticDif);
            glMaterialfv(GL_FRONT, GL_SPECULAR, yellowPlasticSpec);
            glMaterialf(GL_FRONT, GL_SHININESS, yellowPlasticCoef);
            break;
    }
}

GLuint texturas[10]; // 0 - madeira     1 - azulejo     2 - parede    3 - teto
RgbImage imag;


int contador = 0;

GLfloat        SIZE = 10.0;    //.. Mundo  SIZE=coordenadas x=y=z


//========================================================= Objeto Mesa
float      centrox = 0;
float      rotacao = 0;
GLint     sempreRodar = 0;
GLfloat   altura = 0;
GLfloat   incALT = 0.03;
GLfloat Trans = 0;
float AnguloRotacao = 0;

//------------------------------------------------------------ Sistema Coordenadas + objectos
GLint        wScreen = 850, hScreen = 700;        //.. janela
GLfloat        xC = 10.0, yC = 10.0, zC = 10.0;    //.. Mundo

//------------------------------------------------------------ Observador
GLfloat  yRadio;


GLfloat  incZoom;
GLfloat  xPointLook;
GLfloat  yPointLook;
GLfloat  zPointLook;

GLfloat  rVisao = 10, aVisao = 0.5 * PI, incVisao = 0.05;
GLfloat  obsP[] = { rVisao * cos(aVisao), yPointLook, rVisao * sin(aVisao) };
GLfloat  angZoom = 50;

//===========================================================Variaveis e constantes
GLint     msec = 10;












//================================================================================
//================================================ VERTEX ARAY
//------------------------------------------- coordenadas + normais + cores
GLfloat tam = 0.5;
static GLfloat vertices[] = {
    // x=tam (Esquerda)
    -tam,  -tam,  tam,    // 0
    -tam,   tam,  tam,    // 1
    -tam,   tam, -tam,    // 2
    -tam,  -tam, -tam,    // 3
    // Direita
    tam,  -tam,  tam,    // 4
    tam,   tam,  tam,    // 5
    tam,   tam, -tam,    // 6
    tam,  -tam, -tam,    // 7
    //(Cima)
    -tam,  tam,  tam,    // 8
    -tam,  tam, -tam,    // 9
    tam,  tam, -tam,    // 10
    tam,  tam,  tam,    // 11
    //-----------------------------(bottom);
    -tam, -tam,  tam,   //12
    -tam, -tam,  -tam,   //13
    tam, -tam,  -tam,   //14
    tam, -tam,  tam,   //15
    ////------------------------------------- BACK
    tam ,  tam,  -tam,    // 16
    tam,  -tam, -tam,    // 17
    -tam ,  -tam, -tam,     // 18
    -tam,  tam,  -tam,    // 19
    ////------------------------------------- FRONT
    tam ,  tam ,  tam,    // 20
    tam,  -tam , tam,    // 21
    -tam,  -tam,  tam,    // 22
    -tam,  tam,  tam,    // 23
};




static GLfloat normais[] = {
    // x=tam (Esquerda)
    -1.0,  0.0,  0.0,
    -1.0,  0.0,  0.0,
    -1.0,  0.0,  0.0,
    -1.0,  0.0,  0.0,
    // x=tam (Direita)
    1.0,  0.0,  0.0,
    1.0,  0.0,  0.0,
    1.0,  0.0,  0.0,
    1.0,  0.0,  0.0,
    // y=tam (Cima)
    0.0,  1.0,  0.0,
    0.0,  1.0,  0.0,
    0.0,  1.0,  0.0,
    0.0,  1.0,  0.0,
    //-------------------------------------z= tam(Bottom)
    0.0, -1.0, 0.0,
    0.0, -1.0, 0.0,
    0.0, -1.0, 0.0,
    0.0, -1.0, 0.0,
    //-------------------------------------z= tam(Back)
    0.0, 0.0, -1.0,
    0.0, 0.0, -1.0,
    0.0, 0.0, -1.0,
    0.0, 0.0, -1.0,
    //-------------------------------------z= tam(front)
    0.0, 0.0, 1.0,
    0.0, 0.0, 1.0,
    0.0, 0.0, 1.0,
    0.0, 0.0, 1.0,
};
void inicializaTexturas() {
    // Textura de madeira para o banco
    glGenTextures(1, &texturas[0]);
    glBindTexture(GL_TEXTURE_2D, texturas[0]);
    
    imag.LoadBmpFile("/Users/brunosequeira/Desktop/Meta2_CG/Meta2_Proj/Meta2_Proj/madeira.bmp");
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexImage2D(GL_TEXTURE_2D, 0, 3,
                 imag.GetNumCols(),
                 imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
                 imag.ImageData());
    
    // Textura de azulejo para chão
    glGenTextures(1, &texturas[1]);
    glBindTexture(GL_TEXTURE_2D, texturas[1]);
    imag.LoadBmpFile("/Users/brunosequeira/Desktop/Meta2_CG/Meta2_Proj/Meta2_Proj/chao.bmp");
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexImage2D(GL_TEXTURE_2D, 0, 3,
                 imag.GetNumCols(),
                 imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
                 imag.ImageData());
    
    // Textura para paredes
    glGenTextures(1, &texturas[2]);
    glBindTexture(GL_TEXTURE_2D, texturas[2]);
    imag.LoadBmpFile("/Users/brunosequeira/Desktop/Meta2_CG/Meta2_Proj/Meta2_Proj/azulejo.bmp");
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexImage2D(GL_TEXTURE_2D, 0, 3,
                 imag.GetNumCols(),
                 imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
                 imag.ImageData());
    
    // Textura para o teto
    glGenTextures(1, &texturas[3]);
    glBindTexture(GL_TEXTURE_2D, texturas[3]);
    imag.LoadBmpFile("/Users/brunosequeira/Desktop/Meta2_CG/Meta2_Proj/Meta2_Proj/safira.bmp");
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexImage2D(GL_TEXTURE_2D, 0, 3,
                 imag.GetNumCols(),
                 imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
                 imag.ImageData());
    
    // Textura para o PISCAS
    glGenTextures(1, &texturas[4]);
    glBindTexture(GL_TEXTURE_2D, texturas[4]);
    imag.LoadBmpFile("/Users/brunosequeira/Desktop/Meta2_CG/Meta2_Proj/Meta2_Proj/PiscaNotBmp.bmp");
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexImage2D(GL_TEXTURE_2D, 0, 3,
                 imag.GetNumCols(),
                 imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
                 imag.ImageData());
    
    // Textura para as Matricula
    glGenTextures(1, &texturas[5]);
    glBindTexture(GL_TEXTURE_2D, texturas[5]);
    imag.LoadBmpFile("/Users/brunosequeira/Desktop/Meta2_CG/Meta2_Proj/Meta2_Proj/Matricula_.bmp");
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexImage2D(GL_TEXTURE_2D, 0, 3,
                 imag.GetNumCols(),
                 imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
                 imag.ImageData());
    
    // Textura para as lampadas frente
    glGenTextures(1, &texturas[6]);
    glBindTexture(GL_TEXTURE_2D, texturas[6]);
    imag.LoadBmpFile("/Users/brunosequeira/Desktop/Meta2_CG/Meta2_Proj/Meta2_Proj/Lampada-2.bmp");
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexImage2D(GL_TEXTURE_2D, 0, 3,
                 imag.GetNumCols(),
                 imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
                 imag.ImageData());
    
    // Textura para as lampadas frente
    glGenTextures(1, &texturas[7]);
    glBindTexture(GL_TEXTURE_2D, texturas[7]);
    imag.LoadBmpFile("/Users/brunosequeira/Desktop/Meta2_CG/Meta2_Proj/Meta2_Proj/Farol.bmp");
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexImage2D(GL_TEXTURE_2D, 0, 3,
                 imag.GetNumCols(),
                 imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
                 imag.ImageData());
}



// VARIÁVEIS DE LUZ
// Luz ambiente
GLint dia = 1;    //1 - dia    0 - noite
GLfloat intensidadeDia = 0.7;
GLfloat luzAmbiente[4] = { intensidadeDia, intensidadeDia, intensidadeDia, 1.0 };
// Luz teto
GLint teto = 1;
GLfloat intensidadeTeto = 0.3f;
GLint luzR = 1;
GLint luzG = 1;
GLint luzB = 1;
GLfloat posicaoLuz[4] = { 0.0, 12.0, 0.0, 1.0 };
GLfloat localCorAmbiente[4] = { (float) luzR, (float)luzG,(float) luzB, 1.0 };
GLfloat localCorDifusa[4] = { (float)luzR, (float)luzG,(float) luzB, 1.0 };
GLfloat localCorEspecular[4] = {(float) luzR, (float)luzG, (float)luzB, 1.0 };
// Luz foco
GLint foco1 = 0;
GLfloat posicaoFoco1[4] = { -15.0, 0.0, -15.0, 1.0 };
GLfloat corFoco1[4] = { 1.0, 0.0, 0.0, 1.0 };
GLfloat direcaoFoco1[3] = { 1.0, 1.0, 0.0 };
GLfloat anguloFoco = 45.0;
GLint foco2 = 0;
GLfloat posicaoFoco2[4] = { 15.0, 0.0, -15.0, 1.0 };
GLfloat corFoco2[4] = { 0.0, 1.0, 0.0, 1.0 };
GLfloat direcaoFoco2[3] = { -1.0, 1.0, 0.0 };
GLint foco3 = 0;
GLfloat posicaoFoco3[4] = { -15.0, 0.0, 15.0, 1.0 };
GLfloat corFoco3[4] = { 0.0, 0.0, 1.0, 1.0 };
GLfloat direcaoFoco3[3] = { 1.0, -1.0, 0.0 };
GLint foco4 = 0;
GLfloat posicaoFoco4[4] = { 15.0, 0.0, 15.0, 1.0 };
GLfloat corFoco4[4] = { 1.0, 0.0, 1.0, 1.0 };
GLfloat direcaoFoco4[3] = { -1.0, -1.0, 0.0 };


static GLuint esquerda[] = { 0, 1,  2,  3 };
static GLuint  direita[] = { 4, 7,  6,  5 };
static GLuint     cima[] = { 8, 11, 10, 9 };
static GLuint  bottom[] =  {12, 15, 14, 13 };
static GLuint  back[] =     {16,19,18,17};
static GLuint front[] = {20,23,22,21};

//================================================================================
//=========================================================================== INIT
void inicializaLuzes(void);
void initialize(void)
{
    glClearColor(BLACK);        //Apagar
    glEnable(GL_DEPTH_TEST);    //Profundidade
    glShadeModel(GL_SMOOTH);    //Interpolacao de cores
    glVertexPointer(3, GL_FLOAT, 0, vertices);    //Posicoes
    glEnableClientState(GL_VERTEX_ARRAY);
    glNormalPointer(GL_FLOAT, 0, normais);        //Normais
    glEnableClientState(GL_NORMAL_ARRAY);
    
    inicializaLuzes();
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT2);
    glEnable(GL_LIGHT3);
    glEnable(GL_LIGHT4);
    glEnable(GL_LIGHT5);

    inicializaTexturas();
    
}

void drawEsfera() {
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    glBindTexture(GL_TEXTURE_2D, texturas[3]);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glPushMatrix();
    glTranslatef(5, 0.5, 5);
    gluQuadricDrawStyle(esfera, GLU_FILL);
    gluQuadricNormals(esfera, GLU_SMOOTH);
    gluQuadricTexture(esfera, GL_TRUE);
    gluSphere(esfera, 0.5, 150, 150);
    glPopMatrix();
    glDisable(GL_BLEND);
    glDisable(GL_TEXTURE_2D);
}


void drawTeto() {
    initMaterials(16); // white plastic
    glBegin(GL_QUADS);
    glVertex3f(-15.0f, 12.0f, -15.0f);
    glVertex3f(-15.0f, 12.0f, 15.0f);
    glVertex3f(15.0f, 12.0f, 15.0f);
    glVertex3f(15.0f, 12.0f, -15.0f);
    glEnd();
}


void inicializaLuzes(void) {
    // luz ambiente
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);
    // luz teto
    glLightfv(GL_LIGHT1, GL_POSITION, posicaoLuz);
    glLightfv(GL_LIGHT0, GL_AMBIENT, localCorAmbiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, localCorDifusa);
    glLightfv(GL_LIGHT0, GL_SPECULAR, localCorEspecular);
    // luz foco 1
    glLightfv(GL_LIGHT2, GL_POSITION, posicaoFoco1);
    glLightfv(GL_LIGHT2, GL_AMBIENT, corFoco1);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, corFoco1);
    glLightfv(GL_LIGHT2, GL_SPECULAR, corFoco1);
    glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, anguloFoco);
    glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, direcaoFoco1);
    // luz foco 2
    glLightfv(GL_LIGHT3, GL_POSITION, posicaoFoco2);
    glLightfv(GL_LIGHT3, GL_AMBIENT, corFoco2);
    glLightfv(GL_LIGHT3, GL_DIFFUSE, corFoco2);
    glLightfv(GL_LIGHT3, GL_SPECULAR, corFoco2);
    glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, anguloFoco);
    glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, direcaoFoco2);
    // luz foco 3
    glLightfv(GL_LIGHT4, GL_POSITION, posicaoFoco3);
    glLightfv(GL_LIGHT4, GL_AMBIENT, corFoco3);
    glLightfv(GL_LIGHT4, GL_DIFFUSE, corFoco3);
    glLightfv(GL_LIGHT4, GL_SPECULAR, corFoco3);
    glLightf(GL_LIGHT4, GL_SPOT_CUTOFF, anguloFoco);
    glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, direcaoFoco3);
    // luz foco 4
    glLightfv(GL_LIGHT5, GL_POSITION, posicaoFoco4);
    glLightfv(GL_LIGHT5, GL_AMBIENT, corFoco4);
    glLightfv(GL_LIGHT5, GL_DIFFUSE, corFoco4);
    glLightfv(GL_LIGHT5, GL_SPECULAR, corFoco4);
    glLightf(GL_LIGHT5, GL_SPOT_CUTOFF, anguloFoco);
    glLightfv(GL_LIGHT5, GL_SPOT_DIRECTION, direcaoFoco4);
}


void drawParedes() {
    glNormal3f(0, 1, 0);
    initMaterials(2);
    glBegin(GL_QUADS);
    // parede 1
    glVertex3f(-15.0f, -0.1f, -15.0f);
    glVertex3f(-15.0f, -0.1f, 15.0f);
    glVertex3f(-15.0f, 12.0f, 15.0f);
    glVertex3f(-15.0f, 12.0f, -15.0f);
    // parede 2
    glVertex3f(-15.0f, -0.1f, 15.0f);
    glVertex3f(15.0f, -0.1f, 15.0f);
    glVertex3f(15.0f, 12.0f, 15.0f);
    glVertex3f(-15.0f, 12.0f, 15.0f);
    // parede 3
    glVertex3f(15.0f, -0.1f, 15.0f);
    glVertex3f(15.0f, -0.1f, -15.0f);
    glVertex3f(15.0f, 12.0f, -15.0f);
    glVertex3f(15.0f, 12.0f, 15.0f);
    // parede 4
    glVertex3f(15.0f, -0.1f, -15.0f);
    glVertex3f(-15.0f, -0.1f, -15.0f);
    glVertex3f(-15.0f, 12.0f, -15.0f);
    glVertex3f(15.0f, 12.0f, -15.0f);
    glEnd();
}




void verifica_Trans(){
    if(Trans < -3.0){
        Trans = 0;
    }
}


void iluminacao() {
    if (teto) {
        glEnable(GL_LIGHT0);
    }
    else {
        glDisable(GL_LIGHT0);
    }
    if (foco1) {
        glEnable(GL_LIGHT2);
    }
    else {
        glDisable(GL_LIGHT2);
    }
    if (foco2) {
        glEnable(GL_LIGHT3);
    }
    else {
        glDisable(GL_LIGHT3);
    }
    if (foco3) {
        glEnable(GL_LIGHT4);
    }
    else {
        glDisable(GL_LIGHT4);
    }
    if (foco4) {
        glEnable(GL_LIGHT5);
    }
    else {
        glDisable(GL_LIGHT5);
    }
}
//======================================
void drawScene() {
    
    if (sempreRodar) {
        rotacao = rotacao + 1;
        altura = altura + incALT;
        if (altura > 3) incALT = -incALT;
        if (altura < -1) incALT = -incALT;
    }
    glPushMatrix();
    glTranslatef(centrox + pos[0], altura+pos[1], pos[2]);
    glRotatef(rotacao, 0.0, 1.0, 0.0);
    glScalef(2.5, 2.0, 2.5);
    DesenhaBasesCarro();
    DesenhaRodas();
    DesenhaPorta();
    DesenhaMala();
    Matriculas();
    DesenhaLuzes();
    DesenhaPiscas();
    DesenhaLuzesFrente();
}

void drawEixos()
{
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Eixo
    glColor4f(ORANGE);
    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);
    glVertex3f(0.5 * SIZE, 0, 0);
    glEnd();
    glColor4f(GREEN);
    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0.5 * SIZE, 0);
    glEnd();
    glColor4f(BLUE);
    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 0.5 * SIZE);
    glEnd();
}


void DrawCubo(){
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, esquerda);
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, direita);
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, cima);
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, bottom);
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, back);
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, front);
}
void DesenhaChao(){
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturas[1]);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);    glVertex3f(-15.0f, -2.0f, -15.0f);
    glTexCoord2f(1.0f, 0.0f);    glVertex3f(-15.0f, -2.0f, 15.0f);
    glTexCoord2f(1.0f, 1.0f);    glVertex3f(15.0f, -2.0f, 15.0f);
    glTexCoord2f(0.0f, 1.0f);    glVertex3f(15.0f, -2.0f, -15.0f);
    glEnd();
}
void DesenhaBasesCarro(){
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturas[2]);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_MIN_LOD, GL_MODULATE);
    glBegin(GL_QUADS);
    //TETO
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.2, -0.5f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(0.25f, 1.2, -0.5f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(0.25f, 1.2, 0.5f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.2, 0.5f);
    
    
    //CAPÔ
    glTexCoord2f(0.0f, 0.0f); glVertex3f(1, 0.5, -0.5f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(0.25f, 0.5, -0.5f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(0.25f, 0.5, 0.5f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(1, 0.5, 0.5f);
    
    //FRENTE
    glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -0.5, -0.5f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(1, -0.5, 0.5f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(1, 0.5, 0.5f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 0.51,-0.5f);
    
    
    
    //TRASEIRA
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -0.5, -0.5f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1, -0.5, 0.5f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1, 1.2, 0.5f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.2,-0.5f);
    
    
    //BAIXO
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -0.5, -0.5f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(1, -0.5, -0.5f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(1, -0.5, 0.5f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, -0.5, 0.5f);
    
    //LADO
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -0.5, 0.5f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(0.25, -0.5, 0.5f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(0.25, 1.2, 0.5f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,1.2, 0.5f);
    
    
    //LADO
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -0.5, -0.5f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(0.25, -0.5, -0.5f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(0.25, 1.2, -0.5f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,1.2, -0.5f);
    
    //LADO Baixo
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0.25, -0.5, -0.5f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(1, -0.5, -0.5f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(1, 0.5, -0.5f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(0.25,0.5, -0.5f);
    
    
    //LADO Baixo
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0.25, -0.5, 0.5f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(1, -0.5, 0.5f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(1, 0.5, 0.5f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(0.25,0.5, 0.5f);
    
    glEnd();
    glDisable(GL_TEXTURE_2D);

    glColor3f(0.52,0.8,0.98);
    glPushMatrix();
    glTranslatef(0.25, tam+0.2, 0);
    glScalef(0.05, 0.9, 0.9);
    DrawCubo();
    glPopMatrix();
   
 
 
}
void DesenhaRodas(){
    

    
    // RODAS
    glPushMatrix();
    glColor3f(0.44,0.48,0.37);
    glTranslatef(-0.5, -0.75 ,-tam);
    glScalef(0.50, 0.5, 0.2);
    glRotatef(-AnguloRotacao, 0, 0, 1);
    DrawCubo();
    glPopMatrix();
    
    
    glPushMatrix();
    glColor3f(0.44,0.48,0.37);
    glTranslatef(-0.5, -0.75 ,tam);
    glScalef(0.50, 0.5, 0.2);
    glRotatef(-AnguloRotacao, 0, 0, 1);
    DrawCubo();
    glPopMatrix();
    
    
    glPushMatrix();
    glColor3f(0.44,0.48,0.37);
    glTranslatef(0.5, -0.75 ,-tam);
    glScalef(0.50, 0.5, 0.2);
    glRotatef(-AnguloRotacao, 0, 0, 1);
    DrawCubo();
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(0.44,0.48,0.37);
    glTranslatef(0.5, -0.75 ,tam);
    glScalef(0.50, 0.5, 0.2);
    glRotatef(-AnguloRotacao, 0, 0, 1);
    DrawCubo();
    glPopMatrix();
}
void DesenhaPorta(){
    
    
    
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturas[2]);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_MIN_LOD, GL_MODULATE);
    glBegin(GL_QUADS);
    
    //PORTA 1
    
    
    //TETO
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.35, 0.8, 0.5f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(0.25f, 0.8, 0.5f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(0.25f, 0.8, 0.55f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.35f, 0.8, 0.55f);
    
    //FUNDO
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.35, -0.5, 0.5f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(0.25f, -0.5, 0.5f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(0.25f, -0.5, 0.55f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.35f, -0.5, 0.55f);
    
    

    //LADO
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.35, -0.5, 0.55f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(0.25, -0.5, 0.55f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(0.25, 0.8, 0.55f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.35f,0.8, 0.55f);
  
    
    //FRENTE
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0.25, -0.5, 0.55f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(0.25, -0.5, 0.5f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(0.25, 0.8, 0.5f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(0.25, 0.8,0.55f);
    
    
    //TRAS
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.35f, -0.5, 0.55f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.35f, -0.5, 0.5f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.35f, 0.8, 0.5f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.35f, 0.8,0.55f);
    
    
    
    
    //PORTA2
    
    //TETO
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.35, 0.8, -0.5f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(0.25f, 0.8, -0.5f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(0.25f, 0.8, -0.55f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.35f, 0.8, -0.55f);
    
    //FUNDO
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.35, -0.5, -0.5f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(0.25f, -0.5, -0.5f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(0.25f, -0.5, -0.55f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.35f, -0.5,- 0.55f);
    
    
    
    //LADO
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.35, -0.5, -0.55f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(0.25, -0.5,- 0.55f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(0.25, 0.8, -0.55f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.35f,0.8,- 0.55f);
    
    
    //FRENTE
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0.25, -0.5, -0.55f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(0.25, -0.5, -0.5f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(0.25, 0.8, -0.5f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(0.25, 0.8,-0.55f);
    
    
    //TRAS
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.35f, -0.5,- 0.55f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.35f, -0.5,- 0.5f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.35f, 0.8, -0.5f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.35f, 0.8,-0.55f);
    
    
    //PORTA 3
    //TETO
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.95, 0.8, -0.5f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.45, 0.8, -0.5f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.45, 0.8, -0.55f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.95, 0.8, -0.55f);
    
    //FUNDO
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.95, -0.5, -0.5f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.45, -0.5, -0.5f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.45, -0.5, -0.55f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.95, -0.5,- 0.55f);
    
    
    
    //LADO
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.95, -0.5, -0.55f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.45, -0.5,- 0.55f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.45, 0.8, -0.55f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.95,0.8,- 0.55f);
    
    
    //FRENTE
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.45, -0.5, -0.55f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.45, -0.5, -0.5f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.45, 0.8, -0.5f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.45, 0.8,-0.55f);
    
    
    //TRAS
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.95, -0.5,- 0.55f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.95, -0.5,- 0.5f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.95, 0.8, -0.5f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.95, 0.8,-0.55f);
    
    
    
    
    //PORTA 4
    //TETO
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.95, 0.8, 0.5f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.45, 0.8, 0.5f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.45, 0.8, 0.55f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.95, 0.8,0.55f);
    
    //FUNDO
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.95, -0.5, 0.5f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.45, -0.5, 0.5f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.45, -0.5, 0.55f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.95, -0.5, 0.55f);
    
    
    
    //LADO
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.95, -0.5, 0.55f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.45, -0.5, 0.55f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.45, 0.8, 0.55f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.95,0.8, 0.55f);
    
    
    //FRENTE
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.45, -0.5, 0.55f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.45, -0.5, 0.5f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.45, 0.8, 0.5f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.45, 0.8,0.55f);
   
    //TRAS
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.95, -0.5, 0.55f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.95, -0.5, 0.5f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.95, 0.8, 0.5f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.95, 0.8,0.55f);
    
    
    glEnd();
    glDisable(GL_TEXTURE_2D);
    /*
    //PORTA
    glPushMatrix();
    glColor3f(0.83,0.83,0.47);
    glTranslatef(-0.1, 0.3, tam);
    glScalef(0.5, 1, 0.1);
    DrawCubo();
    glPopMatrix();
     */
    glPushMatrix();
    glTranslatef(0, Trans, 0);
    glColor3f(0.52,0.8,0.98);
    glTranslatef(-0.1, 0.6, tam);
    glScalef(0.40, 1, 0.05);
    DrawCubo();
    glPopMatrix();
    
   
    //PORTA
    /*
    glPushMatrix();
    glColor3f(0.83,0.83,0.47);
    glTranslatef(-0.1, 0.3, -tam);
    glScalef(0.5, 1, 0.1);
    DrawCubo();
    glPopMatrix();
    
    */
    glPushMatrix();
    glTranslatef(0, Trans, 0);
    glColor3f(0.52,0.8,0.98);
    glTranslatef(-0.1, 0.6, -tam);
    glScalef(0.40, 1, 0.05);
    DrawCubo();
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(-0.85, 0.3, tam);
    glScalef(0.1, 0.1, 0.15);
    DrawCubo();
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(-0.85, 0.3, -tam);
    glScalef(0.1, 0.1, 0.15);
    DrawCubo();
    glPopMatrix();
    
    
    //PORTA
    /*
    glPushMatrix();
    glColor3f(0.83,0.83,0.47);
    glTranslatef(-0.7, 0.3, tam);
    glScalef(0.5, 1, 0.1);
    DrawCubo();
    glPopMatrix();
    */
    glPushMatrix();
    glTranslatef(0, Trans, 0);
    glColor3f(0.52,0.8,0.98);
    glTranslatef(-0.7, 0.6, tam);
    glScalef(0.40, 1, 0.05);
    DrawCubo();
    glPopMatrix();
    
    //MAOZEIRA
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(-0.25, 0.3, tam);
    glScalef(0.1, 0.1, 0.15);
    DrawCubo();
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(-0.25, 0.3, -tam);
    glScalef(0.1, 0.1, 0.15);
    DrawCubo();
    glPopMatrix();
    
    /*
    //PORTA
    glPushMatrix();
    glColor3f(0.83,0.83,0.47);
    glTranslatef(-0.7, 0.3,- tam);
    glScalef(0.5, 1, 0.1);
    DrawCubo();
    glPopMatrix();
    */
    glPushMatrix();
    glTranslatef(0, Trans, 0);
    glColor3f(0.52,0.8,0.98);
    glTranslatef(-0.7, 0.6, -tam);
    glScalef(0.40, 1, 0.05);
    DrawCubo();
    glPopMatrix();
    
    
}



void DesenhaMala(){
    
  
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(-1, 0.15, 0);
    glScalef(0.15,0.15, 0.6);
    DrawCubo();
    glPopMatrix();
}
void Matriculas(){
    
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturas[5]);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_MAX_LOD, GL_MODULATE);
    glBegin(GL_QUADS);
    
    //FRENTE DIREITA
    glTexCoord2f(0.15f, 0.0f);  glVertex3f(1.02, -0.35, 0.25f);
    glTexCoord2f(1.0f, 0.0f);glVertex3f(1.02, -0.35, -0.25f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(1.02, -0.25,-0.25f);
    glTexCoord2f(0.15f, 1.0f); glVertex3f(1.02, -0.25, 0.25f);
   
    //TRASEIRA DIREITA
    glTexCoord2f(0.15f, 0.0f); glVertex3f(-1.02, -0.35, -0.25f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.02, -0.35, 0.25);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.02, -0.25, 0.25);
    glTexCoord2f(0.15f, 1.0f); glVertex3f(-1.02, -0.25,-0.25f);
 
    glEnd();
    glDisable(GL_TEXTURE_2D);
 
}

void DesenhaLuzes(){
    
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturas[6]);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_MIN_LOD, GL_MODULATE);
    glBegin(GL_QUADS);
    
    //FRENTE DIREITA
    glTexCoord2f(0.0, 0.0f);  glVertex3f(1.02, -0.2, -0.45f);
    glTexCoord2f(1.0f, 0.0f);glVertex3f(1.02, -0.2, -0.35f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(1.02, 0.4,-0.35f);
    glTexCoord2f(0.0, 1.0f); glVertex3f(1.02, 0.4, -0.45);
    
    
    
    glEnd();
    glDisable(GL_TEXTURE_2D);
}


void DesenhaPiscas(){
    
    
    
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturas[4]);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_MIN_LOD, GL_MODULATE);
    glBegin(GL_QUADS);
    
    //FRENTE DIREITA
    glTexCoord2f(0.15f, 0.0f); glVertex3f(1.02, -0.45, -0.45f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(1.02, -0.45, -0.3f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(1.02, -0.25, -0.3f);
    glTexCoord2f(0.15f, 1.0f); glVertex3f(1.02, -0.25,-0.45f);
    
    //FRENTE ESQUERDA
    glTexCoord2f(0.15f, 0.0f); glVertex3f(1.02, -0.45, 0.3f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(1.02, -0.45, 0.45f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(1.02, -0.25, 0.45f);
    glTexCoord2f(0.15f, 1.0f); glVertex3f(1.02, -0.25,0.3f);
    
    //TRASEIRA DIREITA
    glTexCoord2f(0.15f, 0.0f); glVertex3f(-1.02, -0.45, -0.45f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.02, -0.45, -0.3f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.02, -0.25, -0.3f);
    glTexCoord2f(0.15f, 1.0f); glVertex3f(-1.02, -0.25,-0.45f);
    
    //TRASEIRA ESQUERDA
    glTexCoord2f(0.15f, 0.0f); glVertex3f(-1.02, -0.45, 0.3f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.02, -0.45, 0.45f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.02, -0.25, 0.45f);
    glTexCoord2f(0.15f, 1.0f); glVertex3f(-1.02, -0.25,0.3f);
    
    
    glEnd();
    glDisable(GL_TEXTURE_2D);
    
    //LUZES TRAVAGEM
    
    
    
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturas[7]);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_MIN_LOD, GL_MODULATE);
    glBegin(GL_QUADS);
    
    
    //TRASEIRA DIREITA
    glTexCoord2f(0.15f, 0.0f); glVertex3f(-1.02, -0.20, -0.45f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.02, -0.20, -0.3f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.02, 0, -0.3f);
    glTexCoord2f(0.15f, 1.0f); glVertex3f(-1.02, 0,-0.45f);
    
    //TRASEIRA ESQUERDA
    glTexCoord2f(0.15f, 0.0f); glVertex3f(-1.02, -0.20, 0.3f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.02, -0.20, 0.45f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.02, 0, 0.45f);
    glTexCoord2f(0.15f, 1.0f); glVertex3f(-1.02, 0,0.3f);
    
    
    
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void DesenhaLuzesFrente(){
    
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturas[6]);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_MIN_LOD, GL_MODULATE);
    glBegin(GL_QUADS);
    
    //FRENTE DIREITA
    glTexCoord2f(0.0, 0.0f);  glVertex3f(1.02, -0.2, -0.45f);
    glTexCoord2f(1.0f, 0.0f);glVertex3f(1.02, -0.2, -0.35f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(1.02, 0.4,-0.35f);
    glTexCoord2f(0.0, 1.0f); glVertex3f(1.02, 0.4, -0.45);
    
    glTexCoord2f(0.0, 0.0f);  glVertex3f(1.02, -0.2, 0.45f);
    glTexCoord2f(1.0f, 0.0f);glVertex3f(1.02, -0.2, 0.35f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(1.02, 0.4,0.35f);
    glTexCoord2f(0.0, 1.0f); glVertex3f(1.02, 0.4, 0.45);
    
    
    
    glEnd();
    glDisable(GL_TEXTURE_2D);
  
   
    
    glPopMatrix();
   

}




//======================================================
//======================================================
void display(void) {
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    //1º viewPort
    glViewport(0,0, 0.25*wScreen, 0.25*hScreen);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(angZoom,(float)wScreen/hScreen, 0.1, 9999);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, -30,0, 0, 0, 0, 0, 0, -1);
   // DesenhaChao();
    drawEixos();
    drawScene();
    
    //2º viewPort e Principal
    glViewport(0.25*wScreen,0, wScreen, hScreen);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(angZoom+40,(float)wScreen/hScreen, 0.1, 9999);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(obsP[0], obsP[1], obsP[2], xPointLook, yPointLook, zPointLook, 0, 1, 0);
  //  DesenhaChao();
    drawTeto();
   
    iluminacao();
    drawParedes();
    drawEixos();
    drawScene();
    
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Actualizacao
    glutSwapBuffers();
}


void Timer(int value)
{
    glutPostRedisplay();
    glutTimerFunc(msec, Timer, 1);
}




//======================================================= EVENTOS
void keyboard(unsigned char key, int x, int y) {
    
    
    switch (key) {
            
        case 'R': case 'r':
            sempreRodar = !sempreRodar;
            glutPostRedisplay();
            break;
            
        case 'A':case 'a':
            centrox = centrox + 0.5;
            glutPostRedisplay();
            break;
        case 'S': case 's':
            centrox = centrox - 0.5;
            glutPostRedisplay();
            break;
            
        case 'e': case 'E':
            rotacao = rotacao + 2.5;
            glutPostRedisplay();
            break;
        case 'd': case 'D':
            rotacao = rotacao - 4.5;
            glutPostRedisplay();
            break;
        case 'k':case 'K':
            AnguloRotacao = AnguloRotacao + 4.5;
            glutPostRedisplay();
            break;
            
            //====================zz===================================
            //<><><><><><><><><><><><><> Zoom  ???
            //=======================================================
        case 'z':     case 'Z':
            if(contador != -6){
                Trans = Trans - 0.05;
                contador--;
            }
            
            
            glutPostRedisplay();
            
            break;
        case 'x':    case 'X':
            if(contador != 0){
                Trans = Trans + 0.05;
                contador++;
            }
            
            
            glutPostRedisplay();
            break;
            
        case '1':
            obsP[1] = obsP[1] + 0.3;
            
            if (obsP[1] > yC)
                obsP[1] = yC;
            if (obsP[1] < -yC)
                obsP[1] = -yC;
            
            glutPostRedisplay();
            break;
            
        case '2':
            obsP[1] = obsP[1] - 0.3;
            
            if (obsP[1] > yC)
                obsP[1] = yC;
            if (obsP[1] < -yC)
                obsP[1] = -yC;
            
            glutPostRedisplay();
            break;
        case '3':
            aVisao = (aVisao + 0.1);
            obsP[0] = rVisao * cos(aVisao);
            obsP[2] = rVisao * sin(aVisao);
            glutPostRedisplay();
            break;
        case '4':
            aVisao = (aVisao - 0.1);
            obsP[0] = rVisao * cos(aVisao);
            obsP[2] = rVisao * sin(aVisao);
            glutPostRedisplay();
            break;
        case '+':
            if (angZoom > 10) {
                angZoom--;
            }
            else {
                angZoom = 10;
            }
            
            break;
        case '-':
            if (angZoom < 100) {
                angZoom++;
            }
            else {
                angZoom = 100;
            }
            break;
            
            //--------------------------- Escape
        case 27:
            exit(0);
            break;
    }
    
    
}



void teclasNotAscii(int key, int x, int y)
{
    if (key == GLUT_KEY_UP) {
        pos[0] = pos[0] + vel*cos(rotacao*PI/180.);
        pos[2] = pos[2] - vel*sin(rotacao * PI / 180.);
    }
    if (key == GLUT_KEY_DOWN) {
        
        pos[0] = pos[0] - vel*cos(rotacao * PI / 180.);
        pos[2] = pos[2] + vel*sin(rotacao * PI / 180.);
    }
    if (key == GLUT_KEY_LEFT)
        rotacao += 3.;
    if (key == GLUT_KEY_RIGHT)
        rotacao -= 3.;
    glutPostRedisplay();
}


//======================================================= MAIN

int main(int argc, char** argv) {
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(wScreen, hScreen);
    glutInitWindowPosition(400, 100);
    glutCreateWindow("{BS,BrunoSequeira}@student.dei.uc.pt|  |Projeccao :'p'|  |Observador:'SETAS'|  |Mesa-'a/s' 'e/d' 'r'  ");
    
    initialize();
    
    glutSpecialFunc(teclasNotAscii);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(msec, Timer, 1);
    
    glutMainLoop();
    
    return 0;
}





