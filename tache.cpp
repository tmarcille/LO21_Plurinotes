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
    stream.writeTextElement("piorisee", getPriorise());
}

Note * Tache::clone() const
{
    return new Tache(*this);
}

Tache::Tache(const QString& i, const QString& folder, const QString& ti, const QString& a="", const QDate &d=QDate(0,0,0), const QString &p="Faible", const QString &s="en attente", const bool &e = false, const bool &ps = false) : Note(i,folder,ti), action(a), echeance(d), priorite(p), status(s), echue(e),priorise(ps)
{qDebug()<<"creation de la tache"<<"action:"<<action<<this->getEchue()<<"echeance:"<<echeance.toString("d.M.yyyy")<<this->getPriorise()<<"priorite:"<<priorite<<"status"<<status<<this->getType();}


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

QString Tache::getPriorise() const
{
    QString s;
    if (priorise) s = "T";
    else s = "F";
    return s;
}

QString Tache::getIntPriorite() const{
    int i=4;
    if (priorise){
        if (priorite=="Forte")
            i=1;
        if (priorite=="Moyenne")
            i=2;
        if (priorite=="Faible")
            i=3;
    }
    return QString::number(i);
}

void Tache::setAction(const QString& a) {
    action = a ;
}

void Tache::setStatus(const QString& s) {
            status=s;
}

void Tache::setEcheance(const QDate& d) {
    echeance = d ;
    notify();
}

void Tache::setPriorite(const QString& p) {
    priorite = p;
}

void Tache::setEchue(const QString& e) {
    if (e=="T") echue=true;
    else echue=false;
    notify();

}

void Tache::setPriorise(const QString& ps) {
    if (ps=="T") priorise=true;
    else priorise=false;
}
