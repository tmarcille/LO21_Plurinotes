#include "PluriNotes.h"
#include "NoteEditeur.h"
#include "nouvellenote.h"
#include <qDebug>
#include <QList>
#include <QTabWidget>

PluriNotes::PluriNotes(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

    m_sSettingsFile = QDir::currentPath() + "/config.ini";


    QFileInfo check_file(m_sSettingsFile);

    if (!check_file.exists()){
        QSettings* settings = new QSettings(m_sSettingsFile, QSettings::IniFormat);
        settings->setValue("folder", QDir::currentPath());
        settings->sync();
        qDebug()<<"file created"<<endl;
    }

    loadSettings();
    ouvrirProjet();
	QObject::connect(ui.actionNote, SIGNAL(triggered()), this, SLOT(nouvelleNote()));
    QObject::connect(ui.actionOptions, SIGNAL(triggered()), this, SLOT(openSettings()));
    QObject::connect(ui.tabWidget, &QTabWidget::tabCloseRequested, this, &PluriNotes::closeTab);
}

void PluriNotes::closeTab(int i){

    ui.tabWidget->setCurrentIndex(i);
    QWidget* old = ui.tabWidget->widget(i);
    NoteEditeur* noteEdit = dynamic_cast<NoteEditeur*>(old);
    if(noteEdit)
        noteEdit->verifSave();
    delete old;
}

void PluriNotes::loadSettings()
{

    QSettings settings(m_sSettingsFile, QSettings::IniFormat);
    QString sText = settings.value("folder", "").toString();

    NotesManager& m = NotesManager::getManager();
    m.setFoldername(sText);

    qDebug()<<"settings loaded"<<settings.value("folder", "").toString()<<endl;

}

void PluriNotes::closeEvent(QCloseEvent *event)
{

    for(int i=ui.tabWidget->count() ; i>0 ; i--)
        closeTab(i);

    /*NoteEditeur* noteEdit = dynamic_cast<NoteEditeur*>(ui.horizontalLayout->itemAt(1)->widget());
    if (noteEdit) {
        noteEdit->verifSave();
    }*/
}

void PluriNotes::openSettings()
{
    SettingsDialog* x = new SettingsDialog(m_sSettingsFile);
    if(x->exec() == QDialog::Accepted){

        //si on a sauvegardé des changements dans les paramètres, on recharge le projet



        QWidget* old = ui.horizontalLayout->itemAt(1)->widget();
        NoteEditeur* noteEdit = dynamic_cast<NoteEditeur*>(old);
        if (noteEdit){
            noteEdit->verifSave();
            ui.horizontalLayout->replaceWidget(old,new QWidget());
            delete old;
        }
        NotesManager::freeManager();
        ui.listWidget->clear();
        loadSettings();
        ouvrirProjet();
    }
}

void PluriNotes::ouvrirProjet() {

    NotesManager& m = NotesManager::getManager();

    qDebug()<<"folder:"<<m.getFoldername();

	m.load();
	for (NotesManager::Iterator it = m.getIterator(); !it.isDone(); it.next()) {
			new QListWidgetItem(it.current().getId(), ui.listWidget);
	}

	QObject::connect(ui.listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(ouvrirNote(QListWidgetItem*)));
	//On active le bouton nouvelle note
	ui.actionNote->setEnabled(true);
}

void PluriNotes::ouvrirNote(QListWidgetItem* item) {

    /*
	QWidget* old = ui.horizontalLayout->itemAt(1)->widget();
	NoteEditeur* noteEdit = dynamic_cast<NoteEditeur*>(old);
    */
	//On lance la fenetre de verification de fermeture si on ferme un article, si le bouton de sauvegarde est activé, et si la nouvelle note est différente de l'ancienne.
    /*if (noteEdit && noteEdit->getId()!=item->text()) {
		noteEdit->verifSave();
    }*/

	NotesManager& m = NotesManager::getManager();
	Note& n = m.getNote(item->text());

	NoteEditeur* fenetre = m.createEditor(&n);

    //si la note est deja ouverte, on met le focus sur celle-ci
    for (int i = 0; i< ui.tabWidget->count(); i++){
        if (ui.tabWidget->tabText(i) == item->text() || ui.tabWidget->tabText(i) == "*"+item->text()){
            ui.tabWidget->setCurrentIndex(i);
            return;
        }
    }
    connect(fenetre,&NoteEditeur::unsavedChanges, this,&PluriNotes::unsavedChanges);
    connect(fenetre,&NoteEditeur::savedChanges, this,&PluriNotes::saveChanges);


    //sinon on l'ajoute
    qDebug()<<fenetre->getId();
    ui.tabWidget->addTab(fenetre,fenetre->getId());
    ui.tabWidget->setCurrentWidget(fenetre);

    //delete old;
	//**********Code pour Mdi window

	//QMdiSubWindow* sousFenetre = new QMdiSubWindow;
	//sousFenetre->setWidget(fenetre);
	//
	//QList<QMdiSubWindow*> fenetres = ui.mdiArea->subWindowList();
}

void PluriNotes::unsavedChanges(NoteEditeur* f){

    ui.tabWidget->setTabText(ui.tabWidget->indexOf(f),"*"+f->getId());

}

void PluriNotes::saveChanges(NoteEditeur* f){


    ui.tabWidget->setTabText(ui.tabWidget->indexOf(f),f->getId());
    NotesManager& m = NotesManager::getManager();
    m.saveNote(f->getId());
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

PluriNotes::~PluriNotes()
{
    NotesManager::freeManager();
}
