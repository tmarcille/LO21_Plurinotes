#pragma once

#include <QFrame>
#include <QGridLayout>
#include <QParallelAnimationGroup>
#include <QScrollArea>
#include <QToolButton>
#include <QWidget>
#include <QGraphicsItem>
#include <QList>
#include <QGraphicsView>


class Edge;
class RelationTree;

class Node : public QGraphicsSimpleTextItem
{
public:
    /**
    * \brief    Constructeur du noeud.
    * \param    graphWidget  Arbre auquel on ajoute le noeud.
    * \param    text  Texte du noeud.
    */
    Node(RelationTree *graphWidget, QString text);

protected:

private:
    /**
     * \brief Arbre auquel appartient le noeud
     */
    RelationTree *graph;
};


class Edge : public QGraphicsItem
{
public:

    /**
    * \brief    Constructeur d'un arc.
    * \param    sourceNode  Noeud d'origine de l'arc.
    * \param    destNode  Noeud de destination de l'arc.
    * \param    text  Texte affiché a cote de l'arc.
    */
    Edge(Node *sourceNode, Node *destNode, QString text);

    /**
     * \brief    Ajuste l'arc lors des changements sur les noeuds.
     */
    void adjust();

    enum { Type = UserType + 2 };
    int type() const override { return Type; }

protected:
    /**
     * \brief Renvoie la place occupée par la fleche.
     * \return Coordonnees du rectangle recouvrant la fleche.
     */
    QRectF boundingRect() const override;

    /**
     * \brief Paint la fleche dans la scene.
     */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:

    /**
     * \brief    Node source de l'arc.
     */
    Node *source;

    /**
     * \brief    Node destination de l'arc.
     */
    Node *dest;

    /**
     * \brief    Coordonnees de l'origine de l'arc.
     */
    QPointF sourcePoint;
    /**
     * \brief    Coordonnees de l'extremite de l'arc.
     */
    QPointF destPoint;

    /**
     * \brief    Taille de l'arc.
     */
    qreal arrowSize;

    /**
     * \brief    Texte affiche a cote de l'arc.
     */
    QString text;

};


class RelationTree :  public QGraphicsView
{
    Q_OBJECT

public:

    /**
     * \brief    Constructeur d'un arbre.
     * \details Cree une scene ou afficher les elements de l'arbre
     * et la redimensionne correctement.
     */
    RelationTree(QWidget *parent = 0);

    /**
     * \brief    Ajoute un ascendant a l'arbre.
     * \details Cree un nouveau noeud pere a la bonne position
     * dans la scene et le relie par une fleche a la racine de
     * l'arbre.
     *\param a Nom du noeud a ajouter
     * \param relation Texte a afficher a cote de l'arc qui va être cree
     */
    void addAsc(QString a, QString relation);

    /**
     * \brief    Ajoute un descendant a l'arbre.
     * \details Cree un nouveau noeud fils a la bonne position
     * dans la scene et le relie par une fleche a la racine de
     * l'arbre.
     *\param a Nom du noeud a ajouter
     * \param relation Texte a afficher a cote de l'arc qui va être cree
     */
    void addDesc(QString b, QString relation);

    /**
     * \brief    Ajoute une racine a l'arbre.
     * \details Cree un nouveau noeud racine et le positionne au centre de la scene.
     *\param a Nom de la racine.
     */
    void addRoot(QString a);

    /**
     * \brief    Supprime l'arbre de la scene.
     * \details Efface l'arbre et remet le nombre de descendants/ascendants a 0.
     */
    void clearTree();

public slots:

protected:

private:
    /**
     * \brief  Scene dans laquelle on va afficher l'arbre.
     */
    QGraphicsScene *scene;

    /**
     * \brief  Noeud qui va être pris comme racine de l'arbre.
     */
    Node *centerNode;

    /**
     * \brief  Nombre de descendants de la racine.
     */
    int DescNb;

    /**
     * \brief  Nombre d'ascendants de la racine.
     */
    int AscNb;
};
