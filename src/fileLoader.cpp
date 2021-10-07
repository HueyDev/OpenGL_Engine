#include "fileLoader.hpp"
#include <iostream>
#include <fstream>

std::string loadShader(const char* filePath){

  std::ifstream file;

  std::string path(filePath);

  file.open("shaders/" + path);

  std::string result;

  while(file){
    std::string d;
    std::getline(file, d);
    result.append(d + "\n");
  }

  return result;

}


