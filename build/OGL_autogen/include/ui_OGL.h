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
#include <QtWidgets/QOpenGLWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OGL
{
public:
    QWidget *centralwidget;
    QOpenGLWidget *openGLWidget;
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
    QLabel *ViewMatrix_Label;
    QLabel *ViewMatrix_Value_Label;
    QLabel *ViewAngleXMatrix_Label;
    QLabel *ViewAngleXMatrix_Value_Label;
    QLabel *ViewAngleYMatrix_Label;
    QLabel *ViewAngleZMatrix_Label;
    QLabel *ViewAngleYMatrix_Value_Label;
    QLabel *ViewAngleZMatrix_Value_Label;

    void setupUi(QMainWindow *OGL)
    {
        if (OGL->objectName().isEmpty())
            OGL->setObjectName(QString::fromUtf8("OGL"));
        OGL->resize(1280, 940);
        centralwidget = new QWidget(OGL);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        openGLWidget = new QOpenGLWidget(centralwidget);
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
        Model_AngleX_Label = new QLabel(ModelParam_GroupBox);
        Model_AngleX_Label->setObjectName(QString::fromUtf8("Model_AngleX_Label"));
        Model_AngleX_Label->setGeometry(QRect(110, 30, 60, 30));
        Model_AngleY_Label = new QLabel(ModelParam_GroupBox);
        Model_AngleY_Label->setObjectName(QString::fromUtf8("Model_AngleY_Label"));
        Model_AngleY_Label->setGeometry(QRect(110, 60, 60, 30));
        Model_AngleY_DoubleSpinBox = new QDoubleSpinBox(ModelParam_GroupBox);
        Model_AngleY_DoubleSpinBox->setObjectName(QString::fromUtf8("Model_AngleY_DoubleSpinBox"));
        Model_AngleY_DoubleSpinBox->setGeometry(QRect(10, 60, 80, 30));
        Model_AngleZ_Label = new QLabel(ModelParam_GroupBox);
        Model_AngleZ_Label->setObjectName(QString::fromUtf8("Model_AngleZ_Label"));
        Model_AngleZ_Label->setGeometry(QRect(110, 90, 60, 30));
        Model_AngleZ_DoubleSpinBox = new QDoubleSpinBox(ModelParam_GroupBox);
        Model_AngleZ_DoubleSpinBox->setObjectName(QString::fromUtf8("Model_AngleZ_DoubleSpinBox"));
        Model_AngleZ_DoubleSpinBox->setGeometry(QRect(10, 90, 80, 30));
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
        Model_TY_DoubleSpinBox = new QDoubleSpinBox(ModelParam_GroupBox);
        Model_TY_DoubleSpinBox->setObjectName(QString::fromUtf8("Model_TY_DoubleSpinBox"));
        Model_TY_DoubleSpinBox->setGeometry(QRect(10, 150, 80, 30));
        Model_TZ_DoubleSpinBox = new QDoubleSpinBox(ModelParam_GroupBox);
        Model_TZ_DoubleSpinBox->setObjectName(QString::fromUtf8("Model_TZ_DoubleSpinBox"));
        Model_TZ_DoubleSpinBox->setGeometry(QRect(10, 180, 80, 30));
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
        Camera_AngleZ_Label = new QLabel(CameraParam_GroupBox);
        Camera_AngleZ_Label->setObjectName(QString::fromUtf8("Camera_AngleZ_Label"));
        Camera_AngleZ_Label->setGeometry(QRect(110, 90, 60, 30));
        Camera_TY_DoubleSpinBox = new QDoubleSpinBox(CameraParam_GroupBox);
        Camera_TY_DoubleSpinBox->setObjectName(QString::fromUtf8("Camera_TY_DoubleSpinBox"));
        Camera_TY_DoubleSpinBox->setGeometry(QRect(10, 150, 80, 30));
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
        Camera_AngleY_DoubleSpinBox = new QDoubleSpinBox(CameraParam_GroupBox);
        Camera_AngleY_DoubleSpinBox->setObjectName(QString::fromUtf8("Camera_AngleY_DoubleSpinBox"));
        Camera_AngleY_DoubleSpinBox->setGeometry(QRect(10, 60, 80, 30));
        Camera_AngleZ_DoubleSpinBox = new QDoubleSpinBox(CameraParam_GroupBox);
        Camera_AngleZ_DoubleSpinBox->setObjectName(QString::fromUtf8("Camera_AngleZ_DoubleSpinBox"));
        Camera_AngleZ_DoubleSpinBox->setGeometry(QRect(10, 90, 80, 30));
        Camera_TX_DoubleSpinBox = new QDoubleSpinBox(CameraParam_GroupBox);
        Camera_TX_DoubleSpinBox->setObjectName(QString::fromUtf8("Camera_TX_DoubleSpinBox"));
        Camera_TX_DoubleSpinBox->setGeometry(QRect(10, 120, 80, 30));
        ViewMatrix_Label = new QLabel(Param_GroupBox);
        ViewMatrix_Label->setObjectName(QString::fromUtf8("ViewMatrix_Label"));
        ViewMatrix_Label->setGeometry(QRect(230, 20, 81, 31));
        ViewMatrix_Value_Label = new QLabel(Param_GroupBox);
        ViewMatrix_Value_Label->setObjectName(QString::fromUtf8("ViewMatrix_Value_Label"));
        ViewMatrix_Value_Label->setGeometry(QRect(230, 60, 121, 101));
        ViewAngleXMatrix_Label = new QLabel(Param_GroupBox);
        ViewAngleXMatrix_Label->setObjectName(QString::fromUtf8("ViewAngleXMatrix_Label"));
        ViewAngleXMatrix_Label->setGeometry(QRect(390, 20, 101, 31));
        ViewAngleXMatrix_Value_Label = new QLabel(Param_GroupBox);
        ViewAngleXMatrix_Value_Label->setObjectName(QString::fromUtf8("ViewAngleXMatrix_Value_Label"));
        ViewAngleXMatrix_Value_Label->setGeometry(QRect(390, 66, 131, 111));
        ViewAngleYMatrix_Label = new QLabel(Param_GroupBox);
        ViewAngleYMatrix_Label->setObjectName(QString::fromUtf8("ViewAngleYMatrix_Label"));
        ViewAngleYMatrix_Label->setGeometry(QRect(570, 26, 101, 21));
        ViewAngleZMatrix_Label = new QLabel(Param_GroupBox);
        ViewAngleZMatrix_Label->setObjectName(QString::fromUtf8("ViewAngleZMatrix_Label"));
        ViewAngleZMatrix_Label->setGeometry(QRect(710, 26, 101, 21));
        ViewAngleYMatrix_Value_Label = new QLabel(Param_GroupBox);
        ViewAngleYMatrix_Value_Label->setObjectName(QString::fromUtf8("ViewAngleYMatrix_Value_Label"));
        ViewAngleYMatrix_Value_Label->setGeometry(QRect(550, 60, 121, 101));
        ViewAngleZMatrix_Value_Label = new QLabel(Param_GroupBox);
        ViewAngleZMatrix_Value_Label->setObjectName(QString::fromUtf8("ViewAngleZMatrix_Value_Label"));
        ViewAngleZMatrix_Value_Label->setGeometry(QRect(700, 60, 131, 111));
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
        ViewMatrix_Label->setText(QCoreApplication::translate("OGL", "ViewMatrix", nullptr));
        ViewMatrix_Value_Label->setText(QString());
        ViewAngleXMatrix_Label->setText(QCoreApplication::translate("OGL", "AngleXMatrix", nullptr));
        ViewAngleXMatrix_Value_Label->setText(QString());
        ViewAngleYMatrix_Label->setText(QCoreApplication::translate("OGL", "AngleYMatrix", nullptr));
        ViewAngleZMatrix_Label->setText(QCoreApplication::translate("OGL", "AngleZMatrix", nullptr));
        ViewAngleYMatrix_Value_Label->setText(QString());
        ViewAngleZMatrix_Value_Label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class OGL: public Ui_OGL {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OGL_H
