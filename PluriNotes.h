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
#include "Notes.h"
#include <QDirIterator>
#include "NoteManager.h"
#include "SettingsDialog.h"

class PluriNotes : public QMainWindow
{
	Q_OBJECT

public:
    explicit PluriNotes(QWidget *parent = Q_NULLPTR);
    virtual ~PluriNotes();
    void ouvrirProjet();
    void loadSettings();

private:

	Ui::PluriNotesClass ui;
	void closeEvent(QCloseEvent * event);


    QString m_sSettingsFile;

public slots:

    void openSettings();
	void ouvrirNote(QListWidgetItem* item);
	void nouvelleNote();
    void unsavedChanges(NoteEditeur* f);
    void saveChanges(NoteEditeur* f);
};
