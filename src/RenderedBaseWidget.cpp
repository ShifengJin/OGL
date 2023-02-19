#include <iostream>

#include "RenderedBaseWidget.h"


RenderedBaseWidget::RenderedBaseWidget(QWidget *parent)
    :QOpenGLWidget(parent)
{}

RenderedBaseWidget::~RenderedBaseWidget(){
    unInitializedTargets();
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
            it->second->SetProjectMatrix(m_projectMatrix);
            it->second->Draw();
        }
        it++;
    }
    mRenderedObjectsMutex.unlock();
}

void RenderedBaseWidget::unInitializedTargets(){
    mRenderedObjectsMutex.lock();
    std::map<std::string, RenderedObject::ptr>::iterator it = mRenderedObjects.begin();
    while(it != mRenderedObjects.end()){
        if(it->second->GetType() == OBJECTTYPE::INITED){
            it->second->Unit();
        }
        it++;
    }
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
    ComputeProjectMatrix_OpenGL(60.f, w * 1.f / h, 0.01f, 100.f, m_projectMatrix);
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