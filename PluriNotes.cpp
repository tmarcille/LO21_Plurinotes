#include "PluriNotes.h"
#include "NoteEditeur.h"
#include "nouvellenote.h"
#include <qDebug>
#include <QList>

PluriNotes::PluriNotes(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.actionOuvrir, SIGNAL(triggered()), this, SLOT(ouvrirProjet()));
	QObject::connect(ui.actionNote, SIGNAL(triggered()), this, SLOT(nouvelleNote()));
}


void PluriNotes::closeEvent(QCloseEvent *event)
{
	ArticleEditeur* articleEdit = dynamic_cast<ArticleEditeur*>(ui.horizontalLayout->itemAt(1)->widget());
	if (articleEdit) {
		articleEdit->verifSave();
	}
}

void PluriNotes::ouvrirProjet() {
	//a faire : dossier fixe, changeable dans les parametres



	NotesManager& m = NotesManager::getManager();
	m.load();
	for (NotesManager::Iterator it = m.getIterator(); !it.isDone(); it.next()) {
			new QListWidgetItem(it.current().getId(), ui.listWidget);
	}

	QObject::connect(ui.listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(ouvrirNote(QListWidgetItem*)));
	//On active le bouton nouvelle note
	ui.actionNote->setEnabled(true);
}



PluriNotes::~PluriNotes()
{
	NotesManager::freeManager();
}



void PluriNotes::ouvrirNote(QListWidgetItem* item) {

	QWidget* old = ui.horizontalLayout->itemAt(1)->widget();
	NoteEditeur* noteEdit = dynamic_cast<NoteEditeur*>(old);

	//On lance la fenetre de verification de fermeture si on ferme un article, si le bouton de sauvegarde est activé, et si la nouvelle note est différente de l'ancienne.
	if (noteEdit && noteEdit->getId()!=item->text()) {
		noteEdit->verifSave();
	}
	//si on deja sur la note, on ne fait rien
	else if (noteEdit && noteEdit->getId() == item->text()) {
		return;
	}

	NotesManager& m = NotesManager::getManager();
	Note& n = m.getNote(item->text());

	NoteEditeur* fenetre = m.createEditor(&n);

	ui.horizontalLayout->replaceWidget(old,fenetre);
	delete old;
	//**********Code pour Mdi window

	//QMdiSubWindow* sousFenetre = new QMdiSubWindow;
	//sousFenetre->setWidget(fenetre);
	//
	//QList<QMdiSubWindow*> fenetres = ui.mdiArea->subWindowList();
}



void PluriNotes::nouvelleNote()
{
	NouvelleNote* x = new NouvelleNote();
	if (x->exec() == QDialog::Accepted) {

		// Ajouter : tri par ordre alphabetique de la liste, verif si la note n'existe pas deja
		QListWidgetItem* nouvelle_note = new QListWidgetItem(x->getNom(), ui.listWidget);
		NotesManager& m = NotesManager::getManager();

		m.create(x->getSelectedType(),x->getNom());
        m.saveAllNotes();
		ouvrirNote(nouvelle_note);

	}
	delete x;
}
