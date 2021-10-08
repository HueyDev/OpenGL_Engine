#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <shader.hpp>

struct GameObject{
    glm::mat4* transform;
    float* vertex;
    int* triangles;
    Shader* shader;
    unsigned int vao;


    GameObject();
    GameObject(glm::vec3 pos);

    void rotate(float x=0, float y=0, float z=0);
    void move(float x=0, float y=0, float z=0);
    void move(glm::vec3 pos);
    void move(glm::vec4 pos);


    void setShader(Shader* shader);

    void render();
};

struct Box : public GameObject{
    
};



