#ifndef TACHEEDITEUR_H
#define TACHEEDITEUR_H

#include "NoteEditeur.h"
#include "tache.h"
#include <QDate>
#include <QDateEdit>
#include <QRadioButton>
#include <QSpinBox>
#include <QRadioButton>
#include <QButtonGroup>
#include <QCheckBox>
#include <QComboBox>

class TacheEditeur : public NoteEditeur
{
    Q_OBJECT

private:

    friend class NoteViewer;


    /**
     * \brief Layout local de l'editeur de tache
     */

    QVBoxLayout * localLayout;

    /**
     * \brief H1 Layout local de l'editeur de tache attribué à la gestion de la priorité
     *
     */

    QHBoxLayout * h1;

    /**
     * \brief H2 Layout local de l'editeur de tache attribué à la gestion du status
     *
     */

    QHBoxLayout * h2;

    /**
     * \brief H3 Layout local de l'editeur de tache attribué à la gestion de l'echeance
     *
     */

    QHBoxLayout * h3;

    /**
     * \brief Label contenant "action"
     *
     */

    QLabel* actionl;

    /**
     * \brief Champ d'édition de l'action de la tache
     *
     */

    QTextEdit *action;

    /**
     * \brief Check Box permettant de modifier echue de la tache
     *
     */

    QCheckBox * echue;

    /**
     * \brief Label contenant "echeance"
     *
     */

    QLabel* echeancel;

    /**
     * \brief Champ d'édition de la date échéance de la tache
     *
     */

    QDateEdit *echeance;

    /**
     * \brief Check Box permettant de modifier priorise de la tache
     *
     */

    QCheckBox * priorise;

    /**
     * \brief Label contenant "priorité"
     *
     */

    QLabel* prioritel;

    /**
     * \brief Menu déroulant modifier la priorité parmi ("Fort", "Moyenne", "Faible") de la tache
     *
     */

    QComboBox *priorite;

    /**
     * \brief Label contenant "status"
     *
     */

    QLabel* statusl;

    /**
     * \brief boutton radio ayant pour valeur "en attente"
     *
     */

    QRadioButton *en_attente;

    /**
     * \brief boutton radio ayant pour valeur "en cours"
     *
     */

    QRadioButton *en_cours;

    /**
     * \brief boutton radio ayant pour valeur "terminee"
     *
     */

    QRadioButton *terminee;

    /**
     * \brief Regroupement des radios buttons pour modifier le status de la tache
     *
     */

    QButtonGroup *status;


    void sauvegardeAttributs();  

protected :

    /**
    * \brief    Constructeur de l'editeur.
    * \param    a  Tache* vers la tache qui sera affiché dans l'éditeur.
    */


    TacheEditeur(Tache* a, QWidget *parent = 0);

public:

    /**
    * \brief    Constructeur de l'editeur.
    * \param    a Tache* vers la tache qui sera affiché dans l'éditeur.
    */

    ~TacheEditeur();

public slots :

};

#endif // TACHEEDITEUR_H
