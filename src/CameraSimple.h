#ifndef _CAMERASIMPLE_H_
#define _CAMERASIMPLE_H_

#include <iostream>
#include <memory>
#include <memory.h>

#include "Shader.h"

#include "glew.h"


class CameraBase{
public:
    typedef std::shared_ptr<CameraBase> ptr;
    CameraBase();
    void Draw();
    ~CameraBase();

    void SetModelMatrix(float* modelMatrix) {
        memcpy(m_modelMatrix, modelMatrix, 16 * sizeof(float));
    }

    void SetViewMatrix(float* viewMatrix) {
        memcpy(m_viewMatrix, viewMatrix, 16 * sizeof(float));
    }

    void SetProjectMatrix(float* projectMatrix) {
        memcpy(m_projectMatrix, projectMatrix, 16 * sizeof(float));
    }

    void SetShininess(float shininess) {
        m_shininess = shininess;
    }

    void SetDiffuseColor(float diffuseColor[4]) {
        m_diffuseColor[0] = diffuseColor[0];
        m_diffuseColor[1] = diffuseColor[1];
        m_diffuseColor[2] = diffuseColor[2];
        m_diffuseColor[3] = diffuseColor[3];
    }

    void SetSpecularColor(float specularColor[4]) {
        m_specularColor[0] = specularColor[0];
        m_specularColor[1] = specularColor[1];
        m_specularColor[2] = specularColor[2];
        m_specularColor[3] = specularColor[3];
    }

private:
    float m_modelMatrix[16];
    float m_viewMatrix[16];
    float m_projectMatrix[16];

    float m_shininess;
    float m_diffuseColor[4];
    float m_specularColor[4];

    Shader* m_pShader;

    GLuint VAO;
    GLuint VBO;
    GLuint EBO;
};


#endif