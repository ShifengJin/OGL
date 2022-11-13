#include <QDebug>
#include <sstream>
#include "Common.h"
#include "OGL.h"

OGL::OGL(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui_OGL)
{
    ui->setupUi(this);
    parameter_width = ui->Param_GroupBox->width();
    parameter_height = ui->Param_GroupBox->height();

    SetLayoutParameter();
    InitConnect();
}

OGL::~OGL()
{
    UnitConnect();
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

void OGL::SetLabelMatrix(QLabel *label, float matrix[])
{
    if(label){
        std::string text = "";
        text += DarkerOGL::FloatToString(matrix[0]) + " ";
        text += DarkerOGL::FloatToString(matrix[1]) + " ";
        text += DarkerOGL::FloatToString(matrix[2]) + " ";
        text += DarkerOGL::FloatToString(matrix[3]) + "\n";
        text += DarkerOGL::FloatToString(matrix[4]) + " ";
        text += DarkerOGL::FloatToString(matrix[5]) + " ";
        text += DarkerOGL::FloatToString(matrix[6]) + " ";
        text += DarkerOGL::FloatToString(matrix[7]) + "\n";
        text += DarkerOGL::FloatToString(matrix[8]) + " ";
        text += DarkerOGL::FloatToString(matrix[9]) + " ";
        text += DarkerOGL::FloatToString(matrix[10]) + " ";
        text += DarkerOGL::FloatToString(matrix[11]) + "\n";
        text += DarkerOGL::FloatToString(matrix[12]) + " ";
        text += DarkerOGL::FloatToString(matrix[13]) + " ";
        text += DarkerOGL::FloatToString(matrix[14]) + " ";
        text += DarkerOGL::FloatToString(matrix[15]);
        label->setText(QString::fromStdString(text));
    }
}

void OGL::InitConnect()
{
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

void OGL::UnitConnect()
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
}

void OGL::SetLayoutParameter()
{
    ui->Camera_AngleX_DoubleSpinBox->setMinimum(0.);
    ui->Camera_AngleX_DoubleSpinBox->setMaximum(360.);
    ui->Camera_AngleX_DoubleSpinBox->setSingleStep(1.);
    ui->Camera_AngleY_DoubleSpinBox->setMinimum(0.);
    ui->Camera_AngleY_DoubleSpinBox->setMaximum(360.);
    ui->Camera_AngleY_DoubleSpinBox->setSingleStep(1.);
    ui->Camera_AngleZ_DoubleSpinBox->setMinimum(0.);
    ui->Camera_AngleZ_DoubleSpinBox->setMaximum(360.);
    ui->Camera_AngleZ_DoubleSpinBox->setSingleStep(1.);

    ui->Camera_TX_DoubleSpinBox->setMinimum(-100.);
    ui->Camera_TX_DoubleSpinBox->setMaximum(100.);
    ui->Camera_TX_DoubleSpinBox->setSingleStep(1.);
    ui->Camera_TY_DoubleSpinBox->setMinimum(-100.);
    ui->Camera_TY_DoubleSpinBox->setMaximum(100.);
    ui->Camera_TY_DoubleSpinBox->setSingleStep(1.);
    ui->Camera_TZ_DoubleSpinBox->setMinimum(-100.);
    ui->Camera_TZ_DoubleSpinBox->setMaximum(100.);
    ui->Camera_TZ_DoubleSpinBox->setSingleStep(1.);

    ui->Model_AngleX_DoubleSpinBox->setMinimum(0.);
    ui->Model_AngleX_DoubleSpinBox->setMaximum(360.);
    ui->Model_AngleX_DoubleSpinBox->setSingleStep(1.);
    ui->Model_AngleY_DoubleSpinBox->setMinimum(0.);
    ui->Model_AngleY_DoubleSpinBox->setMaximum(360.);
    ui->Model_AngleY_DoubleSpinBox->setSingleStep(1.);
    ui->Model_AngleZ_DoubleSpinBox->setMinimum(0.);
    ui->Model_AngleZ_DoubleSpinBox->setMaximum(360.);
    ui->Model_AngleZ_DoubleSpinBox->setSingleStep(1.);

    ui->Model_TX_DoubleSpinBox->setMinimum(-100.);
    ui->Model_TX_DoubleSpinBox->setMaximum(100.);
    ui->Model_TX_DoubleSpinBox->setSingleStep(1.);
    ui->Model_TY_DoubleSpinBox->setMinimum(-100.);
    ui->Model_TY_DoubleSpinBox->setMaximum(100.);
    ui->Model_TY_DoubleSpinBox->setSingleStep(1.);
    ui->Model_TZ_DoubleSpinBox->setMinimum(-100.);
    ui->Model_TZ_DoubleSpinBox->setMaximum(100.);
    ui->Model_TZ_DoubleSpinBox->setSingleStep(1.);
}

