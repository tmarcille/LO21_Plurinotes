#ifndef TACHE_H
#define TACHE_H
#include "Notes.h"
#include <QDate>
#include "QDebug"
//#define NBSTATUS 3
//namespace st {
//extern QString Tostatus[NBSTATUS] = {"en attente","en cours","terminee"};
//}
class Tache : public Note {
private:
    friend class NotesManager;

    QString action;
    QString priorite;
    QString status;
    QDate echeance;
    bool echue;
    bool priorise;
    void saveAttributesInFile(QXmlStreamWriter& stream) const;

protected :
    Tache(  const QString& f, const QString& ti, const QString& a="", const QDate &d=QDate(0,0,0), const QString &p="Faible", const QString &s="en attente", const bool &e = false, const bool &ps = false);

public:
    Note* clone() const;
    QString getAction() const {return action;}
    QString getPriorite() const {return priorite;}
    QString getStatus() const {return status;}
    QDate getEcheance() const {return echeance;}
    QString getEchue() const;
    QString getPriorise() const;
    QString getIntPriorite() const;
    QString getType() const;

    void setAction(const QString& t);
    void setPriorite(const QString& p);
    void setStatus(const QString& s);
    void setEcheance(const QDate & echeance);
    void setEchue(const QString & e);
    void setPriorise(const QString &ps);
};

#endif // TACHE_H
