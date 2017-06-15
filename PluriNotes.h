#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PluriNotes.h"
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMdiSubWindow>
#include <QFileDialog>
#include <QListWidget>
#include <QListView>
#include "Notes.h"
#include <QDirIterator>
#include "NoteManager.h"
#include "SettingsDialog.h"
#include "NoteViewer.h"
#include "RelationWindow.h"
#include "vector"

/**
 * \brief La classe Plurinote permet de lancer l'application et sa fenetre
 * \details La classe Plurinote permet d'ouvrir le projet, charger les settings et mettre à jours les editeurs
 *
 */

class PluriNotes : public QMainWindow,  public Observer<Note>, public Observer<NoteViewer>
{
	Q_OBJECT

public:
    explicit PluriNotes(QWidget *parent = Q_NULLPTR);
    virtual ~PluriNotes();
    void ouvrirProjet();
    void createTaskList();
    void loadSettings();
    void update(Note* n){
        if(ui.noteViewer->isOpen(n->getId())){
            qDebug()<<"observator";
            ui.noteViewer->refreshNote(n->getId());
        }
        Tache* t = dynamic_cast<Tache*> (n);
        if(t){
            ui.taskList->clear();
            createTaskList();
        }
    }
    void update(NoteViewer* viewer){
        qDebug()<<viewer->currentWindow();
        RelationManager& r = RelationManager::getManager();
        r.load();

        ui.relationTree->clearTree();
        ui.relationTree->addRoot(viewer->currentWindow());

        QVector<Relation*>::iterator it;
        QVector<QString> asc;
        QVector<QString> dsc;

        for ( it = r.begin(); it!=r.end(); it++) {
            asc = (*it)->getAscendants(viewer->currentWindow());
            dsc = (*it)->getDescendants(viewer->currentWindow());
            QVector<QString>::iterator i;
            for (i = asc.begin(); i!=asc.end(); i++)
                ui.relationTree->addAsc(*i, (*it)->getTitle());
            for (i = dsc.begin(); i!=dsc.end(); i++)
                ui.relationTree->addDesc(*i, (*it)->getTitle());
        }
    }

private:

	Ui::PluriNotesClass ui;
    void closeEvent(QCloseEvent * event);
    QString m_sSettingsFile;

public slots:

    void openSettings();
    void openRelations();
	void ouvrirNote(QListWidgetItem* item);
	void nouvelleNote();
    void reactToPannelToggle(bool);
    void removeBtnClicked();
    void restoreBtnClicked();

private slots:
};

class VidageCorbeille : public QDialog
{
public:

    VidageCorbeille(QWidget *parent = 0) :QDialog(parent)
    {
        Vlayout = new QVBoxLayout(this);
        Hlayout = new QHBoxLayout(this);

        text = new QLabel("Des élèments sont présents dans la corbeille. Les restaurer ?");
        closeBtn = new QPushButton("Non");
        acceptBtn = new QPushButton("Oui");
        Vlayout->addWidget(text);
        Hlayout->addWidget(acceptBtn);
        Hlayout->addWidget(closeBtn);

        Vlayout->addLayout(Hlayout);
        setModal(true);

        connect(acceptBtn, SIGNAL(clicked()), this, SLOT(accept()));
        connect(closeBtn, SIGNAL(clicked()), this, SLOT(reject()));
        show();
    }
private:
    QVBoxLayout* Vlayout;
    QHBoxLayout* Hlayout;
    QLabel *text;
    QPushButton *closeBtn;
    QPushButton *acceptBtn;
};
