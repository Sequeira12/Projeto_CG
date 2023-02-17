
/* ===================================================================================
 Meta 02 2021/2022 Computacao Grafica
 Bruno Eduardo Machado Sequeira 2020235721
 ======================================================================================= */

#define HEADER_H_
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GLUT/GLUT.h>
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

char Info[40];
int contadorIntensidade = 10;

GLUquadricObj* esfera = gluNewQuadric();
GLfloat theta = 0.;
GLfloat vel = 1.;
GLfloat pos[] = { 0., 0., 0.};
GLint teto = 1;
GLint B_malha = 0;
GLint material_P = 1;
void initMaterials(int material);

GLuint texturas[10]; // 0 - madeira     1 - azulejo     2 - parede    3 - teto
RgbImage imag;

int contador = 0; //Janela

GLfloat        SIZE = 10.0;    //.. Mundo  SIZE=coordenadas x=y=z

char Materiais[18][30] = {"Esmerald", "Jade", "obsidian", "Pearl", "Ruby", "Turquoise", "Brass", "Bronze", "Chrome", "Copper", "Gold", "Silver", "blackPlastic", "cyanPlastic", "greenPlastic", "redPlastic", "whitePlastic", "yellowPlastic" };

//========================================================= Objeto Mesa
float      centrox = 0;
float      rotacao = 0;
GLint     sempreRodar = 0;
GLfloat   altura = 0;
GLfloat   incALT = 0.03;
GLfloat Trans = 0;
float AnguloRotacao = 0; // Angulo rotação Rodas

//------------------------------------------------------------ Sistema Coordenadas + objectos
GLint        wScreen = 850, hScreen = 700;        //.. janela
GLfloat        xC = 10.0, yC = 10.0, zC = 10.0;    //.. Mundo

//------------------------------------------------------------ Observador
GLfloat  incZoom;
GLfloat  xPointLook;
GLfloat  yPointLook=2.0;
GLfloat  zPointLook;

GLfloat  rVisao = 10, aVisao = 0.5 * PI, incVisao = 0.05;
GLfloat  obsP[] = { rVisao * cos(aVisao), yPointLook, rVisao * sin(aVisao) };
GLfloat  angZoom = 50;

//===========================================================Variaveis e constantes
GLint     msec = 10;



GLint   ligaTeto = 1;         //:::   'T'
GLfloat intensidadeT = 1;  //:::   'I'
GLint   luzR = 1;              //:::   'R'
GLint   luzG = 1;             //:::   'G'
GLint   luzB = 1;             //:::   'B'

//========================================== LUZ TETO ===================================
GLfloat localPos[4] = { 0.0, 12.0, 0.0, 1.0 };
GLfloat localCorAmb[4] = { 0, 0, 0, 0.0 };
GLfloat localCorDif[4] = { (float)luzR, (float)luzG, (float)luzB, 1.0 };
GLfloat localCorEsp[4] = {(float) luzR, (float)luzG,(float) luzB, 1.0 };
GLfloat intensidadeDia = 1.0;
GLfloat luzGlobalCorAmb[4] = { intensidadeDia, intensidadeDia,intensidadeDia, 1.0 };   //



//=================== VARIAVEIS DE LUZ, FOCOS =======================================================

GLint foco1 = 0;
GLfloat posicaoFoco1[4] = { -7.5, 8, -7.5, 1.0 };
GLfloat corFoco1[4] = { 1.0, 0.0, 0.0, 1.0 };
GLfloat direcaoFoco1[3] = {0, -1, 0 };
GLfloat anguloFoco = 45;
GLint foco2 = 0;
GLfloat posicaoFoco2[4] = { -7.5, 8, 7.5, 1.0 };
GLfloat corFoco2[4] = { 0.0, 1.0, 0.0, 1.0 };
GLfloat direcaoFoco2[3] = { 0, -1, 0.0 };
GLint foco3 = 0;
GLfloat posicaoFoco3[4] = { 7.5, 8, 7.5, 1.0 };
GLfloat corFoco3[4] = { 0.0, 0.0, 1.0, 1.0 };
GLfloat direcaoFoco3[3] = {0, -1, 0 };
GLint foco4 = 0;
GLfloat posicaoFoco4[4] = { 7.5, 8, -7.5, 1.0 };
GLfloat corFoco4[4] = { 1.0, 0.0, 1.0, 1.0 };
GLfloat direcaoFoco4[3] = { 0, -1, 0.0 };
GLboolean Troca = true;

//============================================================================================
//================================================ VERTEX ARRAY ==============================
//------------------------------------------- coordenadas + normais + cores ==================
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

