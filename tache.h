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
    QString action;
    int priorite;
    QString status;
    QDate echeance;
    bool echue;
    void saveAttributesInFile(QXmlStreamWriter& stream) const;

public:
    Note* clone() const;
    Tache(const QString& i, const QString& folder,const QString& ti, const QString& a, const QDate &d, const QString &p, const QString &s, const bool &e);
    QString getAction() const {return action;}
    QString getPriorite() const {return QString::number(priorite);}
    QString getStatus() const {return status;}
    QDate getEcheance() const {return echeance;}
    QString getEchue() const;
    QString getType() const;

    void setAction(const QString& t);
    void setPriorite(const QString& p);
    void setStatus(const QString& s);
    void setEcheance(const QDate & echeance);
    void setEchue(const QString & e);
};

#endif // TACHE_H
