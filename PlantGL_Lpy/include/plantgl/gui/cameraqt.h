/********************************************************************************
** Form generated from reading UI file 'cameraqt.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CAMERAQT_H
#define CAMERAQT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CameraProperties
{
public:
    QGridLayout *gridLayout;
    QFrame *Line3_2;
    QLabel *ZoomLabel;
    QLabel *CenterLabel;
    QLineEdit *NearEdit;
    QLineEdit *FarEdit;
    QLabel *EyeLabel2;
    QLabel *NearLabel;
    QLabel *FarLabel;
    QLabel *AngleLabel2;
    QDoubleSpinBox *DefaultAngleEdit;
    QLineEdit *CurrentAngleEdit;
    QLineEdit *ElevationEdit;
    QLineEdit *YTranslationEdit;
    QLabel *Translation;
    QLabel *AzimuthLabel;
    QComboBox *CoordinatesBox;
    QLabel *systemLabel;
    QLabel *PositionLabel;
    QLineEdit *AzimuthEdit;
    QFrame *Line3;
    QLabel *ProjectionLabel2;
    QLineEdit *PositionEdit;
    QFrame *Line3_2_2;
    QLineEdit *ZoomEdit;
    QLabel *AngleLabel;
    QLineEdit *CenterEdit;
    QLineEdit *EyeEdit;
    QLineEdit *XTranslationEdit;
    QComboBox *ProjectionBox;
    QLabel *label;
    QComboBox *ResizePolicyBox;

    void setupUi(QWidget *CameraProperties)
    {
        if (CameraProperties->objectName().isEmpty())
            CameraProperties->setObjectName(QString::fromUtf8("CameraProperties"));
        CameraProperties->resize(556, 571);
        gridLayout = new QGridLayout(CameraProperties);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Line3_2 = new QFrame(CameraProperties);
        Line3_2->setObjectName(QString::fromUtf8("Line3_2"));
        Line3_2->setFrameShape(QFrame::HLine);
        Line3_2->setFrameShadow(QFrame::Sunken);
        Line3_2->setFrameShape(QFrame::HLine);

        gridLayout->addWidget(Line3_2, 7, 0, 1, 3);

        ZoomLabel = new QLabel(CameraProperties);
        ZoomLabel->setObjectName(QString::fromUtf8("ZoomLabel"));
        ZoomLabel->setWordWrap(false);

        gridLayout->addWidget(ZoomLabel, 0, 0, 1, 1);

        CenterLabel = new QLabel(CameraProperties);
        CenterLabel->setObjectName(QString::fromUtf8("CenterLabel"));
        CenterLabel->setWordWrap(false);

        gridLayout->addWidget(CenterLabel, 9, 0, 1, 1);

        NearEdit = new QLineEdit(CameraProperties);
        NearEdit->setObjectName(QString::fromUtf8("NearEdit"));
        NearEdit->setAlignment(Qt::AlignHCenter);

        gridLayout->addWidget(NearEdit, 5, 1, 1, 2);

        FarEdit = new QLineEdit(CameraProperties);
        FarEdit->setObjectName(QString::fromUtf8("FarEdit"));
        FarEdit->setAlignment(Qt::AlignHCenter);

        gridLayout->addWidget(FarEdit, 6, 1, 1, 2);

        EyeLabel2 = new QLabel(CameraProperties);
        EyeLabel2->setObjectName(QString::fromUtf8("EyeLabel2"));
        EyeLabel2->setWordWrap(false);

        gridLayout->addWidget(EyeLabel2, 8, 0, 1, 1);

        NearLabel = new QLabel(CameraProperties);
        NearLabel->setObjectName(QString::fromUtf8("NearLabel"));
        NearLabel->setWordWrap(false);

        gridLayout->addWidget(NearLabel, 5, 0, 1, 1);

        FarLabel = new QLabel(CameraProperties);
        FarLabel->setObjectName(QString::fromUtf8("FarLabel"));
        FarLabel->setWordWrap(false);

        gridLayout->addWidget(FarLabel, 6, 0, 1, 1);

        AngleLabel2 = new QLabel(CameraProperties);
        AngleLabel2->setObjectName(QString::fromUtf8("AngleLabel2"));
        AngleLabel2->setWordWrap(false);

        gridLayout->addWidget(AngleLabel2, 15, 0, 1, 1);

        DefaultAngleEdit = new QDoubleSpinBox(CameraProperties);
        DefaultAngleEdit->setObjectName(QString::fromUtf8("DefaultAngleEdit"));
        DefaultAngleEdit->setMinimum(1);
        DefaultAngleEdit->setMaximum(179);
        DefaultAngleEdit->setValue(30);

        gridLayout->addWidget(DefaultAngleEdit, 14, 1, 1, 2);

        CurrentAngleEdit = new QLineEdit(CameraProperties);
        CurrentAngleEdit->setObjectName(QString::fromUtf8("CurrentAngleEdit"));
        CurrentAngleEdit->setAlignment(Qt::AlignHCenter);

        gridLayout->addWidget(CurrentAngleEdit, 15, 1, 1, 2);

        ElevationEdit = new QLineEdit(CameraProperties);
        ElevationEdit->setObjectName(QString::fromUtf8("ElevationEdit"));
        ElevationEdit->setAlignment(Qt::AlignHCenter);

        gridLayout->addWidget(ElevationEdit, 2, 2, 1, 1);

        YTranslationEdit = new QLineEdit(CameraProperties);
        YTranslationEdit->setObjectName(QString::fromUtf8("YTranslationEdit"));
        YTranslationEdit->setAlignment(Qt::AlignHCenter);

        gridLayout->addWidget(YTranslationEdit, 1, 2, 1, 1);

        Translation = new QLabel(CameraProperties);
        Translation->setObjectName(QString::fromUtf8("Translation"));
        Translation->setWordWrap(false);

        gridLayout->addWidget(Translation, 1, 0, 1, 1);

        AzimuthLabel = new QLabel(CameraProperties);
        AzimuthLabel->setObjectName(QString::fromUtf8("AzimuthLabel"));
        AzimuthLabel->setWordWrap(false);

        gridLayout->addWidget(AzimuthLabel, 2, 0, 1, 1);

        CoordinatesBox = new QComboBox(CameraProperties);
        CoordinatesBox->setObjectName(QString::fromUtf8("CoordinatesBox"));

        gridLayout->addWidget(CoordinatesBox, 12, 1, 1, 2);

        systemLabel = new QLabel(CameraProperties);
        systemLabel->setObjectName(QString::fromUtf8("systemLabel"));
        systemLabel->setWordWrap(false);

        gridLayout->addWidget(systemLabel, 12, 0, 1, 1);

        PositionLabel = new QLabel(CameraProperties);
        PositionLabel->setObjectName(QString::fromUtf8("PositionLabel"));
        PositionLabel->setWordWrap(false);

        gridLayout->addWidget(PositionLabel, 3, 0, 1, 1);

        AzimuthEdit = new QLineEdit(CameraProperties);
        AzimuthEdit->setObjectName(QString::fromUtf8("AzimuthEdit"));
        AzimuthEdit->setAlignment(Qt::AlignHCenter);

        gridLayout->addWidget(AzimuthEdit, 2, 1, 1, 1);

        Line3 = new QFrame(CameraProperties);
        Line3->setObjectName(QString::fromUtf8("Line3"));
        Line3->setFrameShape(QFrame::HLine);
        Line3->setFrameShadow(QFrame::Sunken);
        Line3->setFrameShape(QFrame::HLine);

        gridLayout->addWidget(Line3, 4, 0, 1, 3);

        ProjectionLabel2 = new QLabel(CameraProperties);
        ProjectionLabel2->setObjectName(QString::fromUtf8("ProjectionLabel2"));
        ProjectionLabel2->setWordWrap(false);

        gridLayout->addWidget(ProjectionLabel2, 11, 0, 1, 1);

        PositionEdit = new QLineEdit(CameraProperties);
        PositionEdit->setObjectName(QString::fromUtf8("PositionEdit"));
        PositionEdit->setAcceptDrops(false);
        PositionEdit->setAlignment(Qt::AlignHCenter);

        gridLayout->addWidget(PositionEdit, 3, 1, 1, 2);

        Line3_2_2 = new QFrame(CameraProperties);
        Line3_2_2->setObjectName(QString::fromUtf8("Line3_2_2"));
        Line3_2_2->setFrameShape(QFrame::HLine);
        Line3_2_2->setFrameShadow(QFrame::Sunken);
        Line3_2_2->setFrameShape(QFrame::HLine);

        gridLayout->addWidget(Line3_2_2, 10, 0, 1, 3);

        ZoomEdit = new QLineEdit(CameraProperties);
        ZoomEdit->setObjectName(QString::fromUtf8("ZoomEdit"));
        ZoomEdit->setAcceptDrops(false);
        ZoomEdit->setAlignment(Qt::AlignHCenter);

        gridLayout->addWidget(ZoomEdit, 0, 1, 1, 2);

        AngleLabel = new QLabel(CameraProperties);
        AngleLabel->setObjectName(QString::fromUtf8("AngleLabel"));
        AngleLabel->setWordWrap(false);

        gridLayout->addWidget(AngleLabel, 14, 0, 1, 1);

        CenterEdit = new QLineEdit(CameraProperties);
        CenterEdit->setObjectName(QString::fromUtf8("CenterEdit"));
        CenterEdit->setAlignment(Qt::AlignHCenter);

        gridLayout->addWidget(CenterEdit, 9, 1, 1, 2);

        EyeEdit = new QLineEdit(CameraProperties);
        EyeEdit->setObjectName(QString::fromUtf8("EyeEdit"));
        EyeEdit->setAlignment(Qt::AlignHCenter);

        gridLayout->addWidget(EyeEdit, 8, 1, 1, 2);

        XTranslationEdit = new QLineEdit(CameraProperties);
        XTranslationEdit->setObjectName(QString::fromUtf8("XTranslationEdit"));
        XTranslationEdit->setAlignment(Qt::AlignHCenter);

        gridLayout->addWidget(XTranslationEdit, 1, 1, 1, 1);

        ProjectionBox = new QComboBox(CameraProperties);
        ProjectionBox->setObjectName(QString::fromUtf8("ProjectionBox"));

        gridLayout->addWidget(ProjectionBox, 11, 1, 1, 2);

        label = new QLabel(CameraProperties);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 13, 0, 1, 1);

        ResizePolicyBox = new QComboBox(CameraProperties);
        ResizePolicyBox->setObjectName(QString::fromUtf8("ResizePolicyBox"));

        gridLayout->addWidget(ResizePolicyBox, 13, 1, 1, 2);


        retranslateUi(CameraProperties);

        QMetaObject::connectSlotsByName(CameraProperties);
    } // setupUi

    void retranslateUi(QWidget *CameraProperties)
    {
        CameraProperties->setWindowTitle(QApplication::translate("CameraProperties", "Camera", 0, QApplication::UnicodeUTF8));
        ZoomLabel->setText(QApplication::translate("CameraProperties", "Zoom", 0, QApplication::UnicodeUTF8));
        CenterLabel->setText(QApplication::translate("CameraProperties", "Center", 0, QApplication::UnicodeUTF8));
        EyeLabel2->setText(QApplication::translate("CameraProperties", "Eye", 0, QApplication::UnicodeUTF8));
        NearLabel->setText(QApplication::translate("CameraProperties", "Near Plane", 0, QApplication::UnicodeUTF8));
        FarLabel->setText(QApplication::translate("CameraProperties", "Far Plane", 0, QApplication::UnicodeUTF8));
        AngleLabel2->setText(QApplication::translate("CameraProperties", "Current View Angle", 0, QApplication::UnicodeUTF8));
        Translation->setText(QApplication::translate("CameraProperties", "Translation", 0, QApplication::UnicodeUTF8));
        AzimuthLabel->setText(QApplication::translate("CameraProperties", "Azimuth - Elevation", 0, QApplication::UnicodeUTF8));
        CoordinatesBox->clear();
        CoordinatesBox->insertItems(0, QStringList()
         << QApplication::translate("CameraProperties", "GL", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CameraProperties", "GEOM", 0, QApplication::UnicodeUTF8)
        );
        systemLabel->setText(QApplication::translate("CameraProperties", "Coordinates System", 0, QApplication::UnicodeUTF8));
        PositionLabel->setText(QApplication::translate("CameraProperties", "Position", 0, QApplication::UnicodeUTF8));
        ProjectionLabel2->setText(QApplication::translate("CameraProperties", "Projection", 0, QApplication::UnicodeUTF8));
        AngleLabel->setText(QApplication::translate("CameraProperties", "Default View Angle", 0, QApplication::UnicodeUTF8));
        ProjectionBox->clear();
        ProjectionBox->insertItems(0, QStringList()
         << QApplication::translate("CameraProperties", "Orthographic", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CameraProperties", "Perspective", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QApplication::translate("CameraProperties", "Resize Policy", 0, QApplication::UnicodeUTF8));
        ResizePolicyBox->clear();
        ResizePolicyBox->insertItems(0, QStringList()
         << QApplication::translate("CameraProperties", "Maintain Object Size", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CameraProperties", "Use Default View Angle", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class CameraProperties: public Ui_CameraProperties {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CAMERAQT_H
