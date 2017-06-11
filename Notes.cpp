#include "Notes.h"

Note::Note(const QString & i, const QString & folder,const QString& ti) : id(i), title(ti),filePath(folder +"/"+id + ".xml")
{

}

void Note::setTitle(const QString & t)
{
	title = t;
    notify();
}

void Note::saveInFile() const
{
    QFile newfile(filePath);
	if (!newfile.open(QIODevice::WriteOnly | QIODevice::Text)) {
		//a faire, mettre NoteException dans une classe séparée
		//throw NotesException(QString("erreur sauvegarde notes : ouverture fichier xml"));
	}
	QXmlStreamWriter stream(&newfile);
	stream.setAutoFormatting(true);
	stream.writeStartDocument();
	stream.writeStartElement("notes");
    stream.writeStartElement(getType());
	stream.writeTextElement("id", id);
	stream.writeTextElement("title", title);

	saveAttributesInFile(stream);
    stream.writeEndElement();
    stream.writeEndElement();
	stream.writeEndElement();
	stream.writeEndElement();
	stream.writeEndDocument();
	newfile.close();

    qDebug()<<"saved note"<<id<<"in file";
}

Note::~Note() {}


