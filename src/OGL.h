#ifndef _OGL_H_
#define _OGL_H_

#include "ui_OGL.h"
#include <QMainWindow>
#include <QResizeEvent>
#include "CameraSimple.h"
#include "ObservedObject.h"

class OGL : public QMainWindow {
    Q_OBJECT
    
public:
    OGL(QWidget* parent = nullptr);
    ~OGL();

public slots:
    void CameraAngleXDoubleSpinBoxChanged(double value);
    void CameraAngleYDoubleSpinBoxChanged(double value);
    void CameraAngleZDoubleSpinBoxChanged(double value);
    void CameraTXDoubleSpinBoxChanged(double value);
    void CameraTYDoubleSpinBoxChanged(double value);
    void CameraTZDoubleSpinBoxChanged(double value);

    void ModelAngleXDoubleSpinBoxChanged(double value);
    void ModelAngleYDoubleSpinBoxChanged(double value);
    void ModelAngleZDoubleSpinBoxChanged(double value);
    void ModelTXDoubleSpinBoxChanged(double value);
    void ModelTYDoubleSpinBoxChanged(double value);
    void ModelTZDoubleSpinBoxChanged(double value);

    void ResetPushButtonClicked();

public:
    void resizeEvent(QResizeEvent *event);

private:
    void SetLabelMatrix(QLabel* label, float matrix[16]);

    void InitConnect();
    void UnitConnect();
    void SetLayoutParameter();

    float xCameraMatrix[16];
    float yCameraMatrix[16];
    float zCameraMatrix[16];
    float cameraTMatrix[16];
    float cameraMatrix[16];

    float cameraViewMatrix[16];

    float xObservedModelMatrix[16];
    float yObservedModelMatrix[16];
    float zObservedModelMatrix[16];
    float observedTMatrix[16];
    float observedModelMatrix[16];

    float xCameraAngle, yCameraAngle, zCameraAngle, xCameraT, yCameraT, zCameraT;
    float xObservedAngle, yObservedAngle, zObservedAngle, xObservedT, yObservedT, zObservedT;

    void updateXCameraAngle(float xCameraAngle);
    void updateYCameraAngle(float yCameraAngle);
    void updateZCameraAngle(float zCameraAngle);
    void updateXCameraT(float xCameraT);
    void updateYCameraT(float yCameraT);
    void updateZCameraT(float zCameraT);
    void updateCameraMatrix();
    void updateCameraViewMatrix();

    void updateXObservedAngle(float xObservedAngle);
    void updateYObservedAngle(float yObservedAngle);
    void updateZObservedAngle(float zObservedAngle);
    void updateXObservedT(float xObservedT);
    void updateYObservedT(float yObservedT);
    void updateZObservedT(float zObservedT);
    void updateObservedMatrix();
private:
    int parameter_width = 0;
    int parameter_height = 0;
    int reset_width = 0;
    int reset_height = 0;

private:
    Ui_OGL* ui;

    CameraBase::ptr mpCameraSimple;
    ObservedObject::ptr mpObservedObject;
};

#endif
