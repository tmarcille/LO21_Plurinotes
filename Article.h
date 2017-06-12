#pragma once
#include "Notes.h"

class Article : public Note {

private:

    friend class NotesManager;

	QString text;
	void saveAttributesInFile(QXmlStreamWriter& stream) const;

protected:
    Article(const QString& f, const QString& ti="", const QString& te="");

public:
	Note* clone() const;
	QString getText() const { return text; }
	QString getType() const;
	void setText(const QString& t);
};

