#include "Program.h"

GLuint ProgramMPGK::VAO;
GLuint ProgramMPGK::VBO[1];
GLuint ProgramMPGK::IBO;
GLuint ProgramMPGK::programZShaderami;
GLuint ProgramMPGK::vertexShaderId;
GLuint ProgramMPGK::fragmentShaderId;
GLint ProgramMPGK::zmiennaShader;
GLint ProgramMPGK::zmiennaShader1;

ProgramMPGK::ProgramMPGK(void)
{
	wysokoscOkna = 768;
	szerokoscOkna = 1024;
	polozenieOknaX = 100;
	polozenieOknaY = 100;
}

ProgramMPGK::ProgramMPGK(int wysokoscOkna, int szerokoscOkna, int polozenieOknaX, int polozenieOknaY)
{
	this->wysokoscOkna = wysokoscOkna;
	this->szerokoscOkna = szerokoscOkna;
	this->polozenieOknaX = polozenieOknaX;
	this->polozenieOknaY = polozenieOknaY;
}

ProgramMPGK::~ProgramMPGK()
{
}

void ProgramMPGK::stworzenieOkna(int argc, char** argv)
{
	glewExperimental = GL_TRUE;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(szerokoscOkna, wysokoscOkna);
	glutInitWindowPosition(polozenieOknaX, polozenieOknaY);
	glutInitContextVersion(3, 3);
	glutInitContextProfile(GLUT_CORE_PROFILE);
	glutCreateWindow("Program");
}

void ProgramMPGK::inicjalizacjaGlew()
{
	GLenum wynik = glewInit();
	if (wynik != GLEW_OK)
	{
		std::cerr << "Nie udalo sie zainicjalizowac GLEW. Blad: " << glewGetErrorString(wynik) << std::endl;
		//system("pause");
		exit(1);
	}
}

void ProgramMPGK::wyswietl()
{
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	static GLfloat zmiana = 0.0f;
	zmiana += 0.0005f;
	// glUniform1f(zmiennaShader, abs(sinf(zmiana)));

	przeksztalcenia<4> mac_obrotu2;
	macierz<4> macierz_obrotu2 = mac_obrotu2.macierz_obrotu(150, 'z');
	przeksztalcenia<4> mac_przesunieca;
	macierz<4> macierz_przesunieca = mac_przesunieca.macierz_przesuniecia(0.5, 0, 0);
	macierz<4> macierz_przesunieca2 = mac_przesunieca.macierz_przesuniecia(0, 0, 4);
	przeksztalcenia<4> mac_skalownia;
	macierz<4> macierz_skalowania = mac_skalownia.macierz_skalowania(2, 2, 2);
	przeksztalcenia<4> mac_widoku;
	macierz<4> macierz_widoku = mac_widoku.macierz_perspektywy(50, 768, 768, 1, 15);
	

	przeksztalcenia<4> zlozenie;
	macierz<4> macierz_zlozenia = zlozenie.laczenie_transofrmacji(macierz_widoku, macierz_przesunieca2, macierz_przesunieca,macierz_skalowania );
	wektor<4> a(-0.4f, -0.4f, 0.0f, 1.0f);

	std::cout << "m1: " << macierz_widoku << std::endl;
	std::cout << "macierz skalowania: " << macierz_skalowania << std::endl;
	std::cout << "macierz translacji: " << macierz_przesunieca << std::endl;
	
	std::cout << "macierz zlozenia" << (macierz_widoku *macierz_przesunieca* macierz_skalowania)<< std::endl;

	std::cout << "wierzcholek: " << std::endl << macierz_zlozenia * a << std::endl;
	
	glUniformMatrix4fv(zmiennaShader1, 1, GL_TRUE, **macierz_zlozenia.getTab());

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 8, 0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 8, (GLvoid*)(sizeof(GLfloat) * 4));

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);

	glutSwapBuffers();
}

void ProgramMPGK::usun()
{
	glDeleteShader(vertexShaderId);
	glDeleteShader(fragmentShaderId);
	glDeleteProgram(programZShaderami);
	glDeleteBuffers(1, VBO);
	glDeleteBuffers(1, &IBO);
	glDeleteVertexArrays(1, &VAO);
}

void ProgramMPGK::stworzenieVAO()
{
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
}

