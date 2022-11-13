#ifndef _OGL_H_
#define _OGL_H_

#include "ui_OGL.h"
#include <QMainWindow>
#include <QResizeEvent>

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

public:
    void resizeEvent(QResizeEvent *event);
private:
    int parameter_width = 0;
    int parameter_height = 0;

private:
    Ui_OGL* ui;
};

#endif
