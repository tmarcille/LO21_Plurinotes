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

    // si l'article existe d�j�, on en renvoie une r�f�rence
    
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

    Note& note = getNote(id);
    note.saveInFile();

}


void NotesManager::load() {

    // A refaire pour eviter le crash quand 2 notes dans le m�me fichier

    QDirIterator it(foldername, QStringList() << "*.xml", QDir::Files);
	while (it.hasNext()) {
		QString fichier = it.next();
		QFile fin(fichier);
		// If we can't open it, let's show an error message.
		if (!fin.open(QIODevice::ReadOnly | QIODevice::Text)) {
			throw NotesException("Erreur ouverture fichier notes");
		}

		// QXmlStreamReader takes any QIODevice.
		QXmlStreamReader xml(&fin);
		qDebug() << "debut fichier\n";
		// We'll parse the XML until we reach end of it.
        bool end = false;
        while (!xml.atEnd() && !xml.hasError() && !end) {
			// Read next element.
			QXmlStreamReader::TokenType token = xml.readNext();
			// If token is just StartDocument, we'll go to next.
			if (token == QXmlStreamReader::StartDocument) continue;
			// If token is StartElement, we'll see if we can read it.
            if (token == QXmlStreamReader::StartElement) {
                if (xml.name() == "notes") continue;
				// If it's named tache, we'll dig the information from there.
                //end = true;
                QString type = xml.name().toString();
				QString identificateur;
				QString path = fin.fileName();
				QString file = path.section("/", -1, -1);
				identificateur = file.section(".", 0, 0);
				qDebug() << "id=" << identificateur << "\n";

                //dans le vecteur parameters sera contenu tout les parametres lus dans la note sous la forme: attribut1, valeur1, attribut2, valeur2...
				QVector<QString> parameters;

				QXmlStreamAttributes attributes = xml.attributes();
				xml.readNext();

				//We're going to loop over the things because the order might change.
				//We'll continue the loop until we hit an EndElement named article.

				while (!(xml.tokenType() == QXmlStreamReader::EndElement && xml.name() == type)) {
					if (xml.tokenType() == QXmlStreamReader::StartElement) {
						parameters.push_back(xml.name().toString().toLower());
						xml.readNext();
						parameters.push_back(xml.text().toString());

					}
					// ...and next...
					xml.readNext();
				}
				qDebug() << "ajout note " << identificateur << "\n";
                create(type, identificateur, parameters);
			}
		}
		// Error handling.
		if (xml.hasError()) {
			throw NotesException("Erreur lecteur fichier notes, parser xml");
		}
		// Removes any device() or data from the reader * and resets its internal state to the initial state.
		xml.clear();
		qDebug() << "fin load\n";

	}
}
