#include "Notes.h"

Note::Note(const QString & f,const QString& ti) : filePath(f), title(ti)
{
    qDebug()<<"filePath"<<filePath;

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
    stream.writeStartElement("note");
    stream.writeAttribute("type",getType());
    stream.writeTextElement("title", title);

    saveAttributesInFile(stream);

    stream.writeEndElement();
    stream.writeEndDocument();
    newfile.close();

    qDebug()<<"saved note"<<filePath<<"in file";
}

Note::~Note() {}


