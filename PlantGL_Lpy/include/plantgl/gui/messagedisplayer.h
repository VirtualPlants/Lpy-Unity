/********************************************************************************
** Form generated from reading UI file 'messagedisplayer.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MESSAGEDISPLAYER_H
#define MESSAGEDISPLAYER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MessageDisplayer
{
public:
    QGridLayout *gridLayout;
    QRadioButton *mAutoClearButton;
    QSpacerItem *spacerItem;
    QPushButton *ClearButton;
    QTextBrowser *__text;
    QRadioButton *__popupButton;
    QRadioButton *VerboseButton;

    void setupUi(QWidget *MessageDisplayer)
    {
        if (MessageDisplayer->objectName().isEmpty())
            MessageDisplayer->setObjectName(QString::fromUtf8("MessageDisplayer"));
        MessageDisplayer->resize(405, 150);
        gridLayout = new QGridLayout(MessageDisplayer);
#ifndef Q_OS_MAC
        gridLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        mAutoClearButton = new QRadioButton(MessageDisplayer);
        mAutoClearButton->setObjectName(QString::fromUtf8("mAutoClearButton"));
        mAutoClearButton->setChecked(true);
        mAutoClearButton->setAutoExclusive(false);

        gridLayout->addWidget(mAutoClearButton, 1, 2, 1, 1);

        spacerItem = new QSpacerItem(171, 23, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(spacerItem, 1, 3, 1, 1);

        ClearButton = new QPushButton(MessageDisplayer);
        ClearButton->setObjectName(QString::fromUtf8("ClearButton"));

        gridLayout->addWidget(ClearButton, 1, 4, 1, 1);

        __text = new QTextBrowser(MessageDisplayer);
        __text->setObjectName(QString::fromUtf8("__text"));

        gridLayout->addWidget(__text, 0, 0, 1, 5);

        __popupButton = new QRadioButton(MessageDisplayer);
        __popupButton->setObjectName(QString::fromUtf8("__popupButton"));
        __popupButton->setChecked(true);
        __popupButton->setAutoExclusive(false);

        gridLayout->addWidget(__popupButton, 1, 1, 1, 1);

        VerboseButton = new QRadioButton(MessageDisplayer);
        VerboseButton->setObjectName(QString::fromUtf8("VerboseButton"));
        VerboseButton->setChecked(false);
        VerboseButton->setAutoExclusive(false);

        gridLayout->addWidget(VerboseButton, 1, 0, 1, 1);


        retranslateUi(MessageDisplayer);

        QMetaObject::connectSlotsByName(MessageDisplayer);
    } // setupUi

    void retranslateUi(QWidget *MessageDisplayer)
    {
        MessageDisplayer->setWindowTitle(QApplication::translate("MessageDisplayer", "Error Log", 0, QApplication::UnicodeUTF8));
        mAutoClearButton->setText(QApplication::translate("MessageDisplayer", "Auto Clear", 0, QApplication::UnicodeUTF8));
        ClearButton->setText(QApplication::translate("MessageDisplayer", "Cl&ear", 0, QApplication::UnicodeUTF8));
        __popupButton->setWindowTitle(QString());
        __popupButton->setText(QApplication::translate("MessageDisplayer", "Popup when Errors", 0, QApplication::UnicodeUTF8));
        VerboseButton->setText(QApplication::translate("MessageDisplayer", "Verbose", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MessageDisplayer: public Ui_MessageDisplayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MESSAGEDISPLAYER_H
