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
    QSpinBox *priorite;
    QLabel* statusl;
    QRadioButton *en_attente;
    QRadioButton *en_cours;
    QRadioButton *terminee;
    QButtonGroup *status;
    void sauvegardeAttributs();  

public:
    TacheEditeur(Tache* a, QWidget *parent = 0);
    ~TacheEditeur();

signals :
    void valueChanged(int v);
    void dateChanged(QDate d);
    void buttonClicked(QString s);

public slots :

};

#endif // TACHEEDITEUR_H
