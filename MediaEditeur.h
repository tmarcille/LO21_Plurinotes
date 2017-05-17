#ifndef MEDIAEDITEUR_H
#define MEDIAEDITEUR_H
#include "Media.h"
#include "NoteEditeur.h"
#include "player.h"

class MediaEditeur : public NoteEditeur
{
    Q_OBJECT

private:
    //QStacked Layout pour alterner entre image et video player
    QLabel* descriptionl;
    QTextEdit *description;
    void sauvegardeAttributs();

public:
    MediaEditeur(Media& a, QWidget *parent = 0);
    ~MediaEditeur();


public slots :
};

#endif // MEDIAEDITEUR_H
