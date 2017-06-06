#ifndef RELATIONEDITOR_H
#define RELATIONEDITOR_H

#include <QWidget>
#include "RelationManager.h"
#include<QDialog>
#include<QDialogButtonBox>

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
};

#endif // RELATIONEDITOR_H
