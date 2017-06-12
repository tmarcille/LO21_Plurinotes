#ifndef RELATION_H
#define RELATION_H
#include <QString>
#include <map>
#include <QDebug>
#include <typeinfo>
#include <QFile>
#include <QTextCodec>
#include <QtXml>
#include "Notes.h"

struct Couple{
    Note* father;
    Note* son;
    QString label;
};

class Relation
{
private:
    QString title;
    QString description;
    bool oriented;
    QVector <Couple*> couples;


public:
    Relation(QString t,QString d="", bool o = true);
    bool isOriented() const{ return oriented;}
    void setTitle(const QString& t) {title=t;}
    void setDescription(const QString& d) {description=d;}
    QString getTitle() const { return title; }
    QString getDescription() const { return description;}

    //on ne retourne pas couples entierement pour cacher le stockage des couples (ici un vecteur)
    unsigned int getSize() const { return couples.size();}
    Couple* getCouple(int i) const {
        if (i < couples.size())
            return couples[i];
        else return nullptr;
    }
    void addCouple(Note* p, Note* f, QString l="");
    void removeCouple(int i){
        if (i < couples.size()){
            couples.remove(i);
            qDebug()<<"removed couple";
        }
    }
    QVector<QString> getAscendants(const QString&) const;
    QVector<QString> getDescendants(const QString&) const;

};

#endif // RELATION_H
