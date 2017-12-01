/********************************************************************************
** Form generated from reading UI file 'codecview.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CODECVIEW_H
#define CODECVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CodecView
{
public:
    QVBoxLayout *vboxLayout;
    QTreeWidget *treeWidget;

    void setupUi(QWidget *CodecView)
    {
        if (CodecView->objectName().isEmpty())
            CodecView->setObjectName(QString::fromUtf8("CodecView"));
        CodecView->resize(326, 367);
        vboxLayout = new QVBoxLayout(CodecView);
#ifndef Q_OS_MAC
        vboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        vboxLayout->setContentsMargins(9, 9, 9, 9);
#endif
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        treeWidget = new QTreeWidget(CodecView);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));

        vboxLayout->addWidget(treeWidget);


        retranslateUi(CodecView);

        QMetaObject::connectSlotsByName(CodecView);
    } // setupUi

    void retranslateUi(QWidget *CodecView)
    {
        CodecView->setWindowTitle(QApplication::translate("CodecView", "Form", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(2, QApplication::translate("CodecView", "Comments", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(1, QApplication::translate("CodecView", "Files", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("CodecView", "Codec", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CodecView: public Ui_CodecView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CODECVIEW_H
