#ifndef MEDIA_H
#define MEDIA_H
#include "Notes.h"


class Media : public Note {

private:
    friend class NotesManager;


    /**
     * \brief Description de la note.
     */
    QString description;

    /**
     * \brief Fichier du media de la note.
     */
    QString file;
    void saveAttributesInFile(QXmlStreamWriter& stream) const;
    Media(const Media& copy);
    Media& operator=(const Media& copy);


protected :
    /**
    * \brief    Constructeur de média.
    * \param    fp  QString contenant la valeur de \a filepath.
    * \param    ti  QString contenant la  valeur de \a title.
    * \param    des QString contenant la valeur de \a description.
    * \param    f QString contenant la valeur de \a file.

    */
    Media(const QString& fp, const QString& ti="", const QString& des="", const QString& f="");

public:
    /**
     * \brief    Retourne la description de la note.
     * \return   QString contenant la description de la note
     */
    QString getDescription() const { return description; }

    /**
     * \brief    Retourne le fichier multimedia de la note.
     * \return   QString contenant le chemin vers le fichier multimedia de la note
     */
    QString getFile() const { return file; }

    /**
     * \brief    Retourne le type de la note (article, media, tache, etc)
     * \return   QString contenant le type de la note
     */
    QString getType() const;

    /**
     * \brief    Modifie la descriptions de la note.
     * \param    desc  QString contenant la nouvelle valeur du texte.
     */
    void setDescription(const QString& desc);

    /**
     * \brief    Modifie le fichier multimedia de la note.
     * \param    t  QString contenant le chemin vers le nouveau fichier.
     */
    void setFile(const QString& f);

};

#endif // MEDIA_H


