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

    Darker::Matrix4<float> identity;
    memcpy(xCameraMatrix, identity.Data(), 16*sizeof(float));
    memcpy(yCameraMatrix, identity.Data(), 16*sizeof(float));
    memcpy(zCameraMatrix, identity.Data(), 16*sizeof(float));
    memcpy(cameraTMatrix, identity.Data(), 16*sizeof(float));
    memcpy(cameraMatrix, identity.Data(), 16*sizeof(float));
    memcpy(cameraViewMatrix, identity.Data(), 16*sizeof(float));
    memcpy(xObservedModelMatrix, identity.Data(), 16*sizeof(float));
    memcpy(yObservedModelMatrix, identity.Data(), 16*sizeof(float));
    memcpy(zObservedModelMatrix, identity.Data(), 16*sizeof(float));
    memcpy(observedTMatrix, identity.Data(), 16*sizeof(float));
    memcpy(observedModelMatrix, identity.Data(), 16*sizeof(float));

    SetLayoutParameter();

    SetLabelMatrix(ui->CameraAngleXMatrix_Value_Label, xCameraMatrix);
    SetLabelMatrix(ui->CameraAngleYMatrix_Value_Label, yCameraMatrix);
    SetLabelMatrix(ui->CameraAngleZMatrix_Value_Label, zCameraMatrix);
    SetLabelMatrix(ui->CameraTMatrix_Value_Label, cameraTMatrix);
    SetLabelMatrix(ui->CameraMatrix_Value_Label, cameraMatrix);

    Darker::Matrix4<float> cameraM(cameraMatrix);
    cameraM.Transpose();
    ((RendererWidget*)(ui->openGLWidget))->SetCameraModelMatrix(cameraM.Data());

    Darker::Matrix4<float> observedModelM(observedModelMatrix);
    observedModelM.Transpose();
    ((RendererWidget*)(ui->openGLWidget))->SetObservedModelMatrix(observedModelM.Data());

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
    xCameraAngle = (float)value;
    updateXCameraAngle(xCameraAngle);
    updateCameraMatrix();
    updateCameraViewMatrix();
    SetLabelMatrix(ui->CameraAngleXMatrix_Value_Label, xCameraMatrix);
    SetLabelMatrix(ui->CameraMatrix_Value_Label, cameraMatrix);

    Darker::Matrix4<float> cameraM(cameraMatrix);
    cameraM.Transpose();
    ((RendererWidget*)(ui->openGLWidget))->SetCameraModelMatrix(cameraM.Data());
}

void OGL::CameraAngleYDoubleSpinBoxChanged(double value)
{
    yCameraAngle = (float)value;
    updateYCameraAngle(yCameraAngle);
    updateCameraMatrix();
    updateCameraViewMatrix();
    SetLabelMatrix(ui->CameraAngleYMatrix_Value_Label, yCameraMatrix);
    SetLabelMatrix(ui->CameraMatrix_Value_Label, cameraMatrix);

    Darker::Matrix4<float> cameraM(cameraMatrix);
    cameraM.Transpose();
    ((RendererWidget*)(ui->openGLWidget))->SetCameraModelMatrix(cameraM.Data());
}

void OGL::CameraAngleZDoubleSpinBoxChanged(double value)
{
    zCameraAngle = (float)value;
    updateZCameraAngle(zCameraAngle);
    updateCameraMatrix();
    updateCameraViewMatrix();
    SetLabelMatrix(ui->CameraAngleZMatrix_Value_Label, zCameraMatrix);
    SetLabelMatrix(ui->CameraMatrix_Value_Label, cameraMatrix);

    Darker::Matrix4<float> cameraM(cameraMatrix);
    cameraM.Transpose();
    ((RendererWidget*)(ui->openGLWidget))->SetCameraModelMatrix(cameraM.Data());
}

void OGL::CameraTXDoubleSpinBoxChanged(double value)
{
    xCameraT = (float)value;
    updateXCameraT(xCameraT);
    updateCameraMatrix();
    updateCameraViewMatrix();

    SetLabelMatrix(ui->CameraTMatrix_Value_Label, cameraTMatrix);
    SetLabelMatrix(ui->CameraMatrix_Value_Label, cameraMatrix);

    Darker::Matrix4<float> cameraM(cameraMatrix);
    cameraM.Transpose();
    ((RendererWidget*)(ui->openGLWidget))->SetCameraModelMatrix(cameraM.Data());
}

void OGL::CameraTYDoubleSpinBoxChanged(double value)
{
    yCameraT = (float)value;
    updateYCameraT(yCameraT);
    updateCameraMatrix();
    updateCameraViewMatrix();
    SetLabelMatrix(ui->CameraTMatrix_Value_Label, cameraTMatrix);
    SetLabelMatrix(ui->CameraMatrix_Value_Label, cameraMatrix);

    Darker::Matrix4<float> cameraM(cameraMatrix);
    cameraM.Transpose();
    ((RendererWidget*)(ui->openGLWidget))->SetCameraModelMatrix(cameraM.Data());
}

void OGL::CameraTZDoubleSpinBoxChanged(double value)
{
    zCameraT = (float)value;
    updateZCameraT(zCameraT);
    updateCameraMatrix();
    updateCameraViewMatrix();
    SetLabelMatrix(ui->CameraTMatrix_Value_Label, cameraTMatrix);
    SetLabelMatrix(ui->CameraMatrix_Value_Label, cameraMatrix);

    Darker::Matrix4<float> cameraM(cameraMatrix);
    cameraM.Transpose();
    ((RendererWidget*)(ui->openGLWidget))->SetCameraModelMatrix(cameraM.Data());
}

