#pragma once

#include <cstring>
#include <cmath>
#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <vector>
#include "Wektor.h"
#include "Macierz.h"
#include "StopnieRadiany.h"
#include "Przeksztalcenia.h"

class ProgramMPGK
{
private:
	int wysokoscOkna;
	int szerokoscOkna;
	int polozenieOknaX;
	int polozenieOknaY;
	static GLuint VAO;
	static GLuint VBO[1];
	static GLuint VBO2;
	static GLuint IBO;
	static GLuint programZShaderami;
	static GLuint vertexShaderId;
	static GLuint fragmentShaderId;
	static GLint zmiennaShader;
	static GLint zmiennaShader1;

public:
	ProgramMPGK(void);
	ProgramMPGK(int wysokoscOkna, int szerokoscOkna, int polozenieOknaX, int polozenieOknaY);
	~ProgramMPGK(void);
	void stworzenieOkna(int argc, char** argv);
	void inicjalizacjaGlew();
	static void wyswietl();
	static void usun();
	void stworzenieVAO();
	void stworzenieVBO(macierz<4> przeksztalcen);
	void stworzenieIBO();
	void stworzenieProgramu();
	GLuint dodanieDoProgramu(GLuint programZShaderami, const char * tekstShadera, GLenum typShadera);
	void sprawdzenieWersji();
};