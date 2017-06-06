//fenetre de cr�ation d'une note

#ifndef NOUVELLENOTE_H
#define NOUVELLENOTE_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class NouvelleNote;
}

class NouvelleNote : public QDialog
{
    Q_OBJECT

public:
    explicit NouvelleNote(QWidget *parent = 0);
    ~NouvelleNote();
	QString getNom() const;
	QString getSelectedType() const;
private:
    Ui::NouvelleNote *ui;
	
	public slots:
    void test(int);

};

#endif // NOUVELLENOTE_H
