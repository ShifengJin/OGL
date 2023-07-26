/********************************************************************************
** Form generated from reading UI file 'OGL.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OGL_H
#define UI_OGL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>
#include "RendererWidget.h"

QT_BEGIN_NAMESPACE

class Ui_OGL
{
public:
    QWidget *centralwidget;
    RendererWidget *openGLWidget;
    QGroupBox *Param_GroupBox;
    QGroupBox *ModelParam_GroupBox;
    QDoubleSpinBox *Model_AngleX_DoubleSpinBox;
    QLabel *Model_AngleX_Label;
    QLabel *Model_AngleY_Label;
    QDoubleSpinBox *Model_AngleY_DoubleSpinBox;
    QLabel *Model_AngleZ_Label;
    QDoubleSpinBox *Model_AngleZ_DoubleSpinBox;
    QLabel *Model_TY_Label;
    QLabel *Model_TZ_Label;
    QLabel *Model_TX_Label;
    QDoubleSpinBox *Model_TX_DoubleSpinBox;
    QDoubleSpinBox *Model_TY_DoubleSpinBox;
    QDoubleSpinBox *Model_TZ_DoubleSpinBox;
    QGroupBox *CameraParam_GroupBox;
    QLabel *Camera_AngleY_Label;
    QLabel *Camera_TX_Label;
    QDoubleSpinBox *Camera_TZ_DoubleSpinBox;
    QLabel *Camera_AngleZ_Label;
    QDoubleSpinBox *Camera_TY_DoubleSpinBox;
    QLabel *Camera_TY_Label;
    QLabel *Camera_AngleX_Label;
    QLabel *Camera_TZ_Label;
    QDoubleSpinBox *Camera_AngleX_DoubleSpinBox;
    QDoubleSpinBox *Camera_AngleY_DoubleSpinBox;
    QDoubleSpinBox *Camera_AngleZ_DoubleSpinBox;
    QDoubleSpinBox *Camera_TX_DoubleSpinBox;
    QLabel *CameraMatrix_Label;
    QLabel *CameraMatrix_Value_Label;
    QLabel *CameraAngleXMatrix_Label;
    QLabel *CameraAngleXMatrix_Value_Label;
    QLabel *CameraAngleYMatrix_Label;
    QLabel *CameraAngleZMatrix_Label;
    QLabel *CameraAngleYMatrix_Value_Label;
    QLabel *CameraAngleZMatrix_Value_Label;
    QLabel *CameraTMatrix_Label;
    QLabel *CameraTMatrix_Value_Label;
    QLabel *ModelMatrix_Label;
    QLabel *ModelTMatrix_Label;
    QLabel *ModelAngleXMatrix_Label;
    QLabel *ModelAngleYMatrix_Label;
    QLabel *ModelAngleZMatrix_Label;
    QLabel *ModelAngleZMatrix_Value_Label;
    QLabel *ModelAngleXMatrix_Value_Label;
    QLabel *ModelMatrix_Value_Label;
    QLabel *ModelTMatrix_Value_Label;
    QLabel *ModelAngleYMatrix_Value_Label;

    void setupUi(QMainWindow *OGL)
    {
        if (OGL->objectName().isEmpty())
            OGL->setObjectName(QString::fromUtf8("OGL"));
        OGL->resize(1280, 940);
        centralwidget = new QWidget(OGL);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        openGLWidget = new RendererWidget(centralwidget);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));
        openGLWidget->setEnabled(true);
        openGLWidget->setGeometry(QRect(0, 0, 1280, 480));
        Param_GroupBox = new QGroupBox(centralwidget);
        Param_GroupBox->setObjectName(QString::fromUtf8("Param_GroupBox"));
        Param_GroupBox->setGeometry(QRect(0, 490, 1280, 440));
        ModelParam_GroupBox = new QGroupBox(Param_GroupBox);
        ModelParam_GroupBox->setObjectName(QString::fromUtf8("ModelParam_GroupBox"));
        ModelParam_GroupBox->setGeometry(QRect(0, 220, 180, 220));
        Model_AngleX_DoubleSpinBox = new QDoubleSpinBox(ModelParam_GroupBox);
        Model_AngleX_DoubleSpinBox->setObjectName(QString::fromUtf8("Model_AngleX_DoubleSpinBox"));
        Model_AngleX_DoubleSpinBox->setGeometry(QRect(10, 30, 80, 30));
        Model_AngleX_DoubleSpinBox->setMaximum(360.000000000000000);
        Model_AngleX_Label = new QLabel(ModelParam_GroupBox);
        Model_AngleX_Label->setObjectName(QString::fromUtf8("Model_AngleX_Label"));
        Model_AngleX_Label->setGeometry(QRect(110, 30, 60, 30));
        Model_AngleY_Label = new QLabel(ModelParam_GroupBox);
        Model_AngleY_Label->setObjectName(QString::fromUtf8("Model_AngleY_Label"));
        Model_AngleY_Label->setGeometry(QRect(110, 60, 60, 30));
        Model_AngleY_DoubleSpinBox = new QDoubleSpinBox(ModelParam_GroupBox);
        Model_AngleY_DoubleSpinBox->setObjectName(QString::fromUtf8("Model_AngleY_DoubleSpinBox"));
        Model_AngleY_DoubleSpinBox->setGeometry(QRect(10, 60, 80, 30));
        Model_AngleY_DoubleSpinBox->setMaximum(360.000000000000000);
        Model_AngleZ_Label = new QLabel(ModelParam_GroupBox);
        Model_AngleZ_Label->setObjectName(QString::fromUtf8("Model_AngleZ_Label"));
        Model_AngleZ_Label->setGeometry(QRect(110, 90, 60, 30));
        Model_AngleZ_DoubleSpinBox = new QDoubleSpinBox(ModelParam_GroupBox);
        Model_AngleZ_DoubleSpinBox->setObjectName(QString::fromUtf8("Model_AngleZ_DoubleSpinBox"));
        Model_AngleZ_DoubleSpinBox->setGeometry(QRect(10, 90, 80, 30));
        Model_AngleZ_DoubleSpinBox->setMaximum(360.000000000000000);
        Model_TY_Label = new QLabel(ModelParam_GroupBox);
        Model_TY_Label->setObjectName(QString::fromUtf8("Model_TY_Label"));
        Model_TY_Label->setGeometry(QRect(110, 150, 60, 30));
        Model_TZ_Label = new QLabel(ModelParam_GroupBox);
        Model_TZ_Label->setObjectName(QString::fromUtf8("Model_TZ_Label"));
        Model_TZ_Label->setGeometry(QRect(110, 180, 60, 30));
        Model_TX_Label = new QLabel(ModelParam_GroupBox);
        Model_TX_Label->setObjectName(QString::fromUtf8("Model_TX_Label"));
        Model_TX_Label->setGeometry(QRect(110, 120, 60, 30));
        Model_TX_DoubleSpinBox = new QDoubleSpinBox(ModelParam_GroupBox);
        Model_TX_DoubleSpinBox->setObjectName(QString::fromUtf8("Model_TX_DoubleSpinBox"));
        Model_TX_DoubleSpinBox->setGeometry(QRect(10, 120, 80, 30));
        Model_TX_DoubleSpinBox->setMinimum(-100.000000000000000);
        Model_TX_DoubleSpinBox->setMaximum(100.000000000000000);
        Model_TY_DoubleSpinBox = new QDoubleSpinBox(ModelParam_GroupBox);
        Model_TY_DoubleSpinBox->setObjectName(QString::fromUtf8("Model_TY_DoubleSpinBox"));
        Model_TY_DoubleSpinBox->setGeometry(QRect(10, 150, 80, 30));
        Model_TY_DoubleSpinBox->setMinimum(-100.000000000000000);
        Model_TY_DoubleSpinBox->setMaximum(100.000000000000000);
        Model_TZ_DoubleSpinBox = new QDoubleSpinBox(ModelParam_GroupBox);
        Model_TZ_DoubleSpinBox->setObjectName(QString::fromUtf8("Model_TZ_DoubleSpinBox"));
        Model_TZ_DoubleSpinBox->setGeometry(QRect(10, 180, 80, 30));
        Model_TZ_DoubleSpinBox->setMinimum(-100.000000000000000);
        Model_TZ_DoubleSpinBox->setMaximum(100.000000000000000);
        CameraParam_GroupBox = new QGroupBox(Param_GroupBox);
        CameraParam_GroupBox->setObjectName(QString::fromUtf8("CameraParam_GroupBox"));
        CameraParam_GroupBox->setGeometry(QRect(0, 0, 180, 220));
        Camera_AngleY_Label = new QLabel(CameraParam_GroupBox);
        Camera_AngleY_Label->setObjectName(QString::fromUtf8("Camera_AngleY_Label"));
        Camera_AngleY_Label->setGeometry(QRect(110, 60, 60, 30));
        Camera_TX_Label = new QLabel(CameraParam_GroupBox);
        Camera_TX_Label->setObjectName(QString::fromUtf8("Camera_TX_Label"));
        Camera_TX_Label->setGeometry(QRect(110, 120, 60, 30));
        Camera_TZ_DoubleSpinBox = new QDoubleSpinBox(CameraParam_GroupBox);
        Camera_TZ_DoubleSpinBox->setObjectName(QString::fromUtf8("Camera_TZ_DoubleSpinBox"));
        Camera_TZ_DoubleSpinBox->setGeometry(QRect(10, 180, 80, 30));
        Camera_TZ_DoubleSpinBox->setMinimum(-100.000000000000000);
        Camera_TZ_DoubleSpinBox->setMaximum(100.000000000000000);
        Camera_AngleZ_Label = new QLabel(CameraParam_GroupBox);
        Camera_AngleZ_Label->setObjectName(QString::fromUtf8("Camera_AngleZ_Label"));
        Camera_AngleZ_Label->setGeometry(QRect(110, 90, 60, 30));
        Camera_TY_DoubleSpinBox = new QDoubleSpinBox(CameraParam_GroupBox);
        Camera_TY_DoubleSpinBox->setObjectName(QString::fromUtf8("Camera_TY_DoubleSpinBox"));
        Camera_TY_DoubleSpinBox->setGeometry(QRect(10, 150, 80, 30));
        Camera_TY_DoubleSpinBox->setMinimum(-100.000000000000000);
        Camera_TY_DoubleSpinBox->setMaximum(100.000000000000000);
        Camera_TY_Label = new QLabel(CameraParam_GroupBox);
        Camera_TY_Label->setObjectName(QString::fromUtf8("Camera_TY_Label"));
        Camera_TY_Label->setGeometry(QRect(110, 150, 60, 30));
        Camera_AngleX_Label = new QLabel(CameraParam_GroupBox);
        Camera_AngleX_Label->setObjectName(QString::fromUtf8("Camera_AngleX_Label"));
        Camera_AngleX_Label->setGeometry(QRect(110, 30, 60, 30));
        Camera_TZ_Label = new QLabel(CameraParam_GroupBox);
        Camera_TZ_Label->setObjectName(QString::fromUtf8("Camera_TZ_Label"));
        Camera_TZ_Label->setGeometry(QRect(110, 180, 60, 30));
        Camera_AngleX_DoubleSpinBox = new QDoubleSpinBox(CameraParam_GroupBox);
        Camera_AngleX_DoubleSpinBox->setObjectName(QString::fromUtf8("Camera_AngleX_DoubleSpinBox"));
        Camera_AngleX_DoubleSpinBox->setGeometry(QRect(10, 30, 80, 30));
        Camera_AngleX_DoubleSpinBox->setMaximum(360.000000000000000);
        Camera_AngleY_DoubleSpinBox = new QDoubleSpinBox(CameraParam_GroupBox);
        Camera_AngleY_DoubleSpinBox->setObjectName(QString::fromUtf8("Camera_AngleY_DoubleSpinBox"));
        Camera_AngleY_DoubleSpinBox->setGeometry(QRect(10, 60, 80, 30));
        Camera_AngleY_DoubleSpinBox->setMaximum(360.000000000000000);
        Camera_AngleZ_DoubleSpinBox = new QDoubleSpinBox(CameraParam_GroupBox);
        Camera_AngleZ_DoubleSpinBox->setObjectName(QString::fromUtf8("Camera_AngleZ_DoubleSpinBox"));
        Camera_AngleZ_DoubleSpinBox->setGeometry(QRect(10, 90, 80, 30));
        Camera_AngleZ_DoubleSpinBox->setMaximum(360.000000000000000);
        Camera_TX_DoubleSpinBox = new QDoubleSpinBox(CameraParam_GroupBox);
        Camera_TX_DoubleSpinBox->setObjectName(QString::fromUtf8("Camera_TX_DoubleSpinBox"));
        Camera_TX_DoubleSpinBox->setGeometry(QRect(10, 120, 80, 30));
        Camera_TX_DoubleSpinBox->setMinimum(-100.000000000000000);
        Camera_TX_DoubleSpinBox->setMaximum(100.000000000000000);
        CameraMatrix_Label = new QLabel(Param_GroupBox);
        CameraMatrix_Label->setObjectName(QString::fromUtf8("CameraMatrix_Label"));
        CameraMatrix_Label->setGeometry(QRect(250, 20, 128, 32));
        CameraMatrix_Value_Label = new QLabel(Param_GroupBox);
        CameraMatrix_Value_Label->setObjectName(QString::fromUtf8("CameraMatrix_Value_Label"));
        CameraMatrix_Value_Label->setGeometry(QRect(200, 60, 200, 100));
        CameraAngleXMatrix_Label = new QLabel(Param_GroupBox);
        CameraAngleXMatrix_Label->setObjectName(QString::fromUtf8("CameraAngleXMatrix_Label"));
        CameraAngleXMatrix_Label->setGeometry(QRect(690, 20, 128, 32));
        CameraAngleXMatrix_Value_Label = new QLabel(Param_GroupBox);
        CameraAngleXMatrix_Value_Label->setObjectName(QString::fromUtf8("CameraAngleXMatrix_Value_Label"));
        CameraAngleXMatrix_Value_Label->setGeometry(QRect(640, 60, 200, 100));
        CameraAngleYMatrix_Label = new QLabel(Param_GroupBox);
        CameraAngleYMatrix_Label->setObjectName(QString::fromUtf8("CameraAngleYMatrix_Label"));
        CameraAngleYMatrix_Label->setGeometry(QRect(910, 20, 128, 32));
        CameraAngleZMatrix_Label = new QLabel(Param_GroupBox);
        CameraAngleZMatrix_Label->setObjectName(QString::fromUtf8("CameraAngleZMatrix_Label"));
        CameraAngleZMatrix_Label->setGeometry(QRect(1130, 20, 128, 32));
        CameraAngleYMatrix_Value_Label = new QLabel(Param_GroupBox);
        CameraAngleYMatrix_Value_Label->setObjectName(QString::fromUtf8("CameraAngleYMatrix_Value_Label"));
        CameraAngleYMatrix_Value_Label->setGeometry(QRect(860, 60, 200, 100));
        CameraAngleZMatrix_Value_Label = new QLabel(Param_GroupBox);
        CameraAngleZMatrix_Value_Label->setObjectName(QString::fromUtf8("CameraAngleZMatrix_Value_Label"));
        CameraAngleZMatrix_Value_Label->setGeometry(QRect(1080, 60, 200, 100));
        CameraTMatrix_Label = new QLabel(Param_GroupBox);
        CameraTMatrix_Label->setObjectName(QString::fromUtf8("CameraTMatrix_Label"));
        CameraTMatrix_Label->setGeometry(QRect(490, 20, 128, 32));
        CameraTMatrix_Value_Label = new QLabel(Param_GroupBox);
        CameraTMatrix_Value_Label->setObjectName(QString::fromUtf8("CameraTMatrix_Value_Label"));
        CameraTMatrix_Value_Label->setGeometry(QRect(420, 60, 200, 100));
        ModelMatrix_Label = new QLabel(Param_GroupBox);
        ModelMatrix_Label->setObjectName(QString::fromUtf8("ModelMatrix_Label"));
        ModelMatrix_Label->setGeometry(QRect(250, 250, 128, 32));
        ModelTMatrix_Label = new QLabel(Param_GroupBox);
        ModelTMatrix_Label->setObjectName(QString::fromUtf8("ModelTMatrix_Label"));
        ModelTMatrix_Label->setGeometry(QRect(490, 250, 128, 32));
        ModelAngleXMatrix_Label = new QLabel(Param_GroupBox);
        ModelAngleXMatrix_Label->setObjectName(QString::fromUtf8("ModelAngleXMatrix_Label"));
        ModelAngleXMatrix_Label->setGeometry(QRect(690, 250, 128, 32));
        ModelAngleYMatrix_Label = new QLabel(Param_GroupBox);
        ModelAngleYMatrix_Label->setObjectName(QString::fromUtf8("ModelAngleYMatrix_Label"));
        ModelAngleYMatrix_Label->setGeometry(QRect(910, 250, 128, 32));
        ModelAngleZMatrix_Label = new QLabel(Param_GroupBox);
        ModelAngleZMatrix_Label->setObjectName(QString::fromUtf8("ModelAngleZMatrix_Label"));
        ModelAngleZMatrix_Label->setGeometry(QRect(1130, 250, 128, 32));
        ModelAngleZMatrix_Value_Label = new QLabel(Param_GroupBox);
        ModelAngleZMatrix_Value_Label->setObjectName(QString::fromUtf8("ModelAngleZMatrix_Value_Label"));
        ModelAngleZMatrix_Value_Label->setGeometry(QRect(1080, 300, 200, 100));
        ModelAngleXMatrix_Value_Label = new QLabel(Param_GroupBox);
        ModelAngleXMatrix_Value_Label->setObjectName(QString::fromUtf8("ModelAngleXMatrix_Value_Label"));
        ModelAngleXMatrix_Value_Label->setGeometry(QRect(640, 300, 200, 100));
        ModelMatrix_Value_Label = new QLabel(Param_GroupBox);
        ModelMatrix_Value_Label->setObjectName(QString::fromUtf8("ModelMatrix_Value_Label"));
        ModelMatrix_Value_Label->setGeometry(QRect(200, 300, 200, 100));
        ModelTMatrix_Value_Label = new QLabel(Param_GroupBox);
        ModelTMatrix_Value_Label->setObjectName(QString::fromUtf8("ModelTMatrix_Value_Label"));
        ModelTMatrix_Value_Label->setGeometry(QRect(420, 300, 200, 100));
        ModelAngleYMatrix_Value_Label = new QLabel(Param_GroupBox);
        ModelAngleYMatrix_Value_Label->setObjectName(QString::fromUtf8("ModelAngleYMatrix_Value_Label"));
        ModelAngleYMatrix_Value_Label->setGeometry(QRect(860, 300, 200, 100));
        OGL->setCentralWidget(centralwidget);

        retranslateUi(OGL);

        QMetaObject::connectSlotsByName(OGL);
    } // setupUi

    void retranslateUi(QMainWindow *OGL)
    {
        OGL->setWindowTitle(QCoreApplication::translate("OGL", "OGL", nullptr));
        Param_GroupBox->setTitle(QString());
        ModelParam_GroupBox->setTitle(QCoreApplication::translate("OGL", "Model", nullptr));
        Model_AngleX_Label->setText(QCoreApplication::translate("OGL", "AngleX", nullptr));
        Model_AngleY_Label->setText(QCoreApplication::translate("OGL", "AngleY", nullptr));
        Model_AngleZ_Label->setText(QCoreApplication::translate("OGL", "AngleZ", nullptr));
        Model_TY_Label->setText(QCoreApplication::translate("OGL", "TY", nullptr));
        Model_TZ_Label->setText(QCoreApplication::translate("OGL", "TZ", nullptr));
        Model_TX_Label->setText(QCoreApplication::translate("OGL", "TX", nullptr));
        CameraParam_GroupBox->setTitle(QCoreApplication::translate("OGL", "Camera", nullptr));
        Camera_AngleY_Label->setText(QCoreApplication::translate("OGL", "AngleY", nullptr));
        Camera_TX_Label->setText(QCoreApplication::translate("OGL", "TX", nullptr));
        Camera_AngleZ_Label->setText(QCoreApplication::translate("OGL", "AngleZ", nullptr));
        Camera_TY_Label->setText(QCoreApplication::translate("OGL", "TY", nullptr));
        Camera_AngleX_Label->setText(QCoreApplication::translate("OGL", "AngleX", nullptr));
        Camera_TZ_Label->setText(QCoreApplication::translate("OGL", "TZ", nullptr));
        CameraMatrix_Label->setText(QCoreApplication::translate("OGL", "CameraMatrix", nullptr));
        CameraMatrix_Value_Label->setText(QString());
        CameraAngleXMatrix_Label->setText(QCoreApplication::translate("OGL", "AngleXMatrix", nullptr));
        CameraAngleXMatrix_Value_Label->setText(QString());
        CameraAngleYMatrix_Label->setText(QCoreApplication::translate("OGL", "AngleYMatrix", nullptr));
        CameraAngleZMatrix_Label->setText(QCoreApplication::translate("OGL", "AngleZMatrix", nullptr));
        CameraAngleYMatrix_Value_Label->setText(QString());
        CameraAngleZMatrix_Value_Label->setText(QString());
        CameraTMatrix_Label->setText(QCoreApplication::translate("OGL", "TMatrix", nullptr));
        CameraTMatrix_Value_Label->setText(QString());
        ModelMatrix_Label->setText(QCoreApplication::translate("OGL", "ModelMatrix", nullptr));
        ModelTMatrix_Label->setText(QCoreApplication::translate("OGL", "TMatrix", nullptr));
        ModelAngleXMatrix_Label->setText(QCoreApplication::translate("OGL", "AngleXMatrix", nullptr));
        ModelAngleYMatrix_Label->setText(QCoreApplication::translate("OGL", "AngleYMatrix", nullptr));
        ModelAngleZMatrix_Label->setText(QCoreApplication::translate("OGL", "AngleZMatrix", nullptr));
        ModelAngleZMatrix_Value_Label->setText(QString());
        ModelAngleXMatrix_Value_Label->setText(QString());
        ModelMatrix_Value_Label->setText(QString());
        ModelTMatrix_Value_Label->setText(QString());
        ModelAngleYMatrix_Value_Label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class OGL: public Ui_OGL {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OGL_H
