#ifndef RELATION_H
#define RELATION_H
#include "Notes.h"
class Couple{
private :
    QString label;
    Note * origine;
    Note * reference;
    bool orientation;
public :
    Couple(Note* o, Note* r, const QString & l = "", bool orient = true):origine(o),reference(r),label(l), orientation(orient){}
    const Note * getOrigine(){return origine;}
    const Note * getReference() const {return reference;}
    const QString getLabel() const {return label;}
    const bool getOrientation() const {return orientation;}
    void setOrigine(const Note * o){origine = o;}
    void setReference(const Note * r) {reference = r;}
    void setLabel(const QString& l) {label = l;}
    void setOrientation(const bool b) {orientation = b;}
    ~Couple (){}
};

// modifier dans relation ajouter la mise à jour du couple avec les dernière version de note

class Relation{
private :
    QString titre;
    QString description;
    Couple ** tab;
    int nbCouple;
    int nbMaxCouple;
public :
    Relation(const QString& t, const QString& d):titre(t), description(d),nbCouple(O), nbMaxCouple(0){}
    void add(const Couple *);
    ~Relation(){delete [] tab;}
};

void Relation::add(Couple* c) {
    for (unsigned int i = 0; i<nbCouple; i++) {
        if (c->setOrigine==tab[i]->getOrigine() && c->getReference()==tab[i]->getReference()) throw NotesException("error, relation already exists");
    }
    if (nbCouple == nbMaxCouple) {
        Couple ** nouv = new Couple*[nbMaxCouple + 5];
        nbMaxCouple += 5;
        for (unsigned int i = 0; i<nbCouple; i++) nouv[i] = tab[i];
        Couple** anc = tab;
        notes = nouv;
        if (anc) delete[] anc;
    }
    tab[nbCouple++] = c;
}

// recherche du groupe \ref{...}
// declaration de la relation references

static Relation

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


#endif // RELATION_H
