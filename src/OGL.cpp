#include "OGL.h"

OGL::OGL(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui_OGL)
{
    ui->setupUi(this);
}

OGL::~OGL()
{
    delete ui; 
}