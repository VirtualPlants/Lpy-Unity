/********************************************************************************
** Form generated from reading UI file 'qbrowser.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef QBROWSER_H
#define QBROWSER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QBrowser
{
public:
    QVBoxLayout *vboxLayout;
    QLabel *PixmapLabel1;
    QCheckBox *__FullMode;
    QTreeWidget *__list;

    void setupUi(QWidget *QBrowser)
    {
        if (QBrowser->objectName().isEmpty())
            QBrowser->setObjectName(QString::fromUtf8("QBrowser"));
        QBrowser->resize(322, 373);
        vboxLayout = new QVBoxLayout(QBrowser);
#ifndef Q_OS_MAC
        vboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        vboxLayout->setContentsMargins(9, 9, 9, 9);
#endif
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        PixmapLabel1 = new QLabel(QBrowser);
        PixmapLabel1->setObjectName(QString::fromUtf8("PixmapLabel1"));
        PixmapLabel1->setScaledContents(true);
        PixmapLabel1->setWordWrap(false);

        vboxLayout->addWidget(PixmapLabel1);

        __FullMode = new QCheckBox(QBrowser);
        __FullMode->setObjectName(QString::fromUtf8("__FullMode"));
        QFont font;
        font.setFamily(QString::fromUtf8("Courier New"));
        __FullMode->setFont(font);

        vboxLayout->addWidget(__FullMode);

        __list = new QTreeWidget(QBrowser);
        __list->setObjectName(QString::fromUtf8("__list"));

        vboxLayout->addWidget(__list);


        retranslateUi(QBrowser);

        QMetaObject::connectSlotsByName(QBrowser);
    } // setupUi

    void retranslateUi(QWidget *QBrowser)
    {
        QBrowser->setWindowTitle(QApplication::translate("QBrowser", "Form1", 0, QApplication::UnicodeUTF8));
        PixmapLabel1->setText(QString());
        __FullMode->setText(QApplication::translate("QBrowser", "Full &Mode", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QBrowser: public Ui_QBrowser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // QBROWSER_H
