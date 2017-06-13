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
    void load();
	void saveAllNotes() const; // save notes in file filename
    void saveNote(const QString& id) const;
	static NotesManager& getManager();
	static void freeManager(); // free the memory used by the NotesManager; it can be rebuild later
    void addNote(Note* n);
    Note* create(const QString& type,const QString& filePath,const QVector<QString>& param = QVector<QString>());

	class Iterator {
		friend class NotesManager;
		Note** currentN;
		unsigned int nbRemain;
		Iterator(Note** a, unsigned nb) :currentN(a), nbRemain(nb) {}
	public:
		Iterator() :nbRemain(0), currentN(nullptr) {}
		bool isDone() const { return nbRemain == 0; }
		void next() {
			if (isDone())
				throw NotesException("error, next on an iterator which is done");
			nbRemain--;
			currentN++;
		}
		Note& current() const {
			if (isDone())
				throw NotesException("error, indirection on an iterator which is done");
			return **currentN;
		}
	};
	Iterator getIterator() {
		return Iterator(notes, nbNotes);
	}

	class ConstIterator {
		friend class NotesManager;
		Note** currentN;
		unsigned int nbRemain;
		ConstIterator(Note** a, unsigned nb) :currentN(a), nbRemain(nb) {}
	public:
		ConstIterator() :nbRemain(0), currentN(0) {}
		bool isDone() const { return nbRemain == 0; }
		void next() {
			if (isDone())
				throw NotesException("error, next on an iterator which is done");
			nbRemain--;
			currentN++;
		}
		const Note& current() const {
			if (isDone())
				throw NotesException("error, indirection on an iterator which is done");
			return **currentN;
		}
	};
	ConstIterator getIterator() const {
		return ConstIterator(notes, nbNotes);
	}
};
