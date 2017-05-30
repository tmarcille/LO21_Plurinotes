#ifndef NOTEVIEWER_H
#define NOTEVIEWER_H

#include <QWidget>
#include <QTabWidget>
#include "NoteEditeur.h"
#include "MediaEditeur.h"
#include "ArticleEditeur.h"
#include <QLayout>

class NoteViewer : public QWidget
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
    void unsavedChanges(NoteEditeur* f);
    void saveChanges(NoteEditeur* f);
};

#endif // NOTEVIEWER_H
