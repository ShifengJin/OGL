#include <QDebug>
#include <iostream>

#include "RenderedBaseWidget.h"

RenderedBaseWidget::RenderedBaseWidget(QWidget *parent)
    :QOpenGLWidget(parent)
{
    mpCameraInner = CameraInner::ptr(new CameraInner(0.1f, 1000.0f, 320.f, 240.f, 60.f, 640, 480));
}

RenderedBaseWidget::~RenderedBaseWidget(){
    unInitializedTargets();
    mpCameraInner.reset();
    mRenderedObjectsMutex.lock();
    mRenderedObjects.clear();
    mRenderedObjectsMutex.unlock();
}

bool RenderedBaseWidget::AddTarget(RenderedObject::ptr object, std::string name){

    bool ans = true;
    mRenderedObjectsMutex.lock();
    std::map<std::string, RenderedObject::ptr>::iterator it = mRenderedObjects.begin();
    while(it != mRenderedObjects.end()){
        if(it->first == object->GetName()){
            ans = false;
            break;
        }
        it++;
    }
    if(ans){
        mRenderedObjects[object->GetName()] = object;
    }
    mRenderedObjectsMutex.unlock();
    return ans;
}
    
bool RenderedBaseWidget::RemoveTarget(RenderedObject::ptr object){
    bool ans = false;
    mRenderedObjectsMutex.lock();
    std::map<std::string, RenderedObject::ptr>::iterator it = mRenderedObjects.begin();
    while(it != mRenderedObjects.end()){
        if(it->first == object->GetName()){
            it = mRenderedObjects.erase(it);
            ans = true;
            break;
        }else{
            it++;
        }
    }
    mRenderedObjectsMutex.unlock();
    return ans;
}
    
bool RenderedBaseWidget::RemoveTarget(std::string name){
    bool ans = false;
    mRenderedObjectsMutex.lock();
    std::map<std::string, RenderedObject::ptr>::iterator it = mRenderedObjects.begin();
    while(it != mRenderedObjects.end()){
        if(it->first == name){
            it = mRenderedObjects.erase(it);
            ans = true;
            break;
        }else{
            it++;
        }
    }
    mRenderedObjectsMutex.unlock();
    return ans;
}

void RenderedBaseWidget::makeSureTargetsAreInitialized(){
    mRenderedObjectsMutex.lock();
    std::map<std::string, RenderedObject::ptr>::iterator it = mRenderedObjects.begin();
    while(it != mRenderedObjects.end()){
        if(it->second->GetType() == OBJECTTYPE::NONE){
            it->second->Init();
        }
        it++;
    }
    mRenderedObjectsMutex.unlock();
}

void RenderedBaseWidget::drawTargets(){
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

void RenderedBaseWidget::unInitializedTargets(){
    mRenderedObjectsMutex.lock();
    mRenderedObjects.clear();
    mRenderedObjectsMutex.unlock();
}

void RenderedBaseWidget::initializeGL(){
    GLenum status = glewInit();
    if (status != GLEW_OK) {
        std::cout << "glewInit error." << std::endl;
    }
}

void RenderedBaseWidget::resizeGL(int w, int h){
    glViewport(0, 0, w, h);
    mpCameraInner->SetSize(w, h);
}

void RenderedBaseWidget::paintGL(){
    glClearColor(0.0f, 0.0f, 0.0f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // make sure the RenderedObject is visible before drawing
    makeSureTargetsAreInitialized();
    
    drawTargets();

    glDisable(GL_DEPTH_TEST);

    update();
}