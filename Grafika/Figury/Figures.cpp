#include "Figures.h"
#include <math.h>

using namespace std;

void Figures::createTriangle1()
{
	glm::vec3 Wierzcholki[3] = {
		glm::vec3(-0.7f, 0.8f, 0.0f),
		glm::vec3(-0.6f, 0.7f, 0.0f),
		glm::vec3(-0.8f, 0.7f, 0.0f)
	};

	glGenBuffers(1, &VBO[0]);
	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
	std::cout << "VBO: " << VBO[0] << std::endl;
	glBufferData(GL_ARRAY_BUFFER, sizeof(Wierzcholki), Wierzcholki, GL_STATIC_DRAW);
}

void Figures::createTriangle2()
{
	glm::vec3 Wierzcholki[3] = {
		glm::vec3(-0.7f, 0.1f, 0.0f),
		glm::vec3(-0.6f, -0.1f, 0.0f),
		glm::vec3(-0.8f, -0.1f, 0.0f)
	};

	glGenBuffers(1, &VBO[1]);
	glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
	std::cout << "VBO: " << VBO[1] << std::endl;
	glBufferData(GL_ARRAY_BUFFER, sizeof(Wierzcholki), Wierzcholki, GL_STATIC_DRAW);
}

void Figures::createTriangle3()
{
	glm::vec3 Wierzcholki[3] = {
		glm::vec3(0.7f, -0.1f, 0.0f),
		glm::vec3(0.6f, 0.1f, 0.0f),
		glm::vec3(0.8f, 0.1f, 0.0f)
	};

	glGenBuffers(1, &VBO[2]);
	glBindBuffer(GL_ARRAY_BUFFER, VBO[2]);
	std::cout << "VBO: " << VBO[2] << std::endl;
	glBufferData(GL_ARRAY_BUFFER, sizeof(Wierzcholki), Wierzcholki, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

}

void Figures::createSquare1()
{
	glm::vec3 Wierzcholki[6] = {
		glm::vec3(-0.8f, -0.6f, 0.0f),
		glm::vec3(-0.6f, -0.6f, 0.0f),
		glm::vec3(-0.6f, -0.8f, 0.0f),
		glm::vec3(-0.8f, -0.6f, 0.0f),
		glm::vec3(-0.6f, -0.8f, 0.0f),
		glm::vec3(-0.8f, -0.8f, 0.0f)
	};

	glGenBuffers(1, &VBO[3]);
	glBindBuffer(GL_ARRAY_BUFFER, VBO[3]);
	std::cout << "VBO: " << VBO[3] << std::endl;
	glBufferData(GL_ARRAY_BUFFER, sizeof(Wierzcholki), Wierzcholki, GL_STATIC_DRAW);
}

void Figures::createSquare2()
{
	glm::vec3 Wierzcholki[6] = {
		glm::vec3(0.8f, -0.6f, 0.0f),
		glm::vec3(0.6f, -0.6f, 0.0f),
		glm::vec3(0.6f, -0.8f, 0.0f),
		glm::vec3(0.8f, -0.6f, 0.0f),
		glm::vec3(0.6f, -0.8f, 0.0f),
		glm::vec3(0.8f, -0.8f, 0.0f)
	};

	glGenBuffers(1, &VBO[4]);
	glBindBuffer(GL_ARRAY_BUFFER, VBO[4]);
	std::cout << "VBO: " << VBO[4] << std::endl;
	glBufferData(GL_ARRAY_BUFFER, sizeof(Wierzcholki), Wierzcholki, GL_STATIC_DRAW);
}

glm::vec3 * Figures::makeCircle(GLfloat x, GLfloat y, GLfloat r)
{
	const GLint ilosc_trojkatow = 360;
	GLfloat pi = 2.0f * M_PI;
	glm::vec3 pkts[(ilosc_trojkatow + 2) * 3];

	pkts[0] = glm::vec3(x, y, 0.0f);

	for (int i = 1; i < ilosc_trojkatow + 2; ++i) {
		pkts[i] = glm::vec3(
			x + (r * cos(i * pi / ilosc_trojkatow)),
			y + (r * sin(i * pi / ilosc_trojkatow)),
			0.0f
		);
	}

	return pkts;
}

void Figures::createCircle1()
{
	glm::vec3 Wierzcholki[362 * 2];

	glm::vec3 * kolo1 = makeCircle(0.0f, 0.0f, 0.15f);

	for (int i = 0; i < 362; ++i) {
		Wierzcholki[i] = kolo1[i];
	}

	glGenBuffers(1, &VBO[5]);
	glBindBuffer(GL_ARRAY_BUFFER, VBO[5]);
	std::cout << "VBO: " << VBO << std::endl;
	glBufferData(GL_ARRAY_BUFFER, sizeof(Wierzcholki), Wierzcholki, GL_STATIC_DRAW);
}

void Figures::createCircle2()
{
	glm::vec3 Wierzcholki[362 * 2];

	glm::vec3 * kolo1 = makeCircle(0.7f, 0.5f, 0.1f);

	for (int i = 0; i < 362; ++i) {
		Wierzcholki[i] = kolo1[i];
	}

	glGenBuffers(1, &VBO[6]);
	glBindBuffer(GL_ARRAY_BUFFER, VBO[6]);
	std::cout << "VBO: " << VBO << std::endl;
	glBufferData(GL_ARRAY_BUFFER, sizeof(Wierzcholki), Wierzcholki, GL_STATIC_DRAW);
}

Figures::Figures(void)
{
	wysokoscOkna = 768;
	szerokoscOkna = 1024;
	polozenieOknaX = 100;
	polozenieOknaY = 100;
}

Figures::Figures(int wysokoscOkna, int szerokoscOkna, int polozenieOknaX, int polozenieOknaY)
{
	this->wysokoscOkna = wysokoscOkna;
	this->szerokoscOkna = szerokoscOkna;
	this->polozenieOknaX = polozenieOknaX;
	this->polozenieOknaY = polozenieOknaY;
}

Figures::~Figures()
{

}

void Figures::stworzenieOkna(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(szerokoscOkna, wysokoscOkna);
	glutInitWindowPosition(polozenieOknaX, polozenieOknaY);
	glutInitContextVersion(3, 3);
	glutInitContextProfile(GLUT_CORE_PROFILE);

	glutCreateWindow("Program. Figury");

}

void Figures::inicjalizacjaGlew()
{
	glewExperimental = GL_TRUE;
	GLenum wynik = glewInit();
	if (wynik != GLEW_OK)
	{
		std::cerr << "Nie udalo sie zainicjalizowac GLEW. Blad: " << glewGetErrorString(wynik) << std::endl;
		system("pause");
		exit(1);
	}
}

void Figures::wyswietl()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glEnableVertexAttribArray(0);

	// trojakt 1 - lewy gora
	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 3);

	// trojkat 2 - lewy srodek
	glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 3);

	// trojkat 3 - prawy srodek
	glBindBuffer(GL_ARRAY_BUFFER, VBO[2]);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 3);

	// kwadrat 1 - lewy srodek
	glBindBuffer(GL_ARRAY_BUFFER, VBO[3]);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 6);

	// kwadrat 2 - prawy srodek
	glBindBuffer(GL_ARRAY_BUFFER, VBO[4]);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 6);

	// kolo 1 - srodek
	glBindBuffer(GL_ARRAY_BUFFER, VBO[5]);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 362);

	// kolo2 - prawy gorny rog
	glBindBuffer(GL_ARRAY_BUFFER, VBO[6]);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 362);

	glDisableVertexAttribArray(0);

	glutSwapBuffers();
}

