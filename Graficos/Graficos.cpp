// Graficos.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#define GLEW_STATIC
#include "GL\glew.h"
#include "GLFW\glfw3.h"
#include <math.h>

#include <iostream>
using namespace std;

GLfloat red, green, blue;

void actualizar() { 
	//Aqui esta bien para cambiar los valores de las variables de mi programa

	/*red += 0.001;
	green += 0.002;
	blue += 0.003;

	if (red > 1) red = 0;
	if (green > 1) green = 0;
	if (blue > 1) blue = 0;*/
}

void dibujar() {

	glBegin(GL_QUADS);//CIELO

	glColor3f(0.5f, 0.65f, 0.9f);
	glVertex3f(-1.0f, 1.0f, 0.0f);

	glColor3f(0.5f, 0.65f, 0.9f);
	glVertex3f(1.0f, 1.0f, 0.0f);

	glColor3f(0.5f, 0.65f, 0.9f);
	glVertex3f(1.0f, -0.5f, 0.0f);

	glColor3f(0.5f, 0.65f, 0.9f);
	glVertex3f(-1.0f, -0.5f, 0.0f);

	glEnd();//finaliza rutina

	glBegin(GL_QUADS);//CASA

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-0.5f, 0.1f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.5f, 0.1f, 0.0f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.5f, -0.5f, 0.0f);

	glColor3f(0.5f, 1.0f, 1.0f);
	glVertex3f(-0.5f, -0.5f, 0.0f);

	glEnd();//finaliza rutina

	glBegin(GL_QUADS);//PUERTA

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.09f, -0.2f, 0.0f);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.09f, -0.2f, 0.0f);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.09f, -0.5f, 0.0f);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.09f, -0.5f, 0.0f);

	glEnd();//finaliza rutina

	glBegin(GL_QUADS);//VENTANA

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.4f, -0.1f, 0.0f);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.2f, -0.1f, 0.0f);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.2f, -0.3f, 0.0f);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.4f, -0.3f, 0.0f);

	glEnd();//finaliza rutina


	glBegin(GL_QUADS);//VENTANA2

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.4f, -0.1f, 0.0f);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.2f, -0.1f, 0.0f);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.2f, -0.3f, 0.0f);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.4f, -0.3f, 0.0f);

	glEnd();//finaliza rutina


	glBegin(GL_TRIANGLES);//TECHO

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-0.7f, 0.0f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 0.7f, 0.0f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.7f, 0.0f, 0.7f);

	glEnd();//finaliza rutina

	glBegin(GL_POLYGON);//SOL
	glColor3f(0.5f, 0.2f,0.7f);
	for (float i = 0; i < 360; i++)
	{
		glVertex3f(0.2*cos(i) + 0.4,0.2*sin(i) + 0.8, 0.0f);

	}

	glEnd();//finaliza rutina

}

int main()
{
	//Declaracion de ventana 
	GLFWwindow *window;
	//Propiedades de la ventana
	GLfloat ancho = 800;
	GLfloat alto = 800;

	//Inicializacion de GLFW
	if (!glfwInit()) {
		//Si no se inicio bien, terminar la ejecucion
		exit(EXIT_FAILURE);
	}

	//Inicializar la ventana
	window = glfwCreateWindow(ancho, alto, "Graficos", NULL, NULL);
	//Verificar si se creo bien la ventana
	if (!window) {
		//Cerrar todos los procesos de GLFW
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	//Establecer "window" como contexto
	glfwMakeContextCurrent(window);

	//se trae las funciones de OpenGL Moderno
	glewExperimental = true;
	//Inicializar GLEW
	GLenum glewError = glewInit();
	//Verificar que GLEW se inicializo bien
	if (glewError != GLEW_OK) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}


	const GLubyte *version = glGetString(GL_VERSION);
	cout << "Version de OpenGL: " << version << endl;

	red = green = blue = 0.0f;

	//Ciclo de dibujo
	while (!glfwWindowShouldClose(window)) {
		//Establecer el area de render(Vewport)
		glViewport(0, 0, ancho, alto);
		//Establecer el color con el que se limpia la pantalla

	
		glClearColor(red, green, blue, 1);
		
		//Limpiar pantalla
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//rutina de dibujo
		actualizar();
		dibujar();

		//Intercambio de buffers
		glfwSwapBuffers(window);
		//Buscar señales de entrada
		glfwPollEvents();

	}

	glfwDestroyWindow(window);
	glfwTerminate();

    return 0;
}