//Inicializa Texturas
void inicializaTexturas() {
   
   
    // Textura para carro
    glGenTextures(1, &texturas[2]);
    glBindTexture(GL_TEXTURE_2D, texturas[2]);
    imag.LoadBmpFile("/Users/brunosequeira/Desktop/meta22/azulejo.bmp");
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexImage2D(GL_TEXTURE_2D, 0, 3,
                 imag.GetNumCols(),
                 imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
                 imag.ImageData());
    

    glGenTextures(1, &texturas[3]);
    glBindTexture(GL_TEXTURE_2D, texturas[3]);
    imag.LoadBmpFile("/Users/brunosequeira/Desktop/meta22/colorida.bmp");
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
    imag.LoadBmpFile("/Users/brunosequeira/Desktop/meta22/PiscaNotBmp.bmp");
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
    imag.LoadBmpFile("/Users/brunosequeira/Desktop/meta22/Matricula_.bmp");
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
    imag.LoadBmpFile("/Users/brunosequeira/Desktop/meta22/Lampada-2.bmp");
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
    imag.LoadBmpFile("/Users/brunosequeira/Desktop/meta22/Farol.bmp");
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





//========================================= INIT ==================================
void inicializaLuzes(void);
void initialize(void)
{
    glClearColor(1,1,1, 1);   // apagar ecran = PRETO
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);
    initMaterials(1);   // gold
    inicializaTexturas();
    glPopMatrix();
    
    
}


//Desenha Teto
void drawTeto() {
    initMaterials(16);
    glNormal3f(0,1,0);
    glBegin(GL_QUADS);
    glVertex3f(-15.0f, 12.0f, -15.0f);
    glVertex3f(-15.0f, 12.0f, 15.0f);
    glVertex3f(15.0f, 12.0f, 15.0f);
    glVertex3f(15.0f, 12.0f, -15.0f);
    glEnd();
}


//Verifica que Luzes ativar/desativar ou trocas de posição
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
    if(Troca){
        direcaoFoco1[0] = 0.0;
        direcaoFoco2[0] = 0.0;
        direcaoFoco3[0] = 0.0;
        direcaoFoco4[0] = 0.0;
        anguloFoco = 45;
        
        
    }else{
        direcaoFoco1[0] = 1.0;
        direcaoFoco2[0] = 1.0;
        direcaoFoco3[0] = -1.0;
        direcaoFoco4[0] = -1.0;
        anguloFoco = 50;
    }
}


void inicializaLuzes(void) {
    
    // Ambiente
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzGlobalCorAmb);
    // Teto
    glLightfv(GL_LIGHT0, GL_POSITION, localPos);
    glLightfv(GL_LIGHT0, GL_AMBIENT, localCorAmb);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, localCorDif);
    glLightfv(GL_LIGHT0, GL_SPECULAR, localCorEsp);
    
    //FOCO 1
    glLightfv(GL_LIGHT2, GL_POSITION, posicaoFoco1);
    glLightfv(GL_LIGHT2, GL_AMBIENT, corFoco1);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, corFoco1);
    glLightfv(GL_LIGHT2, GL_SPECULAR, corFoco1);
    glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, anguloFoco);
    glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, direcaoFoco1);
    
    //FOCO 2
    glLightfv(GL_LIGHT3, GL_POSITION, posicaoFoco2);
    glLightfv(GL_LIGHT3, GL_AMBIENT, corFoco2);
    glLightfv(GL_LIGHT3, GL_DIFFUSE, corFoco2);
    glLightfv(GL_LIGHT3, GL_SPECULAR, corFoco2);
    glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, anguloFoco);
    glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, direcaoFoco2);
    //FOCO 3
    glLightfv(GL_LIGHT4, GL_POSITION, posicaoFoco3);
    glLightfv(GL_LIGHT4, GL_AMBIENT, corFoco3);
    glLightfv(GL_LIGHT4, GL_DIFFUSE, corFoco3);
    glLightfv(GL_LIGHT4, GL_SPECULAR, corFoco3);
    glLightf(GL_LIGHT4, GL_SPOT_CUTOFF, anguloFoco);
    glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, direcaoFoco3);
    //FOCO 4
    glLightfv(GL_LIGHT5, GL_POSITION, posicaoFoco4);
    glLightfv(GL_LIGHT5, GL_AMBIENT, corFoco4);
    glLightfv(GL_LIGHT5, GL_DIFFUSE, corFoco4);
    glLightfv(GL_LIGHT5, GL_SPECULAR, corFoco4);
    glLightf(GL_LIGHT5, GL_SPOT_CUTOFF, anguloFoco);
    glLightfv(GL_LIGHT5, GL_SPOT_DIRECTION, direcaoFoco4);
    

}

//Update intensidade luz teto
void updateLuz() {
    localCorAmb[0] = luzR * intensidadeT;
    localCorAmb[1] = luzG * intensidadeT;
    localCorAmb[2] = luzB * intensidadeT;
    localCorDif[0] = luzR * intensidadeT;
    localCorDif[1] = luzG * intensidadeT;
    localCorDif[2] = luzB * intensidadeT;
    localCorEsp[0] = luzR * intensidadeT;
    localCorEsp[1] = luzG * intensidadeT;
    localCorEsp[2] = luzB * intensidadeT;
    glLightfv(GL_LIGHT0, GL_AMBIENT, localCorAmb);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, localCorDif);
    glLightfv(GL_LIGHT0, GL_SPECULAR, localCorEsp);
}


