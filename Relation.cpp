#include "Relation.h"

Relation::Relation(QString t,QString d, bool o) : oriented(o),title(t),description(d)
{

}

void Relation::addCouple(Note* f, Note* s, QString l){

    struct Couple* c = new struct Couple;
    c->father=f;
    c->son=s;
    c->label = l;
    addCouple(c);
    qDebug()<<"added couple to relation: "<<this->title;
}

void Relation::addCouple(Couple* c){
    couples.append(c);
}


QVector<QString> Relation::getAscendants(const QString& id) const{

    qDebug()<<"searching asc";
    QVector<Couple*>::const_iterator it;
    QVector<QString> asc;
    for (it = Relation::couples.begin(); it!=Relation::couples.end(); it++ ){
        if ((*it)->son->getId()==id){
            asc.push_back((*it)->father->getId());
            qDebug()<<"found asc";
        }
    }
    return asc;
}

QVector<QString> Relation::getDescendants(const QString& id) const{

    QVector<Couple*>::const_iterator it;
    QVector<QString> dsc;
    for (it = Relation::couples.begin(); it!=Relation::couples.end(); it++ ){
        if ((*it)->father->getId()==id){
            dsc.push_back((*it)->son->getId());
            qDebug()<<"found dsc";
        }
    }
    return dsc;
}
