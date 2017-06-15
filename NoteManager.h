#pragma once

#include <QString>
#include "Notes.h"
#include "Article.h"
#include "Media.h"
#include "tache.h"
#include <QVector>
#include <QFile>
#include <QTextCodec>
#include <QtXml>
#include <QMessageBox>
#include "ArticleEditeur.h"
#include "MediaEditeur.h"
#include "tacheediteur.h"
class NotesException {
public:
	NotesException(const QString& message) :info(message) {}
	QString getInfo() const { return info; }
private:
	QString info;
};


class NotesManager {
private:

    QVector<Note*> corbeille;

    /**
     * \brief Tableau de pointeurs vers les Note contenues dans le manager.
     */
	Note** notes;

    /**
     * \brief nombre de Note contenues dans le manager.
     */
	unsigned int nbNotes;

    /**
     * \brief nombre maximum de Note que le manager peut stocker avec sa mémoire allouée actuellement.
     */
	unsigned int nbMaxNotes;

    /**
     * \brief chemin du dossier contenant les notes lus par l'application. Modifiable
     * dans les paramètres de l'application.
     */
	mutable QString foldername;

    /**
     * \brief pointeur vers l'unique instance du manager.
     */
    static NotesManager* instance;
	NotesManager();
	~NotesManager();
	NotesManager(const NotesManager& m);
	NotesManager& operator=(const NotesManager& m);

public:

    /**
     * \brief Retourne la Note avec l'identificateur \a id.
     * \param id QString& référencant l'id a rechercher.
     * \return Une référence vers la Note si elle est trouvée (renvoie une erreur si elle n'existe pas).
     */
    Note& getNote(const QString& id) const;

    /**
     * \brief    Retourne le dossier de stockage des Note.
     * \return   QString contenant l'adresse du dossier de stockage des Note.
     */
	QString getFoldername() const { return foldername; }

    /**
     * \brief    Modifie le dossier de stockage des notes.
     * \param    f  QString contenant l'adresse du nouveau dossier.
     */
	void setFoldername(const QString& f) { foldername = f; }

    /**
     * \brief    Fonction de lecture des fichiers de Note.
     * \details  Lit tout les fichiers xml contenus dans le dossier \a foldername. Si c'est une note,
     *           elle est créé en appelant la fonction create().
     */
    void load();

    /**
     * \brief    Sauvegarde toutes les Note du manager dans leur fichier respectif.
     */
    void saveAllNotes() const;

    /**
     * \brief    Sauvegarde une Note du manager dans son fichier.
     * \param    id QString contenant l'id de la note à sauvegarder.
     */
    void saveNote(const QString& id) const;

    /**
     * \brief    Renvoie l'unique instance du manager. Si celui-ci n'existe
     * pas, il est cree.
     * \return   Reference vers l'unique NoteManager.
     */
	static NotesManager& getManager();

    /**
     * \brief    Libere la memoire utilisee par le manager.
     * \details Celui-ci peut être reconstruit plus tard en appelant getManager().
     */
    static void freeManager();

    /**
     * \brief    Ajoute une note au manager.
     * \details  Si une note avec le même \a id existe déjà, on ne fait pas l'ajout.
     * \param n Pointeur vers la Note a ajouter au manager.
     */
    void addNote(Note* n);

    void removeNote(const QString& id);
    void restoreNote(const QString& id);

    /**
     * \brief    Fonction de création d'une note.
     * \details  La fonction va chercher dans le vecteur de QString donné en argument
     * les parametres optionnels correspondant au type de note voulu, puis cree une note
     * avec ces parametres, uniquement si une note avec le même id n'existe pas déjà.
     * Puis la fonction ajoute cette note au manager en appellant addNote().
     * \param type QString& contenant le type de note que l'on veut créé.
     * \param filePath QString& contenant le chemin vers le fichier xml de la note.
     * \param param QVector contenant les paramètres optionnels de la note, selon le format : (parametre1, valeur_du_parametre1,
     * parametre2, valeur_du_parametre2, etc.)
     */
    Note* create(const QString& type,const QString& filePath,const QVector<QString>& param = QVector<QString>());

	class Iterator {
		friend class NotesManager;

        /**
         * \brief    Tableau de Note* sur lequel on itère
         */
		Note** currentN;

        /**
         * \brief    Nombre de Note restant à parcourir
         */
		unsigned int nbRemain;

        /**
         * \brief    constructeur  de Iterator
         * \param a  Tableau de Note* sur lequel iterer
         * \param nb Nombre de Note dans le tableau
         */
		Iterator(Note** a, unsigned nb) :currentN(a), nbRemain(nb) {}
	public:

        /**
         * \brief    Constructeur d'un iterateur vide
         */
		Iterator() :nbRemain(0), currentN(nullptr) {}

        /**
         * \brief    Indique la fin de l'itérateur
         * \return   true si il n'y a plus de Note* dans le plateau.
         * Sinon retourne false.
         */
		bool isDone() const { return nbRemain == 0; }

        /**
         * \brief    Avance l'itérateur d'un cran, si c'est possible.
         */
		void next() {
			if (isDone())
				throw NotesException("error, next on an iterator which is done");
			nbRemain--;
			currentN++;
		}

        /**
         * \brief    Note actuellement pointee par l'iterateur
         * \return   Note& sur la note pointee par l'iterateur, si elle existe.
         */
		Note& current() const {
			if (isDone())
				throw NotesException("error, indirection on an iterator which is done");
			return **currentN;
		}
	};

    /**
     * \brief   Acces à l'itérateur du NotesManager
     * \return Iterator pointant sur la première Note du NotesManager
     */
	Iterator getIterator() {
		return Iterator(notes, nbNotes);
	}

	class ConstIterator {
		friend class NotesManager;
        /**
         * \brief    Tableau de Note* sur lequel on itère
         */
		Note** currentN;
        /**
         * \brief    Nombre de Note restant à parcourir
         */
		unsigned int nbRemain;
        /**
         * \brief    constructeur  de ConstIterator
         * \param a  Tableau de Note* sur lequel iterer
         * \param nb Nombre de Note dans le tableau
         */
		ConstIterator(Note** a, unsigned nb) :currentN(a), nbRemain(nb) {}
	public:
        /**
         * \brief    Constructeur d'un ConstIterator vide
         */
		ConstIterator() :nbRemain(0), currentN(0) {}
        /**
         * \brief    Indique la fin de l'itérateur
         * \return   true si il n'y a plus de Note* dans le plateau.
         * Sinon retourne false.
         */
		bool isDone() const { return nbRemain == 0; }

        /**
         * \brief    Avance l'itérateur d'un cran, si c'est possible.
         */
		void next() {
			if (isDone())
				throw NotesException("error, next on an iterator which is done");
			nbRemain--;
			currentN++;
		}
        /**
         * \brief    Note actuellement pointee par ConstIterator
         * \return   Note& sur la note pointee par ConstIterator, si elle existe.
         */
		const Note& current() const {
			if (isDone())
				throw NotesException("error, indirection on an iterator which is done");
			return **currentN;
		}
	};

    /**
     * \brief   Acces à l'itérateur constant du NotesManager
     * \return ConstIterator pointant sur la première Note du NotesManager
     */
	ConstIterator getIterator() const {
		return ConstIterator(notes, nbNotes);
	}
};