// Desenha paredes com malha
void drawParedesMalha() {
    initMaterials(material_P);
    glBegin(GL_QUADS);
    // parede 1
    glVertex3f(-15.0f, -0.1f, -15.0f);
    glVertex3f(-15.0f, -0.1f, -12.0f);
    glVertex3f(-15.0f, 12.0f, -12.0f);
    glVertex3f(-15.0f, 12.0f, -15.0f);
    glVertex3f(-15.0f, -0.1f, -15.0f);
    glVertex3f(-15.0f, -0.1f, -9.0f);
    glVertex3f(-15.0f, 12.0f, -9.0f);
    glVertex3f(-15.0f, 12.0f, -15.0f);
    glVertex3f(-15.0f, -0.1f, -15.0f);
    glVertex3f(-15.0f, -0.1f, -6.0f);
    glVertex3f(-15.0f, 12.0f, -6.0f);
    glVertex3f(-15.0f, 12.0f, -15.0f);
    glVertex3f(-15.0f, -0.1f, -15.0f);
    glVertex3f(-15.0f, -0.1f, -3.0f);
    glVertex3f(-15.0f, 12.0f, -3.0f);
    glVertex3f(-15.0f, 12.0f, -15.0f);
    glVertex3f(-15.0f, -0.1f, -15.0f);
    glVertex3f(-15.0f, -0.1f, 0.0f);
    glVertex3f(-15.0f, 12.0f, 0.0f);
    glVertex3f(-15.0f, 12.0f, -15.0f);
    glVertex3f(-15.0f, -0.1f, -15.0f);
    glVertex3f(-15.0f, -0.1f, 3.0f);
    glVertex3f(-15.0f, 12.0f, 3.0f);
    glVertex3f(-15.0f, 12.0f, -15.0f);
    glVertex3f(-15.0f, -0.1f, -15.0f);
    glVertex3f(-15.0f, -0.1f, 6.0f);
    glVertex3f(-15.0f, 12.0f, 6.0f);
    glVertex3f(-15.0f, 12.0f, -15.0f);
    glVertex3f(-15.0f, -0.1f, -15.0f);
    glVertex3f(-15.0f, -0.1f, 9.0f);
    glVertex3f(-15.0f, 12.0f, 9.0f);
    glVertex3f(-15.0f, 12.0f, -15.0f);
    glVertex3f(-15.0f, -0.1f, -15.0f);
    glVertex3f(-15.0f, -0.1f, 12.0f);
    glVertex3f(-15.0f, 12.0f, 12.0f);
    glVertex3f(-15.0f, 12.0f, -15.0f);
    glVertex3f(-15.0f, -0.1f, -15.0f);
    glVertex3f(-15.0f, -0.1f, 15.0f);
    glVertex3f(-15.0f, 12.0f, 15.0f);
    glVertex3f(-15.0f, 12.0f, -15.0f);
    // parede 2
    glVertex3f(-15.0f, -0.1f, 15.0f);
    glVertex3f(-12.0f, -0.1f, 15.0f);
    glVertex3f(-12.0f, 12.0f, 15.0f);
    glVertex3f(-15.0f, 12.0f, 15.0f);
    glVertex3f(-15.0f, -0.1f, 15.0f);
    glVertex3f(-9.0f, -0.1f, 15.0f);
    glVertex3f(-9.0f, 12.0f, 15.0f);
    glVertex3f(-15.0f, 12.0f, 15.0f);
    glVertex3f(-15.0f, -0.1f, 15.0f);
    glVertex3f(-6.0f, -0.1f, 15.0f);
    glVertex3f(-6.0f, 12.0f, 15.0f);
    glVertex3f(-15.0f, 12.0f, 15.0f);
    glVertex3f(-15.0f, -0.1f, 15.0f);
    glVertex3f(-3.0f, -0.1f, 15.0f);
    glVertex3f(-3.0f, 12.0f, 15.0f);
    glVertex3f(-15.0f, 12.0f, 15.0f);
    glVertex3f(-15.0f, -0.1f, 15.0f);
    glVertex3f(0.0f, -0.1f, 15.0f);
    glVertex3f(0.0f, 12.0f, 15.0f);
    glVertex3f(-15.0f, 12.0f, 15.0f);
    glVertex3f(-15.0f, -0.1f, 15.0f);
    glVertex3f(3.0f, -0.1f, 15.0f);
    glVertex3f(3.0f, 12.0f, 15.0f);
    glVertex3f(-15.0f, 12.0f, 15.0f);
    glVertex3f(-15.0f, -0.1f, 15.0f);
    glVertex3f(6.0f, -0.1f, 15.0f);
    glVertex3f(6.0f, 12.0f, 15.0f);
    glVertex3f(-15.0f, 12.0f, 15.0f);
    glVertex3f(-15.0f, -0.1f, 15.0f);
    glVertex3f(9.0f, -0.1f, 15.0f);
    glVertex3f(9.0f, 12.0f, 15.0f);
    glVertex3f(-15.0f, 12.0f, 15.0f);
    glVertex3f(-15.0f, -0.1f, 15.0f);
    glVertex3f(12.0f, -0.1f, 15.0f);
    glVertex3f(12.0f, 12.0f, 15.0f);
    glVertex3f(-15.0f, 12.0f, 15.0f);
    glVertex3f(-15.0f, -0.1f, 15.0f);
    glVertex3f(15.0f, -0.1f, 15.0f);
    glVertex3f(15.0f, 12.0f, 15.0f);
    glVertex3f(-15.0f, 12.0f, 15.0f);
    // parede 3
    glVertex3f(15.0f, -0.1f, -12.0f);
    glVertex3f(15.0f, -0.1f, -15.0f);
    glVertex3f(15.0f, 12.0f, -15.0f);
    glVertex3f(15.0f, 12.0f, -12.0f);
    glVertex3f(15.0f, -0.1f, -9.0f);
    glVertex3f(15.0f, -0.1f, -15.0f);
    glVertex3f(15.0f, 12.0f, -15.0f);
    glVertex3f(15.0f, 12.0f, -9.0f);
    glVertex3f(15.0f, -0.1f, -6.0f);
    glVertex3f(15.0f, -0.1f, -15.0f);
    glVertex3f(15.0f, 12.0f, -15.0f);
    glVertex3f(15.0f, 12.0f, -6.0f);
    glVertex3f(15.0f, -0.1f, -3.0f);
    glVertex3f(15.0f, -0.1f, -15.0f);
    glVertex3f(15.0f, 12.0f, -15.0f);
    glVertex3f(15.0f, 12.0f, -3.0f);
    glVertex3f(15.0f, -0.1f, 0.0f);
    glVertex3f(15.0f, -0.1f, -15.0f);
    glVertex3f(15.0f, 12.0f, -15.0f);
    glVertex3f(15.0f, 12.0f, 0.0f);
    glVertex3f(15.0f, -0.1f, 3.0f);
    glVertex3f(15.0f, -0.1f, -15.0f);
    glVertex3f(15.0f, 12.0f, -15.0f);
    glVertex3f(15.0f, 12.0f, 3.0f);
    glVertex3f(15.0f, -0.1f, 6.0f);
    glVertex3f(15.0f, -0.1f, -15.0f);
    glVertex3f(15.0f, 12.0f, -15.0f);
    glVertex3f(15.0f, 12.0f, 6.0f);
    glVertex3f(15.0f, -0.1f, 9.0f);
    glVertex3f(15.0f, -0.1f, -15.0f);
    glVertex3f(15.0f, 12.0f, -15.0f);
    glVertex3f(15.0f, 12.0f, 9.0f);
    glVertex3f(15.0f, -0.1f, 12.0f);
    glVertex3f(15.0f, -0.1f, -15.0f);
    glVertex3f(15.0f, 12.0f, -15.0f);
    glVertex3f(15.0f, 12.0f, 12.0f);
    glVertex3f(15.0f, -0.1f, 15.0f);
    glVertex3f(15.0f, -0.1f, -15.0f);
    glVertex3f(15.0f, 12.0f, -15.0f);
    glVertex3f(15.0f, 12.0f, 15.0f);
    // parede 4
    glVertex3f(-12.0f, -0.1f, -15.0f);
    glVertex3f(-15.0f, -0.1f, -15.0f);
    glVertex3f(-15.0f, 12.0f, -15.0f);
    glVertex3f(-12.0f, 12.0f, -15.0f);
    glVertex3f(-9.0f, -0.1f, -15.0f);
    glVertex3f(-15.0f, -0.1f, -15.0f);
    glVertex3f(-15.0f, 12.0f, -15.0f);
    glVertex3f(-9.0f, 12.0f, -15.0f);
    glVertex3f(-6.0f, -0.1f, -15.0f);
    glVertex3f(-15.0f, -0.1f, -15.0f);
    glVertex3f(-15.0f, 12.0f, -15.0f);
    glVertex3f(-6.0f, 12.0f, -15.0f);
    glVertex3f(-3.0f, -0.1f, -15.0f);
    glVertex3f(-15.0f, -0.1f, -15.0f);
    glVertex3f(-15.0f, 12.0f, -15.0f);
    glVertex3f(-3.0f, 12.0f, -15.0f);
    glVertex3f(0.0f, -0.1f, -15.0f);
    glVertex3f(-15.0f, -0.1f, -15.0f);
    glVertex3f(-15.0f, 12.0f, -15.0f);
    glVertex3f(0.0f, 12.0f, -15.0f);
    glVertex3f(3.0f, -0.1f, -15.0f);
    glVertex3f(-15.0f, -0.1f, -15.0f);
    glVertex3f(-15.0f, 12.0f, -15.0f);
    glVertex3f(3.0f, 12.0f, -15.0f);
    glVertex3f(6.0f, -0.1f, -15.0f);
    glVertex3f(-15.0f, -0.1f, -15.0f);
    glVertex3f(-15.0f, 12.0f, -15.0f);
    glVertex3f(6.0f, 12.0f, -15.0f);
    glVertex3f(9.0f, -0.1f, -15.0f);
    glVertex3f(-15.0f, -0.1f, -15.0f);
    glVertex3f(-15.0f, 12.0f, -15.0f);
    glVertex3f(9.0f, 12.0f, -15.0f);
    glVertex3f(12.0f, -0.1f, -15.0f);
    glVertex3f(-15.0f, -0.1f, -15.0f);
    glVertex3f(-15.0f, 12.0f, -15.0f);
    glVertex3f(12.0f, 12.0f, -15.0f);
    glVertex3f(15.0f, -0.1f, -15.0f);
    glVertex3f(-15.0f, -0.1f, -15.0f);
    glVertex3f(-15.0f, 12.0f, -15.0f);
    glVertex3f(15.0f, 12.0f, -15.0f);
    glEnd();
}

