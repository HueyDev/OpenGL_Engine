#pragma once
#include "glad/glad.h"

class Shader{

    const char* vertexShaderFilePath= "default.vs";
    const char* fragmentShaderFilePath= "default.fs";
    unsigned int id;

public:
    Shader();
    Shader(const char* vSourcePath, const char* fSourcePath);
    ~Shader();

    void setFilePath(GLenum shaderType, const char* path);
    unsigned int compileShader(GLenum shaderType, const char* shaderSource);

    void build();
    void activate();

};



