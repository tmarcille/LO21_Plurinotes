//fenetre de création d'une note

#ifndef NOUVELLENOTE_H
#define NOUVELLENOTE_H

#include <QDialog>
#include <QDebug>

/**
 * \brief La classe NouvelleNote permet de générer une fenetre pour une nouvelle note
 * \details La classe NouvelleNote permet de générer une fenetre pour choisir le type et id d'une note
 *
 */

namespace Ui {
class NouvelleNote;
}

class NouvelleNote : public QDialog
{
    Q_OBJECT

public:
    explicit NouvelleNote(QWidget *parent = 0);
    ~NouvelleNote();

    /**
     * \brief Nom que l'utilisateur a rentre pour la note.
     * \return QString avec le nom.
     */
    QString getNom() const;

    /**
     * \brief Type de Note que l'utilisateur a selectionne.
     * \return QString avec le type.
     */
	QString getSelectedType() const;
private:
    Ui::NouvelleNote *ui;
	
    public slots:

};

#endif // NOUVELLENOTE_H
