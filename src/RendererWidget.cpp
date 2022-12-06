#include <iostream>

#include <QDebug>

#include "Matrices.h"
#include "glew.h"
#include "RendererWidget.h"

using namespace Darker;

RendererWidget::RendererWidget(QWidget* parent)
    :QOpenGLWidget(parent)
{
    m_viewMatrix[0] = 1.f; m_viewMatrix[1] = 0.f; m_viewMatrix[2] = 0.f; m_viewMatrix[3] = 0.f;
    m_viewMatrix[4] = 0.f; m_viewMatrix[5] = 1.f; m_viewMatrix[6] = 0.f; m_viewMatrix[7] = 0.f;
    m_viewMatrix[8] = 0.f; m_viewMatrix[9] = 0.f; m_viewMatrix[10] = 1.f; m_viewMatrix[11] = 0.f;
    m_viewMatrix[12] = 0.f; m_viewMatrix[13] = 0.f; m_viewMatrix[14] = -5.f; m_viewMatrix[15] = 1.f;

    m_modelMatrix[0] = 1.f; m_modelMatrix[1] = 0.f; m_modelMatrix[2] = 0.f; m_modelMatrix[3] = 0.f;
    m_modelMatrix[4] = 0.f; m_modelMatrix[5] = 1.f; m_modelMatrix[6] = 0.f; m_modelMatrix[7] = 0.f;
    m_modelMatrix[8] = 0.f; m_modelMatrix[9] = 0.f; m_modelMatrix[10] = 1.f; m_modelMatrix[11] = 0.f;
    m_modelMatrix[12] = 0.f; m_modelMatrix[13] = 0.f; m_modelMatrix[14] = 0.f; m_modelMatrix[15] = 1.f;

    WindowsWidth = 640;
    WindowsHeight = 480;
}

RendererWidget::~RendererWidget()
{
    unitCamera();
}

void RendererWidget::ResizeWindows(int width, int height)
{
    WindowsWidth = width;
    WindowsHeight = height;

    
    setFixedSize(WindowsWidth, WindowsHeight);
}

void RendererWidget::UpdateWidget() {
    update();
}

void RendererWidget::initializeGL()
{
    GLenum status = glewInit();
    if (status != GLEW_OK) {
        std::cout << "glewInit error." << std::endl;
    }

    initCamera();
}

void RendererWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);

    ComputeProjectMatrix_OpenGL(60.f, w * 1.f / h, 0.01f, 100.f, m_projectMatrix);

}

void RendererWidget::paintGL()
{
    glClearColor(0.5f, 0.5f, 1.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    drawCamera();

    glDisable(GL_DEPTH_TEST);

    update();
}

void RendererWidget::initCamera(){
    m_pCameraBase = CameraBase::ptr(new CameraBase());
}

void RendererWidget::unitCamera(){
    m_pCameraBase.reset();
}

void RendererWidget::drawCamera(){
#if 0
    qDebug() << "viewMatrix:";
    for(int i = 0; i < 4; ++ i){
        qDebug() << m_viewMatrix[i * 4 + 0] << ", " << m_viewMatrix[i * 4 + 1] << ", " <<m_viewMatrix[i * 4 + 2] << ", " <<m_viewMatrix[i * 4 + 3];
        
    }

    qDebug() << "projectMatrix:";
    for(int i = 0; i < 4; ++ i){
        qDebug() << m_projectMatrix[i * 4 + 0] << ", " << m_projectMatrix[i * 4 + 1] << ", " <<m_projectMatrix[i * 4 + 2] << ", " <<m_projectMatrix[i * 4 + 3];
        
    }
#endif
    m_pCameraBase->SetModelMatrix(m_modelMatrix);
    m_pCameraBase->SetViewMatrix(m_viewMatrix);
    m_pCameraBase->SetProjectMatrix(m_projectMatrix);
    m_pCameraBase->Draw();
}

void RendererWidget::mouseMoveEvent(QMouseEvent* e){
    if(m_leftMousePressed){
        qDebug() << "left mouse button move.";

        m_xStart = m_xCur;
        m_yStart = m_yCur;

        m_xCur = (float)(e->x());
        m_yCur = (float)(e->y());

        Darker::Matrix4<float> viewMatrixTrp(m_viewMatrix);
        viewMatrixTrp.Transpose();

        Darker::Matrix3<float> srcRotateMatrix = viewMatrixTrp.GetRotationMatrix();
        Darker::Vector3<float> srcTransform = viewMatrixTrp.GetTransform();

        Darker::Matrix4<float> yRotate4x4;
        Darker::Matrix4<float> xRotate4x4;

        yRotate4x4.RotateY(m_xCur - m_xStart);
        xRotate4x4.RotateX(m_yCur - m_yStart);

        Darker::Matrix3<float> yRotateMatrix = yRotate4x4.GetRotationMatrix();
        Darker::Matrix3<float> xRotateMatrix = xRotate4x4.GetRotationMatrix();

        Darker::Matrix3<float> endRotateMatrix = xRotateMatrix * srcRotateMatrix * yRotateMatrix;

        Darker::Matrix4<float> endViewMatrixTrp(endRotateMatrix, srcTransform);

        endViewMatrixTrp.Transpose();
        memcpy(m_viewMatrix, endViewMatrixTrp.Data(), 16 * sizeof(float));
    }
}

void RendererWidget::mousePressEvent(QMouseEvent* e){
    if(e->button()==Qt::LeftButton){
        qDebug() << "left mouse button pressed.";
        m_xStart = (float)(e->x());
        m_yStart = (float)(e->y());
        m_xCur = m_xStart;
        m_yCur = m_yStart;
        m_leftMousePressed = true;
    }
}
    
void RendererWidget::mouseReleaseEvent(QMouseEvent* e){
    if(e->button()==Qt::LeftButton){
        qDebug() << "left mouse button released.";

        m_xStart = m_xCur;
        m_yStart = m_yCur;
        m_xCur = (float)(e->x());
        m_yCur = (float)(e->y());

        Darker::Matrix4<float> viewMatrixTrp(m_viewMatrix);
        viewMatrixTrp.Transpose();

        Darker::Matrix3<float> srcRotateMatrix = viewMatrixTrp.GetRotationMatrix();
        Darker::Vector3<float> srcTransform = viewMatrixTrp.GetTransform();

        Darker::Matrix4<float> yRotate4x4;
        Darker::Matrix4<float> xRotate4x4;

        yRotate4x4.RotateY(m_xCur - m_xStart);
        xRotate4x4.RotateX(m_yCur - m_yStart);

        Darker::Matrix3<float> yRotateMatrix = yRotate4x4.GetRotationMatrix();
        Darker::Matrix3<float> xRotateMatrix = xRotate4x4.GetRotationMatrix();

        Darker::Matrix3<float> endRotateMatrix = xRotateMatrix * srcRotateMatrix * yRotateMatrix;

        Darker::Matrix4<float> endViewMatrixTrp(endRotateMatrix, srcTransform);

        endViewMatrixTrp.Transpose();
        memcpy(m_viewMatrix, endViewMatrixTrp.Data(), 16 * sizeof(float));
        m_leftMousePressed = false;
    }
}