#pragma once
#include "Notes.h"

class Article : public Note {

private:
	QString text;
	void saveAttributesInFile(QXmlStreamWriter& stream) const;

public:
	Note* clone() const;
    Article(const QString& i,const QString& folder, const QString& ti="", const QString& te="");
	QString getText() const { return text; }
	QString getType() const;
	void setText(const QString& t);
};

