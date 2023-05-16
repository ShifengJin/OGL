#ifndef _RENDEREDBASEWIDGET_H_
#define _RENDEREDBASEWIDGET_H_

#include "glew.h"
#include <QtWidgets/QOpenGLWidget>
#include <mutex>
#include <map>
#include "Common.h"
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

    float m_viewMatrix[16];

    CameraInner::ptr mpCameraInner;
};

#endif