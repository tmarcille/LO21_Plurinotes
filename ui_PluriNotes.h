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
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "NoteViewer.h"
#include "RelationTree.h"

QT_BEGIN_NAMESPACE

class Ui_PluriNotesClass
{
public:
    QAction *actionNote;
    QAction *actionOuvrir;
    QAction *actionDossier_de_stockage;
    QAction *actionOptions;
    QAction *actionRelations;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *listWidget;
    QVBoxLayout *verticalLayout;
    QListWidget *taskList;
    QListWidget *archiveList;
    NoteViewer *noteViewer;
    QGridLayout *relationTreePanelLayout;
    QToolButton *toggleBtn;
    RelationTree *relationTree;
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
        actionDossier_de_stockage = new QAction(PluriNotesClass);
        actionDossier_de_stockage->setObjectName(QStringLiteral("actionDossier_de_stockage"));
        actionOptions = new QAction(PluriNotesClass);
        actionOptions->setObjectName(QStringLiteral("actionOptions"));
        actionRelations = new QAction(PluriNotesClass);
        actionRelations->setObjectName(QStringLiteral("actionRelations"));
        centralWidget = new QWidget(PluriNotesClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
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

        horizontalLayout_2->addWidget(listWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        taskList = new QListWidget(centralWidget);
        taskList->setObjectName(QStringLiteral("taskList"));
        sizePolicy.setHeightForWidth(taskList->sizePolicy().hasHeightForWidth());
        taskList->setSizePolicy(sizePolicy);
        taskList->setMaximumSize(QSize(200, 16777215));
        taskList->setStyleSheet(QLatin1String("border-color: rgb(180, 180, 180);\n"
"    background-color: rgb(245, 245, 245);"));
        taskList->setFrameShape(QFrame::StyledPanel);
        taskList->setSelectionMode(QAbstractItemView::NoSelection);

        verticalLayout->addWidget(taskList);

        archiveList = new QListWidget(centralWidget);
        archiveList->setObjectName(QStringLiteral("archiveList"));
        sizePolicy.setHeightForWidth(archiveList->sizePolicy().hasHeightForWidth());
        archiveList->setSizePolicy(sizePolicy);
        archiveList->setMaximumSize(QSize(200, 16777215));
        archiveList->setStyleSheet(QLatin1String("border-color: rgb(180, 180, 180);\n"
"    background-color: rgb(245, 245, 245);"));

        verticalLayout->addWidget(archiveList);


        horizontalLayout_2->addLayout(verticalLayout);

        noteViewer = new NoteViewer(centralWidget);
        noteViewer->setObjectName(QStringLiteral("noteViewer"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(noteViewer->sizePolicy().hasHeightForWidth());
        noteViewer->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(noteViewer);

        relationTreePanelLayout = new QGridLayout();
        relationTreePanelLayout->setSpacing(6);
        relationTreePanelLayout->setObjectName(QStringLiteral("relationTreePanelLayout"));
        toggleBtn = new QToolButton(centralWidget);
        toggleBtn->setObjectName(QStringLiteral("toggleBtn"));
        toggleBtn->setCheckable(true);
        toggleBtn->setToolButtonStyle(Qt::ToolButtonTextOnly);

        relationTreePanelLayout->addWidget(toggleBtn, 0, 0, 1, 1);

        relationTree = new RelationTree(centralWidget);
        relationTree->setObjectName(QStringLiteral("relationTree"));

        relationTreePanelLayout->addWidget(relationTree, 1, 0, 1, 1);


        horizontalLayout_2->addLayout(relationTreePanelLayout);

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
        menuFichier->addSeparator();
        menuFichier->addAction(actionOptions);
        menuFichier->addAction(actionRelations);
        menuNouveau->addAction(actionNote);

        retranslateUi(PluriNotesClass);

        QMetaObject::connectSlotsByName(PluriNotesClass);
    } // setupUi

    void retranslateUi(QMainWindow *PluriNotesClass)
    {
        PluriNotesClass->setWindowTitle(QApplication::translate("PluriNotesClass", "PluriNotes", Q_NULLPTR));
        actionNote->setText(QApplication::translate("PluriNotesClass", "Note", Q_NULLPTR));
        actionOuvrir->setText(QApplication::translate("PluriNotesClass", "Ouvrir...", Q_NULLPTR));
        actionDossier_de_stockage->setText(QApplication::translate("PluriNotesClass", "Dossier de stockage", Q_NULLPTR));
        actionOptions->setText(QApplication::translate("PluriNotesClass", "Settings...", Q_NULLPTR));
        actionRelations->setText(QApplication::translate("PluriNotesClass", "Relations..", Q_NULLPTR));
        toggleBtn->setText(QApplication::translate("PluriNotesClass", "Arborescence", Q_NULLPTR));
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
