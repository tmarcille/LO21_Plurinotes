#include "NoteEditeur.h"

NoteEditeur::NoteEditeur(Note& a, QWidget *parent) : QWidget(), note(&a)
{
	idl = new QLabel("Identificateur");

	titrel = new QLabel("Titre");

	save = new QPushButton("Sauver");

	id = new QLineEdit;
	titre = new QLineEdit;

	Vlayout = new QVBoxLayout;
	Hlayout = new QHBoxLayout;
	Hlayout2 = new QHBoxLayout;
	Hlayout3 = new QHBoxLayout;

	Hlayout->addWidget(idl);
	Hlayout2->addWidget(titrel);

	Hlayout->addWidget(id);
	Hlayout2->addWidget(titre);

	Vlayout->addLayout(Hlayout);
	Vlayout->addLayout(Hlayout2);
	Vlayout->addLayout(Hlayout3);
	Vlayout->addWidget(save);

	this->setLayout(Vlayout);

	id->setReadOnly(true);
	id->setText(a.getId());
	titre->setText(a.getTitle());
	save->setEnabled(false);

	QObject::connect(titre, SIGNAL(textChanged(QString)), this, SLOT(activerSave()));
	QObject::connect(save, SIGNAL(clicked()), this, SLOT(sauvegarde()));

}


NoteEditeur::~NoteEditeur()
{

}
void NoteEditeur::sauvegarde()
{
	note->setTitle(titre->text());
	sauvegardeAttributs();

	//note->saveInFile(); imposssible car foldername dans NoteManager solutions : stocker le foldername autre part, ou le chemin entier de la note dans chaque note ?
	
	save->setDisabled(true);
}
void NoteEditeur::verifSave()  {

	if (save->isEnabled()) {
		NoteEditeurFermeture* x = new NoteEditeurFermeture();
		int dialogCode = x->exec();
		if (dialogCode == QDialog::Accepted) {
			sauvegarde();
		}
	}

}
void NoteEditeur::activerSave() {
	save->setEnabled(true);
}