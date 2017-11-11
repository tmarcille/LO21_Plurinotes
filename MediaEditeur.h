#ifndef MEDIAEDITEUR_H
#define MEDIAEDITEUR_H
#include "Media.h"
#include "NoteEditeur.h"
#include "player.h"

/**
 * \brief Editeur du type de note Media
 * \details Ajoute un player video en plus des champs d'éditions par défaut de NoteEditeur.
 *
 */


class MediaEditeur : public NoteEditeur
{
    Q_OBJECT

private:

    friend class NoteViewer;

    /**
     * \brief Label du champ description.
     */
    QLabel* descriptionl;

    /**
     * \brief Champ d'édition du champ description.
     */
    QTextEdit *description;

    /**
     * \brief Label du champ fichier.
     */
    QLabel* fichierl;

    /**
     * \brief Champ d'édition du champ fichier.
     */
    QLineEdit *fichier;

    /**
     * \brief Player multimédia.
     */
    VideoPlayer* player;
    void sauvegardeAttributs();

protected :
    /**
    * \brief    Constructeur de l'editeur.
    * \param    m  Media* vers le média qui sera affiché dans l'éditeur.
    */
    MediaEditeur(Media* m, QWidget *parent = 0);

public:
    virtual ~MediaEditeur();

public slots:

    /**
    * \brief    Affichage d'un fichier.
    * \details Ouvre dans le player le fichier dont l'adresse a été passé en paramètre.
    *           Si l'adresse est vide, ouvre une fenêtre de sélection d'un fichier.
    * \param    f  QString contenant l'adresse du fichier a ouvrir.
    */
    void openFile(QString f="");
};

#endif // MEDIAEDITEUR_H
