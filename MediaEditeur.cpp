#include "MediaEditeur.h"

MediaEditeur::MediaEditeur(Media& a, QWidget *parent) : NoteEditeur(a,parent)
{
    descriptionl = new QLabel("Description");

    description = new QTextEdit;
    QVBoxLayout* v1 = new QVBoxLayout();
    QHBoxLayout* v2 = new QHBoxLayout();
    description->setMaximumHeight(50);
    Player* player = new Player();
   // player->setMinimumSize(150,500);
    v2->addWidget(descriptionl);
    v2->addWidget(description);
    v1->addLayout(v2);
    v1->addWidget(player);

    centralLayout->addLayout(v1);
    description->setText(a.getDescription());

    QObject::connect(description, SIGNAL(textChanged()), this, SLOT(activerSave()));

}


MediaEditeur::~MediaEditeur()
{

}
void MediaEditeur::sauvegardeAttributs()
{
    dynamic_cast<Media&>(getNote()).setDescription(description->toPlainText());
}

