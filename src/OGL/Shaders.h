#ifndef SHADERS_CLASS_H
#define SHADERS_CLASS_H

#include<glad/glad.h>
#include<string>
#include <cstdlib>
#include<fstream>
#include<sstream>
#include<iostream>
#include<cerrno>
#include <unistd.h>

std::string get_file_contents(const char* filename);

class Shader
{
public:
    // Reference ID of the Shader Program
    GLuint ID;
    // Constructor that build the Shader Program from 2 different shaders
    Shader(const char* vertexFile, const char* fragmentFile);

    // Activates the Shader Program
    void Activate();
    // Deletes the Shader Program
    void Delete();
private:
    // Checks if the different Shaders have compiled properly
    void compileErrors(unsigned int shader, const char* type);
};
#endif