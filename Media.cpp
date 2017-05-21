#include "Media.h"
#include <QFile>
#include <QTextCodec>
#include <QtXml>
#include <QMessageBox>



void Media::saveAttributesInFile(QXmlStreamWriter & stream) const
{
    stream.writeTextElement("description", description);
    qDebug()<<"saved desc";
    stream.writeTextElement("file", file);
    qDebug()<<"saved file";
}

Note * Media::clone() const
{
    return new Media(*this);
}

Media::Media(const QString& i, const QString& ti, const QString& desc, const QString& f) : Note(i,ti), description(desc), file(f)
{}


QString Media::getType() const
{
    return QString("media");
}

void Media::setDescription(const QString& desc) {
    description=desc;
}
void Media::setFile(const QString& f) {
    file=f;
}
