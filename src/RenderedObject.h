#ifndef _RENDERED_OBJECT_H_
#define _RENDERED_OBJECT_H_

#include <memory>
#include <string>
#include <mutex>

enum class OBJECTTYPE{
    NONE = 0,
    INITED = 1,
    UNITED = 2,
};

class RenderedObject{
public:
    typedef std::shared_ptr<RenderedObject> ptr;
    virtual void Init() = 0;
    virtual void Draw() = 0;
    virtual void Unit() = 0;

    virtual void SetModelMatrix(float* modelMatrix){
        mObjectMutex.lock();
        memcpy(m_modelMatrix, modelMatrix, 16 * sizeof(float));
        mObjectMutex.unlock();
    }
    virtual void SetViewMatrix(float* viewMatrix){
        mObjectMutex.lock();
        memcpy(m_viewMatrix, viewMatrix, 16 * sizeof(float));
        mObjectMutex.unlock();
    }
    virtual void SetProjectMatrix(float* projectionMatrix){
        mObjectMutex.lock();
        memcpy(m_projectMatrix, projectionMatrix, 16 * sizeof(float));
        mObjectMutex.unlock();
    }

    virtual void SetName(std::string name){
        mObjectMutex.lock();
        mName = name;
        mObjectMutex.unlock();
    }
    virtual std::string GetName(){
        std::string ans;
        mObjectMutex.lock();
        ans = mName;
        mObjectMutex.unlock();
        return ans;
    }
    
    OBJECTTYPE GetType(){
        OBJECTTYPE ans;
        mObjectMutex.lock();
        ans = mType;
        mObjectMutex.unlock();
        return ans;
    }

protected:
    std::string mName = "Object";
    OBJECTTYPE mType = OBJECTTYPE::NONE;
    std::mutex mObjectMutex;

    float m_modelMatrix[16];
    float m_viewMatrix[16];
    float m_projectMatrix[16];
};


#endif