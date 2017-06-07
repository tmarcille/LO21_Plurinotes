#include "TacheEditeur.h"

TacheEditeur::TacheEditeur(Tache* t, QWidget *parent) : NoteEditeur(t,parent)
{
    qDebug()<<"creation de l'editeur";

    localLayout = new QVBoxLayout();

    h1 = new QHBoxLayout();

    h2 = new QHBoxLayout();

    actionl = new QLabel("Action");

    action = new QTextEdit;

    prioritel = new QLabel("Priorite");

    priorite = new QComboBox;

    priorite->addItem("Faible");
    priorite->addItem("Moyenne");
    priorite->addItem("Fort");


    echeancel = new QLabel("Echeance");

    echeance = new QDateEdit;

    statusl = new QLabel("Status");

    en_attente = new QRadioButton("en attente");

    en_cours = new QRadioButton("en cours");

    terminee = new QRadioButton("terminee");

    status = new QButtonGroup();

    echue = new QCheckBox("");

    echuel = new QLabel("Prise en compte");

    status->addButton(en_attente, 0);
    status->addButton(en_cours, 1);
    status->addButton(terminee, 2);

    localLayout->addWidget(actionl);

    localLayout->addWidget(action);

    h1->addWidget(prioritel);

    h1->addWidget(priorite);

    h1->addWidget(echeancel);

    h1->addWidget(echeance);

    h1->addWidget(echuel);

    h1->addWidget(echue);

    localLayout->addLayout(h1);

    localLayout->addWidget(statusl);

    h2->addWidget(en_attente);

    h2->addWidget(en_cours);

    h2->addWidget(terminee);

    localLayout->addLayout(h2);

    centralLayout->addLayout(localLayout);

    qDebug("finlayout");

    action->setText(t->getAction());
    if (t->getPriorite() == "Faible") priorite->setCurrentIndex(0);
    if (t->getPriorite() == "Moyenne") priorite->setCurrentIndex(1);
    if (t->getPriorite() == "Forte") priorite->setCurrentIndex(2);
    echeance->setDate(t->getEcheance());

    if (t->getStatus() == "en attente") en_attente->setChecked(true);
    if (t->getStatus() == "en cours") en_cours->setChecked(true);
    if (t->getStatus() == "terminee") terminee->setChecked(true);

    if (t->getEchue()=="T") echue->setChecked(true);

    QObject::connect(action, SIGNAL(textChanged()), this, SLOT(activerSave()));
    QObject::connect(priorite, SIGNAL(activated(int)), this, SLOT(activerSave()));
    QObject::connect(echeance, SIGNAL(dateChanged(QDate)), this, SLOT(activerSave()));
    QObject::connect(status, SIGNAL(buttonClicked(int)), this, SLOT(activerSave()));
    QObject::connect(echue, SIGNAL(clicked(bool)), this, SLOT(activerSave()));
}


TacheEditeur::~TacheEditeur()
{
}


void TacheEditeur::sauvegardeAttributs()
{
    if (dynamic_cast<Tache*>(getNote()))
        qDebug()<<"Tache";
    dynamic_cast<Tache*>(getNote())->setAction(action->toPlainText());
    dynamic_cast<Tache*>(getNote())->setEcheance(echeance->date());

    QString p;
    switch (priorite->currentIndex()) {
    case 1 :
        p="Moyenne";
        break;
    case 2:
        p="Forte";
        break;
    default:
        p="Faible";
        break;
    }
    dynamic_cast<Tache*>(getNote())->setPriorite(p);

    QString s;
    switch (status->checkedId()) {
    case 1 :
        s="en cours";
        break;
    case 2 :
        s="terminee";
        break;
    default:
        s="en attente";
        break;
    }
    dynamic_cast<Tache*>(getNote())->setStatus(s);

    QString e;
    if (echue->isChecked()) e="T";
    else e="F";
    dynamic_cast<Tache*>(getNote())->setEchue(e);
    qDebug()<<"priorite"<<dynamic_cast<Tache*>(getNote())->getPriorite();
}


