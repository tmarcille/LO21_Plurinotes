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
            notes[nbNotes++] = a; //composition ?
        }
        return;
    }
    qDebug()<<"Note was already in the manager";
}


Note& NotesManager::getNote(const QString& id) const{

    // si l'article existe d?j?, on en renvoie une r?f?rence

    for(unsigned int i=0; i<nbNotes; i++){
        if (notes[i]->getId()==id) return *notes[i];
    }
    //sinon on renvoie une erreur;
    throw NotesException("error, note not existing");
}

NotesManager::NotesManager() :notes(nullptr), nbNotes(0), nbMaxNotes(0), foldername("") {}

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


void NotesManager::load() {

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
