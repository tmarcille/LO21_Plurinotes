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
    stream.writeTextElement("echue", getEchue());
}

Note * Tache::clone() const
{
    return new Tache(*this);
}

Tache::Tache(const QString& i, const QString& folder, const QString& ti, const QString& a="", const QDate &d=QDate(0,0,0), const QString &p="0", const QString &s="en attente", const bool &e = false) : Note(i,folder,ti), action(a), echeance(d), priorite(p.toInt()), status(s), echue(e)
{qDebug()<<"creation de la tache"<<"action:"<<action<<"echeance:"<<echeance.toString("d.M.yyyy")<<"priorite:"<<priorite<<"status"<<status<<this->getType();}


QString Tache::getType() const
{
    return QString("tache");
}

QString Tache::getEchue() const
{
    QString s;
    if (echue) s = "T";
    else s = "F";
    return s;
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

void Tache::setEchue(const QString& e) {
    if (e=="T") echue=true;
    else echue=false;
}

