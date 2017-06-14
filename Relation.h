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
    /**
     * \brief Note pere du couple.
     */
    Note* father;
    /**
     * \brief Note fils du couple.
     */
    Note* son;
    /**
     * \brief Label du couple.
     */
    QString label;
};

class Relation
{
private:

    friend class RelationManager;
    /**
     * \brief Titre de la relation.
     */
    QString title;
    /**
     * \brief Description de la relation.
     */
    QString description;
    bool oriented;

    /**
     * \brief Vecteur des couples associes a la relation.
     */
    QVector <Couple*> couples;

protected:

    /**
     * \brief Constructeur d'une relation.
     * \details Initialement une relation n'a pas de couples associes.
     * \param t Titre de la relation
     * \param d Description de la relation
     * \param o
     */
    Relation(QString t,QString d="", bool o = true);

public:

    virtual ~Relation(){}

    bool isOriented() const{ return oriented;}

    /**
     * \brief    Modifie le titre de la Relation.
     * \param    t  QString contenant la nouvelle valeur du titre.
     */
    void setTitle(const QString& t) {title=t;}

    /**
     * \brief    Modifie la description de la relation.
     * \param    t  QString contenant la nouvelle valeur de la description.
     */
    void setDescription(const QString& d) {description=d;}

    /**
     * \brief    Retourne le titre de la relation.
     * \return   Un QString contenant le titre de la relation
     */
    QString getTitle() const { return title; }

    /**
     * \brief    Retourne la description de la relation.
     * \return   Un QString contenant la description de la relation
     */
    QString getDescription() const { return description;}

    //on ne retourne pas couples entierement pour cacher le stockage des couples (ici un vecteur)
    /**
     * \brief    Retourne le nombre de couples dans la Relation.
     * \return   Nombre de couples dans la Relation.
     */
    unsigned int getSize() const { return couples.size();}

    /**
     * \brief    Permet d'acceder a un couple precis de la Relation.
     * \param    i Position du couple que l'on veut récuperer.
     * \return   Pointeur vers le couple a la position \a i.
     */
    Couple* getCouple(int i) const {
        if (i < couples.size())
            return couples[i];
        else return nullptr;
    }

    /**
     * \brief    Ajoute un couple a la relation.
     * \details  Cree un Couple avec les parametres transmis puis appelle addCouple(Couple* c).
     * \param f  Note pere du couple
     * \param s  Note fils du couple
     * \param l  Label du couple
     */
    void addCouple(Note* p, Note* f, QString l="");

    /**
     * \brief    Ajoute un couple a la relation.
     * \param    c Couple a ajouter.
    */
    void addCouple(Couple* c);

    /**
     * \brief    Retire un couple a la relation.
     * \param  i Position du couple a retirer.
    */
    void removeCouple(int i){
        if (i < couples.size()){
            couples.remove(i);
            qDebug()<<"removed couple";
        }
    }

    /**
     * \brief    Cherche les ascendants d'une note.
     * \details Parcours tout les Couple de la relation a la recherche de ceux
     * ayant la note correspondant a l'id comme \a son.
     * \param id ID de la note dont on veut les ascendants.
     * \return QVector<QString> contenant les IDs des notes ascendantes.
    */
    QVector<QString> getAscendants(const QString& id) const;

    /**
     * \brief    Cherche les descendants d'une note.
     * \details Parcours tout les Couple de la relation a la recherche de ceux
     * ayant la note correspondant a l'id comme \a father.
     * \param id ID de la note dont on veut les descendants.
     * \return QVector<QString> contenant les IDs des notes descendantes.
    */
    QVector<QString> getDescendants(const QString& id) const;

};

#endif // RELATION_H
