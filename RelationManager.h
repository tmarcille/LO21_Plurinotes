#ifndef RELATIONMANAGER_H
#define RELATIONMANAGER_H
#include "NoteManager.h"
#include "Relation.h"
#include <QVector>

class RelationManager
{
private:

    /**
     * \brief Adresse du fichier ou sont enregistrees les relations.
     */
    QString filename;

    /**
     * \brief pointeur vers l'unique instance du manager.
     */
    static RelationManager* instance;
    RelationManager();
    ~RelationManager();
    RelationManager(const RelationManager& m);
    RelationManager& operator=(const RelationManager& m);

    /**
     * \brief QVector de pointeurs vers les Relation contenues dans le manager.
     */
    QVector<Relation*> relations;

public:

    /**
     * \brief    Renvoie l'unique instance du manager. Si celui-ci n'existe
     * pas, il est cree.
     * \return   Reference vers l'unique RelationManager.
     */
    static RelationManager& getManager();

    /**
     * \brief    Libere la memoire utilisee par le manager.
     * \details Celui-ci peut être reconstruit plus tard en appelant getManager().
     */
    static void freeManager();

    /**
     * \brief    Modifie le fichier de stockage des relations.
     * \param    f  QString contenant l'adresse du nouveau fichier.
     */
    void setFilename (const QString& f) { filename = f; }

    /**
     * \brief    Retourne le fichier de stockage des Relation.
     * \return   QString contenant l'adresse du fichier de stockage des Relation.
     */
    QString getFilename() const {return filename;}

    /**
     * \brief Retourne la Relation avec le titre \a name.
     * \param title QString& référencant le titre a rechercher.
     * \return Une référence vers la Relation si elle est trouvée (renvoie une erreur si elle n'existe pas).
     */
    Relation* getRelation(const QString& title);

    /**
     * \brief    Ajoute une Relation au manager.
     * \details  Si une relation avec le même \a titre existe déjà, on ne fait pas l'ajout.
     * \param r Pointeur vers la Relation a ajouter au manager.
     */
    void addRelation(Relation* r);

    /**
     * \brief    Ajoute une Relation au manager.
     * \details  Si une relation avec le même \a titre existe déjà, on renvoie un pointeur null.
     * Sinon, on cree une Relation puis on l'ajoute avec addRelation().
     * \param t Titre de la relation.
     * \param d Description de la relation.
     */
    Relation* addRelation(const QString t,const QString d="", bool o = true);

    /**
     * \brief    Retire une Relation du manager.
     * \param t Titre de la relation a retirer.
     */
    void removeRelation(const QString& t);

    /**
     * \brief    Sauvegarde toutes les Relation du manager dans le fichier indique par \a filename.
     */
    void save() const;

    /**
     * \brief    Chargement des relations.
     * \details  Lit les relations sauvegardées dans le fichier indique par \a filename puis
     * les ajoute au manager. Lit egalement les couples contenues dans chaque relation, mais ne les
     * ajoute que si les deux notes du couple sont presentes dans le NoteManager.
     */
    void load();

    using iterator = QVector<Relation*>::iterator;
    using const_iterator = QVector<Relation*>::const_iterator;

    /**
     * \brief    Iterateur sur les relations du manager.
     */
    iterator begin() { return relations.begin(); }
    iterator end() { return relations.end(); }
    /**
     * \brief    Iterateur constant sur les relations du manager.
     */
    const_iterator begin() const { return relations.begin(); }
    const_iterator end() const { return relations.end(); }
    const_iterator cbegin() const { return relations.cbegin(); }
    const_iterator cend() const { return relations.cend(); }

};

#endif // RELATIONMANAGER_H
