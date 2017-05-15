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

class PluriNotes : public QMainWindow
{
	Q_OBJECT

public:
	PluriNotes(QWidget *parent = Q_NULLPTR);
	
	~PluriNotes();
private:
	Ui::PluriNotesClass ui;
	void closeEvent(QCloseEvent * event);

public slots:
	void ouvrirProjet();
	void ouvrirNote(QListWidgetItem* item);
	void nouvelleNote();
};
