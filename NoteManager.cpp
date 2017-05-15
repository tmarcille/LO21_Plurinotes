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
	
	

	for (unsigned int i = 0; i<nbNotes; i++) {
		if (notes[i]->getId() == a->getId()) throw NotesException("error, creation of an already existent note");
	}
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


Note& NotesManager::getNote(const QString& id){

    // si l'article existe déjà, on en renvoie une référence
    
	for(unsigned int i=0; i<nbNotes; i++){
		if (notes[i]->getId()==id) return *notes[i];
	}
    //// sinon il est créé
    //Article* a=new Article(id,"","");
    //addArticle(a);
	Note* note = NULL;
	return *note;
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
		it.current().saveInFile(foldername);
	}
}



void NotesManager::load() {

	//Nom de dossier choisit plus tard dans les parametres

	QString fichier = QFileDialog::getOpenFileName(nullptr, "Ouvrir un fichier", QString(), "Note (*.xml)");
	QDir d = QFileInfo(fichier).absoluteDir();
	QDirIterator it(d.absolutePath(), QStringList() << "*.xml", QDir::Files);
	setFoldername(d.absolutePath());

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

		while (!xml.atEnd() && !xml.hasError()) {
			// Read next element.
			QXmlStreamReader::TokenType token = xml.readNext();
			// If token is just StartDocument, we'll go to next.
			if (token == QXmlStreamReader::StartDocument) continue;
			// If token is StartElement, we'll see if we can read it.
			if (token == QXmlStreamReader::StartElement) {
				if (xml.name() == "notes") continue;
				// If it's named tache, we'll dig the information from there.

				QString type = xml.name().toString();

				QString identificateur;
				QString path = fin.fileName();
				QString file = path.section("/", -1, -1);
				identificateur = file.section(".", 0, 0);
				qDebug() << "id=" << identificateur << "\n";

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
				Note* n = create(type, identificateur, parameters);
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