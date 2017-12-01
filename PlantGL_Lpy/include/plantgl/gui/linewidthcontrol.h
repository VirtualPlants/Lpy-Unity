/********************************************************************************
** Form generated from reading UI file 'linewidthcontrol.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef LINEWIDTHCONTROL_H
#define LINEWIDTHCONTROL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LineWidthControl
{
public:
    QHBoxLayout *hboxLayout;
    QLabel *label;
    QSlider *LineWidthSlider;
    QSpacerItem *spacerItem;

    void setupUi(QWidget *LineWidthControl)
    {
        if (LineWidthControl->objectName().isEmpty())
            LineWidthControl->setObjectName(QString::fromUtf8("LineWidthControl"));
        LineWidthControl->resize(166, 29);
        hboxLayout = new QHBoxLayout(LineWidthControl);
        hboxLayout->setSpacing(3);
        hboxLayout->setContentsMargins(2, 2, 2, 2);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        label = new QLabel(LineWidthControl);
        label->setObjectName(QString::fromUtf8("label"));

        hboxLayout->addWidget(label);

        LineWidthSlider = new QSlider(LineWidthControl);
        LineWidthSlider->setObjectName(QString::fromUtf8("LineWidthSlider"));
        LineWidthSlider->setMinimum(1);
        LineWidthSlider->setMaximum(30);
        LineWidthSlider->setOrientation(Qt::Horizontal);

        hboxLayout->addWidget(LineWidthSlider);

        spacerItem = new QSpacerItem(2, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);


        retranslateUi(LineWidthControl);

        QMetaObject::connectSlotsByName(LineWidthControl);
    } // setupUi

    void retranslateUi(QWidget *LineWidthControl)
    {
        LineWidthControl->setWindowTitle(QApplication::translate("LineWidthControl", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("LineWidthControl", "Line Width", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LineWidthControl: public Ui_LineWidthControl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // LINEWIDTHCONTROL_H
