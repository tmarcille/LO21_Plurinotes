/********************************************************************************
** Form generated from reading UI file 'PluriNotes.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLURINOTES_H
#define UI_PLURINOTES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PluriNotesClass
{
public:
    QAction *actionNote;
    QAction *actionOuvrir;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidget;
    QWidget *widget2;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menuNouveau;
    QMenu *menuEdition;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *PluriNotesClass)
    {
        if (PluriNotesClass->objectName().isEmpty())
            PluriNotesClass->setObjectName(QStringLiteral("PluriNotesClass"));
        PluriNotesClass->resize(1105, 840);
        actionNote = new QAction(PluriNotesClass);
        actionNote->setObjectName(QStringLiteral("actionNote"));
        actionNote->setEnabled(false);
        actionOuvrir = new QAction(PluriNotesClass);
        actionOuvrir->setObjectName(QStringLiteral("actionOuvrir"));
        centralWidget = new QWidget(PluriNotesClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy);
        listWidget->setMaximumSize(QSize(200, 16777215));
        listWidget->setFrameShape(QFrame::StyledPanel);

        horizontalLayout->addWidget(listWidget);

        widget2 = new QWidget(centralWidget);
        widget2->setObjectName(QStringLiteral("widget2"));

        horizontalLayout->addWidget(widget2);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        PluriNotesClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PluriNotesClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1105, 21));
        menuBar->setDefaultUp(false);
        menuBar->setNativeMenuBar(false);
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QStringLiteral("menuFichier"));
        menuNouveau = new QMenu(menuFichier);
        menuNouveau->setObjectName(QStringLiteral("menuNouveau"));
        menuEdition = new QMenu(menuBar);
        menuEdition->setObjectName(QStringLiteral("menuEdition"));
        PluriNotesClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(PluriNotesClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        PluriNotesClass->setStatusBar(statusBar);
        toolBar = new QToolBar(PluriNotesClass);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        PluriNotesClass->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menuEdition->menuAction());
        menuFichier->addAction(menuNouveau->menuAction());
        menuFichier->addAction(actionOuvrir);
        menuNouveau->addAction(actionNote);

        retranslateUi(PluriNotesClass);

        QMetaObject::connectSlotsByName(PluriNotesClass);
    } // setupUi

    void retranslateUi(QMainWindow *PluriNotesClass)
    {
        PluriNotesClass->setWindowTitle(QApplication::translate("PluriNotesClass", "PluriNotes", Q_NULLPTR));
        actionNote->setText(QApplication::translate("PluriNotesClass", "Note", Q_NULLPTR));
        actionOuvrir->setText(QApplication::translate("PluriNotesClass", "Ouvrir...", Q_NULLPTR));
        menuFichier->setTitle(QApplication::translate("PluriNotesClass", "Fichiers", Q_NULLPTR));
        menuNouveau->setTitle(QApplication::translate("PluriNotesClass", "Nouveau", Q_NULLPTR));
        menuEdition->setTitle(QApplication::translate("PluriNotesClass", "Edition", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("PluriNotesClass", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PluriNotesClass: public Ui_PluriNotesClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLURINOTES_H
