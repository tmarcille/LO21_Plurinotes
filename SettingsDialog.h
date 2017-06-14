#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <QFileDialog>
#include <QDebug>
#include <QSettings>

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * \brief  Construit une fenetre SettingsDialog.
     * \details Met en place l'interfece graphique et la charge avec
     * les informations contenues dans le fichier config
     */
    SettingsDialog(QString sF, QWidget *parent = 0);
    ~SettingsDialog();

private:

    /**
     * \brief  Interface graphique de la classe.
     */
    Ui::SettingsDialog *ui;

    /**
     * \brief  Chemin vers le fichier de config.
     */
    QString settingsFile;

    /**
     * \brief Sauvegarde les parametres dans le fichier config.
     */
    void saveSettings();

    /**
     * \brief Charge les parametres contenus dans le fichier config.
     */
    void loadSettings();

    /**
     * \brief Surcharge de l'action a effectue quand la fenetre fini avec le status "accepte".
     * \details Ici, on sauvegarde les changements avec save().
     */
    void accept();

public slots:

    /**
     * \brief Ouvre la fenetre de selection du dossier de stockage des notes.
     */
    void folderSelect();

    /**
     * \brief Ouvre la fenetre de selection du fichier de stockage des relations.
     */
    void relationFileSelect();
};

#endif // SETTINGSDIALOG_H
