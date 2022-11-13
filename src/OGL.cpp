#include <QDebug>
#include "OGL.h"

OGL::OGL(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui_OGL)
{
    ui->setupUi(this);
    parameter_width = ui->Param_GroupBox->width();
    parameter_height = ui->Param_GroupBox->height();



    connect(ui->Camera_AngleX_DoubleSpinBox, SIGNAL(valueChanged(double)), this, SLOT(CameraAngleXDoubleSpinBoxChanged(double)));
    connect(ui->Camera_AngleY_DoubleSpinBox, SIGNAL(valueChanged(double)), this, SLOT(CameraAngleYDoubleSpinBoxChanged(double)));
    connect(ui->Camera_AngleZ_DoubleSpinBox, SIGNAL(valueChanged(double)), this, SLOT(CameraAngleZDoubleSpinBoxChanged(double)));

    connect(ui->Camera_TX_DoubleSpinBox, SIGNAL(valueChanged(double)), this, SLOT(CameraTXDoubleSpinBoxChanged(double)));
    connect(ui->Camera_TY_DoubleSpinBox, SIGNAL(valueChanged(double)), this, SLOT(CameraTYDoubleSpinBoxChanged(double)));
    connect(ui->Camera_TZ_DoubleSpinBox, SIGNAL(valueChanged(double)), this, SLOT(CameraTZDoubleSpinBoxChanged(double)));

    connect(ui->Model_AngleX_DoubleSpinBox, SIGNAL(valueChanged(double)), this, SLOT(ModelAngleXDoubleSpinBoxChanged(double)));
    connect(ui->Model_AngleY_DoubleSpinBox, SIGNAL(valueChanged(double)), this, SLOT(ModelAngleYDoubleSpinBoxChanged(double)));
    connect(ui->Model_AngleZ_DoubleSpinBox, SIGNAL(valueChanged(double)), this, SLOT(ModelAngleZDoubleSpinBoxChanged(double)));

    connect(ui->Model_TX_DoubleSpinBox, SIGNAL(valueChanged(double)), this, SLOT(ModelTXDoubleSpinBoxChanged(double)));
    connect(ui->Model_TY_DoubleSpinBox, SIGNAL(valueChanged(double)), this, SLOT(ModelTYDoubleSpinBoxChanged(double)));
    connect(ui->Model_TZ_DoubleSpinBox, SIGNAL(valueChanged(double)), this, SLOT(ModelTZDoubleSpinBoxChanged(double)));
}

OGL::~OGL()
{
    disconnect(ui->Camera_AngleX_DoubleSpinBox, SIGNAL(valueChanged(double)), this, SLOT(CameraAngleXDoubleSpinBoxChanged(double)));
    disconnect(ui->Camera_AngleY_DoubleSpinBox, SIGNAL(valueChanged(double)), this, SLOT(CameraAngleYDoubleSpinBoxChanged(double)));
    disconnect(ui->Camera_AngleZ_DoubleSpinBox, SIGNAL(valueChanged(double)), this, SLOT(CameraAngleZDoubleSpinBoxChanged(double)));

    disconnect(ui->Camera_TX_DoubleSpinBox, SIGNAL(valueChanged(double)), this, SLOT(CameraTXDoubleSpinBoxChanged(double)));
    disconnect(ui->Camera_TY_DoubleSpinBox, SIGNAL(valueChanged(double)), this, SLOT(CameraTYDoubleSpinBoxChanged(double)));
    disconnect(ui->Camera_TZ_DoubleSpinBox, SIGNAL(valueChanged(double)), this, SLOT(CameraTZDoubleSpinBoxChanged(double)));

    disconnect(ui->Model_AngleX_DoubleSpinBox, SIGNAL(valueChanged(double)), this, SLOT(ModelAngleXDoubleSpinBoxChanged(double)));
    disconnect(ui->Model_AngleY_DoubleSpinBox, SIGNAL(valueChanged(double)), this, SLOT(ModelAngleYDoubleSpinBoxChanged(double)));
    disconnect(ui->Model_AngleZ_DoubleSpinBox, SIGNAL(valueChanged(double)), this, SLOT(ModelAngleZDoubleSpinBoxChanged(double)));

    disconnect(ui->Model_TX_DoubleSpinBox, SIGNAL(valueChanged(double)), this, SLOT(ModelTXDoubleSpinBoxChanged(double)));
    disconnect(ui->Model_TY_DoubleSpinBox, SIGNAL(valueChanged(double)), this, SLOT(ModelTYDoubleSpinBoxChanged(double)));
    disconnect(ui->Model_TZ_DoubleSpinBox, SIGNAL(valueChanged(double)), this, SLOT(ModelTZDoubleSpinBoxChanged(double)));


    delete ui;
}

void OGL::CameraAngleXDoubleSpinBoxChanged(double value)
{
    qDebug() << value;
}

void OGL::CameraAngleYDoubleSpinBoxChanged(double value)
{

}

void OGL::CameraAngleZDoubleSpinBoxChanged(double value)
{

}

void OGL::CameraTXDoubleSpinBoxChanged(double value)
{

}

void OGL::CameraTYDoubleSpinBoxChanged(double value)
{

}

void OGL::CameraTZDoubleSpinBoxChanged(double value)
{

}

void OGL::ModelAngleXDoubleSpinBoxChanged(double value)
{

}

void OGL::ModelAngleYDoubleSpinBoxChanged(double value)
{

}

void OGL::ModelAngleZDoubleSpinBoxChanged(double value)
{

}

void OGL::ModelTXDoubleSpinBoxChanged(double value)
{

}

void OGL::ModelTYDoubleSpinBoxChanged(double value)
{

}

void OGL::ModelTZDoubleSpinBoxChanged(double value)
{

}

void OGL::resizeEvent(QResizeEvent *event)
{
    ui->Param_GroupBox->setGeometry(0, this->height() - parameter_height, this->width(), parameter_height);
    ui->openGLWidget->setGeometry(0, 0, this->width(), this->height() - parameter_height);
}

