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
    void loadRelationList();

private:
    Ui::RelationEditor *ui;

public slots:
    void newRelation();
    void removeRelation();
    void openRelation(QListWidgetItem* item);
    void activateUi(bool b);
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
    QPushButton* ok;

public:
    NewRelationWindow(){
        layout = new QHBoxLayout(this);
        doneLabel = new QLabel("Nom");
        name = new QLineEdit();
        BtnBox = new QDialogButtonBox();
        ok = new QPushButton("Ok");
        ok->setEnabled(false);
        BtnBox->addButton(ok,QDialogButtonBox::AcceptRole);
        BtnBox->addButton("Cancel",QDialogButtonBox::RejectRole);

        connect(BtnBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
        connect(BtnBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

        connect(name, &QLineEdit::textChanged, this, &NewRelationWindow::onTextChanged);

        layout->addWidget(doneLabel);
        layout->addWidget(name);
        layout->addWidget(BtnBox);

    }
    QString getName() const {return name->text();}
    void onTextChanged(const QString &arg1){
        if(name->text().isEmpty()){
            ok->setEnabled(false);
        }else{
            ok->setEnabled(true);
        }
    }
};

#endif // RELATIONEDITOR_H
