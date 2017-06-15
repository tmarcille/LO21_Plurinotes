#include "SettingsDialog.h"
#include "ui_SettingsDialog.h"

SettingsDialog::SettingsDialog(QString sF, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog), settingsFile(sF)
{
    ui->setupUi(this);
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &SettingsDialog::accept);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &SettingsDialog::reject);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(folderSelect()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(relationFileSelect()));
    loadSettings();
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::saveSettings()
{
    QSettings settings(settingsFile, QSettings::IniFormat);
    settings.setValue("folder",ui->lineEdit->text());
    settings.setValue("relationFile",ui->lineEdit_2->text());
    if (ui->checkBin->isChecked())
        settings.setValue("checkBin","true");
    else
        settings.setValue("checkBin","false");
}

void SettingsDialog::loadSettings()
{
    QSettings settings(settingsFile, QSettings::IniFormat);
    ui->lineEdit->setText(settings.value("folder", "").toString());
    ui->lineEdit_2->setText(settings.value("relationFile", "").toString());
    if (settings.value("checkBin", "").toString() == "true")
        ui->checkBin->setChecked(true);
    else
        ui->checkBin->setChecked(false);

}

void SettingsDialog::accept()
{
    saveSettings();
    done(QDialog::Accepted);
}

void SettingsDialog::folderSelect()
{
    QString dir = QFileDialog::getExistingDirectory();
    ui->lineEdit->setText(dir);
}

void SettingsDialog::relationFileSelect(){
    QString path = QFileDialog::getSaveFileName(this, "Enregistrer sous...", QDir::currentPath(), "XML (*.xml)", 0, QFileDialog::DontConfirmOverwrite);
    ui->lineEdit_2->setText(path);
}
