#include "PluriNotes.h"
#include "nouvellenote.h"
#include <qDebug>
#include <QList>
#include <QTabWidget>


PluriNotes::PluriNotes(QWidget *parent)
	: QMainWindow(parent)
{
    qDebug()<<"launched";

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
    NotesManager& m = NotesManager::getManager();
    for (NotesManager::Iterator it = m.getIterator(); !it.isDone(); it.next()) {
            if (ui.noteViewer->isOpen(it.current().getId()))
                ui.noteViewer->closeNote(it.current().getId());
    }
}

void PluriNotes::openSettings()
{
    SettingsDialog* x = new SettingsDialog(m_sSettingsFile);
    if(x->exec() == QDialog::Accepted){

        //si on a sauvegardé des changements dans les paramètres, on recharge le projet

        NotesManager& m = NotesManager::getManager();

        //si on ajoute des parametres qui ne changent pas les notes, besoin de faire des tests pour faire la distinction et ne pas tout recharger
        for (NotesManager::Iterator it = m.getIterator(); !it.isDone(); it.next()) {
                if (ui.noteViewer->isOpen(it.current().getId()))
                    ui.noteViewer->closeNote(it.current().getId());
        }
        ui.listWidget->clear();

        NotesManager::freeManager();
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

	NotesManager& m = NotesManager::getManager();
	Note& n = m.getNote(item->text());
    n.attach(*this);
    qDebug()<<"ouverture note"<<item->text();
    ui.noteViewer->showNote(&n);

}

void PluriNotes::nouvelleNote()
{
	NouvelleNote* x = new NouvelleNote();
	if (x->exec() == QDialog::Accepted) {
		// Ajouter : tri par ordre alphabetique de la liste, verif si la note n'existe pas deja


		NotesManager& m = NotesManager::getManager();
        try{
            m.create(x->getSelectedType(),x->getNom());
        }
        catch (NotesException& a){
            if(a.getInfo()=="Note already exists"){
                QMessageBox::information(this, "Error", a.getInfo()) ;
                return;
            }
        }
        QListWidgetItem* nouvelle_note = new QListWidgetItem(x->getNom(), ui.listWidget);
        m.saveAllNotes();
		ouvrirNote(nouvelle_note);
	}
	delete x;
}

PluriNotes::~PluriNotes()
{
    NotesManager::freeManager();
}
