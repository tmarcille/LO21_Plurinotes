#ifndef NOTEVIEWER_H
#define NOTEVIEWER_H

#include <QWidget>
#include <QTabWidget>
#include "NoteEditeur.h"
#include "MediaEditeur.h"
#include "ArticleEditeur.h"
#include "tacheediteur.h"
#include <QLayout>

/**
 * \brief La classe NoteViewer permet de gérer les editeurs de notes
 * \details La classe NoteViewer permet de créer, afficher, rafraichir, supprimer les editeurs
 *
 */

class NoteViewer : public QWidget, public Subject<NoteViewer> //widget des noteEditeur permettant un affichage plus complexe avec plusieurs notes a la fois.
{
    Q_OBJECT
public:

    /**
     * \brief Constructeur d'un NoteViewer.
     */
    explicit NoteViewer(QWidget *parent = 0);

    /**
     * \brief Affiche une note dans le widget
     * \details Si la note est deja affichee dans le NoteViewer, on la focus.
     * Sinon, on cree le NoteEditeur correspondant grace a createEditor(), puis on affiche
     * celui ci.
     * \param note Note* vers la note que l'on veut afficher dans le NoteViewer.
     */
    void showNote(Note* note);

    /**
     * \brief Ferme l'affichage d'une note.
     * \details Si une note avec cet id est ouverte, on ferme l'onglet correspondant avec closeTab().
     * \param id QString& contenant l'\a id de la note que dont on veut fermer l'affichage.
     */
    void closeNote(const QString& id);

    /**
     * \brief Rafraichit l'affichage d'une note.
     * \details Recharge les parametres d'une Note afin d'afficher les changements.
     * L'avantage par rapport a une suppression puis un ajout etant que
     * l'onglet de la note ouverte reste à la même place.
     * \param id QString& contenant l'\a id de la note que dont on veut raffraichir l'affichage.
     */
    void refreshNote(const QString& id);

    /**
     * \brief Test si une Note est affichée.
     * \param id id QString& contenant l'\a id de la note dont on veut
     * savoir si elle est affichee ou non.
     * \return true si elle est affichée, false sinon.
    */
    bool isOpen(const QString& id) const;

    /**
     * \brief Fenetre actuellement focus.
     * \return QString contenant l'\a id de la Note sur laquelle est le focus dans le
     * NoteViewer. Si il n'y en a pas, renvoie "".
    */
    QString currentWindow() const;
    ~NoteViewer();
private:

    /**
     * \brief Layout principal de NoteViewer.
     */
    QHBoxLayout* layout;

    /**
     * \brief Widget dans lequel les NoteEditeur seront affichés. Ici un QTabWidget.
     */
    QTabWidget* tabWidget;

    /**
     * \brief Ferme un onglet de \a tabWidget.
     * \details avant de fermer l'onglet, vérifie si il ya des changements non sauvegardes
     * a l'aide de NoteEditeur::verifSave().
     * \param i Index de l'onglet a fermer.
     */
    void closeTab(int i);

    /**
     * \brief Cree un editeur.
     * \details La fonction recupere le type de la note passee en parametres pour
     * appeler le constructeur derive de NoteEditeur correspondant.
     * Si un editeur pour cette note existe déjà, on renvoie celui-ci au lieu d'en creer
     * un nouveau
     * \param n Note* vers la note pour laquelle on veut creer un editeur.
     * \return NoteEditeur correspondant a la note passe en parametre
     */
    NoteEditeur* createEditor(Note* n);


signals:


public slots:
    /**
     * \brief Change le nom de l'onglet de l'editeur pour indiquer qu'il est en cours d'edition.
     * \param n Le NoteEditeur en cours d'edition
     */
    void unsavedChanges(NoteEditeur* n); //slots qui changent le nom du tab afin d'indiquer

    /**
     * \brief Change le nom de l'onglet de l'editeur pour indiquer qu'il n'est plus en cours d'edition.
     * \param n Le NoteEditeur plus en cours d'edition
     */
    void saveChanges(NoteEditeur* n);    //si il est en cours d'edition ou non.

    /**
     * \brief Emet un signal notify() lorsqu'on passe la vue sur un autre editeur.
     */
    void currentChanged();
};

#endif // NOTEVIEWER_H
