#ifndef TROJKAT_H
#define TROJKAT_H

#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/vec3.hpp>
#include <time.h>

GLuint VAO;
GLuint VBO;
GLuint wielkoscTrojkatu = 10;

class Trojkat
{
private:
	int wysokoscOkna;
	int szerokoscOkna;
	int polozenieOknaX;
	int polozenieOknaY;

public:
	Trojkat(void);
	Trojkat(int wysokoscOkna, int szerokoscOkna, int polozenieOknaX, int polozenieOknaY);
	~Trojkat(void);
	void stworzenieOkna(int argc, char** argv);
	void inicjalizacjaGlew();
	static void wyswietl();
	static void usun();
	void stworzenieVAO();
	void stworzenieVBO();
	void sprawdz(glm::vec3 * tab, int n);
};

#endif /* TROJKAT_H */