/********************************************************************************
** Form generated from reading UI file 'importselection.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef IMPORTSELECTION_H
#define IMPORTSELECTION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ViewImporterSelection
{
public:
    QLabel *FileMsg;
    QLabel *TypeMsg;
    QLabel *Type;
    QLabel *ImporterMsg;
    QLabel *File;
    QPushButton *OkButton;
    QPushButton *CancelButton;
    QComboBox *ImporterCombo;
    QLabel *GeneralMsg;

    void setupUi(QDialog *ViewImporterSelection)
    {
        if (ViewImporterSelection->objectName().isEmpty())
            ViewImporterSelection->setObjectName(QString::fromUtf8("ViewImporterSelection"));
        ViewImporterSelection->resize(399, 160);
        FileMsg = new QLabel(ViewImporterSelection);
        FileMsg->setObjectName(QString::fromUtf8("FileMsg"));
        FileMsg->setGeometry(QRect(80, 30, 53, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        FileMsg->setFont(font);
        FileMsg->setWordWrap(false);
        TypeMsg = new QLabel(ViewImporterSelection);
        TypeMsg->setObjectName(QString::fromUtf8("TypeMsg"));
        TypeMsg->setGeometry(QRect(80, 50, 53, 20));
        TypeMsg->setFont(font);
        TypeMsg->setWordWrap(false);
        Type = new QLabel(ViewImporterSelection);
        Type->setObjectName(QString::fromUtf8("Type"));
        Type->setGeometry(QRect(140, 50, 140, 20));
        Type->setWordWrap(false);
        ImporterMsg = new QLabel(ViewImporterSelection);
        ImporterMsg->setObjectName(QString::fromUtf8("ImporterMsg"));
        ImporterMsg->setGeometry(QRect(80, 70, 200, 20));
        ImporterMsg->setFont(font);
        ImporterMsg->setWordWrap(false);
        File = new QLabel(ViewImporterSelection);
        File->setObjectName(QString::fromUtf8("File"));
        File->setGeometry(QRect(140, 30, 140, 20));
        File->setWordWrap(false);
        OkButton = new QPushButton(ViewImporterSelection);
        OkButton->setObjectName(QString::fromUtf8("OkButton"));
        OkButton->setGeometry(QRect(80, 120, 126, 32));
        CancelButton = new QPushButton(ViewImporterSelection);
        CancelButton->setObjectName(QString::fromUtf8("CancelButton"));
        CancelButton->setGeometry(QRect(210, 120, 126, 32));
        ImporterCombo = new QComboBox(ViewImporterSelection);
        ImporterCombo->setObjectName(QString::fromUtf8("ImporterCombo"));
        ImporterCombo->setGeometry(QRect(80, 90, 200, 20));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(10);
        ImporterCombo->setFont(font1);
        GeneralMsg = new QLabel(ViewImporterSelection);
        GeneralMsg->setObjectName(QString::fromUtf8("GeneralMsg"));
        GeneralMsg->setGeometry(QRect(80, 10, 220, 20));
        GeneralMsg->setFont(font);
        GeneralMsg->setWordWrap(false);

        retranslateUi(ViewImporterSelection);

        QMetaObject::connectSlotsByName(ViewImporterSelection);
    } // setupUi

    void retranslateUi(QDialog *ViewImporterSelection)
    {
        ViewImporterSelection->setWindowTitle(QApplication::translate("ViewImporterSelection", "Importer Selection", 0, QApplication::UnicodeUTF8));
        FileMsg->setText(QApplication::translate("ViewImporterSelection", "File :", 0, QApplication::UnicodeUTF8));
        TypeMsg->setText(QApplication::translate("ViewImporterSelection", "Type :", 0, QApplication::UnicodeUTF8));
        Type->setText(QApplication::translate("ViewImporterSelection", "GEOM", 0, QApplication::UnicodeUTF8));
        ImporterMsg->setText(QApplication::translate("ViewImporterSelection", "Choose Importer :", 0, QApplication::UnicodeUTF8));
        File->setText(QApplication::translate("ViewImporterSelection", "file.geom", 0, QApplication::UnicodeUTF8));
        OkButton->setText(QApplication::translate("ViewImporterSelection", "&Ok", 0, QApplication::UnicodeUTF8));
        CancelButton->setText(QApplication::translate("ViewImporterSelection", "&Cancel", 0, QApplication::UnicodeUTF8));
        ImporterCombo->clear();
        ImporterCombo->insertItems(0, QStringList()
         << QApplication::translate("ViewImporterSelection", "GEOM", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ViewImporterSelection", "Amap Symbol", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ViewImporterSelection", "Linetree", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ViewImporterSelection", "VegeStar", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ViewImporterSelection", "VegeStar Symbol", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ViewImporterSelection", "GeomView", 0, QApplication::UnicodeUTF8)
        );
        GeneralMsg->setText(QApplication::translate("ViewImporterSelection", "File Format not recognized !", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ViewImporterSelection: public Ui_ViewImporterSelection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // IMPORTSELECTION_H
