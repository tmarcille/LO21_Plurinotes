#include "tache.h"
#include <QFile>
#include <QTextCodec>
#include <QtXml>
#include <QMessageBox>


void Tache::saveAttributesInFile(QXmlStreamWriter & stream) const
{
    stream.writeTextElement("action", getAction());
    stream.writeTextElement("status", getStatus());
    stream.writeTextElement("priorite", getPriorite());
    stream.writeTextElement("echeance", echeance.toString("d.M.yyyy"));
}

Note * Tache::clone() const
{
    return new Tache(*this);
}

Tache::Tache(const QString& i, const QString& folder, const QString& ti, const QString& a="", const QDate &d=QDate(0,0,0), const QString &p="0", const QString &s="en attente") : Note(i,folder,ti), action(a), echeance(d), priorite(p.toInt()), status(s)
{qDebug()<<"creation de la tache"<<"action:"<<action<<"echeance:"<<echeance.toString("d.M.yyyy")<<"priorite:"<<priorite<<"status"<<status<<this->getType();}


QString Tache::getType() const
{
    return QString("tache");
}

void Tache::setAction(const QString& a) {
    action = a ;
}

void Tache::setStatus(const QString& s) {
            status=s;
}

void Tache::setEcheance(const QDate& d) {
    echeance = d ;
}

void Tache::setPriorite(const QString& p) {
    priorite = p.toInt();
}


