/* ===================================================================================
 Meta 02 2022/2023 Computacao Grafica
 Bruno Eduardo Machado Sequeira
 ======================================================================================= */

#define HEADER_H_
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GLUT/GLUT.h>


#define PI         3.14159

//--------------------------------- Definir cores
#define BLUE     0.0, 0.0, 1.0, 1.0
#define YELLOW     1.0, 1.0, 0.0, 1.0
#define GREEN    0.0, 1.0, 0.0, 1.0
#define ORANGE   1.0, 0.5, 0.1, 1.0
#define CYAN     0.0, 1.0, 1.0, 1.0
#define WHITE    1.0, 1.0, 1.0, 1.0
#define BLACK    0.0, 0.0, 0.0, 1.0
#define GRAY     0.3, 0.3, 0.3, 1.0



GLfloat theta = 0.;
GLfloat vel = 1.;
GLfloat pos[] = { 0., 0., 0.};


int contador = 0;
//------------------------------------------------------------ Sistema Coordenadas

//.. janela
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
    //ÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖ x=tam (Esquerda)
    -tam,  -tam,  tam,    // 0
    -tam,   tam,  tam,    // 1
    -tam,   tam, -tam,    // 2
    -tam,  -tam, -tam,    // 3
    //ÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖ Direita
    tam,  -tam,  tam,    // 4
    tam,   tam,  tam,    // 5
    tam,   tam, -tam,    // 6
    tam,  -tam, -tam,    // 7
    //ÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖ (Cima)
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
    //ÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖ x=tam (Esquerda)
    -1.0,  0.0,  0.0,
    -1.0,  0.0,  0.0,
    -1.0,  0.0,  0.0,
    -1.0,  0.0,  0.0,
    //ÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖ x=tam (Direita)
    1.0,  0.0,  0.0,
    1.0,  0.0,  0.0,
    1.0,  0.0,  0.0,
    1.0,  0.0,  0.0,
    //ÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖ y=tam (Cima)
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
static GLfloat cores[] = {
    //ÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖ x=tam (Esquerda) - Red
    1.0,  0.0, 0.0,    // 0
    1.0,  0.0, 0.0,    // 1
    1.0,  1.0, 0.0,    // 2
    1.0,  1.0, 0.0,    // 3
    //ÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖ y=tam (Cima) - Blue
    1.0,  0.0, 1.0,    // 8
    1.0,  0.0, 1.0,    // 9
    0.0,  1.0, 1.0,    // 10
    0.0,  0.5, 1.0,    // 11
    //ÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖ x=2*tam (Direita) - Green
    0.0,  1.0, 1.0,    // 4
    0.0,  1.0, 1.0,    // 5
    0.0,  1.0, 0.0,    // 6
    0.0,  1.0, 0.0  ,  // 7
    //ÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖ x=tam (Esquerda) - Red
    
    1.0,  0.0, 0.0,    // 0
    1.0,  0.0, 0.0,    // 1
    1.0,  1.0, 0.0,    // 2
    1.0,  1.0, 0.0,    // 3
    //ÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖ y=tam (Cima) - Blue
    1.0,  0.0, 1.0,    // 8
    1.0,  0.0, 1.0,    // 9
    0.0,  1.0, 1.0,    // 10
    0.0,  0.5, 1.0,    // 11
    //ÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖ x=2*tam (Direita) - Green
    0.0,  1.0, 1.0,    // 4
    0.0,  1.0, 1.0,    // 5
    0.0,  1.0, 0.0,    // 6
    0.0,  1.0, 0.0    // 7
    
    
};

static GLuint esquerda[] = { 0, 1,  2,  3 };
static GLuint  direita[] = { 4, 7,  6,  5 };
static GLuint     cima[] = { 8, 11, 10, 9 };
static GLuint  bottom[] =  {12, 15, 14, 13 };
static GLuint  back[] =     {16,19,18,17};
static GLuint front[] = {20,23,22,21};

//================================================================================
//=========================================================================== INIT
void initialize(void)
{
    glClearColor(BLACK);        //ÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖApagar
    glEnable(GL_DEPTH_TEST);    //ÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖProfundidade
    glShadeModel(GL_SMOOTH);    //ÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖInterpolacao de cores
    
    //glEnable(GL_CULL_FACE);        //ÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖFaces visiveis
    //glCullFace(GL_BACK);        //ÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖMostrar so as da frente
    
    glVertexPointer(3, GL_FLOAT, 0, vertices);    //ÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖPosicoes
    glEnableClientState(GL_VERTEX_ARRAY);
    glNormalPointer(GL_FLOAT, 0, normais);        //ÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖNormais
    glEnableClientState(GL_NORMAL_ARRAY);
    
    
}


