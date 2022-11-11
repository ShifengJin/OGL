#ifndef _DRAWPOINT_H_
#define _DRAWPOINT_H_

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <map>
#include <mutex>
#include <string.h>
#include "Common.h"
#include "Shader.h"
#include "glew.h"

namespace DarkerOGL {

class Draw3DPoints {
public:
    typedef std::shared_ptr<Draw3DPoints> ptr;
    Draw3DPoints();
    Draw3DPoints(const Draw3DPoints& val) = delete;
    ~Draw3DPoints();

    void AddPoint(Point3D point) {
        m_points_mutex.lock();
        m_point3Ds.push_back(Point3D::ptr(new Point3D(point)));
        m_points_mutex.unlock();
    }

    void AddPoint(Point3D::ptr pLine) {
        m_points_mutex.lock();
        m_point3Ds.push_back(pLine);
        m_points_mutex.unlock();
    }

    void AddPoint(const Vector3<float>& p, const Vector4<float>& c = Vector4<float>(1.f, 1.f, 1.f, 1.f), float si = 1.f) {
        m_points_mutex.lock();
        m_point3Ds.push_back(Point3D::ptr(new Point3D(p, c, si)));
        m_points_mutex.unlock();
    }

    void SetModelMatrix(float* modelMatrix) {
        memcpy(m_modelMatrix, modelMatrix, 16 * sizeof(float));
    }

    void SetViewMatrix(float* viewMatrix) {
        memcpy(m_viewMatrix, viewMatrix, 16 * sizeof(float));
    }

    void SetProjectMatrix(float* projectMatrix) {
        memcpy(m_projectMatrix, projectMatrix, 16 * sizeof(float));
    }

    void Clean() {
        m_points_mutex.lock();
        for (std::list<Point3D::ptr>::iterator iter = m_point3Ds.begin(); iter != m_point3Ds.end(); ++iter) {
            Point3D::ptr deleteLine = *iter;
            iter = m_point3Ds.erase(iter);
            deleteLine.reset();
        }
        m_point3Ds.clear();
        m_points_mutex.unlock();
    }

    void Draw();

    std::list<Point3D::ptr>& GetPoint3Ds() {
        return m_point3Ds;
    }

private:
    Shader* m_pShader;

    float m_modelMatrix[16];
    float m_viewMatrix[16];
    float m_projectMatrix[16];

    std::list<Point3D::ptr> m_point3Ds;
    float* m_pointInfosBuffer;

    GLuint VAO, VBO;

    std::mutex m_points_mutex;
};

}
#endif