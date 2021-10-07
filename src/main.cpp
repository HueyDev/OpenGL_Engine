#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "fileLoader.hpp"

unsigned int VAO, shaderProgram;

float vertices[] = {
  -0.5f, -0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    0.0f,  0.5f, 0.0f
};

unsigned int compileShader(GLenum shaderType, const char* shaderSource){

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

unsigned int constructShader(const char* vSource, const char* fSource){

  unsigned int vShader = compileShader(GL_VERTEX_SHADER, vSource);
  unsigned int fShader = compileShader(GL_FRAGMENT_SHADER, fSource);

  unsigned int program = glCreateProgram();
  glAttachShader(program, vShader);
  glAttachShader(program, fShader);
  glLinkProgram(program);

  glDeleteShader(vShader);
  glDeleteShader(fShader);

  return program;

}

void genTriangleData(){

  glGenVertexArrays(1, &VAO);
  glBindVertexArray(VAO);


  unsigned int VBO;
  glGenBuffers(1, &VBO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);

  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  shaderProgram = constructShader(loadShader("default.vs").c_str(), loadShader("default.fs").c_str());

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);  

}

void render(GLFWwindow* window){

  glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

  glUseProgram(shaderProgram);
  glBindVertexArray(VAO);
    

  

  glDrawArrays(GL_TRIANGLES, 0, 3);

}

int main() {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow* window = glfwCreateWindow(300, 300, "LearnOpenGL", NULL, NULL);
  if (window == NULL)
  {
      std::cout << "Failed to create GLFW window" << std::endl;
      glfwTerminate();
      return -1;
  }
  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
      std::cout << "Failed to initialize GLAD" << std::endl;
      return -1;
  }

  glViewport(0, 0, 300, 300);

  genTriangleData();

  while(!glfwWindowShouldClose(window))
  {
    render(window);

    glfwSwapBuffers(window);
    glfwPollEvents();    
  }

  glfwTerminate();
}