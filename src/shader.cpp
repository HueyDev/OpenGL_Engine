#include <iostream>
#include "glad/glad.h"
#include "shader.hpp"
#include "fileLoader.hpp"

// const char* vertexShaderFilePath= "default.vs";
// const char* fragmentShaderFilePath= "default.fs";
// unsigned int id;


Shader::Shader(){

}

Shader::Shader(const char* vSourcePath="default.vs", const char* fSourcePath="default.fs"){
    this->vertexShaderFilePath = vSourcePath;
    this->fragmentShaderFilePath=fSourcePath;
}

Shader::~Shader(){
    
}

void Shader::setFilePath(GLenum shaderType, const char* path){
    switch(shaderType){
        case GL_VERTEX_SHADER:
            this->vertexShaderFilePath = path;
            break;
        
        case GL_FRAGMENT_SHADER:
            this->fragmentShaderFilePath = path;
            break;
    }
}

unsigned int Shader::compileShader(GLenum shaderType, const char* shaderSource){
    unsigned int shader;
    shader = glCreateShader(shaderType);

    glShaderSource(shader, 1, &shaderSource, NULL);
    glCompileShader(shader);

    int  success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if(!success)
    {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    return shader;
}

void Shader::build(){
    unsigned int vShader = compileShader(GL_VERTEX_SHADER, loadShader(this->vertexShaderFilePath).c_str());
    unsigned int fShader = compileShader(GL_FRAGMENT_SHADER, loadShader(this->fragmentShaderFilePath).c_str());

    this->id = glCreateProgram();
    glAttachShader(this->id, vShader);
    glAttachShader(this->id, fShader);
    glLinkProgram(this->id);

    glDeleteShader(vShader);
    glDeleteShader(fShader);
}
void Shader::activate(){
    glUseProgram(this->id);
}

