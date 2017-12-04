/********************************************************************************
** Form generated from reading UI file 'gloptions.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef GLOPTIONS_H
#define GLOPTIONS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ViewGLOptionsForm
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *spacerItem;
    QGroupBox *OtherGroup;
    QVBoxLayout *verticalLayout;
    QRadioButton *DitheringButton;
    QRadioButton *DepthTestButton;
    QRadioButton *NormalizationButton;
    QRadioButton *OcclusionQueryButton;
    QRadioButton *PixelBufferButton;
    QRadioButton *TwoSideLightButton;
    QGroupBox *ShadeGroup;
    QVBoxLayout *vboxLayout;
    QRadioButton *SmoothButton;
    QRadioButton *FlatButton;
    QSpacerItem *spacerItem1;
    QGroupBox *CullFaceGroup;
    QVBoxLayout *vboxLayout1;
    QRadioButton *NoCullingButton;
    QRadioButton *BackFaceButton;
    QRadioButton *FrontFaceButton;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *FPSButton;

    void setupUi(QWidget *ViewGLOptionsForm)
    {
        if (ViewGLOptionsForm->objectName().isEmpty())
            ViewGLOptionsForm->setObjectName(QString::fromUtf8("ViewGLOptionsForm"));
        ViewGLOptionsForm->resize(349, 425);
        gridLayout = new QGridLayout(ViewGLOptionsForm);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        spacerItem = new QSpacerItem(138, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacerItem, 3, 1, 1, 2);

        OtherGroup = new QGroupBox(ViewGLOptionsForm);
        OtherGroup->setObjectName(QString::fromUtf8("OtherGroup"));
        OtherGroup->setFlat(false);
        OtherGroup->setCheckable(false);
        verticalLayout = new QVBoxLayout(OtherGroup);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        DitheringButton = new QRadioButton(OtherGroup);
        DitheringButton->setObjectName(QString::fromUtf8("DitheringButton"));
        DitheringButton->setAutoExclusive(false);

        verticalLayout->addWidget(DitheringButton);

        DepthTestButton = new QRadioButton(OtherGroup);
        DepthTestButton->setObjectName(QString::fromUtf8("DepthTestButton"));
        DepthTestButton->setAutoExclusive(false);

        verticalLayout->addWidget(DepthTestButton);

        NormalizationButton = new QRadioButton(OtherGroup);
        NormalizationButton->setObjectName(QString::fromUtf8("NormalizationButton"));
        NormalizationButton->setAutoExclusive(false);

        verticalLayout->addWidget(NormalizationButton);

        OcclusionQueryButton = new QRadioButton(OtherGroup);
        OcclusionQueryButton->setObjectName(QString::fromUtf8("OcclusionQueryButton"));
        OcclusionQueryButton->setAutoExclusive(false);

        verticalLayout->addWidget(OcclusionQueryButton);

        PixelBufferButton = new QRadioButton(OtherGroup);
        PixelBufferButton->setObjectName(QString::fromUtf8("PixelBufferButton"));
        PixelBufferButton->setAutoExclusive(false);

        verticalLayout->addWidget(PixelBufferButton);

        TwoSideLightButton = new QRadioButton(OtherGroup);
        TwoSideLightButton->setObjectName(QString::fromUtf8("TwoSideLightButton"));
        TwoSideLightButton->setAutoExclusive(false);

        verticalLayout->addWidget(TwoSideLightButton);


        gridLayout->addWidget(OtherGroup, 1, 1, 1, 2);

        ShadeGroup = new QGroupBox(ViewGLOptionsForm);
        ShadeGroup->setObjectName(QString::fromUtf8("ShadeGroup"));
        vboxLayout = new QVBoxLayout(ShadeGroup);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        SmoothButton = new QRadioButton(ShadeGroup);
        SmoothButton->setObjectName(QString::fromUtf8("SmoothButton"));

        vboxLayout->addWidget(SmoothButton);

        FlatButton = new QRadioButton(ShadeGroup);
        FlatButton->setObjectName(QString::fromUtf8("FlatButton"));

        vboxLayout->addWidget(FlatButton);

        spacerItem1 = new QSpacerItem(20, 2, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout->addItem(spacerItem1);


        gridLayout->addWidget(ShadeGroup, 0, 2, 1, 1);

        CullFaceGroup = new QGroupBox(ViewGLOptionsForm);
        CullFaceGroup->setObjectName(QString::fromUtf8("CullFaceGroup"));
        vboxLayout1 = new QVBoxLayout(CullFaceGroup);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        NoCullingButton = new QRadioButton(CullFaceGroup);
        NoCullingButton->setObjectName(QString::fromUtf8("NoCullingButton"));

        vboxLayout1->addWidget(NoCullingButton);

        BackFaceButton = new QRadioButton(CullFaceGroup);
        BackFaceButton->setObjectName(QString::fromUtf8("BackFaceButton"));

        vboxLayout1->addWidget(BackFaceButton);

        FrontFaceButton = new QRadioButton(CullFaceGroup);
        FrontFaceButton->setObjectName(QString::fromUtf8("FrontFaceButton"));

        vboxLayout1->addWidget(FrontFaceButton);


        gridLayout->addWidget(CullFaceGroup, 0, 1, 1, 1);

        groupBox = new QGroupBox(ViewGLOptionsForm);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        FPSButton = new QRadioButton(groupBox);
        FPSButton->setObjectName(QString::fromUtf8("FPSButton"));

        verticalLayout_2->addWidget(FPSButton);


        gridLayout->addWidget(groupBox, 2, 1, 1, 2);


        retranslateUi(ViewGLOptionsForm);

        QMetaObject::connectSlotsByName(ViewGLOptionsForm);
    } // setupUi

    void retranslateUi(QWidget *ViewGLOptionsForm)
    {
        ViewGLOptionsForm->setWindowTitle(QApplication::translate("ViewGLOptionsForm", "Form", 0, QApplication::UnicodeUTF8));
        OtherGroup->setTitle(QApplication::translate("ViewGLOptionsForm", "Other", 0, QApplication::UnicodeUTF8));
        DitheringButton->setText(QApplication::translate("ViewGLOptionsForm", "Color/Material Dithering", 0, QApplication::UnicodeUTF8));
        DepthTestButton->setText(QApplication::translate("ViewGLOptionsForm", "Hidden Surface Removal", 0, QApplication::UnicodeUTF8));
        NormalizationButton->setText(QApplication::translate("ViewGLOptionsForm", "Normals Normalization", 0, QApplication::UnicodeUTF8));
        OcclusionQueryButton->setText(QApplication::translate("ViewGLOptionsForm", "Use Occlusion Query", 0, QApplication::UnicodeUTF8));
        PixelBufferButton->setText(QApplication::translate("ViewGLOptionsForm", "Use Pixel Buffer", 0, QApplication::UnicodeUTF8));
        TwoSideLightButton->setText(QApplication::translate("ViewGLOptionsForm", "Two Side Lighting", 0, QApplication::UnicodeUTF8));
        ShadeGroup->setTitle(QApplication::translate("ViewGLOptionsForm", "Shade Model", 0, QApplication::UnicodeUTF8));
        SmoothButton->setText(QApplication::translate("ViewGLOptionsForm", "Smooth", 0, QApplication::UnicodeUTF8));
        FlatButton->setText(QApplication::translate("ViewGLOptionsForm", "Flat", 0, QApplication::UnicodeUTF8));
        CullFaceGroup->setTitle(QApplication::translate("ViewGLOptionsForm", "Culling", 0, QApplication::UnicodeUTF8));
        NoCullingButton->setText(QApplication::translate("ViewGLOptionsForm", "None", 0, QApplication::UnicodeUTF8));
        BackFaceButton->setText(QApplication::translate("ViewGLOptionsForm", "Back Face", 0, QApplication::UnicodeUTF8));
        FrontFaceButton->setText(QApplication::translate("ViewGLOptionsForm", "Front Face", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("ViewGLOptionsForm", "Display", 0, QApplication::UnicodeUTF8));
        FPSButton->setText(QApplication::translate("ViewGLOptionsForm", "FPS", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ViewGLOptionsForm: public Ui_ViewGLOptionsForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // GLOPTIONS_H
