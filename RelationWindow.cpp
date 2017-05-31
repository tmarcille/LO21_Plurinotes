#include "RelationWindow.h"
#include "ui_RelationEditor.h"

RelationEditor::RelationEditor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RelationEditor)
{
    ui->setupUi(this);
}

RelationEditor::~RelationEditor()
{
    delete ui;
}
