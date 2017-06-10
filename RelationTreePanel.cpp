#include "RelationTreePanel.h"
#include <QPropertyAnimation>
#include <math.h>
#include <QPainter>

#include <QGraphicsScene>
#include <QStyleOption>

static const double Pi = 3.14159265358979323846264338327950288419717;
static double TwoPi = 2.0 * Pi;

RelationTreePanel::RelationTreePanel(QWidget *parent) : QWidget(parent), animationDuration(200) {

    toggleButton.setToolButtonStyle(Qt::ToolButtonTextOnly);
    toggleButton.setText("Arborescence");
    toggleButton.setCheckable(true);
    toggleButton.setChecked(false);
    contentArea.setStyleSheet("QScrollArea { background-color: white; border: 1px solid black; }");
    contentArea.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    // start out collapsed
    contentArea.setMaximumWidth(0);
    contentArea.setMinimumWidth(0);

    // let the entire widget grow and shrink with its content
    toggleAnimation.addAnimation(new QPropertyAnimation(this, "minimumWidth"));
    toggleAnimation.addAnimation(new QPropertyAnimation(this, "maximumWidth"));
    toggleAnimation.addAnimation(new QPropertyAnimation(&contentArea, "maximumWidth"));
    toggleAnimation.setDirection(QAbstractAnimation::Backward);
    //toggleAnimation.start();
    mainLayout.addWidget(&toggleButton,0,0,Qt::AlignTop);
    mainLayout.addWidget(&contentArea,1,0);
    setLayout(&mainLayout);
    QObject::connect(&toggleButton, &QToolButton::clicked, [this](const bool checked) {
        toggleAnimation.setDirection(checked ? QAbstractAnimation::Forward : QAbstractAnimation::Backward);
        toggleAnimation.start();
    });
}

void RelationTreePanel::setContentLayout(QLayout & contentLayout) {
    delete contentArea.layout();
    contentArea.setLayout(&contentLayout);

    const auto collapsedWidth = sizeHint().width() - contentArea.maximumWidth();
    auto contentWidth = contentLayout.sizeHint().width();
    for (int i = 0; i < toggleAnimation.animationCount() - 1; ++i) {
        QPropertyAnimation * spoilerAnimation = static_cast<QPropertyAnimation *>(toggleAnimation.animationAt(i));
        spoilerAnimation->setDuration(animationDuration);
        spoilerAnimation->setStartValue(collapsedWidth);
        spoilerAnimation->setEndValue(collapsedWidth + contentWidth);
    }
    QPropertyAnimation * contentAnimation = static_cast<QPropertyAnimation *>(toggleAnimation.animationAt(toggleAnimation.animationCount() - 1));
    contentAnimation->setDuration(animationDuration);
    contentAnimation->setStartValue(0);
    contentAnimation->setEndValue(contentWidth);
}


Edge::Edge(Node *sourceNode, Node *destNode)
    : arrowSize(10)
{
    setAcceptedMouseButtons(0);
    source = sourceNode;
    dest = destNode;
    source->addEdge(this);
    dest->addEdge(this);
    adjust();
}

Node *Edge::sourceNode() const
{
    return source;
}

Node *Edge::destNode() const
{
    return dest;
}

void Edge::adjust()
{
    if (!source || !dest)
        return;

    QLineF line(mapFromItem(source, 40, 10), mapFromItem(dest,-10, 10));
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

    return QRectF(sourcePoint, QSizeF(destPoint.x() - sourcePoint.x(),
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
    painter->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter->drawLine(line);

    // Draw the arrows
    double angle = ::acos(line.dx() / line.length());
    if (line.dy() >= 0)
        angle = TwoPi - angle;

    QPointF destArrowP1 = destPoint + QPointF(sin(angle - Pi / 3) * arrowSize,
                                              cos(angle - Pi / 3) * arrowSize);
    QPointF destArrowP2 = destPoint + QPointF(sin(angle - Pi + Pi / 3) * arrowSize,
                                              cos(angle - Pi + Pi / 3) * arrowSize);

    painter->setBrush(Qt::black);
    painter->drawPolygon(QPolygonF() << line.p2() << destArrowP1 << destArrowP2);
}


Node::Node(RelationTree *graphWidget, QString text)
    : QGraphicsSimpleTextItem(text), graph(graphWidget)
{
    setFlag(ItemSendsGeometryChanges);
    setCacheMode(DeviceCoordinateCache);
    setZValue(-1);
}

void Node::addEdge(Edge *edge)
{
    edgeList << edge;
    edge->adjust();
}

QList<Edge *> Node::edges() const
{
    return edgeList;
}


QVariant Node::itemChange(GraphicsItemChange change, const QVariant &value)
{
    switch (change) {
    case ItemPositionHasChanged:
        foreach (Edge *edge, edgeList)
            edge->adjust();
        break;
    default:
        break;
    };
    return QGraphicsItem::itemChange(change, value);
}

RelationTree::RelationTree(QWidget *parent)
    : QGraphicsView(parent)
{
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setSceneRect(-200, -200, 400, 400);
    setScene(scene);
    setViewportUpdateMode(BoundingRectViewportUpdate);
    setRenderHint(QPainter::Antialiasing);
    scale(qreal(0.8), qreal(0.8));
    setMinimumSize(200, 200);

    Node *node1 = new Node(this,"Article 1");
    Node *node2 = new Node(this,"Article 2");
    Node *node3 = new Node(this,"Article 3");
    centerNode = new Node(this,"Article 4");
    scene->addItem(node1);
    scene->addItem(node2);
    scene->addItem(node3);
    scene->addItem(centerNode);


    QRectF bR = node1->sceneBoundingRect();
    node1->setPos( -100 - bR.width()/2, -100 - bR.height()/2 );
    bR = node2->sceneBoundingRect();
    node2->setPos( 0 - bR.width()/2, -100 - bR.height()/2 );
    node3->setPos( 100 - bR.width()/2, -100 - bR.height()/2 );
    centerNode->setPos( 0 - bR.width()/2, 0 - bR.height()/2 );
    scene->addItem(new Edge(node1, node2));
    scene->addItem(new Edge(node2, node3));
    scene->addItem(new Edge(node2, centerNode));

}