void OGL::ModelAngleXDoubleSpinBoxChanged(double value)
{
    xObservedAngle = (float)value;
    updateXObservedAngle(xObservedAngle);
    updateObservedMatrix();
}

void OGL::ModelAngleYDoubleSpinBoxChanged(double value)
{
    yObservedAngle = (float)value;
    updateYObservedAngle(yObservedAngle);
    updateObservedMatrix();
}

void OGL::ModelAngleZDoubleSpinBoxChanged(double value)
{
    zObservedAngle = (float)value;
    updateZObservedAngle(zObservedAngle);
    updateObservedMatrix();
}

void OGL::ModelTXDoubleSpinBoxChanged(double value)
{
    xObservedT = (float)value;
    updateXObservedT(xObservedT);
    updateObservedMatrix();
}

void OGL::ModelTYDoubleSpinBoxChanged(double value)
{
    yObservedT = (float)value;
    updateYObservedT(yObservedT);
    updateObservedMatrix();
}

void OGL::ModelTZDoubleSpinBoxChanged(double value)
{
    zObservedT = (float)value;
    updateZObservedT(zObservedT);
    updateObservedMatrix();
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

void OGL::updateXCameraAngle(float xCameraAngle){
    Darker::Matrix4<float> identity;
    identity.RotateX(xCameraAngle);
    memcpy(xCameraMatrix, identity.Data(), 16 * sizeof(float));
}

void OGL::updateYCameraAngle(float yCameraAngle){
    Darker::Matrix4<float> identity;
    identity.RotateY(yCameraAngle);
    memcpy(yCameraMatrix, identity.Data(), 16 * sizeof(float));
}

void OGL::updateZCameraAngle(float zCameraAngle){
    Darker::Matrix4<float> identity;
    identity.RotateZ(zCameraAngle);
    memcpy(zCameraMatrix, identity.Data(), 16 * sizeof(float));
}

void OGL::updateXCameraT(float xCameraT){
    Darker::Matrix4<float> identity(cameraTMatrix);
    identity.Data()[3] = xCameraT;
    memcpy(cameraTMatrix, identity.Data(), 16 * sizeof(float));
}

void OGL::updateYCameraT(float yCameraT){
    Darker::Matrix4<float> identity(cameraTMatrix);
    identity.Data()[7] = yCameraT;
    memcpy(cameraTMatrix, identity.Data(), 16 * sizeof(float));
}

void OGL::updateZCameraT(float zCameraT){
    Darker::Matrix4<float> identity(cameraTMatrix);
    identity.Data()[11] = zCameraT;
    memcpy(cameraTMatrix, identity.Data(), 16 * sizeof(float));
}

void OGL::updateCameraMatrix(){
    Darker::Matrix4<float> xMatrix(xCameraMatrix);
    Darker::Matrix4<float> yMatrix(yCameraMatrix);
    Darker::Matrix4<float> zMatrix(zCameraMatrix);
    Darker::Matrix4<float> tMatrix(cameraTMatrix);
    Darker::Matrix4<float> matrix;
    matrix = tMatrix * xMatrix * yMatrix * zMatrix;
    memcpy(cameraMatrix, matrix.Data(), 16 * sizeof(float));
}

void OGL::updateCameraViewMatrix(){
    Darker::Matrix4<float> matrix(cameraMatrix);
    matrix.InvertAffinne();
    memcpy(cameraViewMatrix, matrix.Data(), 16 * sizeof(float));
}

void OGL::updateXObservedAngle(float xObservedAngle){
    Darker::Matrix4<float> identity;
    identity.RotateX(xObservedAngle);
    memcpy(xObservedModelMatrix, identity.Data(), 16 * sizeof(float));
}

void OGL::updateYObservedAngle(float yObservedAngle){
    Darker::Matrix4<float> identity;
    identity.RotateX(yObservedAngle);
    memcpy(yObservedModelMatrix, identity.Data(), 16 * sizeof(float));
}

void OGL::updateZObservedAngle(float zObservedAngle){
    Darker::Matrix4<float> identity;
    identity.RotateX(zObservedAngle);
    memcpy(zObservedModelMatrix, identity.Data(), 16 * sizeof(float));
}

void OGL::updateXObservedT(float xObservedT){
    Darker::Matrix4<float> identity(observedTMatrix);
    identity.Data()[3] = xObservedT;
    memcpy(observedTMatrix, identity.Data(), 16 * sizeof(float));
}

void OGL::updateYObservedT(float yObservedT){
    Darker::Matrix4<float> identity(observedTMatrix);
    identity.Data()[7] = yObservedT;
    memcpy(observedTMatrix, identity.Data(), 16 * sizeof(float));
}

void OGL::updateZObservedT(float zObservedT){
    Darker::Matrix4<float> identity(observedTMatrix);
    identity.Data()[11] = zObservedT;
    memcpy(observedTMatrix, identity.Data(), 16 * sizeof(float));
}

void OGL::updateObservedMatrix(){
    Darker::Matrix4<float> xMatrix(xObservedModelMatrix);
    Darker::Matrix4<float> yMatrix(yObservedModelMatrix);
    Darker::Matrix4<float> zMatrix(zObservedModelMatrix);
    Darker::Matrix4<float> tMatrix(observedTMatrix);
    Darker::Matrix4<float> matrix;
    matrix = tMatrix * xMatrix * yMatrix * zMatrix;
    memcpy(observedModelMatrix, matrix.Data(), 16 * sizeof(float));
}