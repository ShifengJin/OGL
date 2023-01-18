#ifndef _RENDERERWIDGET_H_
#define _RENDERERWIDGET_H_

#include "Matrices.h"
#include "CameraSimple.h"

#include <QtWidgets/QOpenGLWidget>
#include <QMouseEvent>

class RendererWidget : public QOpenGLWidget {
    Q_OBJECT

public:
    RendererWidget(QWidget* parent = Q_NULLPTR);
    ~RendererWidget();

    void ResizeWindows(int width, int height);

    void SetViewMatrix(float* viewMatrix) {
        memcpy(m_viewMatrix, viewMatrix, 16 * sizeof(float));
    }

    void SetModelMatrix(float* modelMatrix) {
        memcpy(m_modelMatrix, modelMatrix, 16 * sizeof(float));
    }

    void SetProjectMatrix(float* projectMatrix) {
        memcpy(m_projectMatrix, projectMatrix, 16 * sizeof(float));
    }
    

    void UpdateWidget();


protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

    void initCamera();
    void unitCamera();
    void drawCamera();

    void mouseMoveEvent(QMouseEvent* e);
    void mousePressEvent(QMouseEvent* e);
    void mouseReleaseEvent(QMouseEvent* e);

private:
    void ComputeProjectMatrix_OpenGL(float fov, float aspect, float zNear, float zFar, float* oProjectMatrix) {
        float tanHalfFovy = tanf(fov / 2.f * DEG2RAD);
        memset(oProjectMatrix, 0, sizeof(float) * 16);

        oProjectMatrix[0] = 1.f / (aspect * tanHalfFovy);
        oProjectMatrix[5] = 1.f / tanHalfFovy;
        oProjectMatrix[10] = -(zFar + zNear) / (zFar - zNear);
        oProjectMatrix[11] = -1.f;
        oProjectMatrix[14] = -(2 * zFar * zNear) / (zFar - zNear);
    }

private:
    float m_viewMatrix[16];
    float m_modelMatrix[16];      // 主列
    float m_projectMatrix[16];

    int WindowsWidth, WindowsHeight;

    CameraBase::ptr m_pCameraBase;

    bool m_leftMousePressed = false;
    float m_xStart, m_yStart, m_xCur, m_yCur;

    
    
};

#endif