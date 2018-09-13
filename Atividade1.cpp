#include <iostream>
#include <cstdlib>
#include <GL/gl.h> //biblioteca gl.h
#include <GL/glu.h> //biblioteca glu.h
#include <GL/glut.h> //biblioteca glut - ferramentas adicionais

#define XDMAX 400
#define YDMAX 400

using namespace std;

void Inicializa(void) {
//Seleciona cor do fundo branco...
	glClearColor(1, 1, 1, 0);

}
void Desenha(void) {
// Limpa a janela de visualização com a cor de fundo especifcada
	glClear(GL_COLOR_BUFFER_BIT);
// Size ponto
	// glPointSize(5);
// Width
	// glLineWidth(5);
// Desenha
	
	//Poligono Topo
	//Verde
	glColor3f(0, 1, 0);

	glBegin(GL_POLYGON);
		glVertex2i(100, 300); 
		glVertex2i(300, 300); 
		glVertex2i(200, 350);
		glVertex2i(100, 300);
	glEnd();

	//Poligono Central
	//Vermelho
	glColor3f(1, 0, 0);

	glBegin(GL_POLYGON);
		glVertex2i(150, 150);
		glVertex2i(250, 150); 
		glVertex2i(250, 250);
		glVertex2i(150, 250);
		glVertex2i(150, 150);
	glEnd();

	//Linhas Quadrado Interno
	//Preto
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
		glVertex2i(150, 150);
		glVertex2i(250, 150);

		glVertex2i(250, 150); 
		glVertex2i(250, 250);

		glVertex2i(150, 250);
		glVertex2i(150, 150);

		glVertex2i(150, 250);
		glVertex2i(250, 250);
	glEnd();

	//Quadrado Externo
	glBegin(GL_LINES);
		glVertex2i(100, 100); 
		glVertex2i(300, 100);
		
		glVertex2i(300, 100);
		glVertex2i(300, 300);
		
		glVertex2i(300, 300);
		glVertex2i(100, 300);
		
		glVertex2i(100, 300);
		glVertex2i(100, 100);
	glEnd();

	//Triangulo
	glBegin(GL_LINES);
		glVertex2i(100, 300); 
		glVertex2i(200, 350);

		glVertex2i(200, 350); 
		glVertex2i(300, 300);
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
		gluOrtho2D(0, XDMAX, 0, YDMAX*h/w);
	else
		gluOrtho2D(0, XDMAX*w/h, 0, YDMAX);
}
//Declara o tamanho da janela, posicao e modo de
//visualizacao...(single bufer e RGBA).
//Abre uma janela com o título "4 Pontos" na barra de título.
//Chama as rotinas de inicializacao. Entra no loop principal e
//processa os eventos...
int main(int argc, char **argv) {
//inicializa a lib glut com parametros default
	glutInit(&argc, argv);
//defne o modo de exibição, usando tipo simples e sistema de cor RGB
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//defne o tamanho da janela
	glutInitWindowSize(XDMAX, YDMAX);
//defne a posição da janela
	glutInitWindowPosition(10,10);
//defne o título da janela
	glutCreateWindow("4 Pontos");
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

