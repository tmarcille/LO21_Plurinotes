#ifndef RELATIONMANAGER_H
#define RELATIONMANAGER_H
#include "NoteManager.h"
#include "Relation.h"
#include <QVector>



class RelationManager
{
private:

    QString filename;
    static RelationManager* instance;
    RelationManager();
    ~RelationManager();
    QVector<Relation*> relations;

public:
    static RelationManager& getManager();
    static void freeManager(); // free the memory used by the RelationManager; it can be rebuild later
    void setFilename (const QString& f) { filename = f; }
    QString getFilename() const {return filename;}
    Relation* getRelation(const QString& name);
    void addRelation(Relation*);
    Relation* addRelation(const QString t,const QString d="", bool o = true);
    void save() const;
    void load();

    using iterator = QVector<Relation*>::iterator;
    using const_iterator = QVector<Relation*>::const_iterator;

    iterator begin() { return relations.begin(); }
    iterator end() { return relations.end(); }
    const_iterator begin() const { return relations.begin(); }
    const_iterator end() const { return relations.end(); }
    const_iterator cbegin() const { return relations.cbegin(); }
    const_iterator cend() const { return relations.cend(); }

};

#endif // RELATIONMANAGER_H
