#include "NoteEditeur.h"

QVector<NoteEditeur*> NoteEditeur::editeurs= {};

NoteEditeur::NoteEditeur(Note* a, QWidget *parent) : QWidget(parent), note(a)
{
	idl = new QLabel("Identificateur");
	titrel = new QLabel("Titre");
	save = new QPushButton("Sauver");

    idl->setMinimumWidth(75);
    titrel->setMinimumWidth(75);
    id = new QLineEdit();
    titre = new QLineEdit();

    mainLayout = new QVBoxLayout();
    idLayout = new QHBoxLayout();
    titreLayout = new QHBoxLayout();
    centralLayout = new QHBoxLayout();

    idLayout->addWidget(idl);
    titreLayout->addWidget(titrel);

    idLayout->addWidget(id);
    titreLayout->addWidget(titre);

    mainLayout->addLayout(idLayout);
    mainLayout->addLayout(titreLayout);
    mainLayout->addLayout(centralLayout);
    mainLayout->addWidget(save);

    this->setLayout(mainLayout);

	id->setReadOnly(true);
    id->setText(a->getId());
    titre->setText(a->getTitle());
	save->setEnabled(false);

	QObject::connect(titre, SIGNAL(textChanged(QString)), this, SLOT(activerSave()));
	QObject::connect(save, SIGNAL(clicked()), this, SLOT(sauvegarde()));

    editeurs.push_back(this);
}


NoteEditeur::~NoteEditeur()
{
    editeurs.remove(editeurs.indexOf(this));
}

void NoteEditeur::sauvegarde()
{
	note->setTitle(titre->text());
	sauvegardeAttributs();	
	save->setDisabled(true);
    emit savedChanges(this);
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
    emit unsavedChanges(this);
}
