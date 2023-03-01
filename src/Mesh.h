#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Shader.h"
#include <string>
#include <vector>

using namespace std;

struct Vertex {
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
    glm::vec3 Tangent;   // ����
    glm::vec3 Bitangent; // ˫����
};

struct Texture {
    unsigned int id;
    string type;
    string path;
};

class Mesh {
public:
    vector<Vertex>         vertices;
    vector<unsigned int>   indices;
    vector<Texture>        textures;
    GLuint VAO;

    Mesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures)
    {
        this->vertices = vertices;
        this->indices = indices;
        this->textures = textures;
    #if 0
        for(unsigned int i = 0; i < vertices.size(); ++i){
            std::cout << "vertices: " << vertices[i].Position.x << ", " << 
                                         vertices[i].Position.y << ", " << 
                                         vertices[i].Position.z << std::endl;
            std::cout << "Normals: " << vertices[i].Normal.x << ", " << 
                                        vertices[i].Normal.y << ", " << 
                                        vertices[i].Normal.z << std::endl;
            std::cout << "TexCoords: " << vertices[i].TexCoords.x << ", " << vertices[i].TexCoords.y << std::endl;
        }
        for(unsigned int i = 0; i < indices.size(); ++ i){
            std::cout << indices[i] << std::endl;
        }
    #endif
        setupMesh();
    }

    ~Mesh() {
    }
    void Draw(Shader &shader) {
        unsigned int diffuseNr = 1;
        unsigned int specularNr = 1;
        unsigned int normalNr = 1;
        unsigned int heightNr = 1;
    #if 1
        //std::cout << "textures size: " << textures.size() << std::endl;
        for (unsigned int i = 0; i < textures.size(); ++i) {
            glActiveTexture(GL_TEXTURE0 + i);

            string number;
            string name = textures[i].type;

            if (name == "texture_diffuse") {
                number = std::to_string(diffuseNr++);
            }
            else if (name == "texture_specular") {
                number = std::to_string(specularNr++);
            }
            else if (name == "texture_normal") {
                number = std::to_string(normalNr++);
            }
            else if (name == "texture_height") {
                number = std::to_string(heightNr++);
            }
            //std::cout << "programID: " << shader.programID << "    textureID: " << textures[i].id << ", " << name << number << "    " << i << std::endl;
            glUniform1i(glGetUniformLocation(shader.programID, (name + number).c_str()), i);
            glBindTexture(GL_TEXTURE_2D, textures[i].id);
        }
    #endif
        //std::cout << "VAO : " << VAO << std::endl;
        ///std::cout << "indicesSize: " << indices.size() << std::endl;
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
        glActiveTexture(GL_TEXTURE0);
    }

private:
    GLuint VBO, EBO;

    void setupMesh() {
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);

        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);

        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);
        
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);

        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Normal));

        glEnableVertexAttribArray(2);
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, TexCoords));

        //glEnableVertexAttribArray(3);
        //glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Tangent));

        //glEnableVertexAttribArray(4);
        //glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Bitangent));

        glBindVertexArray(0);
    }

};