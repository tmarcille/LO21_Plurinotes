#ifndef RELATIONEDITOR_H
#define RELATIONEDITOR_H

#include <QWidget>
#include "RelationManager.h"
#include<QDialog>
#include<QDialogButtonBox>
#include <QListWidget>

namespace Ui {
class RelationEditor;
}

class RelationEditor : public QWidget
{
    Q_OBJECT

public:
    explicit RelationEditor(QWidget *parent = 0);
    ~RelationEditor();

private:
    Ui::RelationEditor *ui;

public slots:
    void newRelation();
    void openRelation(QListWidgetItem* item);
    void activateUi();
    void enableSave();
    void save();
    void addCouple();
    void removeCouple();
};



class NewRelationWindow : public QDialog{

    Q_OBJECT
private:
    QHBoxLayout* layout;
    QLabel* doneLabel;
    QLineEdit* name;
    QDialogButtonBox *BtnBox;

public:
    NewRelationWindow(){
        layout = new QHBoxLayout(this);
        doneLabel = new QLabel("Nom");
        name = new QLineEdit();
        BtnBox = new QDialogButtonBox();

        BtnBox->addButton("Ok",QDialogButtonBox::AcceptRole);
        BtnBox->addButton("Cancel",QDialogButtonBox::RejectRole);

        connect(BtnBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
        connect(BtnBox, &QDialogButtonBox::rejected, this, &QDialog::reject);


        layout->addWidget(doneLabel);
        layout->addWidget(name);
        layout->addWidget(BtnBox);
    }
    QString getName() const {return name->text();}

};

#endif // RELATIONEDITOR_H
