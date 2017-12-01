/********************************************************************************
** Form generated from reading UI file 'rotcenteredit.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef ROTCENTEREDIT_H
#define ROTCENTEREDIT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RotCenterEdit
{
public:
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QSlider *XSlider;
    QDoubleSpinBox *XEdit;
    QLabel *XLabel;
    QHBoxLayout *hboxLayout1;
    QSlider *YSlider;
    QDoubleSpinBox *YEdit;
    QLabel *YLabel;
    QHBoxLayout *hboxLayout2;
    QSlider *ZSlider;
    QDoubleSpinBox *ZEdit;
    QLabel *ZLabel;
    QHBoxLayout *hboxLayout3;
    QSpacerItem *spacerItem;
    QHBoxLayout *hboxLayout4;
    QPushButton *ClearButton;
    QPushButton *CancelButton;
    QPushButton *OkButton;

    void setupUi(QWidget *RotCenterEdit)
    {
        if (RotCenterEdit->objectName().isEmpty())
            RotCenterEdit->setObjectName(QString::fromUtf8("RotCenterEdit"));
        RotCenterEdit->resize(487, 145);
        vboxLayout = new QVBoxLayout(RotCenterEdit);
#ifndef Q_OS_MAC
        vboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        vboxLayout->setContentsMargins(9, 9, 9, 9);
#endif
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        hboxLayout->setContentsMargins(0, 0, 0, 0);
#endif
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        XSlider = new QSlider(RotCenterEdit);
        XSlider->setObjectName(QString::fromUtf8("XSlider"));
        XSlider->setMinimum(-150);
        XSlider->setMaximum(150);
        XSlider->setOrientation(Qt::Horizontal);

        hboxLayout->addWidget(XSlider);

        XEdit = new QDoubleSpinBox(RotCenterEdit);
        XEdit->setObjectName(QString::fromUtf8("XEdit"));

        hboxLayout->addWidget(XEdit);

        XLabel = new QLabel(RotCenterEdit);
        XLabel->setObjectName(QString::fromUtf8("XLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("adobe-helvetica"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        XLabel->setFont(font);
        XLabel->setWordWrap(false);

        hboxLayout->addWidget(XLabel);


        vboxLayout->addLayout(hboxLayout);

        hboxLayout1 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout1->setSpacing(6);
#endif
        hboxLayout1->setContentsMargins(0, 0, 0, 0);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        YSlider = new QSlider(RotCenterEdit);
        YSlider->setObjectName(QString::fromUtf8("YSlider"));
        YSlider->setMinimum(-150);
        YSlider->setOrientation(Qt::Horizontal);

        hboxLayout1->addWidget(YSlider);

        YEdit = new QDoubleSpinBox(RotCenterEdit);
        YEdit->setObjectName(QString::fromUtf8("YEdit"));

        hboxLayout1->addWidget(YEdit);

        YLabel = new QLabel(RotCenterEdit);
        YLabel->setObjectName(QString::fromUtf8("YLabel"));
        YLabel->setFont(font);
        YLabel->setWordWrap(false);

        hboxLayout1->addWidget(YLabel);


        vboxLayout->addLayout(hboxLayout1);

        hboxLayout2 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout2->setSpacing(6);
#endif
        hboxLayout2->setContentsMargins(0, 0, 0, 0);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        ZSlider = new QSlider(RotCenterEdit);
        ZSlider->setObjectName(QString::fromUtf8("ZSlider"));
        ZSlider->setMinimum(-150);
        ZSlider->setMaximum(150);
        ZSlider->setPageStep(10);
        ZSlider->setOrientation(Qt::Horizontal);

        hboxLayout2->addWidget(ZSlider);

        ZEdit = new QDoubleSpinBox(RotCenterEdit);
        ZEdit->setObjectName(QString::fromUtf8("ZEdit"));

        hboxLayout2->addWidget(ZEdit);

        ZLabel = new QLabel(RotCenterEdit);
        ZLabel->setObjectName(QString::fromUtf8("ZLabel"));
        ZLabel->setFont(font);
        ZLabel->setWordWrap(false);

        hboxLayout2->addWidget(ZLabel);


        vboxLayout->addLayout(hboxLayout2);

        hboxLayout3 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout3->setSpacing(6);
#endif
        hboxLayout3->setContentsMargins(0, 0, 0, 0);
        hboxLayout3->setObjectName(QString::fromUtf8("hboxLayout3"));
        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout3->addItem(spacerItem);

        hboxLayout4 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout4->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        hboxLayout4->setContentsMargins(0, 0, 0, 0);
#endif
        hboxLayout4->setObjectName(QString::fromUtf8("hboxLayout4"));
        ClearButton = new QPushButton(RotCenterEdit);
        ClearButton->setObjectName(QString::fromUtf8("ClearButton"));

        hboxLayout4->addWidget(ClearButton);

        CancelButton = new QPushButton(RotCenterEdit);
        CancelButton->setObjectName(QString::fromUtf8("CancelButton"));

        hboxLayout4->addWidget(CancelButton);

        OkButton = new QPushButton(RotCenterEdit);
        OkButton->setObjectName(QString::fromUtf8("OkButton"));

        hboxLayout4->addWidget(OkButton);


        hboxLayout3->addLayout(hboxLayout4);


        vboxLayout->addLayout(hboxLayout3);


        retranslateUi(RotCenterEdit);

        QMetaObject::connectSlotsByName(RotCenterEdit);
    } // setupUi

    void retranslateUi(QWidget *RotCenterEdit)
    {
        RotCenterEdit->setWindowTitle(QApplication::translate("RotCenterEdit", "Form1", 0, QApplication::UnicodeUTF8));
        XLabel->setText(QApplication::translate("RotCenterEdit", "X", 0, QApplication::UnicodeUTF8));
        YLabel->setText(QApplication::translate("RotCenterEdit", "Y", 0, QApplication::UnicodeUTF8));
        ZLabel->setText(QApplication::translate("RotCenterEdit", "Z", 0, QApplication::UnicodeUTF8));
        ClearButton->setText(QApplication::translate("RotCenterEdit", "Cle&ar", 0, QApplication::UnicodeUTF8));
        CancelButton->setText(QApplication::translate("RotCenterEdit", "&Cancel", 0, QApplication::UnicodeUTF8));
        OkButton->setText(QApplication::translate("RotCenterEdit", "&Ok", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RotCenterEdit: public Ui_RotCenterEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // ROTCENTEREDIT_H
