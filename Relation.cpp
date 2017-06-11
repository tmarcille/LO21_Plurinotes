#include "Relation.h"

Relation::Relation(QString t,QString d, bool o) : oriented(o),title(t),description(d)
{

}

void Relation::addCouple(Note* f, Note* s, QString l){

    struct Couple* c = new struct Couple;
    c->father=f;
    c->son=s;
    c->label = l;
    couples.append(c);
    qDebug()<<"added couple to relation: "<<this->title;
}
