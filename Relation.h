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
};

class Relation
{
private:
    QString title;
    QString description;
    bool oriented;
    QVector < std::pair<Couple*,QString> > couples;


public:
    Relation(QString t,QString d="", bool o = true);
    bool isOriented() const{ return oriented;}
    void setTitle(const QString& t) {title=t;}
    void setDescription(const QString& d) {description=d;}
    QString getTitle() const { return title;}
    QString getDescription() const { return description;}

    //on ne retourne pas couples entierement pour cacher le stockage des couples
    unsigned int getSize() const { return couples.size();}
    Couple* getCouple(unsigned int i) const {
        if (i<couples.size())
            return couples[i].first;
        else return nullptr;
    }
    void addCouple(QString& p, QString& f, QString& l);
};

#endif // RELATION_H
