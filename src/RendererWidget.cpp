#include <iostream>

#include <QDebug>

#include "Matrices.h"
#include "glew.h"
#include "RendererWidget.h"

using namespace Darker;

RendererWidget::RendererWidget(QWidget* parent)
    :RenderedBaseWidget(parent)
{
    m_viewMatrix[0] = 1.f; m_viewMatrix[1] = 0.f; m_viewMatrix[2] = 0.f; m_viewMatrix[3] = 0.f;
    m_viewMatrix[4] = 0.f; m_viewMatrix[5] = 1.f; m_viewMatrix[6] = 0.f; m_viewMatrix[7] = 0.f;
    m_viewMatrix[8] = 0.f; m_viewMatrix[9] = 0.f; m_viewMatrix[10] = 1.f; m_viewMatrix[11] = 0.f;
    m_viewMatrix[12] = 0.f; m_viewMatrix[13] = 0.f; m_viewMatrix[14] = 0.f; m_viewMatrix[15] = 1.f;
}

RendererWidget::~RendererWidget()
{

}

void RendererWidget::drawTargets(){
    mRenderedObjectsMutex.lock();
    std::map<std::string, RenderedObject::ptr>::iterator it = mRenderedObjects.begin();
    while(it != mRenderedObjects.end()){
        if(it->second->GetType() == OBJECTTYPE::INITED){
            it->second->SetProjectMatrix(mpCameraInner->m_projectMatrix);
            it->second->SetViewMatrix(m_viewMatrix);
            it->second->Draw();
        }
        it++;
    }
    mRenderedObjectsMutex.unlock();
}

void RendererWidget::mouseMoveEvent(QMouseEvent* e){
    if(e->buttons() == Qt::LeftButton){
        //qDebug() << "left mouse button move.";

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

        yRotate4x4.RotateY((m_xCur - m_xStart)*0.3f);
        xRotate4x4.RotateX((m_yCur - m_yStart)*0.3f);

        Darker::Matrix3<float> yRotateMatrix = yRotate4x4.GetRotationMatrix();
        Darker::Matrix3<float> xRotateMatrix = xRotate4x4.GetRotationMatrix();

        Darker::Matrix3<float> endRotateMatrix = xRotateMatrix * srcRotateMatrix * yRotateMatrix;

        Darker::Matrix4<float> endViewMatrixTrp(endRotateMatrix, srcTransform);

        endViewMatrixTrp.Transpose();
        memcpy(m_viewMatrix, endViewMatrixTrp.Data(), 16 * sizeof(float));
    }else if(e->buttons() == Qt::RightButton){
        m_right_xStart = m_right_xCur;
        m_right_yStart = m_right_yCur;
        m_right_xCur = (float)(e->x());
        m_right_yCur = (float)(e->y());

        Darker::Matrix4<float> viewMatrixTrp(m_viewMatrix);
        viewMatrixTrp.Transpose();
        
        Darker::Matrix3<float> srcRotateMatrix = viewMatrixTrp.GetRotationMatrix();
        Darker::Vector3<float> srcTransform = viewMatrixTrp.GetTransform();
        Darker::Vector3<float> offsetTransform(m_right_xCur-m_right_xStart, -m_right_yCur+m_right_yStart, 0.f);
        Darker::Vector3<float> transform = srcTransform+offsetTransform*0.01f;
        Darker::Matrix4<float> endViewMatrixTrp(srcRotateMatrix, transform);   
        endViewMatrixTrp.Transpose();
        memcpy(m_viewMatrix, endViewMatrixTrp.Data(), 16 * sizeof(float));     
    }
}

void RendererWidget::mousePressEvent(QMouseEvent* e){
    if(e->buttons()==Qt::LeftButton){
        // qDebug() << "left mouse button pressed.";
        m_xStart = (float)(e->x());
        m_yStart = (float)(e->y());
        m_xCur = m_xStart;
        m_yCur = m_yStart;
    }else if(e->buttons() == Qt::RightButton){
        m_right_xStart = (float)(e->x());
        m_right_yStart = (float)(e->y());
        m_right_xCur = m_right_xStart;
        m_right_yCur = m_right_yStart;
    }
}
    
void RendererWidget::mouseReleaseEvent(QMouseEvent* e){
    if(e->buttons()==Qt::LeftButton){
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

        yRotate4x4.RotateY((m_xCur - m_xStart)*0.3f);
        xRotate4x4.RotateX((m_yCur - m_yStart)*0.3f);

        Darker::Matrix3<float> yRotateMatrix = yRotate4x4.GetRotationMatrix();
        Darker::Matrix3<float> xRotateMatrix = xRotate4x4.GetRotationMatrix();

        Darker::Matrix3<float> endRotateMatrix = xRotateMatrix * srcRotateMatrix * yRotateMatrix;

        Darker::Matrix4<float> endViewMatrixTrp(endRotateMatrix, srcTransform);

        endViewMatrixTrp.Transpose();
        memcpy(m_viewMatrix, endViewMatrixTrp.Data(), 16 * sizeof(float));
    }else if(e->buttons() == Qt::RightButton){
        m_right_xStart = m_right_xCur;
        m_right_yStart = m_right_yCur;
        m_right_xCur = (float)(e->x());
        m_right_yCur = (float)(e->y());

        Darker::Matrix4<float> viewMatrixTrp(m_viewMatrix);
        viewMatrixTrp.Transpose();
        
        Darker::Matrix3<float> srcRotateMatrix = viewMatrixTrp.GetRotationMatrix();
        Darker::Vector3<float> srcTransform = viewMatrixTrp.GetTransform();
        Darker::Vector3<float> offsetTransform(m_right_xCur-m_right_xStart, -m_right_yCur+m_right_yStart, 0.f);
        Darker::Vector3<float> transform = srcTransform+offsetTransform*0.01f;
        Darker::Matrix4<float> endViewMatrixTrp(srcRotateMatrix, transform);        
        endViewMatrixTrp.Transpose();
        memcpy(m_viewMatrix, endViewMatrixTrp.Data(), 16 * sizeof(float)); 
    }
}

void RendererWidget::wheelEvent(QWheelEvent* e){
    float delta = e->delta();
    Darker::Matrix4<float> viewMatrixTrp(m_viewMatrix);
    viewMatrixTrp.Transpose();
    
    Darker::Matrix3<float> srcRotateMatrix = viewMatrixTrp.GetRotationMatrix();
    Darker::Vector3<float> srcTransform = viewMatrixTrp.GetTransform();
    Darker::Vector3<float> offsetTransform(0.f, 0.f, delta);
    Darker::Vector3<float> transform = srcTransform+offsetTransform*0.01f;
    Darker::Matrix4<float> endViewMatrixTrp(srcRotateMatrix, transform);        
    endViewMatrixTrp.Transpose();
    memcpy(m_viewMatrix, endViewMatrixTrp.Data(), 16 * sizeof(float)); 
}