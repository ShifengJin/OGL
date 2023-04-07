#ifndef _RENDEREDBASEWIDGET_H_
#define _RENDEREDBASEWIDGET_H_

#include "glew.h"
#include <QtWidgets/QOpenGLWidget>
#include <mutex>
#include <map>
#include "Matrices.h"
#include "RenderedObject.h"

class RenderedBaseWidget : public QOpenGLWidget{
    Q_OBJECT

public:
    RenderedBaseWidget(QWidget *parent = Q_NULLPTR);
    ~RenderedBaseWidget();

    bool AddTarget(RenderedObject::ptr object, std::string name);
    bool RemoveTarget(RenderedObject::ptr object);
    bool RemoveTarget(std::string name);

    void SetViewMatrix(float viewMatrix[16]){
        mRenderedObjectsMutex.lock();
        memcpy(m_viewMatrix, viewMatrix, 16 * sizeof(float));
        mRenderedObjectsMutex.unlock();
    }

protected:
    virtual void initializeGL() override;
    virtual void resizeGL(int w, int h) override;
    virtual void paintGL() override;

    std::map<std::string, RenderedObject::ptr> mRenderedObjects;
    std::mutex mRenderedObjectsMutex;

    virtual void makeSureTargetsAreInitialized();
    virtual void drawTargets();
    virtual void unInitializedTargets();

    void ComputeProjectMatrix_OpenGL(float fov, float aspect, float zNear, float zFar, float* oProjectMatrix) {
        float tanHalfFovy = tanf(fov / 2.f * DEG2RAD);
        memset(oProjectMatrix, 0, sizeof(float) * 16);

        oProjectMatrix[0] = 1.f / (aspect * tanHalfFovy);
        oProjectMatrix[5] = 1.f / tanHalfFovy;
        oProjectMatrix[10] = -(zFar + zNear) / (zFar - zNear);
        oProjectMatrix[11] = -1.f;
        oProjectMatrix[14] = -(2 * zFar * zNear) / (zFar - zNear);
    }
    
    float m_projectMatrix[16];
    float m_viewMatrix[16];
};

#endif