#pragma once
#include "NoteEditeur.h"
#include "Article.h"

class ArticleEditeur : public NoteEditeur
{
	Q_OBJECT

private:

	QLabel* textl;
	QTextEdit *text;
	void sauvegardeAttributs();

public:
	ArticleEditeur(Article& a, QWidget *parent = 0);
	~ArticleEditeur();


public slots :
};