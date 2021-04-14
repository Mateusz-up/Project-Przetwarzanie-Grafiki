#ifndef PUNKT_H
#define PUNKT_H

#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/vec3.hpp>

#define _USE_MATH_DEFINES

GLuint VAO;
GLuint VBO[7];
GLuint wielkoscPunktu = 10;

class Figures
{
private:
	int wysokoscOkna;
	int szerokoscOkna;
	int polozenieOknaX;
	int polozenieOknaY;

public:
	Figures(void);
	Figures(int wysokoscOkna, int szerokoscOkna, int polozenieOknaX, int polozenieOknaY);
	~Figures(void);
	void stworzenieOkna(int argc, char** argv);
	void inicjalizacjaGlew();
	static void wyswietl();
	static void usun();
	void stworzenieVAO();
	void sprawdzenieWersji();

	void createTriangle1();
	void createTriangle2();
	void createTriangle3();

	void createSquare1();
	void createSquare2();

	void createCircle1();
	void createCircle2();

	glm::vec3 * makeCircle(GLfloat x, GLfloat y, GLfloat r);

};

#endif /* PUNKT_H */