void Figures::usun()
{
	glDeleteBuffers(1, &VBO[0]);
	glDeleteBuffers(1, &VBO[1]);
	glDeleteBuffers(1, &VBO[2]);
	glDeleteBuffers(1, &VBO[3]);
	glDeleteBuffers(1, &VBO[4]);
	glDeleteBuffers(1, &VBO[5]);
	glDeleteBuffers(1, &VBO[6]);
	glDeleteVertexArrays(1, &VAO);
}

void Figures::stworzenieVAO()
{
	glGenVertexArrays(1, &VAO);
	std::cout << "VAO: " << VAO << std::endl;
	glBindVertexArray(VAO);
}

void Figures::sprawdzenieWersji()
{
	std::cout << "Wersja GLEW: " << glewGetString(GLEW_VERSION) << std::endl;
	std::cout << "Wersja VENDOR: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "Wersja REDERER: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "Wersja GL: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "Wersja GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
}

int main(int argc, char** argv)
{
	Figures figures(650, 650, 0, 0);

	figures.stworzenieOkna(argc, argv);
	figures.inicjalizacjaGlew();
	figures.sprawdzenieWersji();

	figures.stworzenieVAO();

	figures.createTriangle1();
	figures.createTriangle2();
	figures.createTriangle3();

	figures.createSquare1();
	figures.createSquare2();

	figures.createCircle1();
	figures.createCircle2();

	glutDisplayFunc(figures.wyswietl);
	glutCloseFunc(figures.usun);

	glClearColor(0.2f, 0.1f, 0.0f, 0.0f);

	glutMainLoop();

	return 0;
}
