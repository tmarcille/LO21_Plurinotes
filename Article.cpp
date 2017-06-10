#include "Article.h"
#include <QFile>
#include <QTextCodec>
#include <QtXml>
#include <QMessageBox>



void Article::saveAttributesInFile(QXmlStreamWriter & stream) const
{
	stream.writeTextElement("text", text);
}

Note * Article::clone() const
{
	return new Article(*this);
}

Article::Article(const QString& f,const QString& ti, const QString& te) : Note(f,ti), text(te)
{}


QString Article::getType() const
{
	return QString("article");
}

void Article::setText(const QString& t) {
	text = t;
    notify();
}

