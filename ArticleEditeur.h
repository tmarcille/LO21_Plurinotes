#pragma once
#include "NoteEditeur.h"
#include "Article.h"

class ArticleEditeur : public NoteEditeur
{
	Q_OBJECT

private:

    friend class NoteViewer;

    /**
     * \brief Label du champ texte.
     */
	QLabel* textl;

    /**
     * \brief Champ d'édition du texte.
     */
	QTextEdit *text;
	void sauvegardeAttributs();

protected:
    /**
    * \brief    Constructeur de l'editeur.
    * \param    a  Article* vers l'article qui sera affiché dans l'éditeur.
    */
    ArticleEditeur(Article* a, QWidget *parent = 0);

public:
    virtual ~ArticleEditeur();


public slots :
};
