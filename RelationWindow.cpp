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
    loadRelationList();

    NotesManager& nm = NotesManager::getManager();
    for (NotesManager::Iterator it = nm.getIterator(); !it.isDone(); it.next()) {
        ui->note1->addItem((it.current()).getId());
        ui->note2->addItem((it.current()).getId());
    }
    QObject::connect(ui->listRelation, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(openRelation(QListWidgetItem*)));
    QObject::connect(ui->newRelationBtn, SIGNAL(clicked()), this, SLOT(newRelation()));
    QObject::connect(ui->removeRelationBtn, SIGNAL(clicked()), this, SLOT(removeRelation()));
    QObject::connect(ui->description, SIGNAL(textChanged()), this, SLOT(enableSave()));
    QObject::connect(ui->saveBtn,SIGNAL(clicked()), this, SLOT(save()));
    QObject::connect(ui->addCoupleBtn,SIGNAL(clicked()), this, SLOT(addCouple()));
    QObject::connect(ui->removeCoupleBtn,SIGNAL(clicked()), this, SLOT(removeCouple()));

}

RelationEditor::~RelationEditor()
{
    delete ui;
}

void RelationEditor::loadRelationList(){

    RelationManager& m = RelationManager::getManager();
    ui->listRelation->clear();
    QVector<Relation*>::iterator it;
    for ( it = m.begin(); it!=m.end(); it++) {
        qDebug()<<(*it)->getTitle();
        new QListWidgetItem((*it)->getTitle(), ui->listRelation);
    }

}

void RelationEditor::newRelation(){
    RelationManager& m = RelationManager::getManager();

    NewRelationWindow* okDialog = new NewRelationWindow();

    if(okDialog->exec()==QDialog::Accepted){
        m.addRelation(okDialog->getName());
        m.save();
        loadRelationList();
    }
}

void RelationEditor::removeRelation(){

    RelationManager& r = RelationManager::getManager();
    qDebug()<<"removing remation : "<<ui->listRelation->currentItem()->text();
    r.removeRelation(ui->listRelation->currentItem()->text());
    loadRelationList();

    if (ui->listRelation->count() > 0){
        openRelation(ui->listRelation->item(0));
        ui->listRelation->setCurrentRow(0);
    }
    else{
        activateUi(false);
    }
}

void RelationEditor::openRelation(QListWidgetItem *item) {

    activateUi(true);
    RelationManager& m = RelationManager::getManager();
    Relation* r = m.getRelation(item->text());
    ui->couplesList->clear();
    qDebug()<<"ouverture Relation"<<item->text();
    for (unsigned int i=0; i<r->getSize(); i++){
        qDebug()<<"relation"<<i;
        Couple* c = r->getCouple(i);
        ui->couplesList->addItem(c->father->getId()+"--->"+c->son->getId()+"    "+c->label);
    }
    ui->title->setText(r->getTitle());
    ui->description->setPlainText(r->getDescription());
    ui->saveBtn->setEnabled(false);
}

void RelationEditor::enableSave(){
    ui->saveBtn->setEnabled(true);
}

void RelationEditor::save(){
    RelationManager& m = RelationManager::getManager();
    m.getRelation(ui->title->text())->setDescription(ui->description->toPlainText());
    m.save();
    ui->saveBtn->setEnabled(false);
}

void RelationEditor::addCouple(){
    RelationManager& m = RelationManager::getManager();
    NotesManager& nm = NotesManager::getManager();
    QString n1 = ui->note1->currentText();
    QString n2 = ui->note2->currentText();
    QString label = ui->coupleLabel->text();
    m.getRelation(ui->title->text())->addCouple(&nm.getNote(n1),&nm.getNote(n2),label);
    m.save();
    openRelation(ui->listRelation->currentItem());
}

void RelationEditor::removeCouple(){
    qDebug()<<ui->couplesList->currentRow();
    RelationManager& r = RelationManager::getManager();
    r.getRelation(ui->title->text())->removeCouple(ui->couplesList->currentRow());
    r.save();
    openRelation(ui->listRelation->currentItem());
}

void RelationEditor::activateUi(bool b){
    ui->description->setEnabled(b);
    ui->title->setEnabled(b);
    ui->note1->setEnabled(b);
    ui->note2->setEnabled(b);
    ui->addCoupleBtn->setEnabled(b);
    ui->couplesList->setEnabled(b);
    ui->removeCoupleBtn->setEnabled(b);
    ui->coupleLabel->setEnabled(b);
}
