#pragma once

#include "qwidget.h"
#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include "Notes.h"
#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QHboxLayout>
#include <QFileDialog>
#include <iostream>
#include <QObject>
#include <QMessageBox>

class NoteEditeur : public QWidget
{
	Q_OBJECT

private:

	Note* note;
	QLabel* idl;
	QLabel* titrel;

	QLineEdit *id;
	QLineEdit *titre;

	QPushButton* save;

    QHBoxLayout *titreLayout;
    QHBoxLayout *idLayout;
	
    QVBoxLayout *mainLayout;

	virtual void sauvegardeAttributs() = 0;

    NoteEditeur(NoteEditeur& );
    NoteEditeur& operator=(NoteEditeur const&);

protected :
    QHBoxLayout *centralLayout;
    Note* getNote()  { return note; }

public:
    NoteEditeur(Note* a, QWidget *parent = 0);
	virtual ~NoteEditeur();
    const QString getId() const { return note->getId(); }
    static QVector<NoteEditeur*> editeurs;

signals:
    void unsavedChanges(NoteEditeur*);
    void savedChanges(NoteEditeur*);

public slots :
	void activerSave();
	void sauvegarde();
	void verifSave();
};

class NoteEditeurFermeture : public QDialog
{
public:

	NoteEditeurFermeture(QWidget *parent = 0) :QDialog(parent)
	{
		Vlayout = new QVBoxLayout(this);
		Hlayout = new QHBoxLayout(this);

		text = new QLabel("Des changements ont ete effectues. Les sauvegarder ?");
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
