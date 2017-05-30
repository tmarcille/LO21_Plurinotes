#include "NoteViewer.h"

NoteViewer::NoteViewer(QWidget *parent) : QWidget(parent)
{
    layout = new QHBoxLayout(this);
    tabWidget = new QTabWidget();
    tabWidget->setTabsClosable(true);
    tabWidget->setMovable(true);
    layout->addWidget(tabWidget);
    QObject::connect(tabWidget, &QTabWidget::tabCloseRequested, this, &NoteViewer::closeTab);
}

NoteViewer::~NoteViewer(){

    for(int i=tabWidget->count() ; i>0 ; i--)
            closeTab(i);
}

NoteEditeur* NoteViewer::createEditor(Note* n) {

    //test de si l'editeur existe deja (un seul editeur possible par note)

    QVector<NoteEditeur*>::iterator it;
    for (it = NoteEditeur::editeurs.begin(); it!=NoteEditeur::editeurs.end(); it++ ){
        if((*it)->getId()==n->getId()){
            qDebug()<<"returned existing editor";
            return *it;
        }
    }

    qDebug()<<"ajout editeur";
    NoteEditeur* edit = NULL;
    QString type = n->getType();
    if (type == "article") {
        edit = new ArticleEditeur(dynamic_cast<Article*>(n));
        qDebug()<<"article";
    }
    if (type == "media") {
        edit = new MediaEditeur(dynamic_cast<Media*>(n));
        qDebug()<<"media";
    }
    return edit;
}

void NoteViewer::showNote(Note* note){


    //si la note est deja presente on la focus
    for (int i = 0; i < tabWidget->count(); i++){
        if (tabWidget->tabText(i) == note->getId() || tabWidget->tabText(i) == "*"+note->getId()){
            tabWidget->setCurrentIndex(i);
            return;
        }

    }
    //sinon on la crée
    NoteEditeur* fenetre = createEditor(note);
    connect(fenetre,&NoteEditeur::currentlyEditing, this,&NoteViewer::unsavedChanges);
    connect(fenetre,&NoteEditeur::finishedEditing, this,&NoteViewer::saveChanges);

    //puis on l'ajoute
    tabWidget->addTab(fenetre,fenetre->getId());
    tabWidget->setCurrentWidget(fenetre);

}

void NoteViewer::closeNote(const QString& id){

    for (int i = 0; i < tabWidget->count(); i++)
        if (tabWidget->tabText(i)==id || tabWidget->tabText(i)=="*"+id)
            closeTab(i);
}

void NoteViewer::closeTab(int i){

    tabWidget->setCurrentIndex(i);
    QWidget* old = tabWidget->widget(i);
    NoteEditeur* noteEdit = dynamic_cast<NoteEditeur*>(old);
    if(noteEdit)
        noteEdit->verifSave();
    delete old;
}

bool NoteViewer::isOpen(const QString& id) const{

    for (int i = 0; i < tabWidget->count(); i++)
        if (tabWidget->tabText(i)==id || tabWidget->tabText(i)=="*"+id )
            return true;
    return false;
}

void NoteViewer::refreshNote(const QString& id){

    for (int i = 0; i < tabWidget->count(); i++)
        if (tabWidget->tabText(i)==id || tabWidget->tabText(i)=="*"+id){
            QWidget* edit = tabWidget->widget(i);
            qDebug()<<"note trouvée";
            tabWidget->removeTab(i);
            tabWidget->insertTab(i,edit,id);
            tabWidget->setCurrentIndex(i);
        }
}

void NoteViewer::unsavedChanges(NoteEditeur* f){

    tabWidget->setTabText(tabWidget->indexOf(f),"*"+f->getId());

}

void NoteViewer::saveChanges(NoteEditeur* f){

    tabWidget->setTabText(tabWidget->indexOf(f),f->getId());
}
