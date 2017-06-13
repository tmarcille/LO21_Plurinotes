#include "ArticleEditeur.h"



ArticleEditeur::ArticleEditeur(Article* a, QWidget *parent) : NoteEditeur(a,parent)
{
    textl = new QLabel("Texte");

	text = new QTextEdit;

    centralLayout->addWidget(textl);

    centralLayout->addWidget(text);

    text->setText(a->getText());
	
	QObject::connect(text, SIGNAL(textChanged()), this, SLOT(activerSave()));

}


ArticleEditeur::~ArticleEditeur()
{

}
void ArticleEditeur::sauvegardeAttributs()
{
    if (dynamic_cast<Article*>(getNote()))
        qDebug()<<"Article";
    dynamic_cast<Article*>(getNote())->setText(text->toPlainText());
}


