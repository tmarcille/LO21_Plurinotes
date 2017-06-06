#ifndef RELATIONMANAGER_H
#define RELATIONMANAGER_H
#include "relation.h"

class RelationManager {
private:
    Relation** relations;
    unsigned int nbRelation;
    unsigned int nbMaxRelation;
    void addRelation(Note* n);

    RelationManager();
    ~RelationManager();
    RelationManager(const Relationanager& m);
    RelationManager& operator=(const RelationManager& m);

public:
    Note& showRelation() const; // return the article with identificator id (create a new one if it not exists)
    bool isrefered(const Note* n);

    static RelationManager& getManager();
    static void freeRManager(); // free the memory used by the NotesManager; it can be rebuild later

    Note* create(const Relation * o,const Relation * r, bool ) //crée un note et l'ajoute a la liste (pas de note pas dans la liste -> pose un pb plus tard ?)
    {
        Relation* relation = NULL;
        relation = new Tache(id,foldername,title,action,echeance,priorite,status);
        addNote(note);
        return note;
    }

    NoteEditeur* createEditor(Note* n) {



       /************************** vector des editeurs ouverts dans le projet, commenté ou cas où il serait utile
        * plus tard.
        * Si suppression, supprimer aussi le vector static dans noteEditeur.

        QVector<NoteEditeur*>::iterator it;

        for (it = NoteEditeur::editeurs.begin(); it!=NoteEditeur::editeurs.end(); it++ ){

            if((*it)->getId()==n->getId()){

                qDebug()<<"returned existing editor";
                return *it;

            }
        }
*/
        qDebug()<<"ajout editeur";
        NoteEditeur* edit = NULL;
        QString type = n->getType();
        qDebug()<<"type : "<<type;
        if (type == "article") {
            edit = new ArticleEditeur(dynamic_cast<Article*>(n));
            qDebug()<<"article";

        }
        if (type == "media") {
            edit = new MediaEditeur(dynamic_cast<Media*>(n));
            qDebug()<<"media";

        }
        if (type == "tache") {
            edit = new TacheEditeur(dynamic_cast<Tache*>(n));
            qDebug()<<"tache";
        }
        return edit;
    }



    class Iterator {
        friend class NotesManager;
        Note** currentN;
        unsigned int nbRemain;
        Iterator(Note** a, unsigned nb) :currentN(a), nbRemain(nb) {}
    public:
        Iterator() :nbRemain(0), currentN(nullptr) {}
        bool isDone() const { return nbRemain == 0; }
        void next() {
            if (isDone())
                throw NotesException("error, next on an iterator which is done");
            nbRemain--;
            currentN++;
        }
        Note& current() const {
            if (isDone())
                throw NotesException("error, indirection on an iterator which is done");
            return **currentN;
        }
    };
    Iterator getIterator() {
        return Iterator(notes, nbNotes);
    }

    class ConstIterator {
        friend class NotesManager;
        Note** currentN;
        unsigned int nbRemain;
        ConstIterator(Note** a, unsigned nb) :currentN(a), nbRemain(nb) {}
    public:
        ConstIterator() :nbRemain(0), currentN(0) {}
        bool isDone() const { return nbRemain == 0; }
        void next() {
            if (isDone())
                throw NotesException("error, next on an iterator which is done");
            nbRemain--;
            currentN++;
        }
        const Note& current() const {
            if (isDone())
                throw NotesException("error, indirection on an iterator which is done");
            return **currentN;
        }
    };
    ConstIterator getIterator() const {
        return ConstIterator(notes, nbNotes);
    }
};


#endif // RELATIONMANAGER_H
