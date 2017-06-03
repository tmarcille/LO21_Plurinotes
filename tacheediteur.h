#ifndef TACHEEDITEUR_H
#define TACHEEDITEUR_H

#include "NoteEditeur.h"
#include "tache.h"
#include <QDate>
#include <QDateEdit>
#include <QRadioButton>

class TacheEditeur : public NoteEditeur
{
    Q_OBJECT

private:

    QLabel* actionl;
    QTextEdit *action;
    QLabel* echeancel;
    QDateEdit *echeance;
    QLabel* prioritel;
    QLineEdit *priorite;
    QLabel* statusl;
    QLineEdit *status;
    void sauvegardeAttributs();

public:
    TacheEditeur(Tache* a, QWidget *parent = 0);
    ~TacheEditeur();

};

#endif // TACHEEDITEUR_H
