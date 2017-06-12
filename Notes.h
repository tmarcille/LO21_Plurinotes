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

    friend class NotesManager;
    /**
     * \brief Titre de la note.
     */
    QString title;

    /**
     * \brief Chemin vers le fichier où la note est sauvegardée.
     */
    QString filePath;

    /**
     * \brief      Sauvegarde les attributs de la classe fille
     * \details  La classe Note sauvegarde les attributs communs avec saveInFile() , tandis
     *           que chaque classe fille s'occupe de la sauvegarde de ses attributs supplémentaires
     * \param    stream  Le QXmlStreamWriter dans lequel la fonction est en train d'écrire.
     */
	virtual void saveAttributesInFile(QXmlStreamWriter& stream) const = 0;

protected:
    /**
    * \brief    Constructeur de la note.
    * \param    f  QString contenant la valeur de \a filepath.
    * \param    ti  QString contenant la  valeur de \a title.
    */
    Note(const QString& f, const QString& ti="");

public:

	virtual ~Note() = 0;

    /**
     * \brief    Retourne l'id de la note.
     * \details  Determine l'id a partir du chemin vers le fichier indiqué dans \ a filepath
     * \return   Un QString contenant l'ID de la note
     */
    QString getId() const { return filePath.section("/", -1, -1).section(".", 0, 0);}

    /**
     * \brief    Retourne le titre de la note.
     * \return   Un QString contenant le titre de la note
     */
    QString getTitle() const { return title; }

    /**
     * \brief    Modifie le titre de la note.
     * \details  Determine l'id a partir du chemin vers le fichier indiqué dans \ a filepath
     * \param    t  QString contenant la nouvelle valeur du titre.
     */
    virtual void setTitle(const QString& t);

    /**
     * \brief    Retourne le type de la note.
     * \details  Chaque classe fille doit reimplementer cette fonction pour indiquer son type.
     * \return   Un QString contenant le type de la note
     */
    virtual QString getType() const = 0;

    /**
     * \brief      Sauvegarde les attributs communs à toutes les types de notes.
     * \details  Sauvegarde les attributs communs à toutes les types de notes dans le fichier indiqué par \a filepath puis
     * appelle saveAttributesInFile() pour la sauvegarder les attributs specifiques a la classe.
     */
    void saveInFile() const;

};


#endif
