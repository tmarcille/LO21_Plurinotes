#ifndef NOTEVIEWER_H
#define NOTEVIEWER_H

#include <QWidget>
#include <QTabWidget>
#include "NoteEditeur.h"
#include "MediaEditeur.h"
#include "ArticleEditeur.h"
#include <QLayout>

class NoteViewer : public QWidget //widget des noteEditeur permettant un affichage plus complexe avec plusieurs notes a la fois.
{
    Q_OBJECT
public:
    explicit NoteViewer(QWidget *parent = 0);
    void showNote(Note* note);
    void closeNote(const QString& id);
    void refreshNote(const QString& id);
    bool isOpen(const QString& id) const;
    ~NoteViewer();

private:
    QHBoxLayout* layout;
    QTabWidget* tabWidget;
    void closeTab(int);
    NoteEditeur* createEditor(Note* n);


signals:


public slots:
    void unsavedChanges(NoteEditeur* f); //slots qui changent le nom du tab afin d'indiquer
    void saveChanges(NoteEditeur* f);    //si il est en cours d'edition ou non.
};

#endif // NOTEVIEWER_H
