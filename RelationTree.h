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
    Node(RelationTree *graphWidget, QString text);

    void addEdge(Edge *edge);
    QList<Edge *> edges() const;

protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;

private:
    QList<Edge *> edgeList;
    RelationTree *graph;
};


class Edge : public QGraphicsItem
{
public:
    Edge(Node *sourceNode, Node *destNode, QString text);

    Node *sourceNode() const;
    Node *destNode() const;
    void adjust();

    enum { Type = UserType + 2 };
    int type() const override { return Type; }

protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    Node *source, *dest;
    QPointF sourcePoint;
    QPointF destPoint;
    qreal arrowSize;
    QString text;

};


class RelationTree :  public QGraphicsView
{
    Q_OBJECT

public:
    RelationTree(QWidget *parent = 0);
    QString getCentralNodeName(){ return centerNode->text();}
    void addAsc(QString a, QString relation);
    void addDesc(QString b, QString relation);
    void addRoot(QString a);
    void clearTree();

public slots:

protected:

private:
    QGraphicsScene *scene;
    Node *centerNode;
    int DescNb;
    int AscNb;
};
