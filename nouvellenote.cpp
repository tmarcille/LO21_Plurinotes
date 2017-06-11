#include "nouvellenote.h"
#include "ui_nouvellenote.h"
#include "Notes.h"
#include "ArticleEditeur.h"

NouvelleNote::NouvelleNote(QWidget *parent) :
    QDialog(parent), ui(new Ui::NouvelleNote)
{
<<<<<<< HEAD
    ui->setupUi(this);;
=======
    ui->setupUi(this);
    QObject::connect(ui->radioButtons, SIGNAL(buttonPressed(int)), this, SLOT(test(int)));
>>>>>>> refs/remotes/origin/Relations

}

NouvelleNote::~NouvelleNote()
{
    delete ui;
}

QString NouvelleNote::getSelectedType() const
{
    return ui->radioButtons->checkedButton()->text();

}

QString NouvelleNote::getNom() const
{
    return ui->lineEdit->text();
}

<<<<<<< HEAD
=======
void NouvelleNote::test(int a) {

    qDebug()<<a;
}
>>>>>>> refs/remotes/origin/Relations