void ProgramMPGK::stworzenieVBO(macierz<4> przes)
{
	wektor<4> wierzcholki[] = {
		wektor<4>(-0.4f, -0.4f, 0.0f, 1.0f),
		wektor<4>(1.0f, 0.0f, 0.0f, 1.0f),
		wektor<4>(0.4f, -0.4f, 0.0f, 1.0f),
		wektor<4>(0.0f, 1.0f, 0.0f, 1.0f),
		wektor<4>(-0.4f, 0.4f, 0.0f, 1.0f),
		wektor<4>(0.0f, 0.0f, 1.0f, 1.0f),
		wektor<4>(0.4f, 0.4f, 0.0f, 1.0f),
		wektor<4>(0.5f, 0.5f, 0.0f, 1.0f),

	};

	glGenBuffers(1, VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(wierzcholki), wierzcholki, GL_STATIC_DRAW);
}

void ProgramMPGK::stworzenieIBO()
{
	GLuint indeksyTab[] = {
		0, 1, 2, 1, 2, 3,
	};

	glGenBuffers(1, &IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indeksyTab), indeksyTab, GL_STATIC_DRAW);
}

void ProgramMPGK::stworzenieProgramu()
{
	programZShaderami = glCreateProgram();

	if (programZShaderami == 0)
	{
		std::cerr << "Blad podczas tworzenia programu shaderow." << std::endl;
		//system("pause");
		exit(1);
	}

	const char* vertexShader =
		"	#version 330 core \n																	\
			layout(location=0) in vec4 polozenie; \n												\
			layout(location=1) in vec4 kolorVS; \n													\
			out vec4 kolorFS; \n																	\
			//uniform float zmianaShader; \n															\
			uniform mat4 macierz_przeksztalcenia; \n \
			void main()			 \n																	\
			{		 \n																				\
				gl_Position = macierz_przeksztalcenia * polozenie; \n		\
				kolorFS = kolorVS; \n																\
			}";

	const char* fragmentShader =
		"	#version 330 core \n						\
			out vec4 kolor;	\n							\
			in vec4 kolorFS; \n							\
			void main()	\n								\
			{			\n								\
				kolor = kolorFS;	\n					\
			}";

	vertexShaderId = dodanieDoProgramu(programZShaderami, vertexShader, GL_VERTEX_SHADER);
	fragmentShaderId = dodanieDoProgramu(programZShaderami, fragmentShader, GL_FRAGMENT_SHADER);

	GLint linkowanieOK = 0;
	glLinkProgram(programZShaderami);
	glGetProgramiv(programZShaderami, GL_LINK_STATUS, &linkowanieOK);
	if (linkowanieOK == GL_FALSE)
	{
		GLint dlugoscLoga = 0;
		glGetProgramiv(programZShaderami, GL_INFO_LOG_LENGTH, &dlugoscLoga);
		std::vector<GLchar> log(dlugoscLoga);
		glGetProgramInfoLog(programZShaderami, dlugoscLoga, NULL, &log[0]);
		std::cerr << "Blad podczas linkowania programu shaderow." << std::endl;
		for (std::vector<GLchar>::const_iterator i = log.begin(); i != log.end(); ++i)
			std::cerr << *i;
		std::cerr << std::endl;
		glDeleteProgram(programZShaderami);
		//system("pause");
		exit(13);
	}

	GLint walidacjaOK = 0;
	glValidateProgram(programZShaderami);
	glGetProgramiv(programZShaderami, GL_VALIDATE_STATUS, &walidacjaOK);
	if (walidacjaOK == GL_FALSE)
	{
		GLint dlugoscLoga = 0;
		glGetProgramiv(programZShaderami, GL_INFO_LOG_LENGTH, &dlugoscLoga);
		std::vector<GLchar> log(dlugoscLoga);
		glGetProgramInfoLog(programZShaderami, dlugoscLoga, NULL, &log[0]);
		std::cerr << "Blad podczas walidacji programu shaderow." << std::endl;
		for (std::vector<GLchar>::const_iterator i = log.begin(); i != log.end(); ++i)
			std::cerr << *i;
		std::cerr << std::endl;
		glDeleteProgram(programZShaderami);
		//system("pause");
		exit(1);
	}

	glUseProgram(programZShaderami);

	// zmiennaShader = glGetUniformLocation(programZShaderami, "zmianaShader");
	// if (zmiennaShader == -1)
	// {
	// 	std::cerr << "Nie znalezion zmiennej uniform." << std::endl;
	// 	//system("pause");
	// 	exit(1);
	// }

	zmiennaShader1 = glGetUniformLocation(programZShaderami, "macierz_przeksztalcenia");
	if (zmiennaShader1 == -1)
	{
		std::cerr << "Nie znalezion zmiennej uniform." << std::endl;
		//system("pause");
		exit(1);
	}
}

