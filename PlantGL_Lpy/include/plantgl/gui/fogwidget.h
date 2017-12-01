/********************************************************************************
** Form generated from reading UI file 'fogwidget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef FOGWIDGET_H
#define FOGWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FogWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *FogLabel;
    QLabel *ModeLabel;
    QComboBox *ModeCombo;
    QLabel *ColorLabel;
    QPushButton *ColorButton;
    QLabel *HintsLabel;
    QComboBox *HintsCombo;
    QLabel *DensityLabel;
    QSlider *DensitySlider;
    QLabel *StartLabel;
    QLineEdit *StartEdit;
    QLabel *EndLabel;
    QLineEdit *EndEdit;
    QPushButton *OkButton;

    void setupUi(QWidget *FogWidget)
    {
        if (FogWidget->objectName().isEmpty())
            FogWidget->setObjectName(QString::fromUtf8("FogWidget"));
        FogWidget->resize(441, 153);
        gridLayout = new QGridLayout(FogWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        FogLabel = new QLabel(FogWidget);
        FogLabel->setObjectName(QString::fromUtf8("FogLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("adobe-courier"));
        font.setPointSize(16);
        FogLabel->setFont(font);
        FogLabel->setWordWrap(false);

        gridLayout->addWidget(FogLabel, 0, 1, 1, 1);

        ModeLabel = new QLabel(FogWidget);
        ModeLabel->setObjectName(QString::fromUtf8("ModeLabel"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("adobe-courier"));
        font1.setPointSize(10);
        ModeLabel->setFont(font1);
        ModeLabel->setWordWrap(false);

        gridLayout->addWidget(ModeLabel, 1, 0, 1, 1);

        ModeCombo = new QComboBox(FogWidget);
        ModeCombo->setObjectName(QString::fromUtf8("ModeCombo"));

        gridLayout->addWidget(ModeCombo, 1, 1, 1, 1);

        ColorLabel = new QLabel(FogWidget);
        ColorLabel->setObjectName(QString::fromUtf8("ColorLabel"));
        ColorLabel->setFont(font1);
        ColorLabel->setWordWrap(false);

        gridLayout->addWidget(ColorLabel, 1, 2, 1, 1);

        ColorButton = new QPushButton(FogWidget);
        ColorButton->setObjectName(QString::fromUtf8("ColorButton"));

        gridLayout->addWidget(ColorButton, 1, 3, 1, 1);

        HintsLabel = new QLabel(FogWidget);
        HintsLabel->setObjectName(QString::fromUtf8("HintsLabel"));
        HintsLabel->setFont(font1);
        HintsLabel->setWordWrap(false);

        gridLayout->addWidget(HintsLabel, 2, 0, 1, 1);

        HintsCombo = new QComboBox(FogWidget);
        HintsCombo->setObjectName(QString::fromUtf8("HintsCombo"));

        gridLayout->addWidget(HintsCombo, 2, 1, 1, 1);

        DensityLabel = new QLabel(FogWidget);
        DensityLabel->setObjectName(QString::fromUtf8("DensityLabel"));
        DensityLabel->setFont(font1);
        DensityLabel->setWordWrap(false);

        gridLayout->addWidget(DensityLabel, 2, 2, 1, 1);

        DensitySlider = new QSlider(FogWidget);
        DensitySlider->setObjectName(QString::fromUtf8("DensitySlider"));
        DensitySlider->setMinimum(1);
        DensitySlider->setMaximum(100);
        DensitySlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(DensitySlider, 2, 3, 1, 1);

        StartLabel = new QLabel(FogWidget);
        StartLabel->setObjectName(QString::fromUtf8("StartLabel"));
        StartLabel->setFont(font1);
        StartLabel->setWordWrap(false);

        gridLayout->addWidget(StartLabel, 3, 0, 1, 1);

        StartEdit = new QLineEdit(FogWidget);
        StartEdit->setObjectName(QString::fromUtf8("StartEdit"));

        gridLayout->addWidget(StartEdit, 3, 1, 1, 1);

        EndLabel = new QLabel(FogWidget);
        EndLabel->setObjectName(QString::fromUtf8("EndLabel"));
        EndLabel->setFont(font1);
        EndLabel->setWordWrap(false);

        gridLayout->addWidget(EndLabel, 3, 2, 1, 1);

        EndEdit = new QLineEdit(FogWidget);
        EndEdit->setObjectName(QString::fromUtf8("EndEdit"));

        gridLayout->addWidget(EndEdit, 3, 3, 1, 1);

        OkButton = new QPushButton(FogWidget);
        OkButton->setObjectName(QString::fromUtf8("OkButton"));

        gridLayout->addWidget(OkButton, 4, 3, 1, 1);


        retranslateUi(FogWidget);

        QMetaObject::connectSlotsByName(FogWidget);
    } // setupUi

    void retranslateUi(QWidget *FogWidget)
    {
        FogWidget->setWindowTitle(QApplication::translate("FogWidget", "Form1", 0, QApplication::UnicodeUTF8));
        FogLabel->setText(QApplication::translate("FogWidget", "Fog", 0, QApplication::UnicodeUTF8));
        ModeLabel->setText(QApplication::translate("FogWidget", "Mode", 0, QApplication::UnicodeUTF8));
        ModeCombo->clear();
        ModeCombo->insertItems(0, QStringList()
         << QApplication::translate("FogWidget", "GL_LINEAR", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FogWidget", "GL_EXP", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FogWidget", "GL_EXP2", 0, QApplication::UnicodeUTF8)
        );
        ColorLabel->setText(QApplication::translate("FogWidget", "Color", 0, QApplication::UnicodeUTF8));
        ColorButton->setText(QString());
        HintsLabel->setText(QApplication::translate("FogWidget", "Hints", 0, QApplication::UnicodeUTF8));
        HintsCombo->clear();
        HintsCombo->insertItems(0, QStringList()
         << QApplication::translate("FogWidget", "GL_DONT_CARE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FogWidget", "GL_FASTEST", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FogWidget", "GL_NICEST", 0, QApplication::UnicodeUTF8)
        );
        DensityLabel->setText(QApplication::translate("FogWidget", "Density", 0, QApplication::UnicodeUTF8));
        StartLabel->setText(QApplication::translate("FogWidget", "Start", 0, QApplication::UnicodeUTF8));
        EndLabel->setText(QApplication::translate("FogWidget", "End", 0, QApplication::UnicodeUTF8));
        OkButton->setText(QApplication::translate("FogWidget", "&Ok", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FogWidget: public Ui_FogWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // FOGWIDGET_H
