#include "MediaEditeur.h"

MediaEditeur::MediaEditeur(Media* a, QWidget *parent) : NoteEditeur(a,parent)
{
    descriptionl = new QLabel("Description");
    description = new QTextEdit;

    fichierl = new QLabel("Fichier",this);
    fichier = new QLineEdit(this);

    fichier->setMaximumHeight(25);
    fichier->setReadOnly(true);


    QPushButton *openButton = new QPushButton(tr("Open..."));
    connect(openButton, SIGNAL(clicked()), this, SLOT(openFile()));

    player = new VideoPlayer();

    description->setMaximumHeight(50);

    QVBoxLayout* v1 = new QVBoxLayout();
    QHBoxLayout* h1 = new QHBoxLayout();
    QHBoxLayout* h2 = new QHBoxLayout();

    h1->addWidget(descriptionl);
    h1->addWidget(description);
    h2->addWidget(fichierl);
    h2->addWidget(fichier);
    h2->addWidget(openButton);
    v1->addLayout(h1);
    v1->addWidget(player);
    v1->addLayout(h2);



    centralLayout->addLayout(v1);
    if (a->getFile()!=""){
        openFile(a->getFile());
        fichier->setText(a->getFile());
    }
    description->setText(a->getDescription());

    QObject::connect(description, SIGNAL(textChanged()), this, SLOT(activerSave()));
    QObject::connect(fichier, SIGNAL(textChanged(QString)), this, SLOT(activerSave()));

}


MediaEditeur::~MediaEditeur()
{

}
void MediaEditeur::sauvegardeAttributs()
{
    if (dynamic_cast<Media*>(getNote()))
        qDebug()<<"Media";

    dynamic_cast<Media*>(getNote())->setDescription(description->toPlainText());
    qDebug()<<"saved desc";
    qDebug()<<fichier->text();

    dynamic_cast<Media*>(getNote())->setFile(fichier->text());
    qDebug()<<"saved file";

}

void MediaEditeur::openFile(QString f){

    if (f==""){
        QFileDialog fileDialog(this);
        fileDialog.setWindowTitle(tr("Open Movie"));
        fileDialog.setDirectory(QStandardPaths::standardLocations(QStandardPaths::MoviesLocation).value(0, QDir::homePath()));
        f = fileDialog.getOpenFileName();
        fichier->setText(f);
    }
    player->setUrl(QUrl::fromLocalFile(f));
}
