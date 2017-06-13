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

    friend class NoteViewer;

    QVBoxLayout * localLayout;
    QHBoxLayout * h1;
    QHBoxLayout * h2;
    QHBoxLayout * h3;
    QLabel* actionl;
    QTextEdit *action;
    QCheckBox * echue;
    QLabel* echeancel;
    QDateEdit *echeance;
    QCheckBox * priorise;
    QLabel* prioritel;
    QComboBox *priorite;
    QLabel* statusl;
    QRadioButton *en_attente;
    QRadioButton *en_cours;
    QRadioButton *terminee;
    QButtonGroup *status;

    void sauvegardeAttributs();  

protected :
    TacheEditeur(Tache* a, QWidget *parent = 0);

public:
    ~TacheEditeur();

public slots :

};

#endif // TACHEEDITEUR_H
