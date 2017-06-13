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

    friend class NoteViewer;

    /**
     * \brief Note* vers la note affichée dans l'éditeur.
     */
	Note* note;

    /**
     * \brief Label du champ id.
     */
	QLabel* idl;

    /**
     * \brief Label du champ titre.
     */
	QLabel* titrel;


    /**
     * \brief Champ d'édition de l'id.
     */
	QLineEdit *id;

    /**
     * \brief Champ d'édition du titre.
     */
    QLineEdit *titre;

    /**
     * \brief Bouton de sauvegarde.
     */
	QPushButton* save;

    QHBoxLayout *titreLayout;
    QHBoxLayout *idLayout;
	
    /**
     * \brief Layout principal de l'editeur.
     */
    QVBoxLayout *mainLayout;

    /**
    * \brief      Sauvegarde les attributs de la classe fille
    * \details  Enregistre les changements fait dans l'editeur à la note affichée par celui-ci.
    *           sauvegarde() s'occupe des champs communs à toutes les notes tandis que
    *           sauvegardeAttributs() s'occupe des attributs spécifiques au type de note.
    */
	virtual void sauvegardeAttributs() = 0;

    NoteEditeur(NoteEditeur& );
    NoteEditeur& operator=(NoteEditeur const&);

protected :

    /**
    * \brief    Constructeur de l'editeur.
    * \param    a  Note* vers la note qui sera affichée dans l'éditeur.
    */
    NoteEditeur(Note* a, QWidget *parent = 0);


    /**
     * \brief Layout dans lequel les éditeurs spécialisés vont placer leurs ajouts.
     * \details  Le layout est déclaré en protected car seules les classes filles (cad les
     *           editeurs spécialisés) ont le droit d'y ajouter des elements.
     */
    QHBoxLayout *centralLayout;

    /**
     * \brief Renvoie la note affichée par l'editeur.
     * \return Note* vers la note.
     */
    Note* getNote() const { return note; }

public:
	virtual ~NoteEditeur();

    /**
     * \brief Renvoie l'id de la note affichée par l'editeur.
     * \return QString contenant l'id.
     */
    const QString getId() const { return id->text(); }

    /**
     * \brief Sauvegarde dans un fichier de la note affichée.
     * \details Sauvegarde les valeurs des paramètres de la note
     * dans un fichier.
     * Si des changements fait dans l'éditeur n'ont pas encore été sauvegardés, il
     * faut d'abord appelé verifSave() ou sauvegarde().
     */
    void saveNoteInFile() const { getNote()->saveInFile();}

    /**
     * \brief QVector contenant des pointeurs vers tout les éditeurs existants
     * au moment de l'appel.
     */
    static QVector<NoteEditeur*> editeurs;

signals:

    /**
     * \brief Signal émis lorsqu'une note a des changements non sauvegardés.
     * \param n NoteEditeur* vers l'editeur en train d'être modifié.
     */
    void currentlyEditing(NoteEditeur* n);

    /**
     * \brief Signal émis lorsqu'une note n'a plus de changements non sauvegardés.
     * \param n NoteEditeur* vers l'editeur qui vient de finir d'être modifié.
     */
    void finishedEditing(NoteEditeur* f);

public slots :

    /**
     * \brief Active le bouton sauvegarde de l'éditeur.
    */
	void activerSave();

    /**
     * \brief Sauvegarde les changements effectués dans l'éditeur.
     * \details Sauvegarde les changements dans les paramètres de l'objet Note en train
     *          d'être édité. Attention : ne sauvegarde pas les changements dans le fichier. Il faut
     *          pour cela appeler saveNoteInFile().
    */
	void sauvegarde();

    /**
     * \brief PopUp demandant si l'utilisateur veut sauvegarder les changements effectués.
     * \details Si à l'appel de ce slot, des changements n'ont pas été sauvegardés, affiche un widget
     * NoteEditeurFermeture. Si l'utilsateur accepte, sauvegarde les changements, sinon ne sauvegarde pas.
    */
	void verifSave();
};


//fenetre de verification de sauvegarde a la fermeture

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
