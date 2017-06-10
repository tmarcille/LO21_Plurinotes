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
#include "vector"


class PluriNotes : public QMainWindow,  public Observer<Note>
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

private:

	Ui::PluriNotesClass ui;
	void closeEvent(QCloseEvent * event);
    NoteViewer* test;

    QString m_sSettingsFile;

public slots:

    void openSettings();
	void ouvrirNote(QListWidgetItem* item);
	void nouvelleNote();

private slots:
};
