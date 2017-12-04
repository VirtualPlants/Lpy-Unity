/********************************************************************************
** Form generated from reading UI file 'frameglsizedialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef FRAMEGLSIZEDIALOG_H
#define FRAMEGLSIZEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_FrameGLDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *textLabel2;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QSpinBox *width;
    QLabel *textLabel1;
    QSpinBox *height;
    QHBoxLayout *hboxLayout;
    QPushButton *buttonOk;
    QPushButton *buttonCancel;

    void setupUi(QDialog *FrameGLDialog)
    {
        if (FrameGLDialog->objectName().isEmpty())
            FrameGLDialog->setObjectName(QString::fromUtf8("FrameGLDialog"));
        FrameGLDialog->resize(220, 98);
        FrameGLDialog->setSizeGripEnabled(false);
        FrameGLDialog->setModal(true);
        gridLayout = new QGridLayout(FrameGLDialog);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textLabel2 = new QLabel(FrameGLDialog);
        textLabel2->setObjectName(QString::fromUtf8("textLabel2"));
        QFont font;
        font.setFamily(QString::fromUtf8("Century Gothic"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        textLabel2->setFont(font);
        textLabel2->setWordWrap(false);

        gridLayout->addWidget(textLabel2, 0, 0, 1, 2);

        horizontalSpacer_2 = new QSpacerItem(51, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 2);

        horizontalSpacer = new QSpacerItem(91, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        width = new QSpinBox(FrameGLDialog);
        width->setObjectName(QString::fromUtf8("width"));

        gridLayout->addWidget(width, 1, 1, 1, 1);

        textLabel1 = new QLabel(FrameGLDialog);
        textLabel1->setObjectName(QString::fromUtf8("textLabel1"));
        textLabel1->setWordWrap(false);

        gridLayout->addWidget(textLabel1, 1, 2, 1, 1);

        height = new QSpinBox(FrameGLDialog);
        height->setObjectName(QString::fromUtf8("height"));

        gridLayout->addWidget(height, 1, 3, 1, 1);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        buttonOk = new QPushButton(FrameGLDialog);
        buttonOk->setObjectName(QString::fromUtf8("buttonOk"));
        buttonOk->setAutoDefault(true);
        buttonOk->setDefault(true);

        hboxLayout->addWidget(buttonOk);

        buttonCancel = new QPushButton(FrameGLDialog);
        buttonCancel->setObjectName(QString::fromUtf8("buttonCancel"));
        buttonCancel->setAutoDefault(true);

        hboxLayout->addWidget(buttonCancel);


        gridLayout->addLayout(hboxLayout, 2, 0, 1, 4);


        retranslateUi(FrameGLDialog);
        QObject::connect(buttonOk, SIGNAL(clicked()), FrameGLDialog, SLOT(accept()));
        QObject::connect(buttonCancel, SIGNAL(clicked()), FrameGLDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(FrameGLDialog);
    } // setupUi

    void retranslateUi(QDialog *FrameGLDialog)
    {
        FrameGLDialog->setWindowTitle(QApplication::translate("FrameGLDialog", "Frame GL Size", 0, QApplication::UnicodeUTF8));
        textLabel2->setText(QApplication::translate("FrameGLDialog", "Frame GL Size", 0, QApplication::UnicodeUTF8));
        textLabel1->setText(QApplication::translate("FrameGLDialog", "x", 0, QApplication::UnicodeUTF8));
        buttonOk->setText(QApplication::translate("FrameGLDialog", "&OK", 0, QApplication::UnicodeUTF8));
        buttonOk->setShortcut(QString());
        buttonCancel->setText(QApplication::translate("FrameGLDialog", "&Cancel", 0, QApplication::UnicodeUTF8));
        buttonCancel->setShortcut(QString());
    } // retranslateUi

};

namespace Ui {
    class FrameGLDialog: public Ui_FrameGLDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // FRAMEGLSIZEDIALOG_H
