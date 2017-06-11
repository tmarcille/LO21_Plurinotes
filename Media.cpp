#include "Media.h"
#include <QFile>
#include <QTextCodec>
#include <QtXml>
#include <QMessageBox>
#include <string>


void Media::saveAttributesInFile(QXmlStreamWriter & stream) const
{
    stream.writeTextElement("description", description);
    stream.writeTextElement("file", file);
}


Media::Media(const QString& fp, const QString& ti, const QString& desc, const QString& f) : Note(fp,ti), description(desc), file(f)
{}


QString Media::getType() const
{
    return QString("media");
}

void Media::setDescription(const QString& desc) {
    description=desc;
    notify();
}

void Media::setFile(const QString& f) {
    file=f;
    notify();
}
