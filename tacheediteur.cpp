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

    priorite = new QSpinBox;

    priorite->setMaximum(16);

    priorite->setMinimum(0);

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
    priorite->setValue(t->getPriorite().toInt());
    echeance->setDate(t->getEcheance());

    if (t->getStatus() == "en attente") en_attente->setChecked(true);
    if (t->getStatus() == "en cours") en_cours->setChecked(true);
    if (t->getStatus() == "terminee") terminee->setChecked(true);

    if (t->getEchue()=="T") echue->setChecked(true);

    QObject::connect(action, SIGNAL(textChanged()), this, SLOT(activerSave()));
    QObject::connect(priorite, SIGNAL(valueChanged()), this, SLOT(activerSave()));
    QObject::connect(echeance, SIGNAL(dateChanged()), this, SLOT(activerSave()));
    QObject::connect(status, SIGNAL(buttonClicked()), this, SLOT(activerSave()));
    QObject::connect(echue, SIGNAL(buttonClicked()), this, SLOT(activerSave()));
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
    dynamic_cast<Tache*>(getNote())->setPriorite(QString::number(priorite->value()));

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
}


