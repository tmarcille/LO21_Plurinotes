#ifndef MEDIA_H
#define MEDIA_H
#include "Notes.h"


class Media : public Note {

private:
    QString description;
    void saveAttributesInFile(QXmlStreamWriter& stream) const;

public:
    Note* clone() const;
    Media(const QString& i, const QString& ti, const QString& des);
    QString getDescription() const { return description; }
    QString getType() const;
    void setDescription(const QString& desc);
};

#endif // MEDIA_H


