#pragma once


class Shader{

const char* vertexShaderFilePath= "default.vs";
const char* fragmentShaderFilePath= "default.fs";

public:
  Shader();
  ~Shader();

  setFilePath(GLenum shaderType, const char*);


}



