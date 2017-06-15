#ifndef TACHE_H
#define TACHE_H
#include "Notes.h"
#include <QDate>
#include "QDebug"
//#define NBSTATUS 3
//namespace st {
//extern QString Tostatus[NBSTATUS] = {"en attente","en cours","terminee"};
//}

/**
 * \brief La classe Tache hérite de Note
 * \details Une tache possède une action, une priorité, une échéance et un status
 */

class Tache : public Note {
private:
    friend class NotesManager;

    /**
    * \brief    Action de la tache
    */

    QString action;

    /**
    * \brief    Priorité de la tache
    * \value    parmi {"Faible", "Moyenne", "Forte"}
    */

    QString priorite;

    /**
    * \brief    Status de la tache
    * \value    parmi {"en attente", "en cours", "terminee"}
    */

    QString status;

    /**
    * \brief    La date Echeance de la tache
    * \value    format QDate
    */

    QDate echeance;

    /**
    * \brief    Echue, boolean qui permet savoir si l'on doit prendre en compte la date échéance
    */

    bool echue;

    /**
    * \brief    Priorise, boolean qui permet savoir si l'on doit prendre en compte la priorite
    */

    bool priorise;

    void saveAttributesInFile(QXmlStreamWriter& stream) const;

protected :
    Tache(  const QString& f, const QString& ti, const QString& a="", const QDate &d=QDate(0,0,0), const QString &p="Faible", const QString &s="en attente", const bool &e = false, const bool &ps = false);

public:

    /**
     * \brief    Retourne l'action de la tache
     * \return   QString contenant l'action
     */

    QString getAction() const {return action;}

    /**
     * \brief    Retourne la priorité de la tache
     * \return   QString parmi {"Faible", "Moyenne", "Forte"}
     */

    QString getPriorite() const {return priorite;}

    /**
     * \brief    Retourne le status de la tache
     * \return   QString parmi {"en attente", "en cours", "terminee"}
     */

    QString getStatus() const {return status;} 

    /**
     * \brief    Retourne l'échéance de la tache
     * \return   QDate que l'on convertira en string par la suite pour l'enregistrement dans le XML
     */

    QDate getEcheance() const {return echeance;}

    /**
     * \brief    Retourne le boolean echue de la tache
     * \return   QString parmis {"T","F"} pour faciliter l'insertion dans le XML
     */

    QString getEchue() const;

    /**
     * \brief    Retourne le boolean priorise de la tache
     * \return   QString parmis {"T","F"} pour faciliter l'insertion dans le XML
     */

    QString getPriorise() const;

    /**
     * \brief    Retourne un nombre sous forme de Qstring pour faciliter le tri des taches en fonction de leur priorité
     * \return   QString parmi
     *          "1" -> "Forte"
     *          "2" -> "Moyenne"
     *          "3" -> "Faible"
     *          "4" -> pas de priorité
     */

    QString getIntPriorite() const;

    /**
     * \brief    Retourne le type de la note
     * \return   QString contenant "tache"
     */

    QString getType() const;

    /**
     * \brief    Permet de modifier l'action de la tache
     * \param    t  QString contenant la nouvelle valeur de \a action
     */

    void setAction(const QString& t);

    /**
     * \brief    Permet de modifier la priorité de la tache
     * \param    p  QString contenant la nouvelle valeur de \a priorite
     */

    void setPriorite(const QString& p);

    /**
     * \brief    Permet de modifier le status de la tache
     * \param    s QString contenant la nouvelle valeur de \a status
     */

    void setStatus(const QString& s);

    /**
     * \brief    Permet de modifier le'cheance de la tache
     * \param    d QString contenant la nouvelle valeur de \a echeance
     */

    void setEcheance(const QDate & d);

    /**
     * \brief    Permet de modifier echue de la tache
     * \param    e QString contenant la nouvelle valeur de \a echue
     */

    void setEchue(const QString & e);

    /**
     * \brief    Permet de modifier priorise de la tache
     * \param    ps QString contenant la nouvelle valeur de \a echue
     */

    void setPriorise(const QString &ps);
};

#endif // TACHE_H
