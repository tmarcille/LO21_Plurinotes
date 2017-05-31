#ifndef RELATIONEDITOR_H
#define RELATIONEDITOR_H

#include <QWidget>

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
};

#endif // RELATIONEDITOR_H
