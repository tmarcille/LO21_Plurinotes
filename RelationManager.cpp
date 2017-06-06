#include "RelationManager.h"

RelationManager* RelationManager::instance = nullptr;

RelationManager& RelationManager::getManager() {
    if (!instance) instance = new RelationManager;
    return *instance;
}

void RelationManager::freeManager() {
    delete instance;
    instance = nullptr;
}

RelationManager::~RelationManager(){

}

RelationManager::RelationManager(): filename(""),relations({})
{

}

Relation* RelationManager::getRelation(QString &name){


    //test si la relation existe deja
    QVector<Relation*>::iterator it;
    for (it = relations.begin(); it!= relations.end() ; it++ ){
        if( (*it)->getTitle() == name ){
            qDebug()<<typeid(*it).name();
            return (*it);}
    }

    //sinon on en ajoute une nouvelle
    Relation* r = new Relation(name);
    relations.push_back(r);
    return nullptr;

}

void RelationManager::save() const{

    QFile newfile(filename);
    //if (!newfile.open(QIODevice::WriteOnly | QIODevice::Text))
      //  throw NotesException(QString("erreur sauvegarde notes : ouverture fichier xml"));
    QXmlStreamWriter stream(&newfile);
    stream.setAutoFormatting(true);
    stream.writeStartDocument();
    stream.writeStartElement("relations");

    QVector<Relation*>::const_iterator it;
    for (it = relations.begin(); it!= relations.end(); it++){
        stream.writeStartElement("relation");
        stream.writeTextElement("title",(*it)->getTitle());
        stream.writeTextElement("description",(*it)->getDescription());
        for (unsigned int i = 0; i < (*it)->getSize(); i++){
            stream.writeStartElement("couple");
            stream.writeTextElement("father",(*it)->getCouple(i)->father->getId());
            stream.writeTextElement("son",(*it)->getCouple(i)->son->getId());
            stream.writeEndElement();
        }
    }
    stream.writeEndElement();
    stream.writeEndDocument();
    newfile.close();
}

void RelationManager::load() {

    NotesManager& m = NotesManager::getManager();

    QFile fin(filename);
    // If we can't open it, let's show an error message.
    if (!fin.open(QIODevice::ReadOnly | QIODevice::Text))
        throw NotesException("Erreur ouverture fichier notes");

    // QXmlStreamReader takes any QIODevice.
    QXmlStreamReader xml(&fin);
    //qDebug()<<"debut fichier\n";
    // We'll parse the XML until we reach end of it.
    while(!xml.atEnd() && !xml.hasError()) {
        // Read next element.
        QXmlStreamReader::TokenType token = xml.readNext();
        // If token is just StartDocument, we'll go to next.
        if(token == QXmlStreamReader::StartDocument) continue;
        // If token is StartElement, we'll see if we can read it.
        if(token == QXmlStreamReader::StartElement) {
            // If it's named taches, we'll go to the next.
            if(xml.name() == "relations") continue;
            // If it's named tache, we'll dig the information from there.
            if(xml.name() == "relation") {
                qDebug()<<"new article\n";
                QString title;
                QString description;

                QString father;
                QString son;

                //QString text;
                QXmlStreamAttributes attributes = xml.attributes();
                xml.readNext();
                //We're going to loop over the things because the order might change.
                //We'll continue the loop until we hit an EndElement named article.
                while(!(xml.tokenType() == QXmlStreamReader::EndElement && xml.name() == "relation")) {
                    if(xml.tokenType() == QXmlStreamReader::StartElement) {
                        // We've found title.
                        if(xml.name() == "title") {
                            xml.readNext(); title=xml.text().toString();
                            qDebug()<<"title="<<title<<"\n";
                        }

                        // We've found description.
                        if(xml.name() == "description") {
                            xml.readNext(); description=xml.text().toString();
                            qDebug()<<"description="<<description<<"\n";
                        }


                        if(xml.name() == "father") {
                            xml.readNext();
                            father=xml.text().toString();
                            qDebug()<<"text="<<father<<"\n";
                           /* try { father = m.getNote(f);}
                            catch(NotesException& e){
                                if (e.getInfo()== "error, note not existing")
                                    qDebug()<<"Note don't exist anymore"; }
                                    */
                        }
                        if(xml.name() == "son") {
                            xml.readNext();
                            son=xml.text().toString();
                            qDebug()<<"text="<<son<<"\n";
                           /* try { father = m.getNote(f);}
                            catch(NotesException& e){
                                if(e.getInfo()=="error, note not existing")
                                    qDebug()<<"Note don't exist anymore"; }
                                    */
                        }
                    }
                    // ...and next...
                    xml.readNext();
                }
                //qDebug()<<"ajout note "<<identificateur<<"\n";
                //addArticle(identificateur,titre,text);
            }
        }
    }
    // Error handling.
    if(xml.hasError()) {
        throw NotesException("Erreur lecteur fichier notes, parser xml");
    }
    // Removes any device() or data from the reader * and resets its internal state to the initial state.
    xml.clear();
    qDebug()<<"fin load\n";
}

