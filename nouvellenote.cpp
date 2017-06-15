#include "nouvellenote.h"
#include "ui_nouvellenote.h"
#include "Notes.h"
#include "ArticleEditeur.h"

NouvelleNote::NouvelleNote(QWidget *parent) :
    QDialog(parent), ui(new Ui::NouvelleNote)
{
    ui->setupUi(this);

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
