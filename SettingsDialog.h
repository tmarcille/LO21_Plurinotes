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
    SettingsDialog(QString sF, QWidget *parent = 0);
    ~SettingsDialog();

private:
    Ui::SettingsDialog *ui;
    QString settingsFile;
    void saveSettings();
    void loadSettings();
    void accept();

public slots:
    void folderSelect();
};

#endif // SETTINGSDIALOG_H
