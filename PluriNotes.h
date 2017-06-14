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

private slots:
};
