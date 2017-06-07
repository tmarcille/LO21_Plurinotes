#ifndef TACHEEDITEUR_H
#define TACHEEDITEUR_H

#include "NoteEditeur.h"
#include "tache.h"
#include <QDate>
#include <QDateEdit>
#include <QRadioButton>
#include <QSpinBox>
#include <QRadioButton>
#include <QButtonGroup>
#include <QCheckBox>
#include <QComboBox>

class TacheEditeur : public NoteEditeur
{
    Q_OBJECT

private:
    QVBoxLayout * localLayout;
    QHBoxLayout * h1;
    QHBoxLayout * h2;
    QLabel* actionl;
    QTextEdit *action;
    QLabel* echeancel;
    QDateEdit *echeance;
    QLabel* prioritel;
    QComboBox *priorite;
    QLabel* statusl;
    QRadioButton *en_attente;
    QRadioButton *en_cours;
    QRadioButton *terminee;
    QButtonGroup *status;
    QLabel * echuel;
    QCheckBox * echue;
    void sauvegardeAttributs();  

public:
    TacheEditeur(Tache* a, QWidget *parent = 0);
    ~TacheEditeur();

public slots :

};

#endif // TACHEEDITEUR_H
