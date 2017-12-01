/********************************************************************************
** Form generated from reading UI file 'controlpanelwidget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CONTROLPANELWIDGET_H
#define CONTROLPANELWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QToolBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ViewControlPanelWidget
{
public:
    QGridLayout *gridLayout;
    QToolBox *toolBox;
    QWidget *page;
    QGridLayout *gridLayout1;
    QSpacerItem *spacerItem;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *__elevationLabel;
    QLabel *label;
    QDoubleSpinBox *__StepMove;
    QDoubleSpinBox *__zoomSpin;
    QDoubleSpinBox *__azimuthSpin;
    QDoubleSpinBox *__elevationSpin;
    QPushButton *__linkedZoom;
    QWidget *mLightPage;
    QVBoxLayout *vboxLayout;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout2;
    QLabel *label_10;
    QLabel *label_9;
    QLabel *label_8;
    QPushButton *__LightDiffuseButton;
    QPushButton *__LightSpecularButton;
    QPushButton *__LightAmbientButton;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout3;
    QLabel *label_7;
    QLabel *label_6;
    QLabel *label_5;
    QDoubleSpinBox *__LightDistance;
    QDoubleSpinBox *__lightAzimuthSpin;
    QDoubleSpinBox *__lightElevationSpin;
    QSpacerItem *spacerItem1;
    QWidget *page_2;
    QGridLayout *gridLayout4;
    QSpacerItem *spacerItem2;
    QLabel *label_11;
    QLabel *label_12;
    QSpinBox *__sizeGrid;
    QDoubleSpinBox *__unitGrid;
    QPushButton *mLogoButton;

    void setupUi(QWidget *ViewControlPanelWidget)
    {
        if (ViewControlPanelWidget->objectName().isEmpty())
            ViewControlPanelWidget->setObjectName(QString::fromUtf8("ViewControlPanelWidget"));
        ViewControlPanelWidget->resize(139, 363);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ViewControlPanelWidget->sizePolicy().hasHeightForWidth());
        ViewControlPanelWidget->setSizePolicy(sizePolicy);
        ViewControlPanelWidget->setAutoFillBackground(true);
        gridLayout = new QGridLayout(ViewControlPanelWidget);
        gridLayout->setSpacing(4);
        gridLayout->setContentsMargins(2, 2, 2, 2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        toolBox = new QToolBox(ViewControlPanelWidget);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        sizePolicy.setHeightForWidth(toolBox->sizePolicy().hasHeightForWidth());
        toolBox->setSizePolicy(sizePolicy);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 135, 251));
        gridLayout1 = new QGridLayout(page);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        gridLayout1->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout1->setHorizontalSpacing(4);
        gridLayout1->setVerticalSpacing(6);
        gridLayout1->setContentsMargins(0, 9, 0, 9);
        spacerItem = new QSpacerItem(20, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout1->addItem(spacerItem, 4, 1, 1, 1);

        label_4 = new QLabel(page);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout1->addWidget(label_4, 3, 2, 1, 1);

        label_3 = new QLabel(page);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout1->addWidget(label_3, 2, 2, 1, 1);

        __elevationLabel = new QLabel(page);
        __elevationLabel->setObjectName(QString::fromUtf8("__elevationLabel"));

        gridLayout1->addWidget(__elevationLabel, 0, 2, 1, 1);

        label = new QLabel(page);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout1->addWidget(label, 1, 2, 1, 1);

        __StepMove = new QDoubleSpinBox(page);
        __StepMove->setObjectName(QString::fromUtf8("__StepMove"));
        __StepMove->setSingleStep(0.01);

        gridLayout1->addWidget(__StepMove, 3, 1, 1, 1);

        __zoomSpin = new QDoubleSpinBox(page);
        __zoomSpin->setObjectName(QString::fromUtf8("__zoomSpin"));
        __zoomSpin->setSingleStep(0.01);

        gridLayout1->addWidget(__zoomSpin, 2, 1, 1, 1);

        __azimuthSpin = new QDoubleSpinBox(page);
        __azimuthSpin->setObjectName(QString::fromUtf8("__azimuthSpin"));
        __azimuthSpin->setMinimum(-179.99);
        __azimuthSpin->setMaximum(180);
        __azimuthSpin->setSingleStep(0.01);

        gridLayout1->addWidget(__azimuthSpin, 1, 1, 1, 1);

        __elevationSpin = new QDoubleSpinBox(page);
        __elevationSpin->setObjectName(QString::fromUtf8("__elevationSpin"));
        __elevationSpin->setMinimum(-179.99);
        __elevationSpin->setMaximum(180);
        __elevationSpin->setSingleStep(0.01);

        gridLayout1->addWidget(__elevationSpin, 0, 1, 1, 1);

        __linkedZoom = new QPushButton(page);
        __linkedZoom->setObjectName(QString::fromUtf8("__linkedZoom"));
        __linkedZoom->setMaximumSize(QSize(20, 16777215));
        __linkedZoom->setIconSize(QSize(10, 16));
        __linkedZoom->setFlat(true);

        gridLayout1->addWidget(__linkedZoom, 2, 0, 1, 1);

        toolBox->addItem(page, QString::fromUtf8("Camera"));
        mLightPage = new QWidget();
        mLightPage->setObjectName(QString::fromUtf8("mLightPage"));
        mLightPage->setGeometry(QRect(0, 0, 135, 251));
        vboxLayout = new QVBoxLayout(mLightPage);
        vboxLayout->setSpacing(4);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        vboxLayout->setContentsMargins(0, 9, 0, 9);
        groupBox_3 = new QGroupBox(mLightPage);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout2 = new QGridLayout(groupBox_3);
        gridLayout2->setSpacing(5);
        gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
        gridLayout2->setContentsMargins(5, 5, 0, 5);
        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout2->addWidget(label_10, 2, 1, 1, 1);

        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout2->addWidget(label_9, 1, 1, 1, 1);

        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout2->addWidget(label_8, 0, 1, 1, 1);

        __LightDiffuseButton = new QPushButton(groupBox_3);
        __LightDiffuseButton->setObjectName(QString::fromUtf8("__LightDiffuseButton"));

        gridLayout2->addWidget(__LightDiffuseButton, 1, 0, 1, 1);

        __LightSpecularButton = new QPushButton(groupBox_3);
        __LightSpecularButton->setObjectName(QString::fromUtf8("__LightSpecularButton"));

        gridLayout2->addWidget(__LightSpecularButton, 2, 0, 1, 1);

        __LightAmbientButton = new QPushButton(groupBox_3);
        __LightAmbientButton->setObjectName(QString::fromUtf8("__LightAmbientButton"));

        gridLayout2->addWidget(__LightAmbientButton, 0, 0, 1, 1);


        vboxLayout->addWidget(groupBox_3);

        groupBox_2 = new QGroupBox(mLightPage);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout3 = new QGridLayout(groupBox_2);
        gridLayout3->setSpacing(5);
        gridLayout3->setObjectName(QString::fromUtf8("gridLayout3"));
        gridLayout3->setContentsMargins(5, 5, 0, 5);
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout3->addWidget(label_7, 2, 1, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout3->addWidget(label_6, 1, 1, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout3->addWidget(label_5, 0, 1, 1, 1);

        __LightDistance = new QDoubleSpinBox(groupBox_2);
        __LightDistance->setObjectName(QString::fromUtf8("__LightDistance"));
        __LightDistance->setSingleStep(0.01);

        gridLayout3->addWidget(__LightDistance, 2, 0, 1, 1);

        __lightAzimuthSpin = new QDoubleSpinBox(groupBox_2);
        __lightAzimuthSpin->setObjectName(QString::fromUtf8("__lightAzimuthSpin"));
        __lightAzimuthSpin->setMinimum(-179.99);
        __lightAzimuthSpin->setMaximum(180);
        __lightAzimuthSpin->setSingleStep(0.01);

        gridLayout3->addWidget(__lightAzimuthSpin, 1, 0, 1, 1);

        __lightElevationSpin = new QDoubleSpinBox(groupBox_2);
        __lightElevationSpin->setObjectName(QString::fromUtf8("__lightElevationSpin"));
        __lightElevationSpin->setMinimum(-179.99);
        __lightElevationSpin->setMaximum(180);
        __lightElevationSpin->setSingleStep(0.01);

        gridLayout3->addWidget(__lightElevationSpin, 0, 0, 1, 1);


        vboxLayout->addWidget(groupBox_2);

        spacerItem1 = new QSpacerItem(20, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout->addItem(spacerItem1);

        toolBox->addItem(mLightPage, QString::fromUtf8("Light"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 135, 251));
        gridLayout4 = new QGridLayout(page_2);
#ifndef Q_OS_MAC
        gridLayout4->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout4->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout4->setObjectName(QString::fromUtf8("gridLayout4"));
        spacerItem2 = new QSpacerItem(20, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout4->addItem(spacerItem2, 2, 0, 1, 1);

        label_11 = new QLabel(page_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout4->addWidget(label_11, 0, 1, 1, 1);

        label_12 = new QLabel(page_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout4->addWidget(label_12, 1, 1, 1, 1);

        __sizeGrid = new QSpinBox(page_2);
        __sizeGrid->setObjectName(QString::fromUtf8("__sizeGrid"));

        gridLayout4->addWidget(__sizeGrid, 1, 0, 1, 1);

        __unitGrid = new QDoubleSpinBox(page_2);
        __unitGrid->setObjectName(QString::fromUtf8("__unitGrid"));
        __unitGrid->setMinimum(0.01);
        __unitGrid->setSingleStep(0.01);

        gridLayout4->addWidget(__unitGrid, 0, 0, 1, 1);

        toolBox->addItem(page_2, QString::fromUtf8("Grids"));

        gridLayout->addWidget(toolBox, 1, 0, 1, 1);

        mLogoButton = new QPushButton(ViewControlPanelWidget);
        mLogoButton->setObjectName(QString::fromUtf8("mLogoButton"));
        mLogoButton->setFlat(true);

        gridLayout->addWidget(mLogoButton, 0, 0, 1, 1);


        retranslateUi(ViewControlPanelWidget);

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ViewControlPanelWidget);
    } // setupUi

    void retranslateUi(QWidget *ViewControlPanelWidget)
    {
        label_4->setText(QApplication::translate("ViewControlPanelWidget", "Move", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ViewControlPanelWidget", "Zoom", 0, QApplication::UnicodeUTF8));
        __elevationLabel->setText(QApplication::translate("ViewControlPanelWidget", "Elevation", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ViewControlPanelWidget", "Azimut", 0, QApplication::UnicodeUTF8));
        __linkedZoom->setText(QString());
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("ViewControlPanelWidget", "Camera", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("ViewControlPanelWidget", "Material", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("ViewControlPanelWidget", "Specular", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("ViewControlPanelWidget", "Diffuse", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("ViewControlPanelWidget", "Ambient", 0, QApplication::UnicodeUTF8));
        __LightDiffuseButton->setText(QString());
        __LightSpecularButton->setText(QString());
        __LightAmbientButton->setText(QString());
        groupBox_2->setTitle(QApplication::translate("ViewControlPanelWidget", "Position", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("ViewControlPanelWidget", "Distance", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("ViewControlPanelWidget", "Azimut", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ViewControlPanelWidget", "Elevation", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(mLightPage), QApplication::translate("ViewControlPanelWidget", "Light", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("ViewControlPanelWidget", "Unit", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("ViewControlPanelWidget", "Size", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("ViewControlPanelWidget", "Grids", 0, QApplication::UnicodeUTF8));
        mLogoButton->setText(QString());
        Q_UNUSED(ViewControlPanelWidget);
    } // retranslateUi

};

namespace Ui {
    class ViewControlPanelWidget: public Ui_ViewControlPanelWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CONTROLPANELWIDGET_H
