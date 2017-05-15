#if !defined(_NOTES_H)
#define _NOTES_H
#include <QString>
#include <QFile>
#include <QTextCodec>
#include <QtXml>
#include <QVector>
#include <QMessageBox>

class Note {

private:
    QString id;
    QString title;
	virtual void saveAttributesInFile(QXmlStreamWriter& stream) const = 0;

public:

	Note(const QString& i, const QString& ti);
	virtual ~Note() = 0;
    QString getId() const { return id; }
    QString getTitle() const { return title; }
	void setTitle(const QString& t);
	virtual QString getType() const = 0;
	void saveInFile(QString& folder) const;

};


#endif
