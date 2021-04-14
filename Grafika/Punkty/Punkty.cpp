#include "Punkty.h"




Punkty::Punkty(void)
{
	wysokoscOkna = 768;
	szerokoscOkna = 1024;
	polozenieOknaX = 100;
	polozenieOknaY = 100;
}

Punkty::Punkty(int wysokoscOkna, int szerokoscOkna, int polozenieOknaX, int polozenieOknaY)
{
	this->wysokoscOkna = wysokoscOkna;
	this->szerokoscOkna = szerokoscOkna;
	this->polozenieOknaX = polozenieOknaX;
	this->polozenieOknaY = polozenieOknaY;
}

Punkty::~Punkty()
{
	
}

void Punkty::stworzenieOkna(int argc, char** argv)
{
	
	glutInit(&argc, argv);

	
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(szerokoscOkna, wysokoscOkna);
	glutInitWindowPosition(polozenieOknaX, polozenieOknaY);

	
	glewExperimental = GL_TRUE;

	glutInitContextVersion(3, 3);
	glutInitContextProfile(GLUT_CORE_PROFILE);

	glutCreateWindow("punkt");
}


void Punkty::inicjalizacjaGlew()
{
	GLenum wynik = glewInit();
	if (wynik != GLEW_OK)
	{
		std::cerr << "Nie udalo sie zainicjalizowac GLEW. Blad: " << glewGetErrorString(wynik) << std::endl;
		system("pause");
		exit(1);
	}
}


void Punkty::stworzenieVBO() {

	glm::vec3 Wierzcholki[30];

	int i;
	float x = -0.5f;


	for (i = 0; i < 10; i++) {
		Wierzcholki[i] = glm::vec3(x, 0.4f, 0.0f);

		x += (float)0.1f;
	}

	x = -0.5f;

	for (i = 10; i < 20; i++) {
		Wierzcholki[i] = glm::vec3(x, 0.0f, 0.0f);
		x += (float)0.1f;
	}

	x = -0.5f;

	for (i = 20; i < 30; i++) {
		Wierzcholki[i] = glm::vec3(x, -0.4f, 0.0f);
		x += (float)0.1f;
	}


	glGenBuffers(1, &VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	std::cout << "VBO: " << VBO << std::endl;

	glBufferData(GL_ARRAY_BUFFER, sizeof(Wierzcholki), Wierzcholki, GL_STATIC_DRAW);
}

void Punkty::sprawdzenieWersji()
{
	std::cout << "Wersja GLEW: " << glewGetString(GLEW_VERSION) << std::endl;
	std::cout << "Wersja VENDOR: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "Wersja REDERER: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "Wersja GL: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "Wersja GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
}


void Punkty::stworzenieVAO()
{

	glGenVertexArrays(1, &VAO);
	std::cout << "VAO: " << VAO << std::endl;

	glBindVertexArray(VAO);
}

void  Punkty::wyswietl()
{
	
	glClear(GL_COLOR_BUFFER_BIT);

	
	glEnableVertexAttribArray(0);

	
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glPointSize(wielkoscPunktu);

	
	glDrawArrays(GL_POINTS, 0, 30);

	
	glDisableVertexAttribArray(0);

	glutSwapBuffers();
}

void Punkty::usun()
{
	
	glDeleteBuffers(1, &VBO);
	glDeleteVertexArrays(1, &VAO);
}



int main(int argc, char** argv)
{
Punkty punkty(786, 786, 100, 100);

punkty.stworzenieOkna(argc, argv);
punkty.inicjalizacjaGlew();
punkty.sprawdzenieWersji();
punkty.stworzenieVAO();
punkty.stworzenieVBO();

glutDisplayFunc(punkty.wyswietl);
glutCloseFunc(punkty.usun);

glClearColor(0.2f, 0.1f, 0.0f, 0.0f);

glutMainLoop();

return 0;
}

