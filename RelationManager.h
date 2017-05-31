#ifndef RELATIONMANAGER_H
#define RELATIONMANAGER_H
#include "NoteManager.h"
#include "Relation.h"
#include <QVector>

class RelationManager
{
private:

    QString filename;
    QVector<Relation*> relations;
    static RelationManager* instance;
    RelationManager();
    ~RelationManager();

public:

    static RelationManager& getManager();
    static void freeManager(); // free the memory used by the RelationManager; it can be rebuild later
    void setFilename (const QString& f) { filename = f; }
    QString getFilename() const {return filename;}
    Relation* getRelation(QString& name);
    void save() const;
    void load();
};

#endif // RELATIONMANAGER_H
