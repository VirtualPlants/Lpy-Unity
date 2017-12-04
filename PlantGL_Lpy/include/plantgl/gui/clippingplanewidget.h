/********************************************************************************
** Form generated from reading UI file 'clippingplanewidget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CLIPPINGPLANEWIDGET_H
#define CLIPPINGPLANEWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClippingPlaneWidget
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *CPLabel;
    QSpacerItem *horizontalSpacer_3;
    QLabel *ALabel;
    QLabel *BLabel;
    QLabel *CLabel;
    QLabel *DLabel;
    QLabel *Plane1Label;
    QCheckBox *Enable1;
    QDoubleSpinBox *A1;
    QDoubleSpinBox *B1;
    QDoubleSpinBox *C1;
    QDoubleSpinBox *D1;
    QLabel *Plane2Label;
    QFrame *Line2;
    QDoubleSpinBox *A2;
    QDoubleSpinBox *B2;
    QDoubleSpinBox *C2;
    QDoubleSpinBox *D2;
    QCheckBox *Enable2;
    QLabel *Plane3Label;
    QFrame *Line3;
    QDoubleSpinBox *A3;
    QDoubleSpinBox *B3;
    QDoubleSpinBox *C3;
    QDoubleSpinBox *D3;
    QCheckBox *Enable3;
    QLabel *Plane4Label;
    QFrame *Line4;
    QDoubleSpinBox *A4;
    QDoubleSpinBox *B4;
    QDoubleSpinBox *C4;
    QDoubleSpinBox *D4;
    QCheckBox *Enable4;
    QLabel *Plane5Label;
    QFrame *Line5;
    QDoubleSpinBox *A5;
    QDoubleSpinBox *B5;
    QDoubleSpinBox *C5;
    QDoubleSpinBox *D5;
    QCheckBox *Enable5;
    QLabel *Plane1Label_6;
    QFrame *Line6;
    QDoubleSpinBox *A6;
    QDoubleSpinBox *B6;
    QDoubleSpinBox *C6;
    QDoubleSpinBox *D6;
    QCheckBox *Enable6;
    QSpacerItem *horizontalSpacer;
    QPushButton *OkButton;

    void setupUi(QWidget *ClippingPlaneWidget)
    {
        if (ClippingPlaneWidget->objectName().isEmpty())
            ClippingPlaneWidget->setObjectName(QString::fromUtf8("ClippingPlaneWidget"));
        ClippingPlaneWidget->resize(430, 308);
        gridLayout = new QGridLayout(ClippingPlaneWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer_2 = new QSpacerItem(110, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 0, 1, 2);

        CPLabel = new QLabel(ClippingPlaneWidget);
        CPLabel->setObjectName(QString::fromUtf8("CPLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("adobe-courier"));
        font.setPointSize(16);
        CPLabel->setFont(font);
        CPLabel->setWordWrap(false);

        gridLayout->addWidget(CPLabel, 0, 2, 1, 3);

        horizontalSpacer_3 = new QSpacerItem(85, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 5, 1, 2);

        ALabel = new QLabel(ClippingPlaneWidget);
        ALabel->setObjectName(QString::fromUtf8("ALabel"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("adobe-courier"));
        font1.setPointSize(14);
        ALabel->setFont(font1);
        ALabel->setWordWrap(false);

        gridLayout->addWidget(ALabel, 1, 2, 1, 1);

        BLabel = new QLabel(ClippingPlaneWidget);
        BLabel->setObjectName(QString::fromUtf8("BLabel"));
        BLabel->setFont(font1);
        BLabel->setWordWrap(false);

        gridLayout->addWidget(BLabel, 1, 3, 1, 1);

        CLabel = new QLabel(ClippingPlaneWidget);
        CLabel->setObjectName(QString::fromUtf8("CLabel"));
        CLabel->setFont(font1);
        CLabel->setWordWrap(false);

        gridLayout->addWidget(CLabel, 1, 4, 1, 1);

        DLabel = new QLabel(ClippingPlaneWidget);
        DLabel->setObjectName(QString::fromUtf8("DLabel"));
        DLabel->setFont(font1);
        DLabel->setWordWrap(false);

        gridLayout->addWidget(DLabel, 1, 6, 1, 1);

        Plane1Label = new QLabel(ClippingPlaneWidget);
        Plane1Label->setObjectName(QString::fromUtf8("Plane1Label"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("adobe-courier"));
        font2.setPointSize(12);
        Plane1Label->setFont(font2);
        Plane1Label->setWordWrap(false);

        gridLayout->addWidget(Plane1Label, 2, 0, 1, 1);

        Enable1 = new QCheckBox(ClippingPlaneWidget);
        Enable1->setObjectName(QString::fromUtf8("Enable1"));

        gridLayout->addWidget(Enable1, 2, 1, 1, 1);

        A1 = new QDoubleSpinBox(ClippingPlaneWidget);
        A1->setObjectName(QString::fromUtf8("A1"));
        A1->setMinimum(-1.67772e+07);
        A1->setMaximum(1.67772e+07);

        gridLayout->addWidget(A1, 2, 2, 1, 1);

        B1 = new QDoubleSpinBox(ClippingPlaneWidget);
        B1->setObjectName(QString::fromUtf8("B1"));

        gridLayout->addWidget(B1, 2, 3, 1, 1);

        C1 = new QDoubleSpinBox(ClippingPlaneWidget);
        C1->setObjectName(QString::fromUtf8("C1"));

        gridLayout->addWidget(C1, 2, 4, 1, 1);

        D1 = new QDoubleSpinBox(ClippingPlaneWidget);
        D1->setObjectName(QString::fromUtf8("D1"));

        gridLayout->addWidget(D1, 2, 6, 1, 1);

        Plane2Label = new QLabel(ClippingPlaneWidget);
        Plane2Label->setObjectName(QString::fromUtf8("Plane2Label"));
        Plane2Label->setFont(font2);
        Plane2Label->setWordWrap(false);

        gridLayout->addWidget(Plane2Label, 3, 0, 3, 1);

        Line2 = new QFrame(ClippingPlaneWidget);
        Line2->setObjectName(QString::fromUtf8("Line2"));
        Line2->setFrameShape(QFrame::HLine);
        Line2->setFrameShadow(QFrame::Sunken);
        Line2->setFrameShape(QFrame::HLine);

        gridLayout->addWidget(Line2, 3, 1, 2, 5);

        A2 = new QDoubleSpinBox(ClippingPlaneWidget);
        A2->setObjectName(QString::fromUtf8("A2"));

        gridLayout->addWidget(A2, 4, 2, 2, 1);

        B2 = new QDoubleSpinBox(ClippingPlaneWidget);
        B2->setObjectName(QString::fromUtf8("B2"));

        gridLayout->addWidget(B2, 4, 3, 2, 1);

        C2 = new QDoubleSpinBox(ClippingPlaneWidget);
        C2->setObjectName(QString::fromUtf8("C2"));

        gridLayout->addWidget(C2, 4, 4, 2, 1);

        D2 = new QDoubleSpinBox(ClippingPlaneWidget);
        D2->setObjectName(QString::fromUtf8("D2"));

        gridLayout->addWidget(D2, 4, 6, 2, 1);

        Enable2 = new QCheckBox(ClippingPlaneWidget);
        Enable2->setObjectName(QString::fromUtf8("Enable2"));

        gridLayout->addWidget(Enable2, 5, 1, 1, 1);

        Plane3Label = new QLabel(ClippingPlaneWidget);
        Plane3Label->setObjectName(QString::fromUtf8("Plane3Label"));
        Plane3Label->setFont(font2);
        Plane3Label->setWordWrap(false);

        gridLayout->addWidget(Plane3Label, 6, 0, 3, 1);

        Line3 = new QFrame(ClippingPlaneWidget);
        Line3->setObjectName(QString::fromUtf8("Line3"));
        Line3->setFrameShape(QFrame::HLine);
        Line3->setFrameShadow(QFrame::Sunken);
        Line3->setFrameShape(QFrame::HLine);

        gridLayout->addWidget(Line3, 6, 1, 2, 5);

        A3 = new QDoubleSpinBox(ClippingPlaneWidget);
        A3->setObjectName(QString::fromUtf8("A3"));

        gridLayout->addWidget(A3, 7, 2, 2, 1);

        B3 = new QDoubleSpinBox(ClippingPlaneWidget);
        B3->setObjectName(QString::fromUtf8("B3"));

        gridLayout->addWidget(B3, 7, 3, 2, 1);

        C3 = new QDoubleSpinBox(ClippingPlaneWidget);
        C3->setObjectName(QString::fromUtf8("C3"));

        gridLayout->addWidget(C3, 7, 4, 2, 1);

        D3 = new QDoubleSpinBox(ClippingPlaneWidget);
        D3->setObjectName(QString::fromUtf8("D3"));

        gridLayout->addWidget(D3, 7, 6, 2, 1);

        Enable3 = new QCheckBox(ClippingPlaneWidget);
        Enable3->setObjectName(QString::fromUtf8("Enable3"));

        gridLayout->addWidget(Enable3, 8, 1, 1, 1);

        Plane4Label = new QLabel(ClippingPlaneWidget);
        Plane4Label->setObjectName(QString::fromUtf8("Plane4Label"));
        Plane4Label->setFont(font2);
        Plane4Label->setWordWrap(false);

        gridLayout->addWidget(Plane4Label, 9, 0, 3, 1);

        Line4 = new QFrame(ClippingPlaneWidget);
        Line4->setObjectName(QString::fromUtf8("Line4"));
        Line4->setFrameShape(QFrame::HLine);
        Line4->setFrameShadow(QFrame::Sunken);
        Line4->setFrameShape(QFrame::HLine);

        gridLayout->addWidget(Line4, 9, 1, 2, 5);

        A4 = new QDoubleSpinBox(ClippingPlaneWidget);
        A4->setObjectName(QString::fromUtf8("A4"));

        gridLayout->addWidget(A4, 10, 2, 2, 1);

        B4 = new QDoubleSpinBox(ClippingPlaneWidget);
        B4->setObjectName(QString::fromUtf8("B4"));

        gridLayout->addWidget(B4, 10, 3, 2, 1);

        C4 = new QDoubleSpinBox(ClippingPlaneWidget);
        C4->setObjectName(QString::fromUtf8("C4"));

        gridLayout->addWidget(C4, 10, 4, 2, 1);

        D4 = new QDoubleSpinBox(ClippingPlaneWidget);
        D4->setObjectName(QString::fromUtf8("D4"));

        gridLayout->addWidget(D4, 10, 6, 2, 1);

        Enable4 = new QCheckBox(ClippingPlaneWidget);
        Enable4->setObjectName(QString::fromUtf8("Enable4"));

        gridLayout->addWidget(Enable4, 11, 1, 1, 1);

        Plane5Label = new QLabel(ClippingPlaneWidget);
        Plane5Label->setObjectName(QString::fromUtf8("Plane5Label"));
        Plane5Label->setFont(font2);
        Plane5Label->setWordWrap(false);

        gridLayout->addWidget(Plane5Label, 12, 0, 3, 1);

        Line5 = new QFrame(ClippingPlaneWidget);
        Line5->setObjectName(QString::fromUtf8("Line5"));
        Line5->setFrameShape(QFrame::HLine);
        Line5->setFrameShadow(QFrame::Sunken);
        Line5->setFrameShape(QFrame::HLine);

        gridLayout->addWidget(Line5, 12, 1, 2, 5);

        A5 = new QDoubleSpinBox(ClippingPlaneWidget);
        A5->setObjectName(QString::fromUtf8("A5"));

        gridLayout->addWidget(A5, 13, 2, 2, 1);

        B5 = new QDoubleSpinBox(ClippingPlaneWidget);
        B5->setObjectName(QString::fromUtf8("B5"));

        gridLayout->addWidget(B5, 13, 3, 2, 1);

        C5 = new QDoubleSpinBox(ClippingPlaneWidget);
        C5->setObjectName(QString::fromUtf8("C5"));

        gridLayout->addWidget(C5, 13, 4, 2, 1);

        D5 = new QDoubleSpinBox(ClippingPlaneWidget);
        D5->setObjectName(QString::fromUtf8("D5"));

        gridLayout->addWidget(D5, 13, 6, 2, 1);

        Enable5 = new QCheckBox(ClippingPlaneWidget);
        Enable5->setObjectName(QString::fromUtf8("Enable5"));

        gridLayout->addWidget(Enable5, 14, 1, 1, 1);

        Plane1Label_6 = new QLabel(ClippingPlaneWidget);
        Plane1Label_6->setObjectName(QString::fromUtf8("Plane1Label_6"));
        Plane1Label_6->setFont(font2);
        Plane1Label_6->setWordWrap(false);

        gridLayout->addWidget(Plane1Label_6, 15, 0, 3, 1);

        Line6 = new QFrame(ClippingPlaneWidget);
        Line6->setObjectName(QString::fromUtf8("Line6"));
        Line6->setFrameShape(QFrame::HLine);
        Line6->setFrameShadow(QFrame::Sunken);
        Line6->setFrameShape(QFrame::HLine);

        gridLayout->addWidget(Line6, 15, 1, 2, 5);

        A6 = new QDoubleSpinBox(ClippingPlaneWidget);
        A6->setObjectName(QString::fromUtf8("A6"));

        gridLayout->addWidget(A6, 16, 2, 2, 1);

        B6 = new QDoubleSpinBox(ClippingPlaneWidget);
        B6->setObjectName(QString::fromUtf8("B6"));

        gridLayout->addWidget(B6, 16, 3, 2, 1);

        C6 = new QDoubleSpinBox(ClippingPlaneWidget);
        C6->setObjectName(QString::fromUtf8("C6"));

        gridLayout->addWidget(C6, 16, 4, 2, 1);

        D6 = new QDoubleSpinBox(ClippingPlaneWidget);
        D6->setObjectName(QString::fromUtf8("D6"));

        gridLayout->addWidget(D6, 16, 6, 2, 1);

        Enable6 = new QCheckBox(ClippingPlaneWidget);
        Enable6->setObjectName(QString::fromUtf8("Enable6"));

        gridLayout->addWidget(Enable6, 17, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(328, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 18, 0, 1, 6);

        OkButton = new QPushButton(ClippingPlaneWidget);
        OkButton->setObjectName(QString::fromUtf8("OkButton"));

        gridLayout->addWidget(OkButton, 18, 6, 1, 1);


        retranslateUi(ClippingPlaneWidget);

        QMetaObject::connectSlotsByName(ClippingPlaneWidget);
    } // setupUi

    void retranslateUi(QWidget *ClippingPlaneWidget)
    {
        ClippingPlaneWidget->setWindowTitle(QApplication::translate("ClippingPlaneWidget", "Form1", 0, QApplication::UnicodeUTF8));
        CPLabel->setText(QApplication::translate("ClippingPlaneWidget", "Clipping Planes", 0, QApplication::UnicodeUTF8));
        ALabel->setText(QApplication::translate("ClippingPlaneWidget", "A", 0, QApplication::UnicodeUTF8));
        BLabel->setText(QApplication::translate("ClippingPlaneWidget", "B", 0, QApplication::UnicodeUTF8));
        CLabel->setText(QApplication::translate("ClippingPlaneWidget", "C", 0, QApplication::UnicodeUTF8));
        DLabel->setText(QApplication::translate("ClippingPlaneWidget", "D", 0, QApplication::UnicodeUTF8));
        Plane1Label->setText(QApplication::translate("ClippingPlaneWidget", "Plane 1", 0, QApplication::UnicodeUTF8));
        Enable1->setText(QApplication::translate("ClippingPlaneWidget", "Enable", 0, QApplication::UnicodeUTF8));
        Plane2Label->setText(QApplication::translate("ClippingPlaneWidget", "Plane 2", 0, QApplication::UnicodeUTF8));
        Enable2->setText(QApplication::translate("ClippingPlaneWidget", "Enable", 0, QApplication::UnicodeUTF8));
        Plane3Label->setText(QApplication::translate("ClippingPlaneWidget", "Plane 3", 0, QApplication::UnicodeUTF8));
        Enable3->setText(QApplication::translate("ClippingPlaneWidget", "Enable", 0, QApplication::UnicodeUTF8));
        Plane4Label->setText(QApplication::translate("ClippingPlaneWidget", "Plane 4", 0, QApplication::UnicodeUTF8));
        Enable4->setWindowTitle(QString());
        Enable4->setText(QApplication::translate("ClippingPlaneWidget", "Enable", 0, QApplication::UnicodeUTF8));
        Plane5Label->setText(QApplication::translate("ClippingPlaneWidget", "Plane 5", 0, QApplication::UnicodeUTF8));
        Enable5->setText(QApplication::translate("ClippingPlaneWidget", "Enable", 0, QApplication::UnicodeUTF8));
        Plane1Label_6->setText(QApplication::translate("ClippingPlaneWidget", "Plane 6", 0, QApplication::UnicodeUTF8));
        Enable6->setText(QApplication::translate("ClippingPlaneWidget", "Enable", 0, QApplication::UnicodeUTF8));
        OkButton->setText(QApplication::translate("ClippingPlaneWidget", "&Ok", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ClippingPlaneWidget: public Ui_ClippingPlaneWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CLIPPINGPLANEWIDGET_H
