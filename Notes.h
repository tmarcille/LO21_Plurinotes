#if !defined(_NOTES_H)
#define _NOTES_H
#include <QString>
#include <QFile>
#include <QTextCodec>
#include <QtXml>
#include <QVector>
#include <QMessageBox>
#include <iostream>
#include <observator.h>

class Note : public Subject<Note> {

private:
    QString id;
    QString title;
    QString filePath;
	virtual void saveAttributesInFile(QXmlStreamWriter& stream) const = 0;

public:

    Note(const QString& i,const QString& folder, const QString& ti="");
	virtual ~Note() = 0;
    QString getId() const { return id; }
    QString getTitle() const { return title; }
	void setTitle(const QString& t);
	virtual QString getType() const = 0;
    void saveInFile() const;

};


#endif
