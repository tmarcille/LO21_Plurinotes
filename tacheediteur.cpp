#include "TacheEditeur.h"

TacheEditeur::TacheEditeur(Tache* t, QWidget *parent) : NoteEditeur(t,parent)
{
    qDebug()<<"creation de l'editeur";
    actionl = new QLabel("Action");

    action = new QTextEdit;

    prioritel = new QLabel("Priorite");

    priorite = new QLineEdit;

    echeancel = new QLabel("Echeance");

    echeance = new QDateEdit;

    statusl = new QLabel("Status");

    status = new QLineEdit;



    centralLayout->addWidget(actionl);

    centralLayout->addWidget(action);

    centralLayout->addWidget(prioritel);

    centralLayout->addWidget(priorite);

    centralLayout->addWidget(echeancel);

    centralLayout->addWidget(echeance);

    centralLayout->addWidget(statusl);

    centralLayout->addWidget(status);

    qDebug("finlayout");

    action->setText(t->getAction());
    priorite->setText(t->getPriorite());
    echeance->setDate(t->getEcheance());
    status->setText(t->getStatus());

    QObject::connect(action, SIGNAL(textChanged()), this, SLOT(activerSave()));
    QObject::connect(priorite, SIGNAL(textChanged()), this, SLOT(activerSave()));
    QObject::connect(echeance, SIGNAL(dateChanged()), this, SLOT(activerSave()));
    QObject::connect(status, SIGNAL(textChanged()), this, SLOT(activerSave()));

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
    dynamic_cast<Tache*>(getNote())->setPriorite(priorite->text());
    dynamic_cast<Tache*>(getNote())->setStatus(status->text());
}


