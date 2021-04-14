#ifndef Kwadrat_H
#define Kwadrat_H

#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/vec3.hpp>
#include <time.h>

GLuint VAO;
GLuint VBO;
GLuint wielkoscKwadratu = 10;

class Kwadrat
{
private:
	int wysokoscOkna;
	int szerokoscOkna;
	int polozenieOknaX;
	int polozenieOknaY;

public:
	Kwadrat(void);
	Kwadrat(int wysokoscOkna, int szerokoscOkna, int polozenieOknaX, int polozenieOknaY);
	~Kwadrat(void);
	void stworzenieOkna(int argc, char** argv);
	void inicjalizacjaGlew();
	static void wyswietl();
	static void usun();
	void stworzenieVAO();
	void stworzenieVBO();
};

#endif /* Kwadrat_H */