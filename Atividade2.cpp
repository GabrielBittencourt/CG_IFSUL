#include <GL/gl.h>  //biblioteca gl.h
#include <GL/glu.h> //biblioteca glu.h
#include <GL/glut.h>  //biblioteca glut - ferramentas adicionais


void Inicializa(void) { //seleciona cor do fundo azul...
glClearColor(1, 1, 1, 0);
}


void Desenha(void) {
// Limpa a janela de visualização com a cor de fundo especifcada
glClear(GL_COLOR_BUFFER_BIT);

// Especifca que a cor corrente é o branco
glColor3f(0, 0, 1);

// Desenha quatro pontos brancos



	//pol3
	glBegin(GL_POLYGON);
	glVertex2i(50,50);
	glVertex2i(150,50);
	glVertex2i(150,200);
	glVertex2i(100,200);
	glVertex2i(50,150);	
	glVertex2i(50,50);

	glEnd();


	//pol1
	glBegin(GL_POLYGON);
	glVertex2i(50,250);
	glVertex2i(250,250);
	glVertex2i(250,350);
	glVertex2i(50,350);
	glVertex2i(50,250);
	glEnd();

	//pol2
	glBegin(GL_POLYGON);
	glVertex2i(100,200);
	glVertex2i(150,200);
	glVertex2i(150,250);
	glVertex2i(100,250);
	glVertex2i(100,200);
	
	glEnd();

	//pol6
	glBegin(GL_POLYGON);
	glVertex2i(250,150);
	glVertex2i(300,200);
	glVertex2i(300,250);
	glVertex2i(250,300);
	glVertex2i(250,150);
	

	glEnd();

	//pol5
	glBegin(GL_POLYGON);
	glVertex2i(200,100);
	glVertex2i(250,150);
	glVertex2i(250,250);
	glVertex2i(200,250);
	glVertex2i(200,100);
	

	glEnd();

	//pol4
	glBegin(GL_POLYGON);
	glVertex2i(150,100);
	glVertex2i(200,100);
	glVertex2i(200,200);
	glVertex2i(150,150);
	glVertex2i(150,100);
	

	glEnd();
	
glColor3f(0, 0, 0);

	glBegin(GL_LINES);
	
	
	//glVertex2i(i,i);
	glVertex2i(50,50);
	glVertex2i(150,50);

	glVertex2i(150,50);
	glVertex2i(150,100);
	
	glVertex2i(150,100);	
	glVertex2i(200,100);

	glVertex2i(200,100);
	glVertex2i(300,200);

	glVertex2i(300,200);
	glVertex2i(300,250);

	glVertex2i(300,250);
	glVertex2i(250,300);

	glVertex2i(250,300);
	glVertex2i(250,350);

	glVertex2i(250,350);
	glVertex2i(50,350);

	glVertex2i(50,350);
	glVertex2i(50,350);

	glVertex2i(50,350);
	glVertex2i(50,250);

	glVertex2i(50,250);
	glVertex2i(100,250);
	
	//meio começa aqui

	glVertex2i(150,150);
	glVertex2i(200,200);

	glVertex2i(200,200);
	glVertex2i(200,250);

	glVertex2i(200,250);
	glVertex2i(150,250);

	glVertex2i(150,250);
	glVertex2i(150,250);

	//fim do meio
	glVertex2i(100,250);
	glVertex2i(100,200);

	glVertex2i(100,200);
	glVertex2i(50,150);

	glVertex2i(50,150);
	glVertex2i(50,50);

	glEnd();

	


// Executa os comandos OpenGL
glFlush();
}


// Função callback chamada quando o tamanho da janela é alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h) {
// Evita a divisao por zero

if(h == 0)
h = 1;

// Especifca as dimensões da Viewport
glViewport(0, 0, w, h);

// Inicializa o sistema de coordenadas
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
// Estabelece a janela de seleção (left, right, bottom, top)

if (w <= h)
gluOrtho2D(0, 400, 0, 400*h/w);
else
gluOrtho2D(0, 400*w/h, 0, 400);
}



int main(int argc, char **argv) {

//inicializa a lib glut com parametros default
glutInit(&argc, argv); 

//defne o modo de exibição, usando tipo simples e sistema de cor RGB
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
//defne o tamanho da janela
glutInitWindowSize(400, 400); 
//define a posição da janela
glutInitWindowPosition(10,10); 
//defne o título da janela
glutCreateWindow("Pratica 1"); 
//chama funcao callback de exibicao
glutDisplayFunc(Desenha);
//chama funcao para alterar o tamanho da janela corrente
glutReshapeFunc(AlteraTamanhoJanela); 
//chama funcao de inicializacao
Inicializa();
//realiza um loopback na janela ativa
glutMainLoop(); 
//requer que funcao main retorne um inteiro (0)
return 0;
}

