#include "RelationTree.h"
#include <QPropertyAnimation>
#include <math.h>
#include <QPainter>

#include <QGraphicsScene>
#include <QStyleOption>

static const double Pi = 3.14159265358979323846264338327950288419717;
static double TwoPi = 2.0 * Pi;


Edge::Edge(Node *sourceNode, Node *destNode, QString text)
    : arrowSize(10),text(text)
{
    setAcceptedMouseButtons(0);
    source = sourceNode;
    dest = destNode;
    adjust();
}


void Edge::adjust()
{
    if (!source || !dest)
        return;

    QLineF line(mapFromItem(source, 0, 10), mapFromItem(dest,0, 0));
    qreal length = line.length();

    prepareGeometryChange();

    if (length > qreal(20.)) {
        QPointF edgeOffset((line.dx() * 10) / length, (line.dy() * 10) / length);
        sourcePoint = line.p1() + edgeOffset;
        destPoint = line.p2() - edgeOffset;
    } else {
        sourcePoint = destPoint = line.p1();
    }
}

QRectF Edge::boundingRect() const
{
    if (!source || !dest)
        return QRectF();

    qreal penWidth = 1;
    qreal extra = (penWidth + arrowSize) / 2.0;

    return QRectF(QPointF(sourcePoint.x()-50,sourcePoint.y()), QSizeF(destPoint.x() - sourcePoint.x() + 50,
                                      destPoint.y() - sourcePoint.y()))
        .normalized()
        .adjusted(-extra, -extra, extra, extra);
}

void Edge::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    if (!source || !dest)
        return;

    QLineF line(sourcePoint, destPoint);
    if (qFuzzyCompare(line.length(), qreal(0.)))
        return;

    // Draw the line itself
    painter->setPen(QPen(Qt::blue, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter->drawLine(line);

    // Draw the arrows
    double angle = ::acos(line.dx() / line.length());
    if (line.dy() >= 0)
        angle = TwoPi - angle;

    QPointF destArrowP1 = destPoint + QPointF(sin(angle - Pi / 3) * arrowSize,
                                              cos(angle - Pi / 3) * arrowSize);
    QPointF destArrowP2 = destPoint + QPointF(sin(angle - Pi + Pi / 3) * arrowSize,
                                              cos(angle - Pi + Pi / 3) * arrowSize);

    painter->setBrush(Qt::blue);
    painter->drawPolygon(QPolygonF() << line.p2() << destArrowP1 << destArrowP2);

    //Draw the text
    painter->setFont(QFont("Arial", 8, QFont::Bold));
    QPen penHText(QColor("#000000"));
    painter->setPen(penHText);
    painter->drawText(destPoint.x()-20,sourcePoint.y()+(destPoint.y()-sourcePoint.y())/2,text);
}


Node::Node(RelationTree *graphWidget, QString text)
    : QGraphicsSimpleTextItem(text), graph(graphWidget)
{
    setFlag(ItemSendsGeometryChanges);
    setCacheMode(DeviceCoordinateCache);
    setZValue(-1);
}


RelationTree::RelationTree(QWidget *parent)
    : QGraphicsView(parent), AscNb(0), DescNb(0)
{
    scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setSceneRect(-200, -200, 400, 400);
    setScene(scene);
    setViewportUpdateMode(BoundingRectViewportUpdate);
    setRenderHint(QPainter::Antialiasing);
    scale(qreal(1.1), qreal(1.1));
    setMinimumSize(200, 200);

}

void RelationTree::addRoot(QString a){
    centerNode = new Node(this,a);
    scene->addItem(centerNode);
    centerNode->setPos( 0,0);
}


void RelationTree::addAsc(QString a, QString relation){
    Node *node = new Node(this,a);
    scene->addItem(node);
    if(AscNb==0){
        node->setPos(0,-50);
        AscNb++;
    }
    else if(AscNb % 2 == 0){
        node->setPos(-60*(AscNb/2),-50);
        AscNb++;
    }
    else {
        node->setPos(60*(AscNb/2+1),-50);
        AscNb++;
    }
    scene->addItem(new Edge(centerNode, node, relation));
}

void RelationTree::addDesc(QString a, QString relation){

        Node *node = new Node(this,a);
        scene->addItem(node);
        if(DescNb==0){
            node->setPos(0,50);
            DescNb++;
        }
        else if(DescNb % 2 == 0){
            node->setPos(-60*(DescNb/2),50);
            DescNb++;
        }
        else {
            node->setPos(60*(DescNb/2+1),50);
            DescNb++;
        }
        scene->addItem(new Edge(centerNode, node, relation));
}

void RelationTree::clearTree(){
    scene->clear();
    DescNb=0;
    AscNb=0;
}
