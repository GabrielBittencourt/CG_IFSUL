#include <GL/gl.h> 
#include <GL/glu.h> 
#include <GL/glut.h>  
#include <iostream>
#include <cstdlib>
#include <cmath>

#define TAMJANELA 1000

using namespace std;

void Inicializa(void) {
	glClearColor(1, 1, 1, 0);  
}


void pontosCirc(int x, int y, int x1, int y1, int flag)
{
  glPointSize(3);
  if(flag == 0)
    glBegin(GL_POINTS);
  else if(flag == 1)
    glBegin(GL_POLYGON);
    else{
        cout << "Xablauuuu" << endl;
        exit (-1);
    }
    glVertex2i(x1+x, y1+y);
    glVertex2i(x1+y, y1+x);
    glVertex2i(x1+y, y1-x);
    glVertex2i(x1+x, y1-y);
    glVertex2i(x1-x, y1-y);
    glVertex2i(x1-y, y1-x);
    glVertex2i(x1-y, y1+x);
    glVertex2i(x1-x, y1+y);
  glEnd();
}

void desenhaCirc(int raio, int x1, int y1, int flag)
{
  int x, y;
  float d;
  x = 0;
  y = raio;
  d = 5./4-raio;
  pontosCirc(x, y, x1, y1, flag);
  while(y > x) 
  {
    if(d < 0)
      d = d + 2*x + 3;
    else {
       d = d + 2*(x-y) + 5;
       y = y-1;
      }
    x = x + 1;
    pontosCirc(x, y, x1, y1, flag);
  }
}

void Desenha(void) {

  glClear(GL_COLOR_BUFFER_BIT);

  glColor3f(0, 0, 0);  
  desenhaCirc(200,500,500,0); //cabeça

  glColor3f(0, 0, 0);  
  desenhaCirc(125,300,700,1); //orelha esquerda

  glColor3f(0, 0, 0);  
  desenhaCirc(125,700,700,1); //orelha direita

  glColor3f(0, 0, 0);  
  desenhaCirc(35,500,450,1); //nariz

  glColor3f(0, 0, 0);  
  desenhaCirc(35,425,550,0); //olho esquerdo

  glColor3f(0, 0, 0);  
  desenhaCirc(20,415,535,1);

  glColor3f(0, 0, 0);  
  desenhaCirc(35,575,550,0); //olho direito

  glColor3f(0, 0, 0);  
  desenhaCirc(20,565,535,1);

  glBegin(GL_POLYGON);  //boca
    glVertex2i(470, 350);
    glVertex2i(530, 350);
    glVertex2i(575, 385);
    glVertex2i(430, 385);
  glEnd();

  
  glLineWidth(3);
  glBegin(GL_LINES); //linhas boca
    glVertex2i(570, 380);
    glVertex2i(605, 415);

    glVertex2i(400, 415);
    glVertex2i(430, 385);

    glVertex2i(595, 425);
    glVertex2i(615, 405);

    glVertex2i(390, 405);
    glVertex2i(410, 425);

    glVertex2i(380, 500);
    glVertex2i(500, 525);

    glVertex2i(500, 525);
    glVertex2i(620, 500);
    
    
    
  glEnd();

  glBegin(GL_POLYGON);  //cabelo
    glVertex2i(300, 700);
    glVertex2i(700, 700);
    glVertex2i(500, 600);
    glVertex2i(300, 700);
  glEnd();

  glColor3f(1, 0, 0);  

  glBegin(GL_POLYGON);  //lingua
    glVertex2i(470, 355);
    glVertex2i(530, 355);
    glVertex2i(540, 360);
    glVertex2i(530, 370);
    glVertex2i(470, 370);
    glVertex2i(460, 360);
  glEnd();

  glColor3f(0, 0, 0);  
  
  glBegin(GL_LINES);
  
  	glVertex2i(500, 360);
    glVertex2i(480, 370);
  
  glEnd();

  glBegin(GL_POLYGON);  //suiça direita
    glVertex2i(650, 470);
    glVertex2i(700, 500);
    glVertex2i(690, 600);
    glVertex2i(650, 470);
    
  glEnd();

  glBegin(GL_POLYGON);  //suiça direita
    glVertex2i(350, 470);
    glVertex2i(300, 500);
    glVertex2i(310, 600);
    glVertex2i(350, 470);
    
  glEnd();


  glFlush();
}

void AlteraTamanhoJanela(GLsizei w, GLsizei h) {
	if(h == 0)
		h = 1;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		gluOrtho2D(0, TAMJANELA, 0, TAMJANELA*h/w);
	else
		gluOrtho2D(0, TAMJANELA*w/h, 0, TAMJANELA);
}

int main(int argc, char **argv) {
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	glutInitWindowSize(TAMJANELA, TAMJANELA); 
	glutInitWindowPosition(100,100); 
	glutCreateWindow("OpenGL: Circunferencias"); 
	glutDisplayFunc(Desenha);
	glutReshapeFunc(AlteraTamanhoJanela); 
	Inicializa();
	glutMainLoop(); 
	return 0;
}
