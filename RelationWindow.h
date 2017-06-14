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
    /**
     * \brief  Construit une fenetre RelationEditor.
     * \details Met en place l'interface graphique et la charge avec
     * les informations contenues dans les RelationManager et NotesManager
     */
    explicit RelationEditor(QWidget *parent = 0);
    ~RelationEditor();

    /**
     * \brief  Construit la liste des relations a partir des informations de RelationManager.
     */
    void loadRelationList();

private:
    /**
     * \brief  Interface graphique de la classe.
     */
    Ui::RelationEditor *ui;

private slots:
    /**
     * \brief  Activation/Desactivation de l'interface.
     * \details Selon la valeur de \a b, on active ou on desactive les champs
     * editables de l'interface.
     * \param b True si on veut desactiver l'interface, False sinon.
     */
    void activateUi(bool b);

public slots:

    /**
     * \brief  Ajoute une nouvelle relation.
     * \details Affiche une fenetre NewRelationWindow. Si le resultat est "ok", ajoute
     * la relation au manager et à l'interface.
     */
    void newRelation();

    /**
     * \brief  Supprime une relation.
     * \details Recupere la relation actuellement selectionnee puis
     * l'enleve du RelationManager et de l'affichage.
     */
    void removeRelation();

    /**
     * \brief  Affiche la relation selectionne dans la liste.
     * \param item L'item de la liste sur lequel on a cliqué.
     */
    void openRelation(QListWidgetItem* item);

    /**
     * \brief  Affiche le bouton sauvegarde.
     */
    void enableSave();

    /**
     * \brief  Sauvegarde les changements effectues sur la relation dans le RelationManager.
     */
    void save();

    /**
     * \brief  Ajoute un couple a la relation selectionne.
     * \details Recupere les deux notes actuellement selectionnees, ajoute le couple
     * a la relation puis l'affiche dans l'interface graphique.
     */
    void addCouple();

    /**
     * \brief  Retire de la relation le couple selectionne, puis met a jour l'affichage.
     */
    void removeCouple();
};



class NewRelationWindow : public QDialog{

    Q_OBJECT
private:

    /**
     * \brief  Layout principal de la fenetre.
     */
    QHBoxLayout* layout;

    /**
     * \brief Label du champ \a name.
     */
    QLabel* nameLabel;

    /**
     * \brief Champ d'édition du nom.
     */
    QLineEdit* name;

    /**
     * \brief Conteneur des boutons de validations.
     */
    QDialogButtonBox *BtnBox;

    QPushButton* ok;

public:

    /**
     * \brief Construit une nouvelle fenetre NewRelationWindow et initialise son interfae graphique.
     */
    NewRelationWindow(){
        layout = new QHBoxLayout(this);
        nameLabel = new QLabel("Nom");
        name = new QLineEdit();
        BtnBox = new QDialogButtonBox();
        ok = new QPushButton("Ok");
        ok->setEnabled(false);
        BtnBox->addButton(ok,QDialogButtonBox::AcceptRole);
        BtnBox->addButton("Cancel",QDialogButtonBox::RejectRole);

        connect(BtnBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
        connect(BtnBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

        connect(name, &QLineEdit::textChanged, this, &NewRelationWindow::onTextChanged);

        layout->addWidget(nameLabel);
        layout->addWidget(name);
        layout->addWidget(BtnBox);

    }

    /**
     * \brief    Retourne le nom entree par l'utilisateur.
     * \return   Un QString contenant le nom de la nouvelle Relation.
     */
    QString getName() const {return name->text();}

    /**
     * \brief    Actions a effectuer quand le champ \a nom change.
     * \details Si il est vide, on desactive le bouton "ok". Sinon on l'active.
     */
    void onTextChanged(const QString &arg1){
        if(name->text().isEmpty()){
            ok->setEnabled(false);
        }else{
            ok->setEnabled(true);
        }
    }
};

#endif // RELATIONEDITOR_H
