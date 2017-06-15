#include "NoteManager.h"


NotesManager* NotesManager::instance = nullptr;

NotesManager& NotesManager::getManager() {
    if (!instance) instance = new NotesManager;
    return *instance;
}

void NotesManager::freeManager() {
    delete instance;
    instance = nullptr;
}

void NotesManager::addNote(Note* a) {

    try{
        getNote(a->getId());
    }
    catch (NotesException& e){
        if(e.getInfo()=="error, note not existing"){
            if (nbNotes == nbMaxNotes) {
                Note** newNote = new Note*[nbMaxNotes + 5];
                for (unsigned int i = 0; i<nbNotes; i++) newNote[i] = notes[i];
                Note** oldNotes = notes;
                notes = newNote;
                nbMaxNotes += 5;
                if (oldNotes) delete[] oldNotes;
            }
            notes[nbNotes++] = a;
        }
        return;
    }
    qDebug()<<"Note was already in the manager";
}

void NotesManager::removeNote(const QString &id){

    Iterator it = getIterator();
    for (it; !it.isDone(); it.next()) {
        if( it.current().getId()==id){
            corbeille.append(&(it.current()));
            nbNotes--;
            QFile file (it.current().filePath);
            file.remove();
            load();
            if (foldername!="")
                saveAllNotes();
        }
    }
}

void NotesManager::restoreNote(const QString &id){
    auto it = corbeille.begin();
    while (it != corbeille.end()) {
        qDebug()<<"while";
        qDebug()<<corbeille.size();
        if ( dynamic_cast<Note*>(*it) && id == ((*it)->getId())){
            qDebug()<<"adding note"<< id <<"from bin  ";
            addNote((*it));
            it = corbeille.erase(it);
            qDebug()<<corbeille.size();
            saveAllNotes();
            return;
        }
        else
           ++it;
    }

}

Note& NotesManager::getNote(const QString& id) const{

    // si l'article existe d?j?, on en renvoie une r?f?rence

    for(unsigned int i=0; i<nbNotes; i++){
        if (notes[i]->getId()==id) return *notes[i];
    }
    //sinon on renvoie une erreur;
    throw NotesException("error, note not existing");
}

NotesManager::NotesManager() :notes(nullptr), nbNotes(0), nbMaxNotes(0), foldername(""), corbeille(QVector<Note*>()) {}

NotesManager::~NotesManager() {
    if (foldername!="")
        saveAllNotes();
    for (unsigned int i = 0; i<nbNotes; i++) delete notes[i];
    delete[] notes;
}

void NotesManager::saveAllNotes() const {

    for (ConstIterator it = getIterator(); !it.isDone(); it.next()) {
        it.current().saveInFile();
    }
}

void NotesManager::saveNote(const QString& id) const {

    try{
        Note& note = getNote(id);
        note.saveInFile();
    }
    catch(NotesException& e){
        qDebug()<<e.getInfo();
    }
}

Note* NotesManager::create(const QString& type,const QString& filePath,const QVector<QString>& param)
{
    qDebug()<<"trying to create Note";
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
                note = new Tache(filePath,title,action,echeance,priorite,status,echue,priorise);
            }
            addNote(note);
            return note;
        }
    }
    throw NotesException("Note already exists");
}

void NotesManager::load() {
    for (unsigned int i = 0; i<nbNotes; i++) delete notes[i];
    nbNotes = 0;
    QDirIterator it(foldername, QStringList() << "*.xml", QDir::Files);
    while (it.hasNext()) {
        QString fichier = it.next();
        QFile fin(fichier);
        // If we can't open it, let's show an error message.
        if (!fin.open(QIODevice::ReadOnly | QIODevice::Text)) {
            throw NotesException("Erreur ouverture fichier notes");
        }
        QXmlStreamReader xml(&fin);
        while (!xml.atEnd() && !xml.hasError())
        {
            QXmlStreamReader::TokenType token = xml.readNext();

            if (token == QXmlStreamReader::StartDocument) continue;

            if (token == QXmlStreamReader::StartElement)
            {
                if (xml.name() == "note")
                {
                    if (xml.attributes().hasAttribute("type")){
                        QString type = xml.attributes().value("type").toString();
                        QVector<QString> parameters;
                        qDebug() << "id = " << fin.fileName();
                        qDebug() << "type = " << type;
                        xml.readNext();
                        while (!(xml.tokenType() == QXmlStreamReader::EndElement && xml.name() =="note")) {
                            if (xml.tokenType() == QXmlStreamReader::StartElement) {
                                qDebug() << "info = " << xml.name();
                                parameters.push_back(xml.name().toString().toLower());
                                xml.readNext();
                                qDebug() << "text = " << xml.text().toString();
                                parameters.push_back(xml.text().toString());
                            }
                            xml.readNext();
                        }
                        qDebug() << "ajout note " << fin.fileName() << "\n";
                        create(type, fin.fileName(), parameters);
                    }                    
                }
                else
                {
                    qDebug() << "Token:" << xml.name().toLatin1() << QString::number(xml.lineNumber()).toLatin1();
                    break;
                }
                continue;
            }
        }
        if (xml.hasError())
        {
             //Log error
            qDebug() << "XML-Pseudocode parsing error:- "<< xml.errorString();
        }

    }
}
