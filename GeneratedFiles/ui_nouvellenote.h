/********************************************************************************
** Form generated from reading UI file 'nouvellenote.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOUVELLENOTE_H
#define UI_NOUVELLENOTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_NouvelleNote
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QRadioButton *Image;
    QRadioButton *Article;
    QDialogButtonBox *buttonBox;
    QButtonGroup *buttonGroup;

    void setupUi(QDialog *NouvelleNote)
    {
        if (NouvelleNote->objectName().isEmpty())
            NouvelleNote->setObjectName(QStringLiteral("NouvelleNote"));
        NouvelleNote->setWindowModality(Qt::WindowModal);
        NouvelleNote->resize(423, 173);
        gridLayout = new QGridLayout(NouvelleNote);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(NouvelleNote);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(NouvelleNote);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        Image = new QRadioButton(NouvelleNote);
        buttonGroup = new QButtonGroup(NouvelleNote);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(Image);
        Image->setObjectName(QStringLiteral("Image"));

        verticalLayout->addWidget(Image);

        Article = new QRadioButton(NouvelleNote);
        buttonGroup->addButton(Article);
        Article->setObjectName(QStringLiteral("Article"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Article->sizePolicy().hasHeightForWidth());
        Article->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(Article);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(NouvelleNote);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(NouvelleNote);
        QObject::connect(buttonBox, SIGNAL(accepted()), NouvelleNote, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NouvelleNote, SLOT(reject()));

        QMetaObject::connectSlotsByName(NouvelleNote);
    } // setupUi

    void retranslateUi(QDialog *NouvelleNote)
    {
        NouvelleNote->setWindowTitle(QApplication::translate("NouvelleNote", "Dialog", 0));
        label->setText(QApplication::translate("NouvelleNote", "Nom", 0));
        Image->setText(QApplication::translate("NouvelleNote", "Image", 0));
        Article->setText(QApplication::translate("NouvelleNote", "Article", 0));
    } // retranslateUi

};

namespace Ui {
    class NouvelleNote: public Ui_NouvelleNote {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOUVELLENOTE_H