GLuint ProgramMPGK::dodanieDoProgramu(GLuint programZShaderami, const GLchar* tekstShadera, GLenum typShadera)
{
	GLuint shader = glCreateShader(typShadera);

	// 35633 -> vertex shader, 35632 -> fragment shader
	const GLchar* typShaderaTekst = typShadera == 35633 ? "vertex" : "fragment";

	if (shader == 0)
	{
		std::cerr << "Blad podczas tworzenia " << typShaderaTekst << " shadera." << std::endl;
		//system("pause");
		exit(0);
	}

	const GLchar* tekstShaderaTab[1];
	tekstShaderaTab[0] = tekstShadera;
	GLint dlugoscShadera[1];
	dlugoscShadera[0] = strlen(tekstShadera);
	glShaderSource(shader, 1, tekstShaderaTab, dlugoscShadera);

	glCompileShader(shader);
	GLint kompilacjaOK = 0;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &kompilacjaOK);
	if (kompilacjaOK == GL_FALSE)
	{
		GLint dlugoscLoga = 0;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &dlugoscLoga);
		std::vector<GLchar> log(dlugoscLoga);
		glGetShaderInfoLog(shader, dlugoscLoga, NULL, &log[0]);
		std::cerr << std::endl;
		std::cerr << "Blad podczas kompilacji " << typShaderaTekst << " shadera." << std::endl;
		std::cerr << std::endl;
		std::cerr << "log: ";
		for (std::vector<GLchar>::const_iterator i = log.begin(); i != log.end(); ++i)
			std::cerr << *i;
		std::cerr << std::endl;
		glDeleteShader(shader);
		//system("pause");
		exit(1);
	}

	glAttachShader(programZShaderami, shader);
	return shader;
}

void ProgramMPGK::sprawdzenieWersji()
{
	std::cout << "Wersja GLEW: " << glewGetString(GLEW_VERSION) << std::endl;
	std::cout << "Wersja VENDOR: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "Wersja REDERER: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "Wersja GL: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "Wersja GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
}


int main(int argc, char** argv)
{
	ProgramMPGK obiektMPGK(650, 650, 100, 100);

	

	przeksztalcenia<4> P_mac_obrotu;
	macierz<4> macierz_obrotu = P_mac_obrotu.macierz_obrotu(200, 'z');
	std::cout << "macierz obrotu" << std::endl << macierz_obrotu << std::endl;

	przeksztalcenia<4> P_mac_skalowania;
	macierz<4> macierz_skalowania = P_mac_obrotu.macierz_skalowania(1, 1, 1);
	std::cout << "macierz skalowania" << std::endl << macierz_skalowania << std::endl;

	przeksztalcenia<4> P_mac_przesuniecia;
	macierz<4> macierz_przesuniecia = P_mac_obrotu.macierz_przesuniecia(1, 2, 3);
	std::cout << "macierz przesuniecia" << std::endl << macierz_przesuniecia << std::endl;

	
	przeksztalcenia<4> P_mac_perspektywy;
	macierz<4> mx = P_mac_perspektywy.macierz_perspektywy(90, 1, 1, 1, 10);
	std::cout << "macierz perspektywy" << std::endl << mx << std::endl;

	obiektMPGK.stworzenieOkna(argc, argv);
	obiektMPGK.inicjalizacjaGlew();
	obiektMPGK.sprawdzenieWersji();
	obiektMPGK.stworzenieVAO();
	obiektMPGK.stworzenieVBO(macierz_obrotu);

	obiektMPGK.stworzenieIBO();
	obiektMPGK.stworzenieProgramu();
	glutDisplayFunc(obiektMPGK.wyswietl);
	// glutIdleFunc(obiektMPGK.wyswietl);
	glutCloseFunc(obiektMPGK.usun);
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glutMainLoop();

	system("pause");
	return 0;
}
