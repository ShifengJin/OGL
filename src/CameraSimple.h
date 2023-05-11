#ifndef _CAMERASIMPLE_H_
#define _CAMERASIMPLE_H_

#include <iostream>
#include <memory>
#include <memory.h>
#include "Common.h"
#include "RenderedObject.h"
#include "Shader.h"

#include "glew.h"

class CameraInner{
public:
    typedef std::shared_ptr<CameraInner> ptr;

    CameraInner() = delete;    

    CameraInner(float near, float far, float cx, float cy, float fx, float fy){
        m_near = near;
        m_far = far;
        m_cx = cx;
        m_cy = cy;
        m_fx = fx;
        m_fy = fy;
        m_fov = (float)(atan2(cy, fy) * RAD2ANG * 2.);
    }

    CameraInner(float near, float far, float cx, float cy, float fov){
        m_near = near;
        m_far = far;
        m_cx = cx;
        m_cy = cy;
        m_fov = fov;
        
    }

    float m_near;
    float m_far;
    float m_cx, m_cy;
    float m_fx, m_fy;
    float m_fov;
};


class CameraBase: public RenderedObject{
public:
    typedef std::shared_ptr<CameraBase> ptr;
    CameraBase();
    virtual void Init() override;
    virtual void Draw() override;
    virtual void Unit() override;
    ~CameraBase();

    void SetShininess(float shininess) {
        m_shininess = shininess;
    }

    void SetDirection(float direction[3]) {
        m_direction[0] = direction[0];
        m_direction[1] = direction[1];
        m_direction[2] = direction[2];
    }

    void SetAmbient(float ambient[3]){
        m_ambient[0] = ambient[0];
        m_ambient[1] = ambient[1];
        m_ambient[2] = ambient[2];
    }

    void SetDiffuse(float diffuse[3]) {
        m_diffuse[0] = diffuse[0];
        m_diffuse[1] = diffuse[1];
        m_diffuse[2] = diffuse[2];
    }

    void SetSpecular(float specular[3]) {
        m_specular[0] = specular[0];
        m_specular[1] = specular[1];
        m_specular[2] = specular[2];
    }

private:

    float m_shininess;
    float m_direction[3];
    float m_ambient[3];
    float m_diffuse[3];
    float m_specular[3];
    
    Shader* m_pShader;

    GLuint VAO;
    GLuint VBO;
    GLuint EBO;
};


#endif