//Desenha paredes
void drawParedes() {

    initMaterials(material_P);
    glBegin(GL_QUADS);
    // parede 1
    glNormal3f(1, 0, 0);
    glVertex3f(-15.0f, -0.1f, -15.0f);
    glVertex3f(-15.0f, -0.1f, 15.0f);
    glVertex3f(-15.0f, 12.0f, 15.0f);
    glVertex3f(-15.0f, 12.0f, -15.0f);
    glEnd();
    
    glNormal3f(0, 0,-1);
    glBegin(GL_QUADS);
    // parede 2
    glVertex3f(-15.0f, -0.1f, 15.0f);
    glVertex3f(15.0f, -0.1f, 15.0f);
    glVertex3f(15.0f, 12.0f, 15.0f);
    glVertex3f(-15.0f, 12.0f, 15.0f);
    glEnd();
    
    glNormal3f(-1, 0, 0);
    glBegin(GL_QUADS);
    // parede 3
    glVertex3f(15.0f, -0.1f, 15.0f);
    glVertex3f(15.0f, -0.1f, -15.0f);
    glVertex3f(15.0f, 12.0f, -15.0f);
    glVertex3f(15.0f, 12.0f, 15.0f);
    glEnd();

    glNormal3f(0, 0, 1);
    glBegin(GL_QUADS);
    // parede 4
    glVertex3f(15.0f, -0.1f, -15.0f);
    glVertex3f(-15.0f, -0.1f, -15.0f);
    glVertex3f(-15.0f, 12.0f, -15.0f);
    glVertex3f(15.0f, 12.0f, -15.0f);
    glEnd();
    
}



