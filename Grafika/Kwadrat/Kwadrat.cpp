#include "Kwadrat.h"

Kwadrat::Kwadrat(void)
{
	wysokoscOkna = 768;
	szerokoscOkna = 1024;
	polozenieOknaX = 100;
	polozenieOknaY = 100;
}

Kwadrat::Kwadrat(int wysokoscOkna, int szerokoscOkna, int polozenieOknaX, int polozenieOknaY)
{
	this->wysokoscOkna = wysokoscOkna;
	this->szerokoscOkna = szerokoscOkna;
	this->polozenieOknaX = polozenieOknaX;
	this->polozenieOknaY = polozenieOknaY;
}

Kwadrat::~Kwadrat()
{

}

void Kwadrat::stworzenieOkna(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(szerokoscOkna, wysokoscOkna);
	glutInitWindowPosition(polozenieOknaX, polozenieOknaY);
	glewExperimental = GL_TRUE;
	glutInitContextVersion(3, 3);
	glutInitContextProfile(GLUT_CORE_PROFILE);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glDisable(GL_CULL_FACE);
	glFrontFace(GL_CW);
	glCullFace(GL_BACK);

	glutCreateWindow("Kwadrat");
}

void Kwadrat::inicjalizacjaGlew()
{
	GLenum wynik = glewInit();
	if (wynik != GLEW_OK)
	{
		std::cerr << "Nie udalo sie zainicjalizowac GLEW. Blad: " << glewGetErrorString(wynik) << std::endl;
		system("pause");
		exit(1);
	}
}

void  Kwadrat::wyswietl()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glPointSize(wielkoscKwadratu);

	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

	glDisableVertexAttribArray(0);

	glutSwapBuffers();
}

void Kwadrat::usun()
{
	glDeleteBuffers(1, &VBO);
	glDeleteVertexArrays(1, &VAO);
}

void Kwadrat::stworzenieVAO()
{
	glGenVertexArrays(1, &VAO);
	std::cout << "VAO: " << VAO << std::endl;
	glBindVertexArray(VAO);
}

void Kwadrat::stworzenieVBO()
{
	float x = 0.0f;
	float y = 0.0f;
	float r = 0.5f;

	glm::vec3 Wierzcholki[4] = {
		glm::vec3(x, y, 0.0f),
		glm::vec3(x + r, y, 0.0f),
		glm::vec3(x + r, y + r, 0.0f),
		glm::vec3(x, y + r, 0.0f)
	};

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	std::cout << "VBO: " << VBO << std::endl;
	glBufferData(GL_ARRAY_BUFFER, sizeof(Wierzcholki), Wierzcholki, GL_STATIC_DRAW);
}

int main(int argc, char** argv)
{
	Kwadrat Kwadrat(786, 786, 100, 100);

	Kwadrat.stworzenieOkna(argc, argv);
	Kwadrat.inicjalizacjaGlew();
	Kwadrat.stworzenieVAO();
	Kwadrat.stworzenieVBO();
	glutDisplayFunc(Kwadrat.wyswietl);
	glutCloseFunc(Kwadrat.usun);

	glClearColor(0.2f, 0.1f, 0.0f, 0.0f);

	glutMainLoop();

	return 0;
}