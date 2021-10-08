#include <gameObject.hpp>
#include <shader.hpp>

// glm::mat4 transform;
// float* vertex;
// int* triangles;
// Shader* shader;


GameObject::GameObject(){
    this->initRender();
}

GameObject::GameObject(glm::vec3 pos){
    this->initRender();
    this->move(pos);
}

GameObject::initRender(){
    this->transform = new glm::mat4(1.0f);
    glGenVertexArrays(1, &(this->VAO));
    glBindVertexArray(this->VAO);


    unsigned int VBO;
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    this->setAttribPointers();

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
      
    unsigned int EBO;
    glGenBuffers(1, &EBO);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);   

}

GameObject::setAttribPointers(){
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
}

GameObject::updateMesh(float *data, int size){
    glBindVertexArray(this->VAO);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW);
}


void GameObject::rotate(float x, float y, float z){

}

void GameObject::move(float x, float y, float z){
    this->move(glm::vec4(x, y, z, 0.0f));
}

void GameObject::move(glm::vec3 pos){
    glm::translate(this->transform, pos);
}

void GameObject::move(glm::vec4 pos){
    this->move(glm::vec3(pos));
}

void GameObject::setShader(Shader* shader){
    this->shader = shader;
}


void GameObject::render(){
    defaultShader->activate();
    glBindVertexArray(VAO);

    glDrawArrays(GL_TRIANGLES, 0, 3);
}