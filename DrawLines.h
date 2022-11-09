#ifndef _DRAWLINES_H_
#define _DRAWLINES_H_

#include <vector>
#include <list>
#include <mutex>
#include <string.h>
#include "Common.h"

#include "Shader.h"

namespace DarkerOGL {

class Draw2DLines {
public:
    typedef std::shared_ptr<Draw2DLines> ptr;

    Draw2DLines();
    ~Draw2DLines();

    void AddLine(Line2D line) {
        m_lines_mutex.lock();
        m_plines.push_back(Line2D::ptr(new Line2D(line)));
        m_lines_mutex.unlock();
    }

    void AddLine(Line2D::ptr pLine) {
        m_lines_mutex.lock();
        m_plines.push_back(pLine);
        m_lines_mutex.unlock();
    }

    void AddLine(const Vector2<float>& s, const Vector2<float>& e, const Vector4<float>& c = Vector4<float>(1.f, 1.f, 1.f, 1.f), float si = 1.f) {
        m_lines_mutex.lock();
        m_plines.push_back(Line2D::ptr(new Line2D(s, e, c, si)));
        m_lines_mutex.unlock();
    }

    void Erase(int index) {
        int i = 0;
        m_lines_mutex.lock();
        for (std::list<Line2D::ptr>::iterator iter = m_plines.begin(); iter != m_plines.end(); ++iter) {
            if (i == index) {
                Line2D::ptr deleteLine = *iter;
                m_plines.erase(iter);
                deleteLine.reset();
                break;
            }
        }
        m_lines_mutex.unlock();
    }

    void Clean() {
        m_lines_mutex.lock();
        for (std::list<Line2D::ptr>::iterator iter = m_plines.begin(); iter != m_plines.end(); ++iter) {
            Line2D::ptr deleteLine = *iter;
            iter = m_plines.erase(iter);
            deleteLine.reset();
        }
        m_plines.clear();
        m_lines_mutex.unlock();
    }

    void Draw();

private:
    std::list<Line2D::ptr> m_plines;
    std::mutex m_lines_mutex;
    float* m_linesInfosBuffer;

    // opengl parameter
    Shader* m_pShader;

    GLuint VAO;
    GLuint VBO;
};


class Draw3DLines {
public:
    typedef std::shared_ptr<Draw3DLines> ptr;

    Draw3DLines();
    ~Draw3DLines();

    void AddLine(Line3D line) {
        m_lines_mutex.lock();
        m_plines.push_back(Line3D::ptr(new Line3D(line)));
        m_lines_mutex.unlock();
    }

    void AddLine(Line3D::ptr pLine) {
        m_lines_mutex.lock();
        m_plines.push_back(pLine);
        m_lines_mutex.unlock();
    }

    void AddLine(const Vector3<float>& s, const Vector3<float>& e, const Vector4<float>& c = Vector4<float>(1.f, 1.f, 1.f, 1.f), float si = 1.f) {
        m_lines_mutex.lock();
        m_plines.push_back(Line3D::ptr(new Line3D(s, e, c, si)));
        m_lines_mutex.unlock();
    }

    void Erase(int index) {
        int i = 0;
        m_lines_mutex.lock();
        for (std::list<Line3D::ptr>::iterator iter = m_plines.begin(); iter != m_plines.end(); ++iter) {
            if (i == index) {
                Line3D::ptr deleteLine = *iter;
                m_plines.erase(iter);
                deleteLine.reset();
                break;
            }
        }
        m_lines_mutex.unlock();
    }

    void Clean() {
        m_lines_mutex.lock();
        for (std::list<Line3D::ptr>::iterator iter = m_plines.begin(); iter != m_plines.end(); ++iter) {
            Line3D::ptr deleteLine = *iter;
            iter = m_plines.erase(iter);
            deleteLine.reset();
        }
        m_plines.clear();
        m_lines_mutex.unlock();
    }

    void Draw();

    void SetModelMatrix(float* modelMatrix) {
        memcpy(m_modelMatrix, modelMatrix, 16 * sizeof(float));
    }
    void SetViewMatrix(float* viewMatrix) {
        memcpy(m_viewMatrix, viewMatrix, 16 * sizeof(float));
    }
    void SetProjectMatrix(float* projectMatrix) {
        memcpy(m_projectMatrix, projectMatrix, 16 * sizeof(float));
    }

private:
    std::list<Line3D::ptr> m_plines;
    std::mutex m_lines_mutex;
    float* m_linesInfosBuffer;

    float m_modelMatrix[16];
    float m_viewMatrix[16];
    float m_projectMatrix[16];

    // opengl parameter
    Shader* m_pShader;

    GLuint VAO;
    GLuint VBO;
};

}
#endif