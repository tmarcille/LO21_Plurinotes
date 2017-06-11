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
	Note** notes;
	unsigned int nbNotes;
	unsigned int nbMaxNotes;
	void addNote(Note* n);
	mutable QString foldername;
	static NotesManager* instance; // pointeur sur l'unique instance

	NotesManager();
	~NotesManager();
	NotesManager(const NotesManager& m);
	NotesManager& operator=(const NotesManager& m);

public:
    Note& getNote(const QString& id) const; // return the article with identificator id (create a new one if it not exists)
	QString getFoldername() const { return foldername; }
	void setFoldername(const QString& f) { foldername = f; }
	void load(); // load notes from file filename
	void saveAllNotes() const; // save notes in file filename
    void saveNote(const QString& id) const;
	static NotesManager& getManager();
	static void freeManager(); // free the memory used by the NotesManager; it can be rebuild later
    void addNote(Note* n);

	Note* create(const QString& type,const QString& id,const QVector<QString>& param = QVector<QString>()) //crée un note et l'ajoute a la liste (pas de note pas dans la liste -> pose un pb plus tard ?)
	{
		/*Logic based on Genre*/
        try{
            getNote(filePath.section("/", -1, -1).section(".", 0, 0));
        }
        catch (NotesException& a){
            if (a.getInfo()=="error, note not existing"){
                qDebug()<<"creating Note";
                Note* note = NULL;
                QString title = "";
                if (param.contains("title"))
                    title = param.at(param.indexOf("title") + 1);

                if (type.toLower() == "article") {
                    qDebug()<<"creating article";
                    QString text = "";
                    if (param.contains("text"))
                        text = param.at(param.indexOf("text") + 1);
                    note = new Article(filePath,title,text);
                }
                if (type.toLower() == "media") {
                    QString desc = "";
                    QString file = "";
                    if (param.contains("description"))
                        desc = param.at(param.indexOf("description") + 1);
                    if (param.contains("file"))
                        file = param.at(param.indexOf("file") + 1);
                    note = new Media(filePath,title,desc,file);
                }
                if (type.toLower() == "tache") {
                    QString priorite = "Faible";
                    QString status = "en attente";
                    QDate echeance = QDate(2017,6,25);
                    QString action = "";
                    bool echue = false;
                    bool priorise = false;
                    qDebug("recuperation tache");
                    if (param.contains("action"))
                        action = param.at(param.indexOf("action") + 1);
                    if (param.contains("priorite"))
                        priorite = param.at(param.indexOf("priorite") + 1);
                    if (param.contains("status"))
                        status = param.at(param.indexOf("status") + 1);
                    if (param.contains("echeance"))
                        echeance = QDate::fromString(param.at(param.indexOf("echeance") + 1), "d.M.yyyy");
                    if (param.contains("echue"))
                        if (param.at(param.indexOf("echue") + 1)=="T") echue=true;
                    if (param.contains("priorise"))
                        if (param.at(param.indexOf("priorise") + 1)=="T") priorise=true;
                    qDebug("intialisation tache");
                    note = new Tache(id,foldername,title,action,echeance,priorite,status,echue,priorise);
                }
                addNote(note);
                return note;
            }
       }
       throw NotesException("Note already exists");
	}



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
