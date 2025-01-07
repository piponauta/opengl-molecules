#ifndef RYAN_SHADER
#define RYAN_SHADER


#if defined(__APPLE__)
#include <GLUT/glut.h>
#elif defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#include <GL/glew.h>
#include <GL/glut.h>
#include <windows.h>
#elif defined(__linux__)
#include <GL/glew.h>
#include <GL/glut.h>
#endif

class Shader {
public:
	Shader(void);
	~Shader(void);

    char * readCode(const char * fileName);
    int createShaderObj(const char* fileName , int shaderType, GLuint *shaderid);

	// functions creates a shader program.  The two shader programs (vertex and fragment) were already compiled.
	GLint createShaderProgram(GLint vertShaderid, GLint fragShaderid, GLuint *shaderProgId);
	GLuint shaderProgramid;
	// creates a shader program from files vsFileName and fsFileName
    int createShaderProgram(const char * vsFileName, const char * fsFileName, unsigned int *shaderProgramid);
	int shaderStatus(void);
private:
	GLuint vertShaderid;
	GLuint fragShaderid;
};

#endif
