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

/**
 * \brief La classe Plurinote permet de lancer l'application et sa fenetre
 * \details La classe Plurinote permet d'ouvrir le projet, charger les settings et mettre à jours les editeurs
 *
 */
class PluriNotes : public QMainWindow,  public Observer<Note>, public Observer<NoteViewer>
{
	Q_OBJECT

public:
    explicit PluriNotes(QWidget *parent = Q_NULLPTR);
    virtual ~PluriNotes();

    /**
     * \brief Initialise l'application
     * \details Charge les différentes informations contenues dans les fichiers.
     */
    void ouvrirProjet();

    /**
     * \brief Crée l'affichage ergonomimque des notes
     * \details Recupere les taches parmis les notes et l'affiche par ordre de priorité.
     */
    void createTaskList();

    /**
     * \brief Applique les paramètres du fichier config au projet.
     */
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

    /**
     * \brief Verifications effectuées lorsque l'utilisateur ferme l'application.
     */
    void closeEvent(QCloseEvent * event);

    /**
     * \brief Chemin vers le fichier config.
     */
    QString m_sSettingsFile;

public slots:

    /**
     * \brief Ouvre la fenetre des parametres à l'aide de la classe SettingsDialog.
     */
    void openSettings();

    /**
     * \brief Ouvre la fenetre de gestion des relations à l'aide de la classe RelationEditor.
     */
    void openRelations();

    /**
     * \brief Ouvre une note de la liste.
     * \param item Item de la liste représentant la note à ouvrir.
     */
	void ouvrirNote(QListWidgetItem* item);

    /**
     * \brief Ouvre la fenetre de creation d'une note à l'aide de la classe NouvelleNote.
     */
	void nouvelleNote();

    /**
     * \brief Reaction de l'interface graphique lorsqu'on appuie sur le bouton Arborescence.
     */
    void reactToPannelToggle(bool);

    /**
     * \brief Reaction du projet quand on clique sur le bouton Remove Note.
     * \details Place la note selectionne dans la corbeille.
     */
    void removeBtnClicked();

    /**
     * \brief Reaction du projet quand on clique sur le bouton Restore Note.
     * \details Enleve la note selectionne de la corbeille et la replace dans la liste
     * des notes.
     */
    void restoreBtnClicked();

private slots:
};


/**
 * \brief Fenetre de verification de vidage de la corbeille.
 */
class VidageCorbeille : public QDialog
{
public:

    VidageCorbeille(QWidget *parent = 0) :QDialog(parent)
    {
        Vlayout = new QVBoxLayout(this);
        Hlayout = new QHBoxLayout(this);

        text = new QLabel("Des élèments sont présents dans la corbeille. Les restaurer ?");
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
