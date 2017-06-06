#include "RelationWindow.h"
#include "ui_RelationEditor.h"

RelationEditor::RelationEditor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RelationEditor)
{
    ui->setupUi(this);


    RelationManager& m = RelationManager::getManager();

    qDebug()<<"file:"<<m.getFilename();

    try {
        m.load();
    }
    catch (NotesException& e){
        qDebug()<<e.getInfo();
    }

    QVector<Relation*>::iterator it;
    for ( it = m.begin(); it!=m.end(); it++) {
        new QListWidgetItem((*it)->getTitle(), ui->listRelation);
    }

    //QObject::connect(ui.listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(ouvrirNote(QListWidgetItem*)));
    //On active le bouton nouvelle note
    //ui.actionNote->setEnabled(true);
    QObject::connect(ui->newRelation, SIGNAL(clicked()), this, SLOT(newRelation()));

}

RelationEditor::~RelationEditor()
{
    delete ui;
}

void RelationEditor::newRelation(){

    RelationManager& m = RelationManager::getManager();

    QDialog* okDialog = new QDialog();
    QHBoxLayout* layout = new QHBoxLayout(okDialog);
    QLabel* doneLabel = new QLabel("Nom");
    QLineEdit* name = new QLineEdit();
    QDialogButtonBox *BtnBox = new QDialogButtonBox();

    BtnBox->addButton("Ok",QDialogButtonBox::AcceptRole);
    BtnBox->addButton("Cancel",QDialogButtonBox::RejectRole);

    connect(BtnBox, &QDialogButtonBox::accepted, okDialog, &QDialog::accept);
    connect(BtnBox, &QDialogButtonBox::rejected, okDialog, &QDialog::reject);


    layout->addWidget(doneLabel);
    layout->addWidget(name);
    layout->addWidget(BtnBox);
    okDialog->exec();

    //Relation* test = m.getRelation("");
    //QListWidgetItem* nouvelle_note = new QListWidgetItem(test->getTitle(), ui->listRelation);

}
