/********************************************************************************
** Form generated from reading UI file 'approximation.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef APPROXIMATION_H
#define APPROXIMATION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_ViewApproximationForm
{
public:
    QGridLayout *gridLayout_2;
    QLabel *Title;
    QGroupBox *Input;
    QHBoxLayout *horizontalLayout;
    QRadioButton *SceneButton;
    QRadioButton *SelectionButton;
    QRadioButton *ExeptButton;
    QGroupBox *Algorithm;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *AlgorithmBox;
    QGroupBox *Material;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *MaterialButton;
    QGroupBox *Output;
    QGridLayout *gridLayout;
    QRadioButton *Approximation;
    QRadioButton *InputGeometry;
    QSpacerItem *horizontalSpacer_3;
    QRadioButton *Rest;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *CancelButton;
    QPushButton *OkButton;

    void setupUi(QDialog *ViewApproximationForm)
    {
        if (ViewApproximationForm->objectName().isEmpty())
            ViewApproximationForm->setObjectName(QString::fromUtf8("ViewApproximationForm"));
        ViewApproximationForm->resize(386, 273);
        gridLayout_2 = new QGridLayout(ViewApproximationForm);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        Title = new QLabel(ViewApproximationForm);
        Title->setObjectName(QString::fromUtf8("Title"));
        QFont font;
        font.setFamily(QString::fromUtf8("Comic Sans MS"));
        font.setPointSize(12);
        Title->setFont(font);
        Title->setWordWrap(false);

        gridLayout_2->addWidget(Title, 0, 0, 1, 2);

        Input = new QGroupBox(ViewApproximationForm);
        Input->setObjectName(QString::fromUtf8("Input"));
        horizontalLayout = new QHBoxLayout(Input);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        SceneButton = new QRadioButton(Input);
        SceneButton->setObjectName(QString::fromUtf8("SceneButton"));

        horizontalLayout->addWidget(SceneButton);

        SelectionButton = new QRadioButton(Input);
        SelectionButton->setObjectName(QString::fromUtf8("SelectionButton"));
        SelectionButton->setChecked(true);

        horizontalLayout->addWidget(SelectionButton);

        ExeptButton = new QRadioButton(Input);
        ExeptButton->setObjectName(QString::fromUtf8("ExeptButton"));

        horizontalLayout->addWidget(ExeptButton);


        gridLayout_2->addWidget(Input, 1, 0, 1, 4);

        Algorithm = new QGroupBox(ViewApproximationForm);
        Algorithm->setObjectName(QString::fromUtf8("Algorithm"));
        horizontalLayout_2 = new QHBoxLayout(Algorithm);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        AlgorithmBox = new QComboBox(Algorithm);
        AlgorithmBox->setObjectName(QString::fromUtf8("AlgorithmBox"));

        horizontalLayout_2->addWidget(AlgorithmBox);


        gridLayout_2->addWidget(Algorithm, 2, 0, 1, 2);

        Material = new QGroupBox(ViewApproximationForm);
        Material->setObjectName(QString::fromUtf8("Material"));
        horizontalLayout_3 = new QHBoxLayout(Material);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        MaterialButton = new QPushButton(Material);
        MaterialButton->setObjectName(QString::fromUtf8("MaterialButton"));

        horizontalLayout_3->addWidget(MaterialButton);


        gridLayout_2->addWidget(Material, 2, 2, 1, 2);

        Output = new QGroupBox(ViewApproximationForm);
        Output->setObjectName(QString::fromUtf8("Output"));
        gridLayout = new QGridLayout(Output);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Approximation = new QRadioButton(Output);
        Approximation->setObjectName(QString::fromUtf8("Approximation"));
        Approximation->setEnabled(true);
        Approximation->setChecked(true);
        Approximation->setAutoExclusive(false);

        gridLayout->addWidget(Approximation, 0, 0, 1, 1);

        InputGeometry = new QRadioButton(Output);
        InputGeometry->setObjectName(QString::fromUtf8("InputGeometry"));
        InputGeometry->setAutoExclusive(false);

        gridLayout->addWidget(InputGeometry, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(181, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 0, 1, 1);

        Rest = new QRadioButton(Output);
        Rest->setObjectName(QString::fromUtf8("Rest"));
        Rest->setAutoExclusive(false);

        gridLayout->addWidget(Rest, 1, 1, 1, 1);


        gridLayout_2->addWidget(Output, 3, 0, 1, 4);

        horizontalSpacer_2 = new QSpacerItem(203, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 4, 0, 1, 1);

        CancelButton = new QPushButton(ViewApproximationForm);
        CancelButton->setObjectName(QString::fromUtf8("CancelButton"));

        gridLayout_2->addWidget(CancelButton, 4, 1, 1, 2);

        OkButton = new QPushButton(ViewApproximationForm);
        OkButton->setObjectName(QString::fromUtf8("OkButton"));

        gridLayout_2->addWidget(OkButton, 4, 3, 1, 1);


        retranslateUi(ViewApproximationForm);

        QMetaObject::connectSlotsByName(ViewApproximationForm);
    } // setupUi

    void retranslateUi(QDialog *ViewApproximationForm)
    {
        ViewApproximationForm->setWindowTitle(QApplication::translate("ViewApproximationForm", "Approximation", 0, QApplication::UnicodeUTF8));
        Title->setText(QApplication::translate("ViewApproximationForm", "Approximation", 0, QApplication::UnicodeUTF8));
        Input->setTitle(QApplication::translate("ViewApproximationForm", "Input Geometry", 0, QApplication::UnicodeUTF8));
        SceneButton->setText(QApplication::translate("ViewApproximationForm", "&Whole Scene", 0, QApplication::UnicodeUTF8));
        SelectionButton->setText(QApplication::translate("ViewApproximationForm", "&Selection", 0, QApplication::UnicodeUTF8));
        ExeptButton->setText(QApplication::translate("ViewApproximationForm", "&All except Selection", 0, QApplication::UnicodeUTF8));
        Algorithm->setTitle(QApplication::translate("ViewApproximationForm", "Algorithm", 0, QApplication::UnicodeUTF8));
        Material->setTitle(QApplication::translate("ViewApproximationForm", "Material", 0, QApplication::UnicodeUTF8));
        MaterialButton->setText(QApplication::translate("ViewApproximationForm", "Edit", 0, QApplication::UnicodeUTF8));
        Output->setTitle(QApplication::translate("ViewApproximationForm", "Output Geometry", 0, QApplication::UnicodeUTF8));
        Approximation->setText(QApplication::translate("ViewApproximationForm", "&Approximation", 0, QApplication::UnicodeUTF8));
        InputGeometry->setText(QApplication::translate("ViewApproximationForm", "&Input Geometry", 0, QApplication::UnicodeUTF8));
        Rest->setText(QApplication::translate("ViewApproximationForm", "Geometry &not approximated", 0, QApplication::UnicodeUTF8));
        CancelButton->setText(QApplication::translate("ViewApproximationForm", "&Cancel", 0, QApplication::UnicodeUTF8));
        OkButton->setText(QApplication::translate("ViewApproximationForm", "&Ok", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ViewApproximationForm: public Ui_ViewApproximationForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // APPROXIMATION_H
