#pragma once
#include "Notes.h"

class Article : public Note {

private:

    friend class NotesManager;


    /**
     * \brief Texte de la note.
     */
	QString text;
	void saveAttributesInFile(QXmlStreamWriter& stream) const;
    Article(const Article& copy);
    Article& operator=(const Article& copy);

protected:
    /**
    * \brief    Constructeur de l'article.
    * \param    f  QString contenant la valeur de \a filepath.
    * \param    ti  QString contenant la  valeur de \a title.
    * \param    te QString contenant la valeur de \a text.
    */
    Article(const QString& f, const QString& ti="", const QString& te="");

public:
    /**
     * \brief    Retourne le texte de la note.
     * \return   QString contenant le texte de la note
     */
	QString getText() const { return text; }

    /**
     * \brief    Retourne le type de la note (article, media, tache, etc)
     * \return   QString contenant le type de la note
     */
	QString getType() const;
    /**
     * \brief    Modifie le texte de la note.
     * \param    t  QString contenant la nouvelle valeur du texte.
     */
	void setText(const QString& t);
};