//Desenha Eixos
void drawEixos()
{
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Eixo
    initMaterials(2);
    glPushMatrix();
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
    glPopMatrix();
}


//Desenha Chão
void DesenhaChao(){
    glPushMatrix();
    initMaterials(5);
    glNormal3f(0,1,0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-15, 0, -15);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(15, 0, -15);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(15, 0, 15);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-15, 0, 15);
    glEnd();
    glPopMatrix();
}

//Desenha Bases Carro
void DesenhaBasesCarro(){
    glPushMatrix();
    glTranslatef(0,1,0);
    initMaterials(3);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturas[2]);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    //TETO
    glNormal3f(0,1,0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.2, -0.5f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(0.25f, 1.2, -0.5f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(0.25f, 1.2, 0.5f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.2, 0.5f);
    glEnd();
    
    //CAPÔ
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(1, 0.5, -0.5f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(0.25f, 0.5, -0.5f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(0.25f, 0.5, 0.5f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(1, 0.5, 0.5f);
    glEnd();
    
    //FRENTE
    glNormal3f(1,0,0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -0.5, -0.5f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(1, -0.5, 0.5f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(1, 0.5, 0.5f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 0.51,-0.5f);
    glEnd();
    
    //TRASEIRA
    glNormal3f(-1,0,0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -0.5, -0.5f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1, -0.5, 0.5f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1, 1.2, 0.5f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.2,-0.5f);
    glEnd();
    
    //BAIXO
    glNormal3f(0,-1,0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -0.5, -0.5f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(1, -0.5, -0.5f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(1, -0.5, 0.5f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, -0.5, 0.5f);
    glEnd();
    
    //LADO
    glNormal3f(0,0,1);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -0.5, 0.5f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(0.25, -0.5, 0.5f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(0.25, 1.2, 0.5f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,1.2, 0.5f);
    glEnd();
    
    //LADO
    glNormal3f(0,0,-1);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -0.5, -0.5f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(0.25, -0.5, -0.5f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(0.25, 1.2, -0.5f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,1.2, -0.5f);
    glEnd();
    
    //LADO Baixo
    glNormal3f(0,0,-1);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0.25, -0.5, -0.5f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(1, -0.5, -0.5f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(1, 0.5, -0.5f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(0.25,0.5, -0.5f);
    glEnd();
    
    //LADO Baixo
    glNormal3f(0,0,1);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0.25, -0.5, 0.5f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(1, -0.5, 0.5f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(1, 0.5, 0.5f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(0.25,0.5, 0.5f);
    glEnd();
    
    glDisable(GL_TEXTURE_2D);
    
    glPopMatrix();
    
    
    
    
}

//Desenha Vidro Transparente
void DesenhaVidroTransparente(){
    
    glPushMatrix();
    initMaterials(17);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_DST_ALPHA);
    glColor4f(1, 0,0, 0);
    glPushMatrix();
    glBegin(GL_POLYGON);
    glVertex3f(0.25,2.2,0.5);
    glVertex3f(0.25,1,0.5);
    glVertex3f(0.25,1,-0.5);
    glVertex3f(0.25,2.2,-0.5);
    glEnd();
    glPopMatrix();
    glDisable(GL_BLEND);
    glPopMatrix();
   
}

//Função auxiliar criação de rodas
void FuncQuadrado(){
    glPushMatrix();
    glRotatef(-AnguloRotacao,0,0,1);
    glBegin(GL_QUADS);
    
    //FRENTE
    glNormal3f(0,0,-1);
    glVertex3f(-0.25, -0.25, -0.5);
    glVertex3f(-0.25, 0.25, -0.5);
    glVertex3f(0.25, 0.25, -0.5);
    glVertex3f(0.25, -0.25, -0.5);
    
    //TRAS
    glNormal3f(0,0,1);
    glVertex3f(-0.25, -0.25, -0.3);
    glVertex3f(-0.25, 0.25, -0.3);
    glVertex3f(0.25, 0.25, -0.3);
    glVertex3f(0.25, -0.25, -0.3);
    
    //BAIXO
    glNormal3f(0,-1,0);
    glVertex3f(-0.25,-0.25, -0.5);
    glVertex3f(-0.25,-0.25, -0.3);
    glVertex3f(0.25,-0.25, -0.3);
    glVertex3f(0.25,-0.25, -0.5);
    glNormal3f(0,-1,0);
    
    //CIMA
    glNormal3f(0,1,0);
    glVertex3f(-0.25,0.25, -0.5);
    glVertex3f(-0.25,0.25, -0.3);
    glVertex3f(0.25,0.25, -0.3);
    glVertex3f(0.25,0.25, -0.5);
    
    //ESQUERDA
    glNormal3f(-1,0,0);
    glVertex3f(-0.25,0.25, -0.3);
    glVertex3f(-0.25,0.25, -0.5);
    glVertex3f(-0.25,-0.25, -0.5);
    glVertex3f(-0.25,-0.25, -0.3);
    
    //DIREITA
    glNormal3f(1,0,0);
    glVertex3f(0.25,0.25, -0.3);
    glVertex3f(0.25,0.25, -0.5);
    glVertex3f(0.25,-0.25, -0.5);
    glVertex3f(0.25,-0.25, -0.3);

    glEnd();
    glPopMatrix();
}

//Desenha rodas
void DesenhaRodas(){
    glPushMatrix();
    glTranslatef(-0.5, 0.3, 0.1);
    FuncQuadrado();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.5, 0.3, 0.7);
    FuncQuadrado();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.5, 0.3, 0.7);
    FuncQuadrado();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.5,0.3, 0.1);
    FuncQuadrado();
    glPopMatrix();
}


//DesenhaPorta
void DesenhaPorta(){
    
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturas[3]);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_MIN_LOD, GL_MODULATE);
    initMaterials(3);
    glPushMatrix();
    glTranslatef(0,0.5,0);
    glBegin(GL_QUADS);
    
    //PORTA 1
    
    
    //TETO
    glNormal3f(0,1,0);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.35, 0.8, 0.5f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(0.25f, 0.8, 0.5f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(0.25f, 0.8, 0.55f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.35f, 0.8, 0.55f);
    
    //FUNDO
    glNormal3f(0,-1,0);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.35, -0.5, 0.5f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(0.25f, -0.5, 0.5f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(0.25f, -0.5, 0.55f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.35f, -0.5, 0.55f);
    
    
    
    //LADO
    glNormal3f(0,0,1);

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
     glNormal3f(0,1,0);
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
    glNormal3f(0,0,-1);
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
     glNormal3f(0,1,0);
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
    glNormal3f(0,0,-1);
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
     glNormal3f(0,1,0);
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
    glNormal3f(0,0,1);
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
    glPopMatrix();
    
}

//desenha vidros
void DesenhaVidros(){
    //FRENTE
    glPushMatrix();
    glTranslatef(0, Trans, 0);
    initMaterials(15);
    glBegin(GL_QUADS);
    glVertex3f(-0.9,2.1, 0.53);
    glVertex3f(-0.45, 2.1, 0.53f);
    glVertex3f(-0.45, 1, 0.53f);
    glVertex3f(-0.9, 1,0.53f);
    
    
    glVertex3f(-0.9,2.1, -0.53);
    glVertex3f(-0.45, 2.1, -0.53f);
    glVertex3f(-0.45, 1, -0.53f);
    glVertex3f(-0.9, 1,-0.53f);
    
    
    glVertex3f(-0.35,2.1, 0.53);
    glVertex3f(0.2, 2.1, 0.53f);
    glVertex3f(0.2, 1, 0.53f);
    glVertex3f(-0.35, 1,0.53f);
    
    glVertex3f(-0.35,2.1, -0.53);
    glVertex3f(0.2, 2.1, -0.53f);
    glVertex3f(0.2, 1, -0.53f);
    glVertex3f(-0.35, 1, -0.53f);
    glEnd();
    glPopMatrix();
    
    
}

// Desenha Matriculas
void Matriculas(){
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturas[5]);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_MAX_LOD, GL_MODULATE);
    glBegin(GL_QUADS);
    
    //FRENTE DIREITA
    glTexCoord2f(0.15f, 0.0f);  glVertex3f(1.02, 0.7, 0.25f);
    glTexCoord2f(1.0f, 0.0f);glVertex3f(1.02, 0.7, -0.25f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(1.02, 0.85,-0.25f);
    glTexCoord2f(0.15f, 1.0f); glVertex3f(1.02, 0.85, 0.25f);
    
    //TRASEIRA DIREITA
    glTexCoord2f(0.15f, 0.0f); glVertex3f(-1.02, 0.7, -0.25f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.02, 0.7, 0.25);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.02, 0.85, 0.25);
    glTexCoord2f(0.15f, 1.0f); glVertex3f(-1.02, 0.85,-0.25f);
    
    glEnd();
    glDisable(GL_TEXTURE_2D);
    
}

//Desenha Piscas
void DesenhaPiscas(){

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturas[4]);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_MIN_LOD, GL_MODULATE);
    glBegin(GL_QUADS);
    
    //FRENTE DIREITA
    glTexCoord2f(0.15f, 0.0f); glVertex3f(1.02, 0.6, -0.45f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(1.02, 0.6, -0.3f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(1.02, 0.8, -0.3f);
    glTexCoord2f(0.15f, 1.0f); glVertex3f(1.02, 0.8,-0.45f);
    
    //FRENTE ESQUERDA
    glTexCoord2f(0.15f, 0.0f); glVertex3f(1.02, 0.65, 0.3f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(1.02, 0.6, 0.45f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(1.02, 0.8, 0.45f);
    glTexCoord2f(0.15f, 1.0f); glVertex3f(1.02, 0.8,0.3f);
    
    //TRASEIRA DIREITA
    glTexCoord2f(0.15f, 0.0f); glVertex3f(-1.02, 0.6, -0.45f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.02, 0.6, -0.3f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.02, 0.8, -0.3f);
    glTexCoord2f(0.15f, 1.0f); glVertex3f(-1.02, 0.8,-0.45f);
    
    //TRASEIRA ESQUERDA
    glTexCoord2f(0.15f, 0.0f); glVertex3f(-1.02,0.6, 0.3f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.02, 0.6, 0.45f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.02, 0.8, 0.45f);
    glTexCoord2f(0.15f, 1.0f); glVertex3f(-1.02, 0.8,0.3f);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    
    
    //LUZES TRAVAGEM
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturas[7]);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_MIN_LOD, GL_MODULATE);
    glBegin(GL_QUADS);
    
    
    //TRASEIRA DIREITA
    glTexCoord2f(0.15f, 0.0f); glVertex3f(-1.02, 0.7, -0.45f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.02,0.7, -0.3f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.02, 0.9, -0.3f);
    glTexCoord2f(0.15f, 1.0f); glVertex3f(-1.02, 0.9,-0.45f);
    
    //TRASEIRA ESQUERDA
    glTexCoord2f(0.15f, 0.0f); glVertex3f(-1.02,0.7, 0.3f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.02, 0.7, 0.45f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.02, 0.9, 0.45f);
    glTexCoord2f(0.15f, 1.0f); glVertex3f(-1.02, 0.9,0.3f);

    glEnd();
    glDisable(GL_TEXTURE_2D);
}

//Desenha Luzes Frente
void DesenhaLuzesFrente(){
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturas[6]);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_MIN_LOD, GL_MODULATE);
    glBegin(GL_QUADS);
    
    //FRENTE DIREITA
    glTexCoord2f(0.0, 0.0f);  glVertex3f(1.02, 0.7, -0.45f);
    glTexCoord2f(1.0f, 0.0f);glVertex3f(1.02, 0.7, -0.35f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(1.02, 1.3,-0.35f);
    glTexCoord2f(0.0, 1.0f); glVertex3f(1.02, 1.3, -0.45);
    
    glTexCoord2f(0.0, 0.0f);  glVertex3f(1.02, 0.7, 0.45f);
    glTexCoord2f(1.0f, 0.0f);glVertex3f(1.02, 0.7, 0.35f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(1.02, 1.3,0.35f);
    glTexCoord2f(0.0, 1.0f); glVertex3f(1.02, 1.3, 0.45);

    glEnd();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

//Desenha Cena
void drawScene() {
    
    if (sempreRodar) {
        rotacao = rotacao + 1;
        altura = altura + incALT;
        if (altura > 3) incALT = -incALT;
        if (altura < -1) incALT = -incALT;
    }
    // glPushMatrix();
    
    glTranslatef(centrox + pos[0], altura+pos[1], pos[2]);
    glRotatef(rotacao, 0.0, 1.0, 0.0);
    glScalef(2.5, 2.0, 2.5);
    
    DesenhaBasesCarro();
    DesenhaRodas();
    
    glPushMatrix();
    glTranslatef(0, 0.6, 0);
    DesenhaPorta();
    glPopMatrix();
    
    Matriculas();
    
    
    DesenhaPiscas();
    DesenhaLuzesFrente();
    DesenhaVidros();
    DesenhaVidroTransparente();
    
    
}
//Desenha Info
void desenhaInfo(char* string, GLfloat x, GLfloat y, GLfloat z) {
    glRasterPos3f(x, y, z);
    while (*string)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *string++);
}


void DefineInformacao(){
    if(teto){
        sprintf(Info, "Luz Teto '9' - ATIVADO");
    }else{
        sprintf(Info, "Luz Teto '9' - DESATIVADO");
    }
    desenhaInfo(Info, -3,2,0);
    sprintf(Info, "Luz R - %d G - %d B - %d",luzR,luzG,luzB);
    desenhaInfo(Info, -3, 1.5, 0);
    sprintf(Info, "Intensidade  %4.2f (+ U  | -T)",intensidadeT);
    desenhaInfo(Info, -3, 1, 0);
    
    if(foco1){
        sprintf(Info, "Foco '5' - ATIVADO",foco1);
    }else{
        sprintf(Info, "Foco '5' - DESATIVADO",foco1);
    }
    desenhaInfo(Info, -3, 0.5, 0);
    
    if(foco2){
        sprintf(Info, "Foco '6' - ATIVADO",foco2);
    }else{
        sprintf(Info, "Foco '6' -DESATIVADO",foco2);
    }
    desenhaInfo(Info, -3, 0, 0);
    
    if(foco3){
        sprintf(Info, "Foco '7' - ATIVADO",foco3);
    }else{
        sprintf(Info, "Foco '7' - DESATIVADO",foco3);
    }
    desenhaInfo(Info, -3, -0.5, 0);
    if(foco4){
        sprintf(Info, "Foco '8' - ATIVADO");
    }else{
        sprintf(Info, "Foco '8' - DESATIVADO");
    }
    desenhaInfo(Info, -3, -1, 0);
    if(B_malha){
        sprintf(Info, "Malha 'M' - ATIVADO");
    }else{
        sprintf(Info, "Malha 'M' - DESATIVADO");
    }
    
    
    desenhaInfo(Info, -3, -1.5, 0);
    sprintf(Info, "Material 'H' - %s",Materiais[material_P]);
    
    desenhaInfo(Info, -3, -2, 0);
    
    sprintf(Info, "Sair 'Q'");
    desenhaInfo(Info, -3, 2.5, 0);
    
}

//======================================================
//======================================================
void display(void) {
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    //Ultimo viewPort apenas com informação
    
    glViewport(0,0.25*wScreen, 0.25*wScreen,hScreen);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(angZoom,(float)wScreen/hScreen, 0.1, 9999);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.00001,-0.10000,10.00000, xPointLook, yPointLook, zPointLook, 0, 1, 0);
    
    
    
    glColor3f(1,1,1);
    DefineInformacao();
   
    
    //1º Viewport
    glViewport(0,0, 0.25*wScreen, 0.25*hScreen);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(angZoom,(float)wScreen/hScreen, 0.1, 9999);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 12, 0, 0, 0, 0, 0, 0, 1);
    
    inicializaLuzes();
    iluminacao();
    DesenhaChao();
    drawTeto();
    drawParedes();
    if(!B_malha){
        drawParedes();
    }else{
        drawParedesMalha();
    }
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
  
    inicializaLuzes();
    iluminacao();
    DesenhaChao();
    drawTeto();
    drawParedes();
    if(!B_malha){
        drawParedes();
    }else{
        drawParedesMalha();
    }
    drawEixos();
    drawScene();
    updateLuz();

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
            
            
        case 'A':case 'a':
            centrox = centrox + 0.5;
            glutPostRedisplay();
            break;
        case 'S': case 's':
            centrox = centrox - 0.5;
            glutPostRedisplay();
            break;
            
        case 'r':    case 'R':
            luzR = (luzR + 1) % 2;
            updateLuz();
            glutPostRedisplay();
            break;
        case 'g':    case 'G':
            luzG = (luzG + 1) % 2;
            updateLuz();
            glutPostRedisplay();
            break;
        case 'b':    case 'B':
            luzB = (luzB + 1) % 2;
            updateLuz();
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
            
        case 'm':case 'M':
            B_malha = !B_malha;
            glutPostRedisplay();
            break;
        case 'h':case 'H':
            material_P = material_P + 1;
            if(material_P == 18){
                material_P = 1;
            }
            glutPostRedisplay();
            break;
            
        case 'l':case 'L':
            Troca = !Troca;
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
        case 'u':    case 'U':
            if(contadorIntensidade != 10){
                intensidadeT = intensidadeT + 0.10 ;
                contadorIntensidade++;
            }
            updateLuz();
            printf("%f\n",intensidadeT);
            glutPostRedisplay();
            break;
            
        case 't':    case 'T':
            if(contadorIntensidade != 0){
                intensidadeT = intensidadeT - 0.1;
                contadorIntensidade--;
            }else{
                intensidadeT = 0.0;
            }
            printf("%f\n",intensidadeT);
            updateLuz();
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
        case '5':
            foco1 = !foco1;
            glutPostRedisplay();
            break;
        case '6':
            foco2 = !foco2;
            glutPostRedisplay();
            break;
        case '7':
            foco3 = !foco3;
            glutPostRedisplay();
            break;
        case '8':
            foco4 = !foco4;
            glutPostRedisplay();
            break;
        case '9':
            teto = !teto;
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
        case 'q':case'Q':
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
    glutCreateWindow("Meta2 - Bruno Sequeira");
    
    initialize();
    
    glutSpecialFunc(teclasNotAscii);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(msec, Timer, 1);
    
    glutMainLoop();
    glPopMatrix();
    
    return 0;
}





