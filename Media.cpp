#include "Media.h"
#include <QFile>
#include <QTextCodec>
#include <QtXml>
#include <QMessageBox>



void Media::saveAttributesInFile(QXmlStreamWriter & stream) const
{
    stream.writeTextElement("description", description);
}

Note * Media::clone() const
{
    return new Media(*this);
}

Media::Media(const QString& i, const QString& ti, const QString& desc) : Note(i,ti), description(desc)
{}


QString Media::getType() const
{
    return QString("media");
}

void Media::setDescription(const QString& desc) {
    description=desc;
}

