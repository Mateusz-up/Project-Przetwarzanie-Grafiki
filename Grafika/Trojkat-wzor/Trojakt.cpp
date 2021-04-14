#include "Trojkat.h"

Trojkat::Trojkat(void)
{
	wysokoscOkna = 768;
	szerokoscOkna = 1024;
	polozenieOknaX = 100;
	polozenieOknaY = 100;
}

Trojkat::Trojkat(int wysokoscOkna, int szerokoscOkna, int polozenieOknaX, int polozenieOknaY)
{
	this->wysokoscOkna = wysokoscOkna;
	this->szerokoscOkna = szerokoscOkna;
	this->polozenieOknaX = polozenieOknaX;
	this->polozenieOknaY = polozenieOknaY;
}

Trojkat::~Trojkat()
{

}

void Trojkat::stworzenieOkna(int argc, char** argv)
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
	glFrontFace(GL_CCW);
	glCullFace(GL_FRONT);

	glutCreateWindow("Trojkat");
}

void Trojkat::inicjalizacjaGlew()
{
	GLenum wynik = glewInit();
	if (wynik != GLEW_OK)
	{
		std::cerr << "Nie udalo sie zainicjalizowac GLEW. Blad: " << glewGetErrorString(wynik) << std::endl;
		system("pause");
		exit(1);
	}
}

void  Trojkat::wyswietl()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glEnableVertexAttribArray(0);

	
	glEnable(GL_CULL_FACE);

	
	glFrontFace(GL_CCW);

	 
	glCullFace(GL_BACK);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glDrawArrays(GL_TRIANGLES, 0, 3);

	glDisableVertexAttribArray(0);

	glutSwapBuffers();
}

void Trojkat::usun()
{
	glDeleteBuffers(1, &VBO);
	glDeleteVertexArrays(1, &VAO);
}

void Trojkat::stworzenieVAO()
{
	glGenVertexArrays(1, &VAO);
	std::cout << "VAO: " << VAO << std::endl;
	glBindVertexArray(VAO);
}

void Trojkat::stworzenieVBO()
{
	glm::vec3 Wierzcholki[3] = {
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(0.25f, 0.5f, 0.0f),
		glm::vec3(0.5f, 0.0f, 0.0f),
	};

	sprawdz(Wierzcholki, 3);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	std::cout << "VBO: " << VBO << std::endl;
	glBufferData(GL_ARRAY_BUFFER, sizeof(Wierzcholki), Wierzcholki, GL_STATIC_DRAW);
}

void Trojkat::sprawdz(glm::vec3 * tab, int n)
{
	float suma = 0.0f;

	for (int i = 0; i < n; ++i) {
		suma += (tab[i][0] * tab[(i + 1) % n][1]) - (tab[(i + 1) % n][0] * tab[i][1]);
	}

	float wynik = suma / 2;

	if (wynik <= 0) {
		std::cout << "Trojkat obrocony przodem" << std::endl;
		
	}
	else
		std::cout << "Trojkat obrocony tylem" << std::endl;
}

int main(int argc, char** argv)
{
	Trojkat Trojkat(786, 786, 100, 100);

	Trojkat.stworzenieOkna(argc, argv);
	Trojkat.inicjalizacjaGlew();
	Trojkat.stworzenieVAO();
	Trojkat.stworzenieVBO();
	glutDisplayFunc(Trojkat.wyswietl);
	glutCloseFunc(Trojkat.usun);

	glClearColor(0.2f, 0.1f, 0.0f, 0.0f);

	glutMainLoop();

	return 0;
}