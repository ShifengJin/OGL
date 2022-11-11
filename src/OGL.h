#ifndef _OGL_H_
#define _OGL_H_

#include "ui_OGL.h"
#include <QMainWindow>

class OGL : public QMainWindow {
    Q_OBJECT
    
public:
    OGL(QWidget* parent = nullptr);
    ~OGL();

private:
    Ui_OGL* ui;
};

#endif