void verifica_Trans(){
    if(Trans < -3.0){
        Trans = 0;
    }
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

void drawObservador_Onde()
{
    glColor4f(GREEN);
    glPushMatrix();
    glTranslatef(obsP[0], obsP[1], obsP[2]);
    glutSolidCube(1.5);
    glPopMatrix();
}






void DrawCubo(){
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, esquerda);
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, direita);
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, cima);
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, bottom);
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, back);
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, front);
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
    
    
    //BASE DO CARRO
    glColor3f(1,1,0);
    glPushMatrix();
    glScalef(2, 1, 1);
    DrawCubo();
    glPopMatrix();
    
    
    
    glColor3f(0.52,0.8,0.98);
    glPushMatrix();
    glTranslatef(0.25, tam+0.2, 0);
    
    glScalef(0.05, 0.9, 0.9);
    DrawCubo();
    glPopMatrix();
    
    
    // PARTE DE CIMA DO CARRO
    glPushMatrix();
    glScalef(1.25, 1.2, 1);
    glColor3f(1,1,0);
    glTranslatef(-0.3, tam, 0);
    DrawCubo();
    glPopMatrix();
    
    
    //PRIMEIRA RODA
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
    
    
    
    
    
    //PORTA
    glPushMatrix();
    glColor3f(0.83,0.83,0.47);
    glTranslatef(-0.1, 0.3, tam);
    glScalef(0.5, 1, 0.1);
    DrawCubo();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, Trans, 0);
    glColor3f(0.52,0.8,0.98);
    glTranslatef(-0.1, 0.6, tam);
    glScalef(0.40, 1, 0.05);
    DrawCubo();
    glPopMatrix();
    
    
    //PORTA
    glPushMatrix();
    glColor3f(0.83,0.83,0.47);
    glTranslatef(-0.1, 0.3, -tam);
    glScalef(0.5, 1, 0.1);
    DrawCubo();
    glPopMatrix();
    
    
    
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
    glPushMatrix();
    glColor3f(0.83,0.83,0.47);
    glTranslatef(-0.7, 0.3, tam);
    glScalef(0.5, 1, 0.1);
    DrawCubo();
    glPopMatrix();
    
    
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
    
    
    //PORTA
    glPushMatrix();
    glColor3f(0.83,0.83,0.47);
    glTranslatef(-0.7, 0.3,- tam);
    glScalef(0.5, 1, 0.1);
    DrawCubo();
    glPopMatrix();
    
    
    glPushMatrix();
    glTranslatef(0, Trans, 0);
    glColor3f(0.52,0.8,0.98);
    glTranslatef(-0.7, 0.6, -tam);
    glScalef(0.40, 1, 0.05);
    DrawCubo();
    glPopMatrix();
    
    
    
    
    
    
    
    
    
    
    //mala
    glPushMatrix();
    glColor3f(0.83,0.83,0.47);
    glTranslatef(-0.95, 0.5, 0);
    glScalef(0.15, 1, 0.9);
    DrawCubo();
    glPopMatrix();
    
    
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(-1, 0.15, 0);
    glScalef(0.15,0.15, 0.6);
    DrawCubo();
    glPopMatrix();
    
    //Matriculas
    
    glPushMatrix();
    glColor3f(1,0,1);
    glTranslatef(-1,-0.3, 0);
    glScalef(0.05,0.15, 0.40);
    DrawCubo();
    glPopMatrix();
    
    
    glPushMatrix();
    glColor3f(1,0,1);
    glTranslatef(1,-0.3, 0);
    glScalef(0.05,0.15, 0.40);
    DrawCubo();
    glPopMatrix();
    
    
    
    
    // Luzese
    
    glPushMatrix();
    glColor3f(1,0,0);
    glTranslatef(-1,-0.15, -0.4);
    glScalef(0.05,0.15, 0.1);
    DrawCubo();
    glPopMatrix();
    
    
    glPushMatrix();
    glColor3f(1,0,0);
    glTranslatef(-1,-0.15, 0.4);
    glScalef(0.05,0.15, 0.1);
    DrawCubo();
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(-1,-0.15, 0.28);
    glScalef(0.05,0.15, 0.1);
    DrawCubo();
    glPopMatrix();
    
    
    
    
    
    // LUZES PISCAS
    
    glPushMatrix();
    glColor3f(1,0.64,0);
    glTranslatef(-1,-0.3, -0.4);
    glScalef(0.05,0.15, 0.1);
    DrawCubo();
    glPopMatrix();
    
    
    glPushMatrix();
    glColor3f(1,0.64,0);
    glTranslatef(-1,-0.3, 0.4);
    glScalef(0.05,0.15, 0.1);
    DrawCubo();
    glPopMatrix();
    
    
    
    
    glPushMatrix();
    glColor3f(1,0.64,0);
    glTranslatef(1,-0.3, -0.4);
    glScalef(0.05,0.15, 0.1);
    DrawCubo();
    glPopMatrix();
    
    
    glPushMatrix();
    glColor3f(1,0.64,0);
    glTranslatef(1,-0.3, 0.4);
    glScalef(0.05,0.15, 0.1);
    DrawCubo();
    glPopMatrix();
    
    
    //LUZES NORMAIS FRENTE
    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(1,0.1, -0.4);
    glScalef(0.05,0.6, 0.1);
    DrawCubo();
    glPopMatrix();
    
    
    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(1,0.1, 0.4);
    glScalef(0.05,0.6, 0.1);
    DrawCubo();
    glPopMatrix();
    
    
    
    glPopMatrix();
}


void DesenhaCarro(void){
    glClear(GL_COLOR_BUFFER_BIT);
    drawScene();
    glutSwapBuffers();
    
}


//======================================================
//======================================================
void display(void) {
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    

    glViewport(0,0, 0.25*wScreen, 0.25*hScreen);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(angZoom,(float)wScreen/hScreen, 0.1, 9999);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 30,0, 0, 0, 0, 0, 0, -1);
    
   
    drawEixos();
    
    drawScene();
    
   
    glViewport(0.25*wScreen,0, wScreen, hScreen);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(angZoom+40,(float)wScreen/hScreen, 0.1, 9999);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(obsP[0], obsP[1], obsP[2], xPointLook, yPointLook, zPointLook, 0, 1, 0);
    
    //ÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖObjectos
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
            rotacao = rotacao - 2.5;
            glutPostRedisplay();
            break;
        case 'k':case 'K':
            AnguloRotacao = AnguloRotacao + 2.5;
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





